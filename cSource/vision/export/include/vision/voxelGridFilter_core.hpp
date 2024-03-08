///////////////////////////////////////////////////////////////////////////
//    This header includes voxelGridFilter Core implementation
//    Copyright 2018-2021 The MathWorks, Inc.
///////////////////////////////////////////////////////////////////////////
#ifndef VOXELGRIDFILTER_CORE_HPP
#define VOXELGRIDFILTER_CORE_HPP

#define _USE_MATH_DEFINES

#ifndef __portable__
// export includes
#include <mfl_scalar/query.hpp>

// 3rd party includes
#include <tbb/concurrent_vector.h>
#include <tbb/parallel_for.h>
#include <tbb/parallel_sort.h>
#endif

// system includes
#include <assert.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <limits>
#include <cmath>
#include <cstring>
#include <functional>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#if defined(NDEBUG)
#define VISION_ASSERT(EXPR) (void)0
#else
#define VISION_ASSERT(EXPR) assert(EXPR)
#endif

#if defined(NDEBUG)
#define VISION_ASSERT_MSG(EXPR, MSG) (void)0
#else
#define VISION_ASSERT_MSG(EXPR, MSG) \
    do {                             \
        if (!(EXPR)) {               \
            printf("%s \n", MSG);    \
            assert((EXPR));          \
        }                            \
    } while (false)
#endif

///////////////////////////////////////////////////////////////////////////
// pointCloudIndexStruct
//
// This is an internal structure to bookkeep the points falling into a voxel
///////////////////////////////////////////////////////////////////////////
template <typename T1>
struct pointCloudIndexStruct {
    T1 voxelIndex;
    uint32_T matrixIndex;

    pointCloudIndexStruct(T1 vidx = 0, uint32_T midx = 0)
        : voxelIndex(vidx)
        , matrixIndex(midx) {}
    
    boolean_T operator<(const pointCloudIndexStruct<T1>& p) const {
        // Use the matrix index to break ties when voxel indices are equal. This
        // ensures a stable, deterministic sort.
        return (voxelIndex < p.voxelIndex) ||
               ((voxelIndex == p.voxelIndex) && (matrixIndex < p.matrixIndex));
    }
};

///////////////////////////////////////////////////////////////////////////
// populateIndexVectorNoFilter
// Function to populate index vector without filtering. Use this interface
// when you know all incoming points are valid, and no filtering is
// required. This allows use of multiple threads to speed up execution time.
///////////////////////////////////////////////////////////////////////////
#ifndef __portable__
template <typename valueType, typename T1, typename T2>
uint32_T populateIndexVectorNoFilter(const valueType* pData,
                                     const uint32_T numPoints,
                                     const double voxelSize,
                                     const valueType* pOverlapRange,
                                     std::vector<pointCloudIndexStruct<T1>>& index_vector) {
    
    const double inverseVoxelSize = 1 / voxelSize;
    
    const valueType xmin = pOverlapRange[0], xmax = pOverlapRange[1];
    const valueType ymin = pOverlapRange[2], ymax = pOverlapRange[3];
    const valueType zmin = pOverlapRange[4], zmax = pOverlapRange[5];
    
    // Check that the voxel size is not too small, given the size of the data
    const T1 dx = static_cast<T1>((xmax - xmin) * inverseVoxelSize + 1);
    const T1 dy = static_cast<T1>((ymax - ymin) * inverseVoxelSize + 1);
    const T1 dz = static_cast<T1>((zmax - zmin) * inverseVoxelSize + 1);
    
    const T1 dxy = dx * dy;
    const T1 dxyz = dxy * dz;
    
    VISION_ASSERT_MSG((dx != 0 && dy != 0 && dz != 0 && dxy != 0), "Input grid step is too small");
    VISION_ASSERT_MSG((dx == dxy / dy && dz == dxyz / dxy), "Input grid step is too small");
    
    // Compute the minimum and maximum bounding box values
    const T2 minbx = static_cast<T2>(floor(xmin * inverseVoxelSize));
    const T2 maxbx = static_cast<T2>(floor(xmax * inverseVoxelSize));
    const T2 minby = static_cast<T2>(floor(ymin * inverseVoxelSize));
    const T2 maxby = static_cast<T2>(floor(ymax * inverseVoxelSize));
    
    const T1 numx = static_cast<T1>(maxbx - minbx + 1);
    const T1 numy = static_cast<T1>(maxby - minby + 1);
    const T1 numxy = numx * numy;
    
    // Use a concurrent vector that can be grown from multiple threads
    tbb::concurrent_vector<pointCloudIndexStruct<T1>> tbbIndexVector;
    tbbIndexVector.reserve(numPoints);
    
    // First pass: Go over all points and insert them into the vector
    // with linear voxel index. Points with the same voxel index value
    // will contribute to the same point in the output.
    constexpr size_t grainSize(100000);
    tbb::parallel_for(
                      tbb::blocked_range<uint32_T>(0, numPoints, grainSize), // Range
                      [&](const tbb::blocked_range<uint32_T>& range) { //Begin lambda
                          
                          uint32_T xOffset(0), yOffset(xOffset + numPoints), zOffset(yOffset + numPoints);
                          
                          std::vector<pointCloudIndexStruct<T1>> localIndexVector;
                          localIndexVector.reserve(range.end()-range.begin());
                          auto pDataLocal(pData);
                          
                          for (uint32_T n = range.begin(); n < range.end(); n++) {
                              auto x = pDataLocal[n + xOffset];
                              auto y = pDataLocal[n + yOffset];
                              auto z = pDataLocal[n + zOffset];
                              
                              // Note: We do not check for invalid or out of range points.
                              auto ijk0 = static_cast<T1>(floor((x - xmin) * inverseVoxelSize));
                              auto ijk1 = static_cast<T1>(floor((y - ymin) * inverseVoxelSize));
                              auto ijk2 = static_cast<T1>(floor((z - zmin) * inverseVoxelSize));
                              
                              auto voxelIndex = ijk0 + ijk1 * numx + ijk2 * numxy;
                              localIndexVector.push_back( pointCloudIndexStruct<T1>( voxelIndex, n ) );
                          }
                          
                          std::copy(localIndexVector.begin(), localIndexVector.end(),
                                    tbbIndexVector.grow_by(localIndexVector.size()));
                      }, // End lambda
                      tbb::simple_partitioner());
    
    // Second pass: Sort the index_vector vector using voxel index value
    // so that all points belonging to the same output voxel will be
    // arranged together.
    // tbb::parallel_sort is unstable (it does not preserve ordering) and
    // not-deterministic (the same ordering is not ensured between runs).
    // The operator< overload of pointCloudIndexStruct is modified to make
    // it stable using the matrixIndex when voxel indices are equal.
    
    // First copy the tbb index vector back into a std vector.
    std::copy(tbbIndexVector.begin(), tbbIndexVector.end(), std::back_inserter(index_vector));
    tbb::parallel_sort(index_vector.begin(), index_vector.end(), std::less<pointCloudIndexStruct<T1>>());
    tbbIndexVector.clear();
    
    // Third pass: Count the number of voxels with points in them
    // TODO araja: Fold this into tbb loop
    uint32_T index(0), total(0), numel((uint32_T)index_vector.size());
    while (index < numel) {
        uint32_T i(index+1);
        while( i < numel && index_vector[i].voxelIndex==index_vector[index].voxelIndex) {
            i++;
        }
        total++;
        index = i;
    }
    
    return total;
}
#endif


///////////////////////////////////////////////////////////////////////////
// populateIndexVector
//
// Function to filter out invalid points, points outside given range and
// minVoxelPoints.
// Note: Reserve memory for index_vector of size numPoints
///////////////////////////////////////////////////////////////////////////
template <typename valueType, typename T1, typename T2>
uint32_T populateIndexVector(const valueType* pData,
                             const uint32_T numPoints,
                             const double voxelSize,
                             const valueType* pOverlapRange,
                             std::vector<pointCloudIndexStruct<T1>>& index_vector,
                             double minVoxelPoints = 1) {

    const double inverseVoxelSize = 1 / voxelSize;

    const valueType xmin = pOverlapRange[0], xmax = pOverlapRange[1];
    const valueType ymin = pOverlapRange[2], ymax = pOverlapRange[3];
    const valueType zmin = pOverlapRange[4], zmax = pOverlapRange[5];

    // Check that the voxel size is not too small, given the size of the data
    const T1 dx = static_cast<T1>((xmax - xmin) * inverseVoxelSize + 1);
    const T1 dy = static_cast<T1>((ymax - ymin) * inverseVoxelSize + 1);
    const T1 dz = static_cast<T1>((zmax - zmin) * inverseVoxelSize + 1);

    const T1 dxy = dx * dy;
    const T1 dxyz = dxy * dz;

    VISION_ASSERT_MSG((dx != 0 && dy != 0 && dz != 0 && dxy != 0), "Input grid step is too small");
    VISION_ASSERT_MSG((dx == dxy / dy && dz == dxyz / dxy), "Input grid step is too small");

    // Compute the minimum and maximum bounding box values
    const T2 minbx = static_cast<T2>(floor(xmin * inverseVoxelSize));
    const T2 maxbx = static_cast<T2>(floor(xmax * inverseVoxelSize));
    const T2 minby = static_cast<T2>(floor(ymin * inverseVoxelSize));
    const T2 maxby = static_cast<T2>(floor(ymax * inverseVoxelSize));

    const T1 numx = static_cast<T1>(maxbx - minbx + 1);
    const T1 numy = static_cast<T1>(maxby - minby + 1);
    const T1 numxy = numx * numy;

    std::vector<pointCloudIndexStruct<T1>> index_vector_tmp;
    index_vector_tmp.reserve(numPoints);

    // First pass: Go over all points and insert them into the vector
    // with linear voxel index. Points with the same voxel index value
    // will contribute to the same point in the output.
    valueType x, y, z;
    uint32_T total = 0;

    for (uint32_T n = 0; n < numPoints; n++) {
        x = pData[n];
        y = pData[n + numPoints];
        z = pData[n + numPoints * 2];
        
#ifndef __portable__
        if (!mfl_scalar::IsFinite(x) || !mfl_scalar::IsFinite(y) || !mfl_scalar::IsFinite(z)) {
#else
        if (!std::isfinite(x) || !std::isfinite(y) || !std::isfinite(z)) {
#endif
            continue;
        }

        if (x < xmin || x > xmax || y < ymin || y > ymax || z < zmin || z > zmax) {
            total++;
            continue;
        }

        // Compute the linear voxel index
        T1 ijk0 = static_cast<T1>(floor((x - xmin) * inverseVoxelSize));
        T1 ijk1 = static_cast<T1>(floor((y - ymin) * inverseVoxelSize));
        T1 ijk2 = static_cast<T1>(floor((z - zmin) * inverseVoxelSize));

        T1 voxelIndex = ijk0 + ijk1 * numx + ijk2 * numxy;
        index_vector.push_back(pointCloudIndexStruct<T1>(voxelIndex, n));
    }

        // Second pass: Sort the index_vector vector using voxel index value
        // so that all points belonging to the same output voxel will be
        // arranged together.
        // tbb::parallel_sort is unstable (it does not preserve ordering) and
        // not-deterministic (the same ordering is not ensured between runs).
        // The operator< overload of pointCloudIndexStruct is modified to make
        // it stable using the matrixIndex when voxel indices are equal.
#ifndef __portable__
    tbb::parallel_sort(index_vector.begin(), index_vector.end(),
                       std::less<pointCloudIndexStruct<T1>>());
#else
    std::sort(index_vector.begin(), index_vector.end(), std::less<pointCloudIndexStruct<T1>>());
#endif

    // Third pass: Count the number of voxels that have minimum number of points
    uint32_T index = 0;
    while (index < index_vector.size()) {
        uint32_T i = index + 1;
        while (i < index_vector.size() &&
               index_vector[i].voxelIndex == index_vector[index].voxelIndex) {
            i++;
        }
        if (i - index >= minVoxelPoints) {
            total++;
            if (minVoxelPoints > 1) {
                for (uint32_T j = index; j < i; ++j) {
                    index_vector_tmp.push_back(index_vector[j]);
                }
            }
        }
        index = i;
    }

    if (minVoxelPoints > 1) {
        index_vector = std::move(index_vector_tmp);
    }
    
    return total;
}



///////////////////////////////////////////////////////////////////////////
// voxelGridFilter
//
// Aggregate voxel attributes using index_vector.
// Caller must allocate/deallocate memory for pFilteredData, pFilteredColorData
// pFilteredNormalData, pFilteredIntensityData, pFilteredRangeData
///////////////////////////////////////////////////////////////////////////
template <typename valueType, typename intensityValueType, typename T1>
void voxelGridAlgImpl(const valueType* pData,
                      const uint32_T numPoints,
                      const unsigned char* pColor,
                      const valueType* pNormal,
                      const intensityValueType* pIntensity,
                      const valueType* pRangeData,
                      const valueType* pOverlapRange,
                      valueType* pFilteredData,
                      unsigned char* pFilteredColorData,
                      valueType* pFilteredNormalData,
                      intensityValueType* pFilteredIntensityData,
                      valueType* pFilteredRangeData,
                      valueType* pCovData,
                      uint32_T* pCountData,
                      std::vector<pointCloudIndexStruct<T1>>& index_vector,
                      const uint32_T total,
                      const boolean_T needColor,
                      const boolean_T needNormal,
                      const boolean_T needIntensity,
                      const boolean_T needRangeData,
                      const boolean_T needCovariance,
                      const boolean_T needCount) {
    
    // Fourth pass: compute averages
    
    // intensityType is double when intensityValueType is double and float otherwise.
    typedef typename std::conditional<std::is_same<intensityValueType, double>::value, double,
                                      float>::type intensityType;

    valueType x, y, z;

    valueType xmin = pOverlapRange[0], xmax = pOverlapRange[1];
    valueType ymin = pOverlapRange[2], ymax = pOverlapRange[3];
    valueType zmin = pOverlapRange[4], zmax = pOverlapRange[5];

    // Double for location is more accurate
    double cx(0), cy(0), cz(0);
    float  cr(0), cg(0), cb(0);
    valueType nx(0), ny(0), nz(0);
    intensityType ix(0);
    double range(0), pitch(0), yaw(0);
    uint32_T index(0);
    
    // TODO araja: It is possible to break this up into 4 chunks for 4 parallel
    //             threads using binary search to find a partition point that
    //             splits at a voxel index transition.
    
    for (uint32_T n = 0; n < index_vector.size();) {
        // Calculate centroid
        uint32_T matrixIndex = index_vector[n].matrixIndex;
        cx = (double)pData[matrixIndex];
        cy = (double)pData[matrixIndex + numPoints];
        cz = (double)pData[matrixIndex + numPoints * 2];
        
        if (needColor) {
            cr = (float)pColor[matrixIndex];
            cg = (float)pColor[matrixIndex + numPoints];
            cb = (float)pColor[matrixIndex + numPoints * 2];
        }
        if (needNormal) {
            nx = pNormal[matrixIndex];
            ny = pNormal[matrixIndex + numPoints];
            nz = pNormal[matrixIndex + numPoints * 2];
        }
        if (needIntensity) {
            ix = static_cast<intensityType>(pIntensity[matrixIndex]);
        }

        uint32_T i = n + 1;
        while (i < index_vector.size() &&
               index_vector[i].voxelIndex == index_vector[n].voxelIndex) {
            matrixIndex = index_vector[i].matrixIndex;
            cx += pData[matrixIndex];
            cy += pData[matrixIndex + numPoints];
            cz += pData[matrixIndex + numPoints * 2];
            
            if (needColor) {
                cr += (float)pColor[matrixIndex];
                cg += (float)pColor[matrixIndex + numPoints];
                cb += (float)pColor[matrixIndex + numPoints * 2];
            }
            if (needNormal) {
                nx += pNormal[matrixIndex];
                ny += pNormal[matrixIndex + numPoints];
                nz += pNormal[matrixIndex + numPoints * 2];
            }
            if (needIntensity) {
                ix += static_cast<intensityType>(pIntensity[matrixIndex]);
            }

            i++;
        }

        cx /= (i - n);
        cy /= (i - n);
        cz /= (i - n);

        // Store averages
        pFilteredData[index] = static_cast<valueType>(cx);
        pFilteredData[index + total] = static_cast<valueType>(cy);
        pFilteredData[index + 2 * total] = static_cast<valueType>(cz);
        
        if (needColor) {
            cr /= (i - n);
            cg /= (i - n);
            cb /= (i - n);
            pFilteredColorData[index] = static_cast<unsigned char>(cr);
            pFilteredColorData[index + total] = static_cast<unsigned char>(cg);
            pFilteredColorData[index + 2 * total] = static_cast<unsigned char>(cb);
        }

        if (needNormal) {
            nx /= (i - n);
            ny /= (i - n);
            nz /= (i - n);
            pFilteredNormalData[index] = nx;
            pFilteredNormalData[index + total] = ny;
            pFilteredNormalData[index + 2 * total] = nz;
        }
        if (needIntensity) {
            ix /= (i - n);
            pFilteredIntensityData[index] = static_cast<intensityValueType>(ix);
        }
        if (needRangeData) {
            range = sqrt(cx * cx + cy * cy + cz * cz);
            pitch = asin(cz / range);
            yaw = atan2(cx, cy);
            if (yaw < 0) {
                yaw = yaw + 2 * M_PI;
            }
            pFilteredRangeData[index] = static_cast<valueType>(range);
            pFilteredRangeData[index + total] = static_cast<valueType>(pitch);
            pFilteredRangeData[index + 2 * total] = static_cast<valueType>(yaw);
        }

        n = i;
        index++;
    }
    
    // Compute covariance
    if (needCovariance || needCount) {
        index = 0;
        for (uint32_T n = 0; n < index_vector.size();) {
            double cov[9];
            for (uint32_T k = 0; k < 9; ++k) {
                cov[k] = 0;
            }
            // Get centroid
            cx = (double)pFilteredData[index];
            cy = (double)pFilteredData[index + total];
            cz = (double)pFilteredData[index + total * 2];

            uint32_T i = n + 1;
            while (i < index_vector.size() &&
                   index_vector[i].voxelIndex == index_vector[n].voxelIndex) {
                i++;
            }

            uint32_T numNeighbors = i - n;
            if (numNeighbors > 1) {
                for (uint32_T k = 0; k < numNeighbors; k++) {
                    uint32_T matrixIndex = index_vector[n + k].matrixIndex;
                    double xVal = pData[matrixIndex];
                    double yVal = pData[matrixIndex + numPoints];
                    double zVal = pData[matrixIndex + 2 * numPoints];
                    cov[0] += xVal * xVal;
                    cov[1] += xVal * yVal;
                    cov[2] += xVal * zVal;
                    cov[3] += xVal * yVal;
                    cov[4] += yVal * yVal;
                    cov[5] += yVal * zVal;
                    cov[6] += zVal * xVal;
                    cov[7] += zVal * yVal;
                    cov[8] += zVal * zVal;
                }

                double sx = cx * numNeighbors;
                double sy = cy * numNeighbors;
                double sz = cz * numNeighbors;

                cov[0] = cov[0] - 2 * sx * cx + numNeighbors * cx * cx;
                cov[1] = cov[1] - 2 * sx * cy + numNeighbors * cx * cy;
                cov[2] = cov[2] - 2 * sx * cz + numNeighbors * cx * cz;
                cov[3] = cov[3] - 2 * sy * cx + numNeighbors * cx * cy;
                cov[4] = cov[4] - 2 * sy * cy + numNeighbors * cy * cy;
                cov[5] = cov[5] - 2 * sy * cz + numNeighbors * cy * cz;
                cov[6] = cov[6] - 2 * sz * cx + numNeighbors * cz * cx;
                cov[7] = cov[7] - 2 * sz * cy + numNeighbors * cz * cy;
                cov[8] = cov[8] - 2 * sz * cz + numNeighbors * cz * cz;

                for (uint32_T k = 0; k < 9; ++k) {
                    cov[k] /= (numNeighbors - 1);
                }
            } else {
                for (uint32_T d = 0; d < 9; d++) {
                    cov[d] = std::numeric_limits<valueType>::quiet_NaN();
                }
            }

            pCovData[index * 9] = static_cast<valueType>(cov[0]);
            pCovData[index * 9 + 1] = static_cast<valueType>(cov[3]);
            pCovData[index * 9 + 2] = static_cast<valueType>(cov[6]);
            pCovData[index * 9 + 3] = static_cast<valueType>(cov[1]);
            pCovData[index * 9 + 4] = static_cast<valueType>(cov[4]);
            pCovData[index * 9 + 5] = static_cast<valueType>(cov[7]);
            pCovData[index * 9 + 6] = static_cast<valueType>(cov[2]);
            pCovData[index * 9 + 7] = static_cast<valueType>(cov[5]);
            pCovData[index * 9 + 8] = static_cast<valueType>(cov[8]);

            if (needCount)
                pCountData[index] = numNeighbors;
            
            n = i;
            index++;
        }
    }

    // Copy the untouched data outside the given range
    for (uint32_T n = 0; n < numPoints; n++) {
        x = pData[n];
        y = pData[n + numPoints];
        z = pData[n + numPoints * 2];

#ifndef __portable__
        if (!mfl_scalar::IsFinite(x) || !mfl_scalar::IsFinite(y) || !mfl_scalar::IsFinite(z)) {
#else
        if (!std::isfinite(x) || !std::isfinite(y) || !std::isfinite(z)) {
#endif
            continue;
        }

        if (x < xmin || x > xmax || y < ymin || y > ymax || z < zmin || z > zmax) {
            pFilteredData[index] = x;
            pFilteredData[index + total] = y;
            pFilteredData[index + 2 * total] = z;

            if (needColor) {
                pFilteredColorData[index] = pColor[n];
                pFilteredColorData[index + total] = pColor[n + numPoints];
                pFilteredColorData[index + 2 * total] = pColor[n + numPoints * 2];
            }

            if (needNormal) {
                pFilteredNormalData[index] = pNormal[n];
                pFilteredNormalData[index + total] = pNormal[n + numPoints];
                pFilteredNormalData[index + 2 * total] = pNormal[n + numPoints * 2];
            }

            if (needIntensity) {
                pFilteredIntensityData[index] = static_cast<intensityValueType>(pIntensity[n]);
            }

            if (needRangeData) {
                pFilteredRangeData[index] = pRangeData[n];
                pFilteredRangeData[index + total] = pRangeData[n + numPoints];
                pFilteredRangeData[index + 2 * total] = pRangeData[n + numPoints * 2];
            }

            if (needCovariance) {
                for (uint32_T d = 0; d < 9; d++) {
                    pCovData[index * 9 + d] = std::numeric_limits<valueType>::quiet_NaN();
                }
            }

            index++;
        }
    }
    return;
}
#endif
