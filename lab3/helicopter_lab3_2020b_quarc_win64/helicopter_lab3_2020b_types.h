/*
 * helicopter_lab3_2020b_types.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "helicopter_lab3_2020b".
 *
 * Model version              : 11.1
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C source code generated on : Fri Feb 24 12:26:06 2023
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_helicopter_lab3_2020b_types_h_
#define RTW_HEADER_helicopter_lab3_2020b_types_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"

/* Model Code Variants */
#ifndef DEFINED_TYPEDEF_FOR_struct_Ag3ILDvcUaDdalFn77cwdG_
#define DEFINED_TYPEDEF_FOR_struct_Ag3ILDvcUaDdalFn77cwdG_

typedef struct {
  real_T values[705];
} struct_Ag3ILDvcUaDdalFn77cwdG;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_Lz4TuwIk5mbe1G5RW4RVlH_
#define DEFINED_TYPEDEF_FOR_struct_Lz4TuwIk5mbe1G5RW4RVlH_

typedef struct {
  real_T time[141];
  struct_Ag3ILDvcUaDdalFn77cwdG signals;
} struct_Lz4TuwIk5mbe1G5RW4RVlH;

#endif

/* Parameters (default storage) */
typedef struct P_helicopter_lab3_2020b_T_ P_helicopter_lab3_2020b_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_helicopter_lab3_2020b_T RT_MODEL_helicopter_lab3_2020_T;

#endif                           /* RTW_HEADER_helicopter_lab3_2020b_types_h_ */
