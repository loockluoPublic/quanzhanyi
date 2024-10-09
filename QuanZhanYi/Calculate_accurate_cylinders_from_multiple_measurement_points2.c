/*
 * File: Calculate_accurate_cylinders_from_multiple_measurement_points2.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 09-Oct-2024 11:13:17
 */

/* Include Files */
#include "Calculate_accurate_cylinders_from_multiple_measurement_points2.h"
#include "QuanZhanYi_data.h"
#include "QuanZhanYi_emxutil.h"
#include "QuanZhanYi_initialize.h"
#include "QuanZhanYi_rtwutil.h"
#include "QuanZhanYi_types.h"
#include "cat.h"
#include "combineVectorElements.h"
#include "fitcircle.h"
#include "ixfun.h"
#include "mldivide.h"
#include "mtimes.h"
#include "pinv.h"
#include "rt_nonfinite.h"
#include "unsafeSxfun.h"
#include "xzsvdc.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
/*
 * points = points';
 *
 * Arguments    : const emxArray_real_T *points
 *                const double P_bound1[3]
 *                const double P_bound2[3]
 *                double Mcenter[3]
 *                double MTaon[3]
 *                double *Mradial
 *                emxArray_real_T *Err_every
 *                double Bottom_round_center1[3]
 *                double Bottom_round_center2[3]
 * Return Type  : void
 */
void Calculate_accurate_cylinders_from_multiple_measurement_points2(
    const emxArray_real_T *points, const double P_bound1[3],
    const double P_bound2[3], double Mcenter[3], double MTaon[3],
    double *Mradial, emxArray_real_T *Err_every, double Bottom_round_center1[3],
    double Bottom_round_center2[3])
{
  static const double dv1[360] = {0.0,
                                  0.017501908933647871,
                                  0.035003817867295742,
                                  0.052505726800943613,
                                  0.070007635734591483,
                                  0.087509544668239347,
                                  0.10501145360188723,
                                  0.1225133625355351,
                                  0.14001527146918297,
                                  0.15751718040283083,
                                  0.17501908933647869,
                                  0.19252099827012659,
                                  0.21002290720377445,
                                  0.22752481613742231,
                                  0.24502672507107021,
                                  0.26252863400471804,
                                  0.28003054293836593,
                                  0.29753245187201383,
                                  0.31503436080566166,
                                  0.33253626973930955,
                                  0.35003817867295739,
                                  0.36754008760660528,
                                  0.38504199654025317,
                                  0.402543905473901,
                                  0.4200458144075489,
                                  0.43754772334119679,
                                  0.45504963227484463,
                                  0.47255154120849252,
                                  0.49005345014214041,
                                  0.5075553590757883,
                                  0.52505726800943608,
                                  0.542559176943084,
                                  0.56006108587673187,
                                  0.57756299481037976,
                                  0.59506490374402765,
                                  0.61256681267767543,
                                  0.63006872161132332,
                                  0.64757063054497122,
                                  0.66507253947861911,
                                  0.682574448412267,
                                  0.70007635734591478,
                                  0.71757826627956267,
                                  0.73508017521321056,
                                  0.75258208414685845,
                                  0.77008399308050635,
                                  0.78758590201415424,
                                  0.805087810947802,
                                  0.82258971988144991,
                                  0.8400916288150978,
                                  0.85759353774874569,
                                  0.87509544668239359,
                                  0.89259735561604137,
                                  0.91009926454968926,
                                  0.92760117348333715,
                                  0.945103082416985,
                                  0.96260499135063293,
                                  0.98010690028428082,
                                  0.9976088092179286,
                                  1.0151107181515766,
                                  1.0326126270852243,
                                  1.0501145360188722,
                                  1.06761644495252,
                                  1.085118353886168,
                                  1.1026202628198158,
                                  1.1201221717534637,
                                  1.1376240806871116,
                                  1.1551259896207595,
                                  1.1726278985544074,
                                  1.1901298074880553,
                                  1.2076317164217032,
                                  1.2251336253553509,
                                  1.2426355342889988,
                                  1.2601374432226466,
                                  1.2776393521562945,
                                  1.2951412610899424,
                                  1.3126431700235903,
                                  1.3301450789572382,
                                  1.3476469878908861,
                                  1.365148896824534,
                                  1.3826508057581819,
                                  1.4001527146918296,
                                  1.4176546236254775,
                                  1.4351565325591253,
                                  1.4526584414927732,
                                  1.4701603504264211,
                                  1.487662259360069,
                                  1.5051641682937169,
                                  1.5226660772273648,
                                  1.5401679861610127,
                                  1.5576698950946606,
                                  1.5751718040283085,
                                  1.5926737129619561,
                                  1.610175621895604,
                                  1.6276775308292519,
                                  1.6451794397628998,
                                  1.6626813486965477,
                                  1.6801832576301956,
                                  1.6976851665638435,
                                  1.7151870754974914,
                                  1.7326889844311393,
                                  1.7501908933647872,
                                  1.7676928022984351,
                                  1.7851947112320827,
                                  1.8026966201657306,
                                  1.8201985290993785,
                                  1.8377004380330264,
                                  1.8552023469666743,
                                  1.8727042559003222,
                                  1.89020616483397,
                                  1.907708073767618,
                                  1.9252099827012659,
                                  1.9427118916349138,
                                  1.9602138005685616,
                                  1.9777157095022093,
                                  1.9952176184358572,
                                  2.0127195273695051,
                                  2.0302214363031532,
                                  2.0477233452368009,
                                  2.0652252541704486,
                                  2.0827271631040967,
                                  2.1002290720377443,
                                  2.1177309809713925,
                                  2.13523288990504,
                                  2.1527347988386882,
                                  2.1702367077723359,
                                  2.187738616705984,
                                  2.2052405256396317,
                                  2.22274243457328,
                                  2.2402443435069275,
                                  2.2577462524405751,
                                  2.2752481613742233,
                                  2.2927500703078709,
                                  2.310251979241519,
                                  2.3277538881751667,
                                  2.3452557971088148,
                                  2.3627577060424625,
                                  2.3802596149761106,
                                  2.3977615239097583,
                                  2.4152634328434064,
                                  2.4327653417770541,
                                  2.4502672507107017,
                                  2.46776915964435,
                                  2.4852710685779975,
                                  2.5027729775116456,
                                  2.5202748864452933,
                                  2.5377767953789414,
                                  2.5552787043125891,
                                  2.5727806132462372,
                                  2.5902825221798849,
                                  2.607784431113533,
                                  2.6252863400471806,
                                  2.6427882489808283,
                                  2.6602901579144764,
                                  2.6777920668481241,
                                  2.6952939757817722,
                                  2.71279588471542,
                                  2.730297793649068,
                                  2.7477997025827157,
                                  2.7653016115163638,
                                  2.7828035204500114,
                                  2.8003054293836591,
                                  2.8178073383173072,
                                  2.8353092472509549,
                                  2.852811156184603,
                                  2.8703130651182507,
                                  2.8878149740518988,
                                  2.9053168829855465,
                                  2.9228187919191946,
                                  2.9403207008528423,
                                  2.9578226097864904,
                                  2.975324518720138,
                                  2.9928264276537857,
                                  3.0103283365874338,
                                  3.0278302455210815,
                                  3.0453321544547296,
                                  3.0628340633883773,
                                  3.0803359723220254,
                                  3.0978378812556731,
                                  3.1153397901893212,
                                  3.1328416991229688,
                                  3.150343608056617,
                                  3.1678455169902646,
                                  3.1853474259239123,
                                  3.2028493348575604,
                                  3.2203512437912081,
                                  3.2378531527248562,
                                  3.2553550616585039,
                                  3.272856970592152,
                                  3.2903588795257996,
                                  3.3078607884594478,
                                  3.3253626973930954,
                                  3.3428646063267435,
                                  3.3603665152603912,
                                  3.3778684241940389,
                                  3.395370333127687,
                                  3.4128722420613347,
                                  3.4303741509949828,
                                  3.4478760599286304,
                                  3.4653779688622786,
                                  3.4828798777959262,
                                  3.5003817867295743,
                                  3.517883695663222,
                                  3.53538560459687,
                                  3.5528875135305178,
                                  3.5703894224641655,
                                  3.5878913313978136,
                                  3.6053932403314612,
                                  3.6228951492651094,
                                  3.640397058198757,
                                  3.6578989671324051,
                                  3.6754008760660528,
                                  3.6929027849997009,
                                  3.7104046939333486,
                                  3.7279066028669967,
                                  3.7454085118006444,
                                  3.762910420734292,
                                  3.78041232966794,
                                  3.7979142386015878,
                                  3.8154161475352359,
                                  3.8329180564688836,
                                  3.8504199654025317,
                                  3.8679218743361794,
                                  3.8854237832698275,
                                  3.9029256922034752,
                                  3.9204276011371233,
                                  3.937929510070771,
                                  3.9554314190044186,
                                  3.9729333279380667,
                                  3.9904352368717144,
                                  4.0079371458053625,
                                  4.02543905473901,
                                  4.0429409636726579,
                                  4.0604428726063064,
                                  4.0779447815399541,
                                  4.0954466904736018,
                                  4.1129485994072494,
                                  4.1304505083408971,
                                  4.1479524172745457,
                                  4.1654543262081933,
                                  4.182956235141841,
                                  4.2004581440754887,
                                  4.2179600530091372,
                                  4.2354619619427849,
                                  4.2529638708764326,
                                  4.27046577981008,
                                  4.2879676887437288,
                                  4.3054695976773765,
                                  4.3229715066110241,
                                  4.3404734155446718,
                                  4.3579753244783195,
                                  4.375477233411968,
                                  4.3929791423456157,
                                  4.4104810512792634,
                                  4.427982960212911,
                                  4.44548486914656,
                                  4.4629867780802073,
                                  4.4804886870138549,
                                  4.4979905959475026,
                                  4.51549250488115,
                                  4.5329944138147988,
                                  4.5504963227484465,
                                  4.5679982316820942,
                                  4.5855001406157418,
                                  4.60300204954939,
                                  4.6205039584830381,
                                  4.6380058674166857,
                                  4.6555077763503334,
                                  4.6730096852839811,
                                  4.69051159421763,
                                  4.7080135031512773,
                                  4.725515412084925,
                                  4.7430173210185727,
                                  4.7605192299522212,
                                  4.7780211388858689,
                                  4.7955230478195165,
                                  4.8130249567531642,
                                  4.8305268656868128,
                                  4.8480287746204604,
                                  4.8655306835541081,
                                  4.8830325924877558,
                                  4.9005345014214035,
                                  4.918036410355052,
                                  4.9355383192887,
                                  4.9530402282223474,
                                  4.970542137155995,
                                  4.9880440460896436,
                                  5.0055459550232912,
                                  5.0230478639569389,
                                  5.0405497728905866,
                                  5.0580516818242343,
                                  5.0755535907578828,
                                  5.0930554996915305,
                                  5.1105574086251782,
                                  5.1280593175588258,
                                  5.1455612264924744,
                                  5.1630631354261221,
                                  5.18056504435977,
                                  5.1980669532934174,
                                  5.2155688622270659,
                                  5.2330707711607136,
                                  5.2505726800943613,
                                  5.268074589028009,
                                  5.2855764979616566,
                                  5.3030784068953052,
                                  5.3205803158289529,
                                  5.3380822247626005,
                                  5.3555841336962482,
                                  5.3730860426298968,
                                  5.3905879515635444,
                                  5.4080898604971921,
                                  5.42559176943084,
                                  5.4430936783644874,
                                  5.460595587298136,
                                  5.4780974962317837,
                                  5.4955994051654313,
                                  5.513101314099079,
                                  5.5306032230327276,
                                  5.5481051319663752,
                                  5.5656070409000229,
                                  5.5831089498336706,
                                  5.6006108587673182,
                                  5.6181127677009668,
                                  5.6356146766346145,
                                  5.6531165855682621,
                                  5.67061849450191,
                                  5.6881204034355584,
                                  5.705622312369206,
                                  5.7231242213028537,
                                  5.7406261302365014,
                                  5.75812803917015,
                                  5.7756299481037976,
                                  5.7931318570374453,
                                  5.8106337659710929,
                                  5.8281356749047406,
                                  5.8456375838383892,
                                  5.8631394927720368,
                                  5.8806414017056845,
                                  5.8981433106393322,
                                  5.9156452195729807,
                                  5.9331471285066284,
                                  5.9506490374402761,
                                  5.9681509463739237,
                                  5.9856528553075714,
                                  6.00315476424122,
                                  6.0206566731748676,
                                  6.0381585821085153,
                                  6.055660491042163,
                                  6.0731623999758115,
                                  6.0906643089094592,
                                  6.1081662178431069,
                                  6.1256681267767545,
                                  6.1431700357104031,
                                  6.1606719446440508,
                                  6.1781738535776984,
                                  6.1956757625113461,
                                  6.2131776714449938,
                                  6.2306795803786423,
                                  6.24818148931229,
                                  6.2656833982459377,
                                  6.2831853071795862};
  static const signed char b_V[16] = {1, 0, 0, 0, 0, 1, 0, 0,
                                      0, 0, 1, 0, 0, 0, 0, 1};
  emxArray_real_T *A;
  emxArray_real_T *OptAllErr;
  emxArray_real_T *P;
  emxArray_real_T *U;
  emxArray_real_T *b_A;
  emxArray_real_T *b_y;
  emxArray_real_T *denom;
  emxArray_real_T *err;
  emxArray_real_T *n;
  emxArray_real_T *x;
  emxArray_real_T *x2_contents;
  emxArray_real_T *x_contents;
  emxArray_real_T *y;
  double V[16];
  double dv[9];
  double dv2[9];
  double s_data[4];
  double b_n[3];
  double h[3];
  double Merr;
  double OptAngle_idx_0;
  double OptAngle_idx_1;
  double OptErr;
  double OptPara_idx_0;
  double OptPara_idx_1;
  double absx;
  double absxk;
  double c;
  double d;
  double d1;
  double norm_vec;
  double rcoselev;
  double s;
  double scale;
  double t;
  double theta_tmp;
  double *Err_every_data;
  double *OptAllErr_data;
  double *P_data;
  double *denom_data;
  double *err_data;
  double *x2_contents_data;
  double *x_contents_data;
  double *y_data;
  int outsize[2];
  int i;
  int j;
  int m_contents;
  int nIts;
  int npages;
  int nx;
  int xi;
  boolean_T exitg1;
  boolean_T p;
  if (!isInitialized_QuanZhanYi) {
    QuanZhanYi_initialize();
  }
  OptErr = 99999.0;
  OptAngle_idx_0 = 0.0;
  OptAngle_idx_1 = 0.0;
  OptPara_idx_0 = 0.0;
  OptPara_idx_1 = 0.0;
  *Mradial = 0.0;
  emxInit_real_T(&OptAllErr, 1);
  xi = OptAllErr->size[0];
  OptAllErr->size[0] = points->size[1];
  emxEnsureCapacity_real_T(OptAllErr, xi);
  OptAllErr_data = OptAllErr->data;
  nx = points->size[1];
  for (xi = 0; xi < nx; xi++) {
    OptAllErr_data[xi] = 0.0;
  }
  emxInit_real_T(&P, 2);
  emxInit_real_T(&err, 1);
  emxInit_real_T(&x_contents, 2);
  emxInit_real_T(&x2_contents, 1);
  emxInit_real_T(&U, 2);
  emxInit_real_T(&denom, 1);
  emxInit_real_T(&A, 2);
  emxInit_real_T(&y, 2);
  y_data = y->data;
  emxInit_real_T(&x, 2);
  emxInit_real_T(&n, 2);
  emxInit_real_T(&b_y, 1);
  emxInit_real_T(&b_A, 2);
  for (i = 0; i < 360; i++) {
    d = dv1[i];
    d1 = cos(d);
    d = sin(d);
    for (j = 0; j < 360; j++) {
      absx = dv1[j];
      rcoselev = cos(absx);
      absx = sin(absx);
      b_n[0] = rcoselev * d1;
      b_n[1] = rcoselev * d;
      h[0] = 0.0 * absx - b_n[1];
      h[1] = b_n[0] - 0.0 * absx;
      scale = 3.3121686421112381E-170;
      absxk = fabs(h[0]);
      if (absxk > 3.3121686421112381E-170) {
        theta_tmp = 1.0;
        scale = absxk;
      } else {
        t = absxk / 3.3121686421112381E-170;
        theta_tmp = t * t;
      }
      absxk = fabs(h[1]);
      if (absxk > scale) {
        t = scale / absxk;
        theta_tmp = theta_tmp * t * t + 1.0;
        scale = absxk;
      } else {
        t = absxk / scale;
        theta_tmp += t * t;
      }
      theta_tmp = scale * sqrt(theta_tmp);
      absx = rt_atan2d_snf(theta_tmp, absx);
      s = sin(absx);
      c = cos(absx);
      /* SL3DNORMALIZE Normalize a vector. */
      /*    Y = SL3DNORMALIZE(X,MAXZERO) returns a unit vector Y parallel to the
       */
      /*    input vector X. Input X can be vector of any size. If the modulus of
       */
      /*    the input vector is <= MAXZERO, the output is set to zeros(size(X)).
       */
      /*  */
      /*    Not to be called directly. */
      /*    Copyright 1998-2008 HUMUSOFT s.r.o. and The MathWorks, Inc. */
      scale = 3.3121686421112381E-170;
      Merr = h[0] / theta_tmp;
      rcoselev = Merr;
      absxk = fabs(Merr);
      if (absxk > 3.3121686421112381E-170) {
        norm_vec = 1.0;
        scale = absxk;
      } else {
        t = absxk / 3.3121686421112381E-170;
        norm_vec = t * t;
      }
      Merr = h[1] / theta_tmp;
      absx = Merr;
      absxk = fabs(Merr);
      if (absxk > scale) {
        t = scale / absxk;
        norm_vec = norm_vec * t * t + 1.0;
        scale = absxk;
      } else {
        t = absxk / scale;
        norm_vec += t * t;
      }
      Merr = (0.0 * b_n[1] - 0.0 * b_n[0]) / theta_tmp;
      t = Merr / scale;
      norm_vec += t * t;
      norm_vec = scale * sqrt(norm_vec);
      if (norm_vec <= 1.0E-12) {
        b_n[0] = 0.0;
        b_n[1] = 0.0;
        b_n[2] = 0.0;
      } else {
        b_n[0] = rcoselev / norm_vec;
        b_n[1] = absx / norm_vec;
        b_n[2] = Merr / norm_vec;
      }
      absx = (1.0 - c) * b_n[0];
      dv[0] = absx * b_n[0] + c;
      norm_vec = absx * b_n[1];
      Merr = s * b_n[2];
      dv[3] = norm_vec - Merr;
      absx *= b_n[2];
      rcoselev = s * b_n[1];
      dv[6] = absx + rcoselev;
      dv[1] = norm_vec + Merr;
      norm_vec = (1.0 - c) * b_n[1];
      dv[4] = norm_vec * b_n[1] + c;
      norm_vec *= b_n[2];
      Merr = s * b_n[0];
      dv[7] = norm_vec - Merr;
      dv[2] = absx - rcoselev;
      dv[5] = norm_vec + Merr;
      dv[8] = (1.0 - c) * b_n[2] * b_n[2] + c;
      mtimes(points, dv, P);
      P_data = P->data;
      xi = x_contents->size[0] * x_contents->size[1];
      x_contents->size[0] = 2;
      x_contents->size[1] = P->size[0];
      emxEnsureCapacity_real_T(x_contents, xi);
      x_contents_data = x_contents->data;
      nx = P->size[0];
      for (xi = 0; xi < nx; xi++) {
        x_contents_data[2 * xi] = P_data[xi];
        x_contents_data[2 * xi + 1] = P_data[xi + P->size[0]];
      }
      m_contents = x_contents->size[1];
      xi = err->size[0];
      err->size[0] = x_contents->size[1];
      emxEnsureCapacity_real_T(err, xi);
      err_data = err->data;
      nx = x_contents->size[1];
      xi = x2_contents->size[0];
      x2_contents->size[0] = x_contents->size[1];
      emxEnsureCapacity_real_T(x2_contents, xi);
      x2_contents_data = x2_contents->data;
      for (xi = 0; xi < nx; xi++) {
        err_data[xi] = x_contents_data[2 * xi];
        x2_contents_data[xi] = x_contents_data[2 * xi + 1];
      }
      /*  Form the coefficient matrix */
      /*  Least squares estimate is right singular vector corresp. to smallest
       */
      /*  singular value of B */
      if (err->size[0] == x2_contents->size[0]) {
        xi = A->size[0] * A->size[1];
        A->size[0] = err->size[0];
        A->size[1] = 4;
        emxEnsureCapacity_real_T(A, xi);
        Err_every_data = A->data;
        nx = err->size[0];
        for (xi = 0; xi < nx; xi++) {
          norm_vec = err_data[xi];
          absx = x2_contents_data[xi];
          Err_every_data[xi] = norm_vec * norm_vec + absx * absx;
          Err_every_data[xi + A->size[0]] = x_contents_data[2 * xi];
          Err_every_data[xi + A->size[0] * 2] = x_contents_data[2 * xi + 1];
          Err_every_data[xi + A->size[0] * 3] = 1.0;
        }
      } else {
        binary_expand_op_8(A, err, x2_contents, x_contents);
        Err_every_data = A->data;
      }
      nx = A->size[0] << 2;
      p = true;
      for (npages = 0; npages < nx; npages++) {
        if ((!p) || (rtIsInf(Err_every_data[npages]) ||
                     rtIsNaN(Err_every_data[npages]))) {
          p = false;
        }
      }
      if (p) {
        if (A->size[0] == 0) {
          for (xi = 0; xi < 16; xi++) {
            V[xi] = b_V[xi];
          }
        } else {
          xi = b_A->size[0] * b_A->size[1];
          b_A->size[0] = A->size[0];
          b_A->size[1] = 4;
          emxEnsureCapacity_real_T(b_A, xi);
          denom_data = b_A->data;
          nx = A->size[0] * A->size[1] - 1;
          for (xi = 0; xi <= nx; xi++) {
            denom_data[xi] = Err_every_data[xi];
          }
          xzsvdc(b_A, U, s_data, V);
        }
      } else {
        for (xi = 0; xi < 16; xi++) {
          V[xi] = rtNaN;
        }
      }
      /*  For clarity, set the quadratic form variables */
      /*  Convert to centre/radius */
      scale = 3.3121686421112381E-170;
      /*  2) Nonlinear refinement to miminise geometric error, and compute
       * residual */
      /*  [z, r, residual] = fitcircle_geometric(x, z, r); */
      /*  NESTED FUNCTIONS */
      /*      function [z, r, residual] = fitcircle_geometric(x, z0, r0) */
      /*  Use a simple Gauss Newton method to minimize the geometric error */
      /*  Set initial u */
      absx = 2.0 * V[12];
      absxk = fabs(V[13]);
      if (absxk > 3.3121686421112381E-170) {
        Merr = 1.0;
        scale = absxk;
      } else {
        t = absxk / 3.3121686421112381E-170;
        Merr = t * t;
      }
      b_n[0] = -V[13] / absx;
      absxk = fabs(V[14]);
      if (absxk > scale) {
        t = scale / absxk;
        Merr = Merr * t * t + 1.0;
        scale = absxk;
      } else {
        t = absxk / scale;
        Merr += t * t;
      }
      b_n[1] = -V[14] / absx;
      Merr = scale * sqrt(Merr);
      Merr /= 2.0 * V[12];
      b_n[2] = sqrt(Merr * Merr - V[15] / V[12]);
      /*  Delta is the norm of current step, scaled by the norm of u */
      nIts = 0;
      exitg1 = false;
      while ((!exitg1) && (nIts < 100)) {
        /*  Find the function and Jacobian  */
        /* SYS   Nonlinear system to be minimised - the objective */
        /* function is the distance to each point from the fitted circle */
        /* contained in u */
        /*  Objective function */
        xi = x->size[0] * x->size[1];
        x->size[0] = 2;
        x->size[1] = m_contents;
        emxEnsureCapacity_real_T(x, xi);
        Err_every_data = x->data;
        for (npages = 0; npages < m_contents; npages++) {
          nx = npages << 1;
          Err_every_data[nx] = b_n[0];
          Err_every_data[nx + 1] = b_n[1];
        }
        /*  Jacobian */
        if (err->size[0] == x2_contents->size[0]) {
          xi = denom->size[0];
          denom->size[0] = err->size[0];
          emxEnsureCapacity_real_T(denom, xi);
          denom_data = denom->data;
          nx = err->size[0];
          for (xi = 0; xi < nx; xi++) {
            norm_vec = b_n[0] - err_data[xi];
            absx = b_n[1] - x2_contents_data[xi];
            denom_data[xi] = norm_vec * norm_vec + absx * absx;
          }
        } else {
          binary_expand_op_7(denom, b_n, err, x2_contents);
          denom_data = denom->data;
        }
        nx = denom->size[0];
        for (npages = 0; npages < nx; npages++) {
          denom_data[npages] = sqrt(denom_data[npages]);
        }
        outsize[0] = m_contents;
        /*  Solve for the step and update u */
        if (x->size[1] == x_contents->size[1]) {
          nx = x->size[1] << 1;
          xi = x->size[0] * x->size[1];
          x->size[0] = 2;
          emxEnsureCapacity_real_T(x, xi);
          Err_every_data = x->data;
          for (xi = 0; xi < nx; xi++) {
            norm_vec = Err_every_data[xi] - x_contents_data[xi];
            Err_every_data[xi] = norm_vec * norm_vec;
          }
        } else {
          binary_expand_op_6(x, x_contents);
          Err_every_data = x->data;
        }
        if (x->size[1] == 0) {
          y->size[0] = 1;
          y->size[1] = 0;
        } else {
          npages = x->size[1];
          xi = y->size[0] * y->size[1];
          y->size[0] = 1;
          y->size[1] = x->size[1];
          emxEnsureCapacity_real_T(y, xi);
          y_data = y->data;
          for (xi = 0; xi < npages; xi++) {
            nx = xi << 1;
            y_data[xi] = Err_every_data[nx] + Err_every_data[nx + 1];
          }
        }
        nx = y->size[1];
        for (npages = 0; npages < nx; npages++) {
          y_data[npages] = sqrt(y_data[npages]);
        }
        if ((err->size[0] == denom->size[0]) &&
            (x2_contents->size[0] == denom->size[0])) {
          xi = n->size[0] * n->size[1];
          n->size[0] = err->size[0];
          n->size[1] = 3;
          emxEnsureCapacity_real_T(n, xi);
          Err_every_data = n->data;
          nx = err->size[0];
          for (xi = 0; xi < nx; xi++) {
            Err_every_data[xi] = -((b_n[0] - err_data[xi]) / denom_data[xi]);
          }
          nx = x2_contents->size[0];
          for (xi = 0; xi < nx; xi++) {
            Err_every_data[xi + n->size[0]] =
                -((b_n[1] - x2_contents_data[xi]) / denom_data[xi]);
          }
          for (xi = 0; xi < m_contents; xi++) {
            Err_every_data[xi + n->size[0] * 2] = 1.0;
          }
          xi = b_y->size[0];
          b_y->size[0] = y->size[1];
          emxEnsureCapacity_real_T(b_y, xi);
          Err_every_data = b_y->data;
          nx = y->size[1];
          for (xi = 0; xi < nx; xi++) {
            Err_every_data[xi] = y_data[xi] - b_n[2];
          }
          mldivide(n, b_y, h);
        } else {
          binary_expand_op_5(b_n, err, denom, x2_contents, outsize, y, h);
        }
        /*  Check for convergence */
        Merr = 0.0;
        absxk = 0.0;
        for (npages = 0; npages < 3; npages++) {
          absx = h[npages];
          norm_vec = b_n[npages] + absx;
          b_n[npages] = norm_vec;
          absx = fabs(absx);
          if (rtIsNaN(absx) || (absx > Merr)) {
            Merr = absx;
          }
          absx = fabs(norm_vec);
          if (rtIsNaN(absx) || (absx > absxk)) {
            absxk = absx;
          }
        }
        if (Merr / absxk < 1.0E-5) {
          exitg1 = true;
        } else {
          nIts++;
        }
      }
      /* SYS   Nonlinear system to be minimised - the objective */
      /* function is the distance to each point from the fitted circle */
      /* contained in u */
      /*  Objective function */
      /*  Jacobian */
      /*  sys */
      /*      end % fitcircle_geometric */
      /*  END NESTED FUNCTIONS */
      xi = denom->size[0];
      denom->size[0] = P->size[0];
      emxEnsureCapacity_real_T(denom, xi);
      denom_data = denom->data;
      nx = P->size[0];
      xi = b_y->size[0];
      b_y->size[0] = P->size[0];
      emxEnsureCapacity_real_T(b_y, xi);
      Err_every_data = b_y->data;
      for (xi = 0; xi < nx; xi++) {
        denom_data[xi] = P_data[xi] - b_n[0];
        Err_every_data[xi] = P_data[xi + P->size[0]] - b_n[1];
      }
      if (denom->size[0] == b_y->size[0]) {
        xi = err->size[0];
        err->size[0] = denom->size[0];
        emxEnsureCapacity_real_T(err, xi);
        err_data = err->data;
        nx = denom->size[0];
        for (xi = 0; xi < nx; xi++) {
          norm_vec = denom_data[xi];
          absx = Err_every_data[xi];
          err_data[xi] = rt_hypotd_snf(norm_vec, absx);
        }
      } else {
        expand_hypot(denom, b_y, err);
        err_data = err->data;
      }
      nx = err->size[0];
      for (xi = 0; xi < nx; xi++) {
        err_data[xi] -= b_n[2];
      }
      xi = b_y->size[0];
      b_y->size[0] = err->size[0];
      emxEnsureCapacity_real_T(b_y, xi);
      Err_every_data = b_y->data;
      nx = err->size[0];
      for (xi = 0; xi < nx; xi++) {
        norm_vec = err_data[xi];
        Err_every_data[xi] = norm_vec * norm_vec;
      }
      Merr = sqrt(combineVectorElements(b_y) / (double)b_y->size[0]);
      if (Merr < OptErr) {
        OptErr = Merr;
        OptPara_idx_0 = b_n[0];
        OptPara_idx_1 = b_n[1];
        *Mradial = b_n[2];
        xi = OptAllErr->size[0];
        OptAllErr->size[0] = err->size[0];
        emxEnsureCapacity_real_T(OptAllErr, xi);
        OptAllErr_data = OptAllErr->data;
        nx = err->size[0];
        for (xi = 0; xi < nx; xi++) {
          OptAllErr_data[xi] = err_data[xi];
        }
        OptAngle_idx_0 = dv1[i];
        OptAngle_idx_1 = dv1[j];
      }
    }
  }
  emxFree_real_T(&b_A);
  emxFree_real_T(&b_y);
  emxFree_real_T(&n);
  emxFree_real_T(&x);
  emxFree_real_T(&y);
  emxFree_real_T(&A);
  emxFree_real_T(&denom);
  emxFree_real_T(&U);
  emxFree_real_T(&x2_contents);
  emxFree_real_T(&x_contents);
  emxFree_real_T(&err);
  emxFree_real_T(&P);
  rcoselev = cos(OptAngle_idx_1);
  d = sin(OptAngle_idx_1);
  MTaon[0] = rcoselev * cos(OptAngle_idx_0);
  MTaon[1] = rcoselev * sin(OptAngle_idx_0);
  MTaon[2] = d;
  h[0] = 0.0 * d - MTaon[1];
  h[1] = MTaon[0] - 0.0 * d;
  scale = 3.3121686421112381E-170;
  absxk = fabs(h[0]);
  if (absxk > 3.3121686421112381E-170) {
    theta_tmp = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    theta_tmp = t * t;
  }
  absxk = fabs(h[1]);
  if (absxk > scale) {
    t = scale / absxk;
    theta_tmp = theta_tmp * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    theta_tmp += t * t;
  }
  theta_tmp = scale * sqrt(theta_tmp);
  d1 = rt_atan2d_snf(theta_tmp, d);
  s = sin(d1);
  c = cos(d1);
  /* SL3DNORMALIZE Normalize a vector. */
  /*    Y = SL3DNORMALIZE(X,MAXZERO) returns a unit vector Y parallel to the */
  /*    input vector X. Input X can be vector of any size. If the modulus of */
  /*    the input vector is <= MAXZERO, the output is set to zeros(size(X)). */
  /*  */
  /*    Not to be called directly. */
  /*    Copyright 1998-2008 HUMUSOFT s.r.o. and The MathWorks, Inc. */
  scale = 3.3121686421112381E-170;
  Merr = h[0] / theta_tmp;
  rcoselev = Merr;
  absxk = fabs(Merr);
  if (absxk > 3.3121686421112381E-170) {
    norm_vec = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    norm_vec = t * t;
  }
  Merr = h[1] / theta_tmp;
  absx = Merr;
  absxk = fabs(Merr);
  if (absxk > scale) {
    t = scale / absxk;
    norm_vec = norm_vec * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    norm_vec += t * t;
  }
  Merr = (0.0 * MTaon[1] - 0.0 * MTaon[0]) / theta_tmp;
  t = Merr / scale;
  norm_vec += t * t;
  norm_vec = scale * sqrt(norm_vec);
  if (norm_vec <= 1.0E-12) {
    b_n[0] = 0.0;
    b_n[1] = 0.0;
    b_n[2] = 0.0;
  } else {
    b_n[0] = rcoselev / norm_vec;
    b_n[1] = absx / norm_vec;
    b_n[2] = Merr / norm_vec;
  }
  d1 = (1.0 - c) * b_n[0];
  dv[0] = d1 * b_n[0] + c;
  absx = d1 * b_n[1];
  norm_vec = s * b_n[2];
  dv[3] = absx - norm_vec;
  d1 *= b_n[2];
  Merr = s * b_n[1];
  dv[6] = d1 + Merr;
  dv[1] = absx + norm_vec;
  absx = (1.0 - c) * b_n[1];
  dv[4] = absx * b_n[1] + c;
  absx *= b_n[2];
  norm_vec = s * b_n[0];
  dv[7] = absx - norm_vec;
  dv[2] = d1 - Merr;
  dv[5] = absx + norm_vec;
  dv[8] = (1.0 - c) * b_n[2] * b_n[2] + c;
  pinv(dv, dv2);
  for (xi = 0; xi < 3; xi++) {
    Mcenter[xi] =
        (OptPara_idx_0 * dv2[3 * xi] + OptPara_idx_1 * dv2[3 * xi + 1]) +
        0.0 * dv2[3 * xi + 2];
  }
  xi = Err_every->size[0] * Err_every->size[1];
  Err_every->size[0] = 1;
  Err_every->size[1] = OptAllErr->size[0];
  emxEnsureCapacity_real_T(Err_every, xi);
  Err_every_data = Err_every->data;
  nx = OptAllErr->size[0];
  for (xi = 0; xi < nx; xi++) {
    Err_every_data[xi] = OptAllErr_data[xi];
  }
  emxFree_real_T(&OptAllErr);
  /*  三个点定义 */
  /*  斜率计算 */
  norm_vec = (Mcenter[0] + MTaon[0]) - Mcenter[0];
  absxk = (Mcenter[1] + MTaon[1]) - Mcenter[1];
  rcoselev = (Mcenter[2] + d) - Mcenter[2];
  Merr = (norm_vec * norm_vec + absxk * absxk) + rcoselev * rcoselev;
  absx = -(((Mcenter[0] - P_bound1[0]) * norm_vec +
            (Mcenter[1] - P_bound1[1]) * absxk) +
           (Mcenter[2] - P_bound1[2]) * rcoselev) /
         Merr;
  /*  P1点在轴线上的投影坐标 */
  /*  三个点定义 */
  /*  斜率计算 */
  Merr = -(((Mcenter[0] - P_bound2[0]) * norm_vec +
            (Mcenter[1] - P_bound2[1]) * absxk) +
           (Mcenter[2] - P_bound2[2]) * rcoselev) /
         Merr;
  /*  P1点在轴线上的投影坐标 */
  Bottom_round_center1[0] = absx * norm_vec + Mcenter[0];
  Bottom_round_center1[1] = absx * absxk + Mcenter[1];
  Bottom_round_center1[2] = absx * rcoselev + Mcenter[2];
  Bottom_round_center2[0] = Merr * norm_vec + Mcenter[0];
  Bottom_round_center2[1] = Merr * absxk + Mcenter[1];
  Bottom_round_center2[2] = Merr * rcoselev + Mcenter[2];
  /*  ！  需求1  判断方向 ，改法向量方向 */
}

/*
 * File trailer for
 * Calculate_accurate_cylinders_from_multiple_measurement_points2.c
 *
 * [EOF]
 */
