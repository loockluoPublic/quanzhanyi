/*
 * File: _coder_QuanZhanYi_info.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 07-Aug-2024 19:00:37
 */

/* Include Files */
#include "_coder_QuanZhanYi_info.h"
#include "emlrt.h"
#include "tmwtypes.h"

/* Function Declarations */
static const mxArray *c_emlrtMexFcnResolvedFunctionsI(void);

/* Function Definitions */
/*
 * Arguments    : void
 * Return Type  : const mxArray *
 */
static const mxArray *c_emlrtMexFcnResolvedFunctionsI(void)
{
  const mxArray *nameCaptureInfo;
  const char_T *data[10] = {
      "789ced9b4d72db3614c7a94ed269a793549bf60ad97432b21467922eda8914f95b963492"
      "1b5b550741485042429034084a560ed0c9ae5d76e92364d923e40cb9"
      "40ae5189102d91152c32f4c891e6bd0d093f02ff8707e337f023ade5f66b394dd3ee6bd2"
      "f6f6e4f5deb49d9f5ebfd2a216f7e7623fcf451fd7ee6a7716faff9a",
      "5e75c716e442c8868d19b9ea69388cdad816ed914b344e3cc71a1023f098d4226dca486b"
      "be713c69b19d39d75563e29adc57fa447fd3f299c6fbde2c426bbe71"
      "958f4bc57cef24ccc7af8a7ce463fedfab7f547eee9e78847bddd317edee73e2bd118edb"
      "7debd8bd66e7ac2b88274add0ab674dfc2023d43d8365019351c6a0b",
      "ef21bb8af7ef8cf1feb424ded06f3a8e408e895cc25d621b74121647267718c2c89d4485"
      "8433beb5a81d2c6518dfcb8cf17dad8c4f7a0cc77f659199debf19f5"
      "da4abda83fd9faa5c9da7851b5e579fb3ee13ce2d7d9f3dfc8e73f7dccad52af70f16765"
      "957aa1dd96de8562bca4bf873f2af4f231bf4ef176f3517554300b9d",
      "ce5667b7de2c9dd47766713496e82c8b4353b45735fea5a2ff97ca633763bcf763ed78bc"
      "a19f8d069c3b6240f422c3e2f678fb4f46bdc74abda83fd9fa44b332"
      "212af0f466f442db749e168af4a47cf8a2695052293cfaad36b40ffa3bbbc0d375e5e977"
      "4be20dfdd8ee59a4181cc982f6baf2b4a4d48bfa93adcf5c56e4f114",
      "787a437aa1ad2b4f7f50e8e563fec639e795fd678785d3bdce71e16979f094e16d6d7378"
      "fa5ed13f691e6b8af1f3317f269e226c0ac251dd34c74f15839d0cf5"
      "03a81f5c370fe0b3b475e533d40fa4ad3b9fa19e904e0fea099fa7077c9506f58474e37f"
      "50f44f9a4753317e3ee64fc75782b0aefb7c72a38fc6872363dc4d1e",
      "9b986f09ea5a0431823d9f1346c667a8e024e515e7f73770379d1e70f7f3f480bbd280bb"
      "e9c607ee2e9ed7b74be615fa4d2a74ca752bfcee645db9bba5d48bfa"
      "13d61bc2ac4cabbdc05de0aeb4a4dcc5d5f35ebf373c7ad518b083c76d7fcb78bb8b9f03"
      "77bf74ee421d18eac08be601dc96b6e9dcdef43a70d6fddc548c9f8f",
      "f993ede75d629380d6019e91854784136301a3ff770e034e03a717cd03382d0d387dbdce"
      "b23834451b389d8ed3ef32cee3c1927984fe5e18a16f5381e41fef68"
      "48451fd90e67d84203a20b87df1a9fdf67d4ab2bf5a2fe64eb99305b73df1fbe54c4075c"
      "4ea617daba7239e9776e65f3b085cf7a87a5335f17e5e6fe7689f65b",
      "dae67039eb3e6ec4da5aecb9d07fa3fbb8f890c1b919cecdd7cd03f82c6d5df90ce76669"
      "59f956508c9f8ff993ed67d7c23631a998f1d7cd185fd2f77a15ee78"
      "ded114ae1abcd79bbe2708b302eff56e582fb44de767f3f5932727072e3baed7bce31a19"
      "ee18769d55819fabe2e7aad639ac78b4390dfef94b7ea07c7b1cbdcc",
      "a8f78b522fea4f570f8a6607be4f039ea6dd67ed417d702e4a546fd9d5a3fac8d05f9f9e"
      "0d2bebcfd3ff008cc5b530",
      ""};
  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(&data[0], 18528U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/*
 * Arguments    : void
 * Return Type  : mxArray *
 */
mxArray *emlrtMexFcnProperties(void)
{
  mxArray *xEntryPoints;
  mxArray *xInputs;
  mxArray *xResult;
  const char_T *propFieldName[9] = {"Version",
                                    "ResolvedFunctions",
                                    "Checksum",
                                    "EntryPoints",
                                    "CoverageInfo",
                                    "IsPolymorphic",
                                    "PropertyList",
                                    "UUID",
                                    "ClassEntryPointIsHandle"};
  const char_T *epFieldName[8] = {
      "Name",     "NumberOfInputs", "NumberOfOutputs", "ConstantInputs",
      "FullPath", "TimeStamp",      "Constructor",     "Visible"};
  xEntryPoints =
      emlrtCreateStructMatrix(1, 16, 8, (const char_T **)&epFieldName[0]);
  xInputs = emlrtCreateLogicalMatrix(1, 6);
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("angle2point"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(6.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath",
                emlrtMxCreateString(
                    "C:\\Users\\XWT\\Desktop\\zongQZY\\test3\\angle2point.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp",
                emlrtMxCreateDoubleScalar(739469.68054398149));
  emlrtSetField(xEntryPoints, 0, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 0, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 8);
  emlrtSetField(xEntryPoints, 1, "Name",
                emlrtMxCreateString("Calculat_A_and_B_Points"));
  emlrtSetField(xEntryPoints, 1, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(8.0));
  emlrtSetField(xEntryPoints, 1, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(2.0));
  emlrtSetField(xEntryPoints, 1, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 1, "FullPath",
      emlrtMxCreateString("C:\\Users\\XWT\\Desktop\\zongQZY\\test3\\Calculat_A_"
                          "and_B_Points.m"));
  emlrtSetField(xEntryPoints, 1, "TimeStamp",
                emlrtMxCreateDoubleScalar(739469.68054398149));
  emlrtSetField(xEntryPoints, 1, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 1, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 8);
  emlrtSetField(xEntryPoints, 2, "Name",
                emlrtMxCreateString("Calculat_A_and_B_Points_after_Offest2"));
  emlrtSetField(xEntryPoints, 2, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(8.0));
  emlrtSetField(xEntryPoints, 2, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(2.0));
  emlrtSetField(xEntryPoints, 2, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 2, "FullPath",
      emlrtMxCreateString("C:\\Users\\XWT\\Desktop\\zongQZY\\test3\\Calculat_A_"
                          "and_B_Points_after_Offest2.m"));
  emlrtSetField(xEntryPoints, 2, "TimeStamp",
                emlrtMxCreateDoubleScalar(739470.03709490737));
  emlrtSetField(xEntryPoints, 2, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 2, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 3);
  emlrtSetField(
      xEntryPoints, 3, "Name",
      emlrtMxCreateString(
          "Calculate_accurate_cylinders_from_multiple_measurement_points2"));
  emlrtSetField(xEntryPoints, 3, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 3, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(6.0));
  emlrtSetField(xEntryPoints, 3, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 3, "FullPath",
                emlrtMxCreateString(
                    "C:\\Users\\XWT\\Desktop\\zongQZY\\test3\\Calculate_"
                    "accurate_cylinders_from_multiple_measurement_points2.m"));
  emlrtSetField(xEntryPoints, 3, "TimeStamp",
                emlrtMxCreateDoubleScalar(739469.68054398149));
  emlrtSetField(xEntryPoints, 3, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 3, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 3);
  emlrtSetField(xEntryPoints, 4, "Name", emlrtMxCreateString("CrossLine"));
  emlrtSetField(xEntryPoints, 4, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 4, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(2.0));
  emlrtSetField(xEntryPoints, 4, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 4, "FullPath",
                emlrtMxCreateString(
                    "C:\\Users\\XWT\\Desktop\\zongQZY\\test3\\CrossLine.m"));
  emlrtSetField(xEntryPoints, 4, "TimeStamp",
                emlrtMxCreateDoubleScalar(739469.68054398149));
  emlrtSetField(xEntryPoints, 4, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 4, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 1);
  emlrtSetField(xEntryPoints, 5, "Name", emlrtMxCreateString("fitcircle"));
  emlrtSetField(xEntryPoints, 5, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 5, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 5, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 5, "FullPath",
                emlrtMxCreateString(
                    "C:\\Users\\XWT\\Desktop\\zongQZY\\test3\\fitcircle.m"));
  emlrtSetField(xEntryPoints, 5, "TimeStamp",
                emlrtMxCreateDoubleScalar(739469.68054398149));
  emlrtSetField(xEntryPoints, 5, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 5, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 3);
  emlrtSetField(
      xEntryPoints, 6, "Name",
      emlrtMxCreateString("foot_of_perpendicular_from_a_point_to_a_line"));
  emlrtSetField(xEntryPoints, 6, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 6, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 6, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 6, "FullPath",
      emlrtMxCreateString("C:\\Users\\XWT\\Desktop\\zongQZY\\test3\\foot_of_"
                          "perpendicular_from_a_point_to_a_line.m"));
  emlrtSetField(xEntryPoints, 6, "TimeStamp",
                emlrtMxCreateDoubleScalar(739469.68054398149));
  emlrtSetField(xEntryPoints, 6, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 6, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 5);
  emlrtSetField(
      xEntryPoints, 7, "Name",
      emlrtMxCreateString("Generate_multi_layered_measurement_points"));
  emlrtSetField(xEntryPoints, 7, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(5.0));
  emlrtSetField(xEntryPoints, 7, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 7, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 7, "FullPath",
      emlrtMxCreateString("C:\\Users\\XWT\\Desktop\\zongQZY\\test3\\Generate_"
                          "multi_layered_measurement_points.m"));
  emlrtSetField(xEntryPoints, 7, "TimeStamp",
                emlrtMxCreateDoubleScalar(739469.68054398149));
  emlrtSetField(xEntryPoints, 7, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 7, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 3);
  emlrtSetField(xEntryPoints, 8, "Name",
                emlrtMxCreateString("generate_unit_circle_with_normal_vector"));
  emlrtSetField(xEntryPoints, 8, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 8, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 8, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 8, "FullPath",
      emlrtMxCreateString("C:\\Users\\XWT\\Desktop\\zongQZY\\test3\\generate_"
                          "unit_circle_with_normal_vector.m"));
  emlrtSetField(xEntryPoints, 8, "TimeStamp",
                emlrtMxCreateDoubleScalar(739469.68054398149));
  emlrtSetField(xEntryPoints, 8, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 8, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 6);
  emlrtSetField(
      xEntryPoints, 9, "Name",
      emlrtMxCreateString("generate_unit_circle_with_normal_vector2"));
  emlrtSetField(xEntryPoints, 9, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(6.0));
  emlrtSetField(xEntryPoints, 9, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 9, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 9, "FullPath",
      emlrtMxCreateString("C:\\Users\\XWT\\Desktop\\zongQZY\\test3\\generate_"
                          "unit_circle_with_normal_vector2.m"));
  emlrtSetField(xEntryPoints, 9, "TimeStamp",
                emlrtMxCreateDoubleScalar(739469.95052083337));
  emlrtSetField(xEntryPoints, 9, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 9, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 4);
  emlrtSetField(xEntryPoints, 10, "Name",
                emlrtMxCreateString("GenerateTrianglePoints"));
  emlrtSetField(xEntryPoints, 10, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(4.0));
  emlrtSetField(xEntryPoints, 10, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 10, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 10, "FullPath",
      emlrtMxCreateString(
          "C:\\Users\\XWT\\Desktop\\zongQZY\\test3\\GenerateTrianglePoints.m"));
  emlrtSetField(xEntryPoints, 10, "TimeStamp",
                emlrtMxCreateDoubleScalar(739469.68054398149));
  emlrtSetField(xEntryPoints, 10, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 10, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 1);
  emlrtSetField(xEntryPoints, 11, "Name",
                emlrtMxCreateString("myvrrotvec2mat"));
  emlrtSetField(xEntryPoints, 11, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 11, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 11, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 11, "FullPath",
      emlrtMxCreateString(
          "C:\\Users\\XWT\\Desktop\\zongQZY\\test3\\myvrrotvec2mat.m"));
  emlrtSetField(xEntryPoints, 11, "TimeStamp",
                emlrtMxCreateDoubleScalar(739469.68054398149));
  emlrtSetField(xEntryPoints, 11, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 11, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 4);
  emlrtSetField(xEntryPoints, 12, "Name",
                emlrtMxCreateString("OffsetCalculate"));
  emlrtSetField(xEntryPoints, 12, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(4.0));
  emlrtSetField(xEntryPoints, 12, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 12, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 12, "FullPath",
      emlrtMxCreateString(
          "C:\\Users\\XWT\\Desktop\\zongQZY\\test3\\OffsetCalculate.m"));
  emlrtSetField(xEntryPoints, 12, "TimeStamp",
                emlrtMxCreateDoubleScalar(739469.68054398149));
  emlrtSetField(xEntryPoints, 12, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 12, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 4);
  emlrtSetField(xEntryPoints, 13, "Name", emlrtMxCreateString("planefit"));
  emlrtSetField(xEntryPoints, 13, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(4.0));
  emlrtSetField(xEntryPoints, 13, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(2.0));
  emlrtSetField(xEntryPoints, 13, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 13, "FullPath",
                emlrtMxCreateString(
                    "C:\\Users\\XWT\\Desktop\\zongQZY\\test3\\planefit.m"));
  emlrtSetField(xEntryPoints, 13, "TimeStamp",
                emlrtMxCreateDoubleScalar(739469.68054398149));
  emlrtSetField(xEntryPoints, 13, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 13, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 4);
  emlrtSetField(xEntryPoints, 14, "Name", emlrtMxCreateString("RepeatSurvey"));
  emlrtSetField(xEntryPoints, 14, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(4.0));
  emlrtSetField(xEntryPoints, 14, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(2.0));
  emlrtSetField(xEntryPoints, 14, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 14, "FullPath",
                emlrtMxCreateString(
                    "C:\\Users\\XWT\\Desktop\\zongQZY\\test3\\RepeatSurvey.m"));
  emlrtSetField(xEntryPoints, 14, "TimeStamp",
                emlrtMxCreateDoubleScalar(739469.68054398149));
  emlrtSetField(xEntryPoints, 14, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 14, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 1);
  emlrtSetField(xEntryPoints, 15, "Name",
                emlrtMxCreateString("ShengLuJiaoJiSuan"));
  emlrtSetField(xEntryPoints, 15, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 15, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 15, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 15, "FullPath",
      emlrtMxCreateString(
          "C:\\Users\\XWT\\Desktop\\zongQZY\\test3\\ShengLuJiaoJiSuan.m"));
  emlrtSetField(xEntryPoints, 15, "TimeStamp",
                emlrtMxCreateDoubleScalar(739469.68054398149));
  emlrtSetField(xEntryPoints, 15, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 15, "Visible", emlrtMxCreateLogicalScalar(true));
  xResult =
      emlrtCreateStructMatrix(1, 1, 9, (const char_T **)&propFieldName[0]);
  emlrtSetField(xResult, 0, "Version",
                emlrtMxCreateString("23.2.0.2365128 (R2023b)"));
  emlrtSetField(xResult, 0, "ResolvedFunctions",
                (mxArray *)c_emlrtMexFcnResolvedFunctionsI());
  emlrtSetField(xResult, 0, "Checksum",
                emlrtMxCreateString("jQcBS7vuVQ219emhWY3FOG"));
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  return xResult;
}

/*
 * File trailer for _coder_QuanZhanYi_info.c
 *
 * [EOF]
 */
