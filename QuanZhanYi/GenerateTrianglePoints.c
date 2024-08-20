/*
 * File: GenerateTrianglePoints.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 20-Aug-2024 21:47:45
 */

/* Include Files */
#include "GenerateTrianglePoints.h"
#include "QuanZhanYi_data.h"
#include "QuanZhanYi_initialize.h"
#include "QuanZhanYi_types.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
/*
 * Arguments    : const double PlaneParaIn[4]
 *                const double BoundPoint1[3]
 *                const double P0[3]
 *                const double Direction[3]
 *                double PointTri[6]
 * Return Type  : void
 */
void GenerateTrianglePoints(const double PlaneParaIn[4],
                            const double BoundPoint1[3], const double P0[3],
                            const double Direction[3], double PointTri[6])
{
  double absxk;
  double dir1_idx_0;
  double dir1_idx_1;
  double scale;
  double t;
  double t1;
  double v1_idx_0;
  double v1_idx_1;
  double v1_idx_1_tmp;
  double xfit_idx_0;
  double y;
  double yfit_idx_0;
  double zfit_idx_0;
  if (!isInitialized_QuanZhanYi) {
    QuanZhanYi_initialize();
  }
  t1 = -(((-((Direction[0] * BoundPoint1[0] + Direction[1] * BoundPoint1[1]) +
             Direction[2] * BoundPoint1[2]) +
           Direction[0] * P0[0]) +
          Direction[1] * P0[1]) +
         Direction[2] * P0[2]) /
       ((Direction[0] * Direction[0] + Direction[1] * Direction[1]) +
        Direction[2] * Direction[2]);
  xfit_idx_0 = P0[0] + Direction[0] * t1;
  yfit_idx_0 = P0[1] + Direction[1] * t1;
  zfit_idx_0 = P0[2] + Direction[2] * t1;
  if (PlaneParaIn[2] != 0.0) {
    t1 = -PlaneParaIn[3] / PlaneParaIn[2] - zfit_idx_0;
    v1_idx_0 = Direction[1] * t1 - (0.0 - yfit_idx_0) * Direction[2];
    v1_idx_1_tmp = (0.0 - xfit_idx_0) * Direction[2];
    v1_idx_1 = v1_idx_1_tmp - Direction[0] * t1;
    t1 = (0.0 - xfit_idx_0) * Direction[1];
    dir1_idx_1 = Direction[0] * (0.0 - yfit_idx_0) - t1;
    scale = 3.3121686421112381E-170;
    absxk = fabs(v1_idx_0);
    if (absxk > 3.3121686421112381E-170) {
      y = 1.0;
      scale = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      y = t * t;
    }
    absxk = fabs(v1_idx_1);
    if (absxk > scale) {
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
    absxk = fabs(dir1_idx_1);
    if (absxk > scale) {
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
    y = scale * sqrt(y);
    if (y < 2.2204460492503131E-16) {
      /*  如果法向量与 [0, 0, 1] 平行，则选择另一个向量 */
      dir1_idx_1 = -PlaneParaIn[3] / PlaneParaIn[1] - yfit_idx_0;
      v1_idx_0 = Direction[1] * (0.0 - zfit_idx_0) - dir1_idx_1 * Direction[2];
      v1_idx_1 = v1_idx_1_tmp - Direction[0] * (0.0 - zfit_idx_0);
      dir1_idx_1 = Direction[0] * dir1_idx_1 - t1;
    }
  } else {
    dir1_idx_1 = -PlaneParaIn[3] / PlaneParaIn[1] - yfit_idx_0;
    t1 = Direction[1] * (0.0 - zfit_idx_0);
    v1_idx_0 = t1 - dir1_idx_1 * Direction[2];
    v1_idx_1_tmp = Direction[0] * (0.0 - zfit_idx_0);
    v1_idx_1 = (0.0 - xfit_idx_0) * Direction[2] - v1_idx_1_tmp;
    dir1_idx_1 = Direction[0] * dir1_idx_1 - (0.0 - xfit_idx_0) * Direction[1];
    scale = 3.3121686421112381E-170;
    absxk = fabs(v1_idx_0);
    if (absxk > 3.3121686421112381E-170) {
      y = 1.0;
      scale = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      y = t * t;
    }
    absxk = fabs(v1_idx_1);
    if (absxk > scale) {
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
    absxk = fabs(dir1_idx_1);
    if (absxk > scale) {
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
    y = scale * sqrt(y);
    if (y < 2.2204460492503131E-16) {
      /*  如果法向量与 [0, 0, 1] 平行，则选择另一个向量 */
      dir1_idx_0 = -PlaneParaIn[3] / PlaneParaIn[0] - xfit_idx_0;
      v1_idx_0 = t1 - (0.0 - yfit_idx_0) * Direction[2];
      v1_idx_1 = dir1_idx_0 * Direction[2] - v1_idx_1_tmp;
      dir1_idx_1 =
          Direction[0] * (0.0 - yfit_idx_0) - dir1_idx_0 * Direction[1];
    }
  }
  dir1_idx_0 = Direction[1] * dir1_idx_1 - v1_idx_1 * Direction[2];
  dir1_idx_1 = v1_idx_0 * Direction[2] - Direction[0] * dir1_idx_1;
  t1 = Direction[0] * v1_idx_1 - v1_idx_0 * Direction[1];
  scale = 3.3121686421112381E-170;
  absxk = fabs(dir1_idx_0);
  if (absxk > 3.3121686421112381E-170) {
    y = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    y = t * t;
  }
  absxk = fabs(dir1_idx_1);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }
  absxk = fabs(t1);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }
  y = scale * sqrt(y);
  dir1_idx_0 /= y;
  dir1_idx_1 /= y;
  t1 /= y;
  PointTri[0] = xfit_idx_0;
  PointTri[1] = yfit_idx_0;
  PointTri[2] = zfit_idx_0;
  PointTri[3] = xfit_idx_0 - 2.0 * dir1_idx_0;
  PointTri[4] = yfit_idx_0 - 2.0 * dir1_idx_1;
  PointTri[5] = zfit_idx_0 - 2.0 * t1;
}

/*
 * Arguments    : const emxArray_real_T *PlaneParaIn
 *                const double BoundPoint1[3]
 *                const double P0[3]
 *                const double Direction[3]
 *                double PointTri[6]
 * Return Type  : void
 */
void b_GenerateTrianglePoints(const emxArray_real_T *PlaneParaIn,
                              const double BoundPoint1[3], const double P0[3],
                              const double Direction[3], double PointTri[6])
{
  const double *PlaneParaIn_data;
  double absxk;
  double dir1_idx_0;
  double dir1_idx_1;
  double scale;
  double t;
  double t1;
  double v1_idx_0;
  double v1_idx_1;
  double v1_idx_1_tmp;
  double xfit_idx_0;
  double y;
  double yfit_idx_0;
  double zfit_idx_0;
  PlaneParaIn_data = PlaneParaIn->data;
  t1 = -(((-((Direction[0] * BoundPoint1[0] + Direction[1] * BoundPoint1[1]) +
             Direction[2] * BoundPoint1[2]) +
           Direction[0] * P0[0]) +
          Direction[1] * P0[1]) +
         Direction[2] * P0[2]) /
       ((Direction[0] * Direction[0] + Direction[1] * Direction[1]) +
        Direction[2] * Direction[2]);
  xfit_idx_0 = P0[0] + Direction[0] * t1;
  yfit_idx_0 = P0[1] + Direction[1] * t1;
  zfit_idx_0 = P0[2] + Direction[2] * t1;
  if (PlaneParaIn_data[2] != 0.0) {
    t1 = -PlaneParaIn_data[3] / PlaneParaIn_data[2] - zfit_idx_0;
    v1_idx_0 = Direction[1] * t1 - (0.0 - yfit_idx_0) * Direction[2];
    v1_idx_1_tmp = (0.0 - xfit_idx_0) * Direction[2];
    v1_idx_1 = v1_idx_1_tmp - Direction[0] * t1;
    t1 = (0.0 - xfit_idx_0) * Direction[1];
    dir1_idx_1 = Direction[0] * (0.0 - yfit_idx_0) - t1;
    scale = 3.3121686421112381E-170;
    absxk = fabs(v1_idx_0);
    if (absxk > 3.3121686421112381E-170) {
      y = 1.0;
      scale = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      y = t * t;
    }
    absxk = fabs(v1_idx_1);
    if (absxk > scale) {
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
    absxk = fabs(dir1_idx_1);
    if (absxk > scale) {
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
    y = scale * sqrt(y);
    if (y < 2.2204460492503131E-16) {
      /*  如果法向量与 [0, 0, 1] 平行，则选择另一个向量 */
      dir1_idx_1 = -PlaneParaIn_data[3] / PlaneParaIn_data[1] - yfit_idx_0;
      v1_idx_0 = Direction[1] * (0.0 - zfit_idx_0) - dir1_idx_1 * Direction[2];
      v1_idx_1 = v1_idx_1_tmp - Direction[0] * (0.0 - zfit_idx_0);
      dir1_idx_1 = Direction[0] * dir1_idx_1 - t1;
    }
  } else {
    dir1_idx_1 = -PlaneParaIn_data[3] / PlaneParaIn_data[1] - yfit_idx_0;
    t1 = Direction[1] * (0.0 - zfit_idx_0);
    v1_idx_0 = t1 - dir1_idx_1 * Direction[2];
    v1_idx_1_tmp = Direction[0] * (0.0 - zfit_idx_0);
    v1_idx_1 = (0.0 - xfit_idx_0) * Direction[2] - v1_idx_1_tmp;
    dir1_idx_1 = Direction[0] * dir1_idx_1 - (0.0 - xfit_idx_0) * Direction[1];
    scale = 3.3121686421112381E-170;
    absxk = fabs(v1_idx_0);
    if (absxk > 3.3121686421112381E-170) {
      y = 1.0;
      scale = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      y = t * t;
    }
    absxk = fabs(v1_idx_1);
    if (absxk > scale) {
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
    absxk = fabs(dir1_idx_1);
    if (absxk > scale) {
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
    y = scale * sqrt(y);
    if (y < 2.2204460492503131E-16) {
      /*  如果法向量与 [0, 0, 1] 平行，则选择另一个向量 */
      dir1_idx_0 = -PlaneParaIn_data[3] / PlaneParaIn_data[0] - xfit_idx_0;
      v1_idx_0 = t1 - (0.0 - yfit_idx_0) * Direction[2];
      v1_idx_1 = dir1_idx_0 * Direction[2] - v1_idx_1_tmp;
      dir1_idx_1 =
          Direction[0] * (0.0 - yfit_idx_0) - dir1_idx_0 * Direction[1];
    }
  }
  dir1_idx_0 = Direction[1] * dir1_idx_1 - v1_idx_1 * Direction[2];
  dir1_idx_1 = v1_idx_0 * Direction[2] - Direction[0] * dir1_idx_1;
  t1 = Direction[0] * v1_idx_1 - v1_idx_0 * Direction[1];
  scale = 3.3121686421112381E-170;
  absxk = fabs(dir1_idx_0);
  if (absxk > 3.3121686421112381E-170) {
    y = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    y = t * t;
  }
  absxk = fabs(dir1_idx_1);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }
  absxk = fabs(t1);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }
  y = scale * sqrt(y);
  dir1_idx_0 /= y;
  dir1_idx_1 /= y;
  t1 /= y;
  PointTri[0] = xfit_idx_0;
  PointTri[1] = yfit_idx_0;
  PointTri[2] = zfit_idx_0;
  PointTri[3] = xfit_idx_0 - 2.0 * dir1_idx_0;
  PointTri[4] = yfit_idx_0 - 2.0 * dir1_idx_1;
  PointTri[5] = zfit_idx_0 - 2.0 * t1;
}

/*
 * Arguments    : const double PlaneParaIn[4]
 *                const double BoundPoint1[3]
 *                const double P0[3]
 *                const double Direction[3]
 *                double PointTri[6]
 * Return Type  : void
 */
void c_GenerateTrianglePoints(const double PlaneParaIn[4],
                              const double BoundPoint1[3], const double P0[3],
                              const double Direction[3], double PointTri[6])
{
  double absxk;
  double dir1_idx_0;
  double dir1_idx_1;
  double scale;
  double t;
  double t1;
  double v1_idx_0;
  double v1_idx_1;
  double v1_idx_1_tmp;
  double xfit_idx_0;
  double y;
  double yfit_idx_0;
  double zfit_idx_0;
  t1 = -(((-((Direction[0] * BoundPoint1[0] + Direction[1] * BoundPoint1[1]) +
             Direction[2] * BoundPoint1[2]) +
           Direction[0] * P0[0]) +
          Direction[1] * P0[1]) +
         Direction[2] * P0[2]) /
       ((Direction[0] * Direction[0] + Direction[1] * Direction[1]) +
        Direction[2] * Direction[2]);
  xfit_idx_0 = P0[0] + Direction[0] * t1;
  yfit_idx_0 = P0[1] + Direction[1] * t1;
  zfit_idx_0 = P0[2] + Direction[2] * t1;
  if (PlaneParaIn[2] != 0.0) {
    t1 = PlaneParaIn[3] - zfit_idx_0;
    v1_idx_0 = Direction[1] * t1 - (0.0 - yfit_idx_0) * Direction[2];
    v1_idx_1_tmp = (0.0 - xfit_idx_0) * Direction[2];
    v1_idx_1 = v1_idx_1_tmp - Direction[0] * t1;
    t1 = (0.0 - xfit_idx_0) * Direction[1];
    dir1_idx_1 = Direction[0] * (0.0 - yfit_idx_0) - t1;
    scale = 3.3121686421112381E-170;
    absxk = fabs(v1_idx_0);
    if (absxk > 3.3121686421112381E-170) {
      y = 1.0;
      scale = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      y = t * t;
    }
    absxk = fabs(v1_idx_1);
    if (absxk > scale) {
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
    absxk = fabs(dir1_idx_1);
    if (absxk > scale) {
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
    y = scale * sqrt(y);
    if (y < 2.2204460492503131E-16) {
      /*  如果法向量与 [0, 0, 1] 平行，则选择另一个向量 */
      dir1_idx_1 = -PlaneParaIn[3] / PlaneParaIn[1] - yfit_idx_0;
      v1_idx_0 = Direction[1] * (0.0 - zfit_idx_0) - dir1_idx_1 * Direction[2];
      v1_idx_1 = v1_idx_1_tmp - Direction[0] * (0.0 - zfit_idx_0);
      dir1_idx_1 = Direction[0] * dir1_idx_1 - t1;
    }
  } else {
    dir1_idx_1 = -PlaneParaIn[3] / PlaneParaIn[1] - yfit_idx_0;
    t1 = Direction[1] * (0.0 - zfit_idx_0);
    v1_idx_0 = t1 - dir1_idx_1 * Direction[2];
    v1_idx_1_tmp = Direction[0] * (0.0 - zfit_idx_0);
    v1_idx_1 = (0.0 - xfit_idx_0) * Direction[2] - v1_idx_1_tmp;
    dir1_idx_1 = Direction[0] * dir1_idx_1 - (0.0 - xfit_idx_0) * Direction[1];
    scale = 3.3121686421112381E-170;
    absxk = fabs(v1_idx_0);
    if (absxk > 3.3121686421112381E-170) {
      y = 1.0;
      scale = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      y = t * t;
    }
    absxk = fabs(v1_idx_1);
    if (absxk > scale) {
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
    absxk = fabs(dir1_idx_1);
    if (absxk > scale) {
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
    y = scale * sqrt(y);
    if (y < 2.2204460492503131E-16) {
      /*  如果法向量与 [0, 0, 1] 平行，则选择另一个向量 */
      dir1_idx_0 = -PlaneParaIn[3] / PlaneParaIn[0] - xfit_idx_0;
      v1_idx_0 = t1 - (0.0 - yfit_idx_0) * Direction[2];
      v1_idx_1 = dir1_idx_0 * Direction[2] - v1_idx_1_tmp;
      dir1_idx_1 =
          Direction[0] * (0.0 - yfit_idx_0) - dir1_idx_0 * Direction[1];
    }
  }
  dir1_idx_0 = Direction[1] * dir1_idx_1 - v1_idx_1 * Direction[2];
  dir1_idx_1 = v1_idx_0 * Direction[2] - Direction[0] * dir1_idx_1;
  t1 = Direction[0] * v1_idx_1 - v1_idx_0 * Direction[1];
  scale = 3.3121686421112381E-170;
  absxk = fabs(dir1_idx_0);
  if (absxk > 3.3121686421112381E-170) {
    y = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    y = t * t;
  }
  absxk = fabs(dir1_idx_1);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }
  absxk = fabs(t1);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }
  y = scale * sqrt(y);
  dir1_idx_0 /= y;
  dir1_idx_1 /= y;
  t1 /= y;
  PointTri[0] = xfit_idx_0;
  PointTri[1] = yfit_idx_0;
  PointTri[2] = zfit_idx_0;
  PointTri[3] = xfit_idx_0 - 2.0 * dir1_idx_0;
  PointTri[4] = yfit_idx_0 - 2.0 * dir1_idx_1;
  PointTri[5] = zfit_idx_0 - 2.0 * t1;
}

/*
 * Arguments    : const double PlaneParaIn[4]
 *                const double BoundPoint1[3]
 *                const double P0[3]
 *                const double Direction[3]
 *                double PointTri[6]
 * Return Type  : void
 */
void d_GenerateTrianglePoints(const double PlaneParaIn[4],
                              const double BoundPoint1[3], const double P0[3],
                              const double Direction[3], double PointTri[6])
{
  double absxk;
  double dir1_idx_0;
  double dir1_idx_1;
  double scale;
  double t;
  double t1;
  double v1_idx_0;
  double v1_idx_1;
  double v1_idx_1_tmp;
  double xfit_idx_0;
  double y;
  double yfit_idx_0;
  double zfit_idx_0;
  t1 = -(((-((Direction[0] * BoundPoint1[0] + Direction[1] * BoundPoint1[1]) +
             Direction[2] * BoundPoint1[2]) +
           Direction[0] * P0[0]) +
          Direction[1] * P0[1]) +
         Direction[2] * P0[2]) /
       ((Direction[0] * Direction[0] + Direction[1] * Direction[1]) +
        Direction[2] * Direction[2]);
  xfit_idx_0 = P0[0] + Direction[0] * t1;
  yfit_idx_0 = P0[1] + Direction[1] * t1;
  zfit_idx_0 = P0[2] + Direction[2] * t1;
  if (PlaneParaIn[2] != 0.0) {
    t1 = -PlaneParaIn[3] / PlaneParaIn[2] - zfit_idx_0;
    v1_idx_0 = Direction[1] * t1 - (0.0 - yfit_idx_0) * Direction[2];
    v1_idx_1_tmp = (0.0 - xfit_idx_0) * Direction[2];
    v1_idx_1 = v1_idx_1_tmp - Direction[0] * t1;
    t1 = (0.0 - xfit_idx_0) * Direction[1];
    dir1_idx_1 = Direction[0] * (0.0 - yfit_idx_0) - t1;
    scale = 3.3121686421112381E-170;
    absxk = fabs(v1_idx_0);
    if (absxk > 3.3121686421112381E-170) {
      y = 1.0;
      scale = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      y = t * t;
    }
    absxk = fabs(v1_idx_1);
    if (absxk > scale) {
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
    absxk = fabs(dir1_idx_1);
    if (absxk > scale) {
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
    y = scale * sqrt(y);
    if (y < 2.2204460492503131E-16) {
      /*  如果法向量与 [0, 0, 1] 平行，则选择另一个向量 */
      dir1_idx_1 = -PlaneParaIn[3] / PlaneParaIn[1] - yfit_idx_0;
      v1_idx_0 = Direction[1] * (0.0 - zfit_idx_0) - dir1_idx_1 * Direction[2];
      v1_idx_1 = v1_idx_1_tmp - Direction[0] * (0.0 - zfit_idx_0);
      dir1_idx_1 = Direction[0] * dir1_idx_1 - t1;
    }
  } else {
    dir1_idx_1 = -PlaneParaIn[3] / PlaneParaIn[1] - yfit_idx_0;
    t1 = Direction[1] * (0.0 - zfit_idx_0);
    v1_idx_0 = t1 - dir1_idx_1 * Direction[2];
    v1_idx_1_tmp = Direction[0] * (0.0 - zfit_idx_0);
    v1_idx_1 = (0.0 - xfit_idx_0) * Direction[2] - v1_idx_1_tmp;
    dir1_idx_1 = Direction[0] * dir1_idx_1 - (0.0 - xfit_idx_0) * Direction[1];
    scale = 3.3121686421112381E-170;
    absxk = fabs(v1_idx_0);
    if (absxk > 3.3121686421112381E-170) {
      y = 1.0;
      scale = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      y = t * t;
    }
    absxk = fabs(v1_idx_1);
    if (absxk > scale) {
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
    absxk = fabs(dir1_idx_1);
    if (absxk > scale) {
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
    y = scale * sqrt(y);
    if (y < 2.2204460492503131E-16) {
      /*  如果法向量与 [0, 0, 1] 平行，则选择另一个向量 */
      dir1_idx_0 = -PlaneParaIn[3] / PlaneParaIn[0] - xfit_idx_0;
      v1_idx_0 = t1 - (0.0 - yfit_idx_0) * Direction[2];
      v1_idx_1 = dir1_idx_0 * Direction[2] - v1_idx_1_tmp;
      dir1_idx_1 =
          Direction[0] * (0.0 - yfit_idx_0) - dir1_idx_0 * Direction[1];
    }
  }
  dir1_idx_0 = Direction[1] * dir1_idx_1 - v1_idx_1 * Direction[2];
  dir1_idx_1 = v1_idx_0 * Direction[2] - Direction[0] * dir1_idx_1;
  t1 = Direction[0] * v1_idx_1 - v1_idx_0 * Direction[1];
  scale = 3.3121686421112381E-170;
  absxk = fabs(dir1_idx_0);
  if (absxk > 3.3121686421112381E-170) {
    y = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    y = t * t;
  }
  absxk = fabs(dir1_idx_1);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }
  absxk = fabs(t1);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }
  y = scale * sqrt(y);
  dir1_idx_0 /= y;
  dir1_idx_1 /= y;
  t1 /= y;
  PointTri[0] = xfit_idx_0;
  PointTri[1] = yfit_idx_0;
  PointTri[2] = zfit_idx_0;
  PointTri[3] = xfit_idx_0 - 2.0 * dir1_idx_0;
  PointTri[4] = yfit_idx_0 - 2.0 * dir1_idx_1;
  PointTri[5] = zfit_idx_0 - 2.0 * t1;
}

/*
 * File trailer for GenerateTrianglePoints.c
 *
 * [EOF]
 */
