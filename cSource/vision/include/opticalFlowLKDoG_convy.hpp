/*
*  Function for Optical Flow
*  (Lucas & Kanade method - Gaussian derivative).
*  Spacial Convolution
*
*  Copyright 1995-2007 The MathWorks, Inc.
*/
#ifndef OPTICALFLOWLKDOG_CONVY_H
#define OPTICALFLOWLKDOG_CONVY_H

template <typename T>
void MWCV_OFLK_ConvY_T(const T *in, 
                                   T *out, 
                                   const T *kernel, 
                                   int_T inRows, 
                                   int_T inCols, 
                                   int_T kernelLen)
{
    int_T i, j, k;
    int_T halfKernelLen = kernelLen>>1; /* kernelLen/2 */
    int_T offset = halfKernelLen;
    for (j = 0; j < inCols; j++)
    {
        int_T firstElem = j*inRows;
        for (i = 0; i < inRows; i++)
        {
            int_T outIdx = firstElem+i;
            out[outIdx] = 0;
            if inRange(i,j,halfKernelLen,inRows,inCols)
            {
                int_T inIdx = outIdx-offset;
                for (k = 0; k < kernelLen; k++)
                    out[outIdx] += in[inIdx+k]*kernel[k]; 
            }
        }
    }
}

#endif
/* [EOF] oflk_convy_d_rt.c */
