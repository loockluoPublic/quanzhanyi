/*
 * handle.c
 *
 * Code generation for function 'handle'
 *
 */

/* Include files */
#include "handle.h"
#include "cylderfit_data.h"
#include "cylderfit_types.h"
#include "rt_nonfinite.h"
#include "cvstCG_kdtree.h"

/* Function Definitions */
void handle_matlabCodegenDestructor(const emlrtStack *sp, pointCloud *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    if (obj->HasLocationHandleAllocated) {
      kdtreeDeleteLocationDataPointer_double(obj->LocationHandle);
      obj->HasLocationHandleAllocated = false;
    }
    if (obj->HasKdtreeConstructed) {
      kdtreeDeleteObj_double(obj->Kdtree);
      obj->HasKdtreeConstructed = false;
    }
  }
}

/* End of code generation (handle.c) */
