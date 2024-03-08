/* Copyright 2021 The MathWorks, Inc. */

#ifndef _PCALIGNUTILSCORE_API_HPP
#define _PCALIGNUTILSCORE_API_HPP

#include "vision_defines.h"

/* Pcalign VoxelGrid Filter  */
EXTERN_C LIBMWCVSTRT_API
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
                            const uint32_T total);

EXTERN_C LIBMWCVSTRT_API
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
                            const uint32_T total);

EXTERN_C LIBMWCVSTRT_API
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
                                            const uint32_T total);
    
EXTERN_C LIBMWCVSTRT_API
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
                                            const uint32_T total);

#endif
