//////////////////////////////////////////////////////////////////////////////
//
// APIs for interfaces for pcalignUtils that are used in codegeneration
// Copyright 2021 The MathWorks, Inc.
//
//////////////////////////////////////////////////////////////////////////////
// vision_builtins does not need this source file

#ifndef COMPILE_FOR_VISION_BUILTINS

#include "pcalignUtilsCore_api.hpp"
#include "pcalignUtils.hpp"

///////////////////////////////////////////////////////////////////////////
//           voxelGridFilter Wrapper for single dataType
///////////////////////////////////////////////////////////////////////////
void voxelGridAlgImpl_single(const float* pData,
        const unsigned char* pColor,
        const float* pNormal,
        const float* pIntensity,
        float* pFilteredData,
        unsigned char* pFilteredColorData,
        float* pFilteredNormalData,
        float* pFilteredIntensityData,
        const uint64_T* indexVector,
        const uint32_T numClouds,
        const boolean_T needColor,
        const boolean_T needNormal,
        const boolean_T needIntensity,
        const uint32_T indexVecSize,
        const uint32_T* sizeArray,
        const uint32_T total){
    
    voxelGridAlgImpl<float, float>(pData, pColor, pNormal, pIntensity, pFilteredData,
            pFilteredColorData, pFilteredNormalData, pFilteredIntensityData,
            indexVector, numClouds, needColor, needNormal, needIntensity,
            indexVecSize, sizeArray, total);
}
///////////////////////////////////////////////////////////////////////////
//           voxelGridFilter Wrapper for double dataType
///////////////////////////////////////////////////////////////////////////
void voxelGridAlgImpl_double(const double* pData,
        const unsigned char* pColor,
        const double* pNormal,
        const double* pIntensity,
        double* pFilteredData,
        unsigned char* pFilteredColorData,
        double* pFilteredNormalData,
        double* pFilteredIntensityData,
        const uint64_T* indexVector,
        const uint32_T numClouds,
        const boolean_T needColor,
        const boolean_T needNormal,
        const boolean_T needIntensity,
        const uint32_T indexVecSize,
        const uint32_T* sizeArray,
        const uint32_T total){
    
    voxelGridAlgImpl<double, double>(pData, pColor, pNormal, pIntensity, pFilteredData,
            pFilteredColorData, pFilteredNormalData, pFilteredIntensityData,
            indexVector, numClouds, needColor, needNormal, needIntensity,
            indexVecSize, sizeArray, total);
}
///////////////////////////////////////////////////////////////////////////
//    voxelGridFilter Wrapper for single dataType and uint8 Intensity
///////////////////////////////////////////////////////////////////////////
void voxelGridAlgImpl_single_uint8Intensity(const float* pData,
        const unsigned char* pColor,
        const float* pNormal,
        const unsigned char* pIntensity,
        float* pFilteredData,
        unsigned char* pFilteredColorData,
        float* pFilteredNormalData,
        unsigned char* pFilteredIntensityData,
        const uint64_T* indexVector,
        const uint32_T numClouds,
        const boolean_T needColor,
        const boolean_T needNormal,
        const boolean_T needIntensity,
        const uint32_T indexVecSize,
        const uint32_T* sizeArray,
        const uint32_T total){
    
    voxelGridAlgImpl<float, unsigned char>(pData, pColor, pNormal, pIntensity,
            pFilteredData, pFilteredColorData, pFilteredNormalData,
            pFilteredIntensityData, indexVector, numClouds, needColor, needNormal,
            needIntensity, indexVecSize, sizeArray, total);
}
///////////////////////////////////////////////////////////////////////////
//    voxelGridFilter Wrapper for double dataType and uint8 Intensity
///////////////////////////////////////////////////////////////////////////
void voxelGridAlgImpl_double_uint8Intensity(const double* pData,
        const unsigned char* pColor,
        const double* pNormal,
        const unsigned char* pIntensity,
        double* pFilteredData,
        unsigned char* pFilteredColorData,
        double* pFilteredNormalData,
        unsigned char* pFilteredIntensityData,
        const uint64_T* indexVector,
        const uint32_T numClouds,
        const boolean_T needColor,
        const boolean_T needNormal,
        const boolean_T needIntensity,
        const uint32_T indexVecSize,
        const uint32_T* sizeArray,
        const uint32_T total){
    
    voxelGridAlgImpl<double, unsigned char>(pData, pColor, pNormal, pIntensity,
            pFilteredData, pFilteredColorData, pFilteredNormalData,
            pFilteredIntensityData, indexVector, numClouds, needColor, needNormal,
            needIntensity, indexVecSize, sizeArray, total);
}
#endif

