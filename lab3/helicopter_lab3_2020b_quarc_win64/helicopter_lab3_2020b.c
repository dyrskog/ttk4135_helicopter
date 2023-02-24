/*
 * helicopter_lab3_2020b.c
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

#include "helicopter_lab3_2020b.h"
#include "helicopter_lab3_2020b_private.h"
#include "helicopter_lab3_2020b_dt.h"

/* Block signals (default storage) */
B_helicopter_lab3_2020b_T helicopter_lab3_2020b_B;

/* Continuous states */
X_helicopter_lab3_2020b_T helicopter_lab3_2020b_X;

/* Block states (default storage) */
DW_helicopter_lab3_2020b_T helicopter_lab3_2020b_DW;

/* Real-time model */
static RT_MODEL_helicopter_lab3_2020_T helicopter_lab3_2020b_M_;
RT_MODEL_helicopter_lab3_2020_T *const helicopter_lab3_2020b_M =
  &helicopter_lab3_2020b_M_;

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 4;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  helicopter_lab3_2020b_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void helicopter_lab3_2020b_output(void)
{
  /* local block i/o variables */
  real_T rtb_HILReadEncoderTimebase_o1;
  real_T rtb_HILReadEncoderTimebase_o2;
  real_T rtb_HILReadEncoderTimebase_o3;
  real_T lastTime;
  real_T rtb_Backgain;
  real_T rtb_Clock;
  real_T rtb_Derivative;
  real_T *lastU;
  int32_T i;
  int8_T rtAction;
  if (rtmIsMajorTimeStep(helicopter_lab3_2020b_M)) {
    /* set solver stop time */
    if (!(helicopter_lab3_2020b_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&helicopter_lab3_2020b_M->solverInfo,
                            ((helicopter_lab3_2020b_M->Timing.clockTickH0 + 1) *
        helicopter_lab3_2020b_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&helicopter_lab3_2020b_M->solverInfo,
                            ((helicopter_lab3_2020b_M->Timing.clockTick0 + 1) *
        helicopter_lab3_2020b_M->Timing.stepSize0 +
        helicopter_lab3_2020b_M->Timing.clockTickH0 *
        helicopter_lab3_2020b_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(helicopter_lab3_2020b_M)) {
    helicopter_lab3_2020b_M->Timing.t[0] = rtsiGetT
      (&helicopter_lab3_2020b_M->solverInfo);
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC(helicopter_lab3_2020b_DW.IfActionSubsystem_SubsysRanBC);
  if (rtmIsMajorTimeStep(helicopter_lab3_2020b_M)) {
    /* S-Function (hil_read_encoder_timebase_block): '<S4>/HIL Read Encoder Timebase' */

    /* S-Function Block: helicopter_lab3_2020b/Helicopter_interface/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
    {
      t_error result;
      result = hil_task_read_encoder
        (helicopter_lab3_2020b_DW.HILReadEncoderTimebase_Task, 1,
         &helicopter_lab3_2020b_DW.HILReadEncoderTimebase_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helicopter_lab3_2020b_M, _rt_error_message);
      } else {
        rtb_HILReadEncoderTimebase_o1 =
          helicopter_lab3_2020b_DW.HILReadEncoderTimebase_Buffer[0];
        rtb_HILReadEncoderTimebase_o2 =
          helicopter_lab3_2020b_DW.HILReadEncoderTimebase_Buffer[1];
        rtb_HILReadEncoderTimebase_o3 =
          helicopter_lab3_2020b_DW.HILReadEncoderTimebase_Buffer[2];
      }
    }
  }

  /* FromWorkspace: '<Root>/From Workspace1' */
  {
    real_T *pDataValues = (real_T *)
      helicopter_lab3_2020b_DW.FromWorkspace1_PWORK.DataPtr;
    real_T *pTimeValues = (real_T *)
      helicopter_lab3_2020b_DW.FromWorkspace1_PWORK.TimePtr;
    int_T currTimeIndex =
      helicopter_lab3_2020b_DW.FromWorkspace1_IWORK.PrevIndex;
    real_T t = helicopter_lab3_2020b_M->Timing.t[0];

    /* Get index */
    if (t <= pTimeValues[0]) {
      currTimeIndex = 0;
    } else if (t >= pTimeValues[140]) {
      currTimeIndex = 139;
    } else {
      if (t < pTimeValues[currTimeIndex]) {
        while (t < pTimeValues[currTimeIndex]) {
          currTimeIndex--;
        }
      } else {
        while (t >= pTimeValues[currTimeIndex + 1]) {
          currTimeIndex++;
        }
      }
    }

    helicopter_lab3_2020b_DW.FromWorkspace1_IWORK.PrevIndex = currTimeIndex;

    /* Post output */
    {
      real_T t1 = pTimeValues[currTimeIndex];
      real_T t2 = pTimeValues[currTimeIndex + 1];
      if (t1 == t2) {
        if (t < t1) {
          {
            int_T elIdx;
            for (elIdx = 0; elIdx < 5; ++elIdx) {
              (&helicopter_lab3_2020b_B.FromWorkspace1[0])[elIdx] =
                pDataValues[currTimeIndex];
              pDataValues += 141;
            }
          }
        } else {
          {
            int_T elIdx;
            for (elIdx = 0; elIdx < 5; ++elIdx) {
              (&helicopter_lab3_2020b_B.FromWorkspace1[0])[elIdx] =
                pDataValues[currTimeIndex + 1];
              pDataValues += 141;
            }
          }
        }
      } else {
        real_T f1 = (t2 - t) / (t2 - t1);
        real_T f2 = 1.0 - f1;
        real_T d1;
        real_T d2;
        int_T TimeIndex= currTimeIndex;

        {
          int_T elIdx;
          for (elIdx = 0; elIdx < 5; ++elIdx) {
            d1 = pDataValues[TimeIndex];
            d2 = pDataValues[TimeIndex + 1];
            (&helicopter_lab3_2020b_B.FromWorkspace1[0])[elIdx] = (real_T)
              rtInterpolate(d1, d2, f1, f2);
            pDataValues += 141;
          }
        }
      }
    }
  }

  if (rtmIsMajorTimeStep(helicopter_lab3_2020b_M)) {
    /* Gain: '<S4>/Travel: Count to rad' incorporates:
     *  Gain: '<S4>/Travel_gain'
     */
    helicopter_lab3_2020b_B.TravelCounttorad =
      helicopter_lab3_2020b_P.travel_gain * rtb_HILReadEncoderTimebase_o1 *
      helicopter_lab3_2020b_P.TravelCounttorad_Gain;

    /* Gain: '<S13>/Gain' */
    helicopter_lab3_2020b_B.Gain = helicopter_lab3_2020b_P.Gain_Gain *
      helicopter_lab3_2020b_B.TravelCounttorad;

    /* Sum: '<Root>/Sum3' incorporates:
     *  Constant: '<Root>/Constant'
     */
    helicopter_lab3_2020b_B.Sum3 = helicopter_lab3_2020b_P.Constant_Value +
      helicopter_lab3_2020b_B.Gain;

    /* Gain: '<S4>/Pitch: Count to rad' */
    helicopter_lab3_2020b_B.PitchCounttorad =
      helicopter_lab3_2020b_P.PitchCounttorad_Gain *
      rtb_HILReadEncoderTimebase_o2;

    /* Gain: '<S10>/Gain' */
    helicopter_lab3_2020b_B.Gain_i = helicopter_lab3_2020b_P.Gain_Gain_a *
      helicopter_lab3_2020b_B.PitchCounttorad;
  }

  /* Gain: '<S14>/Gain' incorporates:
   *  TransferFcn: '<S4>/Travel: Transfer Fcn'
   */
  helicopter_lab3_2020b_B.Gain_d = (helicopter_lab3_2020b_P.TravelTransferFcn_C *
    helicopter_lab3_2020b_X.TravelTransferFcn_CSTATE +
    helicopter_lab3_2020b_P.TravelTransferFcn_D *
    helicopter_lab3_2020b_B.TravelCounttorad) *
    helicopter_lab3_2020b_P.Gain_Gain_l;

  /* Gain: '<S11>/Gain' incorporates:
   *  TransferFcn: '<S4>/Pitch: Transfer Fcn'
   */
  helicopter_lab3_2020b_B.Gain_b = (helicopter_lab3_2020b_P.PitchTransferFcn_C *
    helicopter_lab3_2020b_X.PitchTransferFcn_CSTATE +
    helicopter_lab3_2020b_P.PitchTransferFcn_D *
    helicopter_lab3_2020b_B.PitchCounttorad) *
    helicopter_lab3_2020b_P.Gain_Gain_ae;
  if (rtmIsMajorTimeStep(helicopter_lab3_2020b_M)) {
    /* Gain: '<S4>/Elevation: Count to rad' incorporates:
     *  Gain: '<S4>/Elevation_gain'
     */
    helicopter_lab3_2020b_B.ElevationCounttorad =
      helicopter_lab3_2020b_P.elevation_gain * rtb_HILReadEncoderTimebase_o3 *
      helicopter_lab3_2020b_P.ElevationCounttorad_Gain;

    /* Gain: '<S8>/Gain' */
    helicopter_lab3_2020b_B.Gain_e = helicopter_lab3_2020b_P.Gain_Gain_lv *
      helicopter_lab3_2020b_B.ElevationCounttorad;

    /* Sum: '<Root>/Sum' incorporates:
     *  Constant: '<Root>/elavation_offset [deg]'
     */
    helicopter_lab3_2020b_B.Sum = helicopter_lab3_2020b_B.Gain_e +
      helicopter_lab3_2020b_P.elavation_offsetdeg_Value;
  }

  /* Gain: '<S9>/Gain' incorporates:
   *  TransferFcn: '<S4>/Elevation: Transfer Fcn'
   */
  helicopter_lab3_2020b_B.Gain_dg =
    (helicopter_lab3_2020b_P.ElevationTransferFcn_C *
     helicopter_lab3_2020b_X.ElevationTransferFcn_CSTATE +
     helicopter_lab3_2020b_P.ElevationTransferFcn_D *
     helicopter_lab3_2020b_B.ElevationCounttorad) *
    helicopter_lab3_2020b_P.Gain_Gain_n;

  /* Gain: '<S2>/Gain1' */
  helicopter_lab3_2020b_B.Gain1[0] = helicopter_lab3_2020b_P.Gain1_Gain *
    helicopter_lab3_2020b_B.Sum3;
  helicopter_lab3_2020b_B.Gain1[1] = helicopter_lab3_2020b_P.Gain1_Gain *
    helicopter_lab3_2020b_B.Gain_d;
  helicopter_lab3_2020b_B.Gain1[2] = helicopter_lab3_2020b_P.Gain1_Gain *
    helicopter_lab3_2020b_B.Gain_i;
  helicopter_lab3_2020b_B.Gain1[3] = helicopter_lab3_2020b_P.Gain1_Gain *
    helicopter_lab3_2020b_B.Gain_b;
  helicopter_lab3_2020b_B.Gain1[4] = helicopter_lab3_2020b_P.Gain1_Gain *
    helicopter_lab3_2020b_B.Sum;
  helicopter_lab3_2020b_B.Gain1[5] = helicopter_lab3_2020b_P.Gain1_Gain *
    helicopter_lab3_2020b_B.Gain_dg;

  /* Sum: '<S5>/Sum3' incorporates:
   *  Gain: '<S5>/Gain'
   *  Sum: '<S5>/Sum1'
   */
  helicopter_lab3_2020b_B.Sum3_b = helicopter_lab3_2020b_B.FromWorkspace1[0] -
    ((((helicopter_lab3_2020b_B.Gain1[0] -
        helicopter_lab3_2020b_B.FromWorkspace1[1]) *
       helicopter_lab3_2020b_P.K_lqr[0] + (helicopter_lab3_2020b_B.Gain1[1] -
        helicopter_lab3_2020b_B.FromWorkspace1[2]) *
       helicopter_lab3_2020b_P.K_lqr[1]) + (helicopter_lab3_2020b_B.Gain1[2] -
       helicopter_lab3_2020b_B.FromWorkspace1[3]) *
      helicopter_lab3_2020b_P.K_lqr[2]) + (helicopter_lab3_2020b_B.Gain1[3] -
      helicopter_lab3_2020b_B.FromWorkspace1[4]) *
     helicopter_lab3_2020b_P.K_lqr[3]);
  if (rtmIsMajorTimeStep(helicopter_lab3_2020b_M)) {
    for (i = 0; i < 5; i++) {
      /* SignalConversion generated from: '<Root>/To Workspace' */
      helicopter_lab3_2020b_B.TmpSignalConversionAtToWorkspac[i] =
        helicopter_lab3_2020b_B.FromWorkspace1[i];
    }

    /* SignalConversion generated from: '<Root>/To Workspace' */
    helicopter_lab3_2020b_B.TmpSignalConversionAtToWorkspac[5] =
      helicopter_lab3_2020b_B.Sum3_b;
    for (i = 0; i < 6; i++) {
      helicopter_lab3_2020b_B.TmpSignalConversionAtToWorkspac[i + 6] =
        helicopter_lab3_2020b_B.Gain1[i];
    }
  }

  /* Sum: '<Root>/Sum1' incorporates:
   *  Constant: '<Root>/Vd_bias'
   *  Gain: '<S6>/K_pd'
   *  Gain: '<S6>/K_pp'
   *  Sum: '<S6>/Sum2'
   *  Sum: '<S6>/Sum3'
   */
  rtb_Clock = ((helicopter_lab3_2020b_B.Sum3_b - helicopter_lab3_2020b_B.Gain1[2])
               * helicopter_lab3_2020b_P.K_pp - helicopter_lab3_2020b_P.K_pd *
               helicopter_lab3_2020b_B.Gain1[3]) + helicopter_lab3_2020b_P.Vd_ff;

  /* Integrator: '<S3>/Integrator' */
  /* Limited  Integrator  */
  if (helicopter_lab3_2020b_X.Integrator_CSTATE >=
      helicopter_lab3_2020b_P.Integrator_UpperSat) {
    helicopter_lab3_2020b_X.Integrator_CSTATE =
      helicopter_lab3_2020b_P.Integrator_UpperSat;
  } else {
    if (helicopter_lab3_2020b_X.Integrator_CSTATE <=
        helicopter_lab3_2020b_P.Integrator_LowerSat) {
      helicopter_lab3_2020b_X.Integrator_CSTATE =
        helicopter_lab3_2020b_P.Integrator_LowerSat;
    }
  }

  /* Sum: '<S3>/Sum' incorporates:
   *  Constant: '<Root>/elevation_ref'
   */
  rtb_Derivative = helicopter_lab3_2020b_P.elevation_ref_Value -
    helicopter_lab3_2020b_B.Gain1[4];

  /* Sum: '<Root>/Sum2' incorporates:
   *  Constant: '<Root>/Vs_bias'
   *  Gain: '<S3>/K_ed'
   *  Gain: '<S3>/K_ep'
   *  Integrator: '<S3>/Integrator'
   *  Sum: '<S3>/Sum1'
   */
  rtb_Backgain = ((helicopter_lab3_2020b_P.K_ep * rtb_Derivative +
                   helicopter_lab3_2020b_X.Integrator_CSTATE) -
                  helicopter_lab3_2020b_P.K_ed * helicopter_lab3_2020b_B.Gain1[5])
    + helicopter_lab3_2020b_P.Vs_ff;

  /* If: '<S3>/If' incorporates:
   *  Clock: '<S3>/Clock'
   *  Gain: '<S3>/K_ei'
   *  Inport: '<S7>/In1'
   */
  if (rtmIsMajorTimeStep(helicopter_lab3_2020b_M)) {
    rtAction = (int8_T)!(helicopter_lab3_2020b_M->Timing.t[0] >= 2.0);
    helicopter_lab3_2020b_DW.If_ActiveSubsystem = rtAction;
  } else {
    rtAction = helicopter_lab3_2020b_DW.If_ActiveSubsystem;
  }

  if (rtAction == 0) {
    /* Outputs for IfAction SubSystem: '<S3>/If Action Subsystem' incorporates:
     *  ActionPort: '<S7>/Action Port'
     */
    helicopter_lab3_2020b_B.In1 = helicopter_lab3_2020b_P.K_ei * rtb_Derivative;
    if (rtmIsMajorTimeStep(helicopter_lab3_2020b_M)) {
      srUpdateBC(helicopter_lab3_2020b_DW.IfActionSubsystem_SubsysRanBC);
    }

    /* End of Outputs for SubSystem: '<S3>/If Action Subsystem' */
  }

  /* End of If: '<S3>/If' */
  if (rtmIsMajorTimeStep(helicopter_lab3_2020b_M)) {
  }

  /* Derivative: '<S4>/Derivative' */
  rtb_Derivative = helicopter_lab3_2020b_M->Timing.t[0];
  if ((helicopter_lab3_2020b_DW.TimeStampA >= rtb_Derivative) &&
      (helicopter_lab3_2020b_DW.TimeStampB >= rtb_Derivative)) {
    rtb_Derivative = 0.0;
  } else {
    lastTime = helicopter_lab3_2020b_DW.TimeStampA;
    lastU = &helicopter_lab3_2020b_DW.LastUAtTimeA;
    if (helicopter_lab3_2020b_DW.TimeStampA <
        helicopter_lab3_2020b_DW.TimeStampB) {
      if (helicopter_lab3_2020b_DW.TimeStampB < rtb_Derivative) {
        lastTime = helicopter_lab3_2020b_DW.TimeStampB;
        lastU = &helicopter_lab3_2020b_DW.LastUAtTimeB;
      }
    } else {
      if (helicopter_lab3_2020b_DW.TimeStampA >= rtb_Derivative) {
        lastTime = helicopter_lab3_2020b_DW.TimeStampB;
        lastU = &helicopter_lab3_2020b_DW.LastUAtTimeB;
      }
    }

    rtb_Derivative = (helicopter_lab3_2020b_B.PitchCounttorad - *lastU) /
      (rtb_Derivative - lastTime);
  }

  /* End of Derivative: '<S4>/Derivative' */

  /* Gain: '<S12>/Gain' */
  helicopter_lab3_2020b_B.Gain_l = helicopter_lab3_2020b_P.Gain_Gain_a1 *
    rtb_Derivative;
  if (rtmIsMajorTimeStep(helicopter_lab3_2020b_M)) {
  }

  /* Gain: '<S1>/Back gain' incorporates:
   *  Sum: '<S1>/Subtract'
   */
  rtb_Derivative = (rtb_Backgain - rtb_Clock) *
    helicopter_lab3_2020b_P.Backgain_Gain;

  /* Saturate: '<S4>/Back motor: Saturation' */
  if (rtb_Derivative > helicopter_lab3_2020b_P.BackmotorSaturation_UpperSat) {
    /* Saturate: '<S4>/Back motor: Saturation' */
    helicopter_lab3_2020b_B.BackmotorSaturation =
      helicopter_lab3_2020b_P.BackmotorSaturation_UpperSat;
  } else if (rtb_Derivative <
             helicopter_lab3_2020b_P.BackmotorSaturation_LowerSat) {
    /* Saturate: '<S4>/Back motor: Saturation' */
    helicopter_lab3_2020b_B.BackmotorSaturation =
      helicopter_lab3_2020b_P.BackmotorSaturation_LowerSat;
  } else {
    /* Saturate: '<S4>/Back motor: Saturation' */
    helicopter_lab3_2020b_B.BackmotorSaturation = rtb_Derivative;
  }

  /* End of Saturate: '<S4>/Back motor: Saturation' */
  if (rtmIsMajorTimeStep(helicopter_lab3_2020b_M)) {
  }

  /* Gain: '<S1>/Front gain' incorporates:
   *  Sum: '<S1>/Add'
   */
  rtb_Derivative = (rtb_Clock + rtb_Backgain) *
    helicopter_lab3_2020b_P.Frontgain_Gain;

  /* Saturate: '<S4>/Front motor: Saturation' */
  if (rtb_Derivative > helicopter_lab3_2020b_P.FrontmotorSaturation_UpperSat) {
    /* Saturate: '<S4>/Front motor: Saturation' */
    helicopter_lab3_2020b_B.FrontmotorSaturation =
      helicopter_lab3_2020b_P.FrontmotorSaturation_UpperSat;
  } else if (rtb_Derivative <
             helicopter_lab3_2020b_P.FrontmotorSaturation_LowerSat) {
    /* Saturate: '<S4>/Front motor: Saturation' */
    helicopter_lab3_2020b_B.FrontmotorSaturation =
      helicopter_lab3_2020b_P.FrontmotorSaturation_LowerSat;
  } else {
    /* Saturate: '<S4>/Front motor: Saturation' */
    helicopter_lab3_2020b_B.FrontmotorSaturation = rtb_Derivative;
  }

  /* End of Saturate: '<S4>/Front motor: Saturation' */
  if (rtmIsMajorTimeStep(helicopter_lab3_2020b_M)) {
    /* S-Function (hil_write_analog_block): '<S4>/HIL Write Analog' */

    /* S-Function Block: helicopter_lab3_2020b/Helicopter_interface/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      helicopter_lab3_2020b_DW.HILWriteAnalog_Buffer[0] =
        helicopter_lab3_2020b_B.FrontmotorSaturation;
      helicopter_lab3_2020b_DW.HILWriteAnalog_Buffer[1] =
        helicopter_lab3_2020b_B.BackmotorSaturation;
      result = hil_write_analog(helicopter_lab3_2020b_DW.HILInitialize_Card,
        helicopter_lab3_2020b_P.HILWriteAnalog_channels, 2,
        &helicopter_lab3_2020b_DW.HILWriteAnalog_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helicopter_lab3_2020b_M, _rt_error_message);
      }
    }
  }
}

/* Model update function */
void helicopter_lab3_2020b_update(void)
{
  real_T *lastU;

  /* Update for Derivative: '<S4>/Derivative' */
  if (helicopter_lab3_2020b_DW.TimeStampA == (rtInf)) {
    helicopter_lab3_2020b_DW.TimeStampA = helicopter_lab3_2020b_M->Timing.t[0];
    lastU = &helicopter_lab3_2020b_DW.LastUAtTimeA;
  } else if (helicopter_lab3_2020b_DW.TimeStampB == (rtInf)) {
    helicopter_lab3_2020b_DW.TimeStampB = helicopter_lab3_2020b_M->Timing.t[0];
    lastU = &helicopter_lab3_2020b_DW.LastUAtTimeB;
  } else if (helicopter_lab3_2020b_DW.TimeStampA <
             helicopter_lab3_2020b_DW.TimeStampB) {
    helicopter_lab3_2020b_DW.TimeStampA = helicopter_lab3_2020b_M->Timing.t[0];
    lastU = &helicopter_lab3_2020b_DW.LastUAtTimeA;
  } else {
    helicopter_lab3_2020b_DW.TimeStampB = helicopter_lab3_2020b_M->Timing.t[0];
    lastU = &helicopter_lab3_2020b_DW.LastUAtTimeB;
  }

  *lastU = helicopter_lab3_2020b_B.PitchCounttorad;

  /* End of Update for Derivative: '<S4>/Derivative' */
  if (rtmIsMajorTimeStep(helicopter_lab3_2020b_M)) {
    rt_ertODEUpdateContinuousStates(&helicopter_lab3_2020b_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++helicopter_lab3_2020b_M->Timing.clockTick0)) {
    ++helicopter_lab3_2020b_M->Timing.clockTickH0;
  }

  helicopter_lab3_2020b_M->Timing.t[0] = rtsiGetSolverStopTime
    (&helicopter_lab3_2020b_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.002s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++helicopter_lab3_2020b_M->Timing.clockTick1)) {
      ++helicopter_lab3_2020b_M->Timing.clockTickH1;
    }

    helicopter_lab3_2020b_M->Timing.t[1] =
      helicopter_lab3_2020b_M->Timing.clockTick1 *
      helicopter_lab3_2020b_M->Timing.stepSize1 +
      helicopter_lab3_2020b_M->Timing.clockTickH1 *
      helicopter_lab3_2020b_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void helicopter_lab3_2020b_derivatives(void)
{
  XDot_helicopter_lab3_2020b_T *_rtXdot;
  boolean_T lsat;
  boolean_T usat;
  _rtXdot = ((XDot_helicopter_lab3_2020b_T *) helicopter_lab3_2020b_M->derivs);

  /* Derivatives for TransferFcn: '<S4>/Travel: Transfer Fcn' */
  _rtXdot->TravelTransferFcn_CSTATE = 0.0;
  _rtXdot->TravelTransferFcn_CSTATE +=
    helicopter_lab3_2020b_P.TravelTransferFcn_A *
    helicopter_lab3_2020b_X.TravelTransferFcn_CSTATE;
  _rtXdot->TravelTransferFcn_CSTATE += helicopter_lab3_2020b_B.TravelCounttorad;

  /* Derivatives for TransferFcn: '<S4>/Pitch: Transfer Fcn' */
  _rtXdot->PitchTransferFcn_CSTATE = 0.0;
  _rtXdot->PitchTransferFcn_CSTATE += helicopter_lab3_2020b_P.PitchTransferFcn_A
    * helicopter_lab3_2020b_X.PitchTransferFcn_CSTATE;
  _rtXdot->PitchTransferFcn_CSTATE += helicopter_lab3_2020b_B.PitchCounttorad;

  /* Derivatives for TransferFcn: '<S4>/Elevation: Transfer Fcn' */
  _rtXdot->ElevationTransferFcn_CSTATE = 0.0;
  _rtXdot->ElevationTransferFcn_CSTATE +=
    helicopter_lab3_2020b_P.ElevationTransferFcn_A *
    helicopter_lab3_2020b_X.ElevationTransferFcn_CSTATE;
  _rtXdot->ElevationTransferFcn_CSTATE +=
    helicopter_lab3_2020b_B.ElevationCounttorad;

  /* Derivatives for Integrator: '<S3>/Integrator' */
  lsat = (helicopter_lab3_2020b_X.Integrator_CSTATE <=
          helicopter_lab3_2020b_P.Integrator_LowerSat);
  usat = (helicopter_lab3_2020b_X.Integrator_CSTATE >=
          helicopter_lab3_2020b_P.Integrator_UpperSat);
  if (((!lsat) && (!usat)) || (lsat && (helicopter_lab3_2020b_B.In1 > 0.0)) ||
      (usat && (helicopter_lab3_2020b_B.In1 < 0.0))) {
    _rtXdot->Integrator_CSTATE = helicopter_lab3_2020b_B.In1;
  } else {
    /* in saturation */
    _rtXdot->Integrator_CSTATE = 0.0;
  }

  /* End of Derivatives for Integrator: '<S3>/Integrator' */
}

/* Model initialize function */
void helicopter_lab3_2020b_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: helicopter_lab3_2020b/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q8_usb", "0",
                      &helicopter_lab3_2020b_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(helicopter_lab3_2020b_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options
      (helicopter_lab3_2020b_DW.HILInitialize_Card,
       "update_rate=normal;decimation=1", 32);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(helicopter_lab3_2020b_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(helicopter_lab3_2020b_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(helicopter_lab3_2020b_M, _rt_error_message);
      return;
    }

    if ((helicopter_lab3_2020b_P.HILInitialize_AIPStart && !is_switching) ||
        (helicopter_lab3_2020b_P.HILInitialize_AIPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums =
          &helicopter_lab3_2020b_DW.HILInitialize_AIMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMinimums[i1] = (helicopter_lab3_2020b_P.HILInitialize_AILow);
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums =
          &helicopter_lab3_2020b_DW.HILInitialize_AIMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMaximums[i1] = helicopter_lab3_2020b_P.HILInitialize_AIHigh;
        }
      }

      result = hil_set_analog_input_ranges
        (helicopter_lab3_2020b_DW.HILInitialize_Card,
         helicopter_lab3_2020b_P.HILInitialize_AIChannels, 8U,
         &helicopter_lab3_2020b_DW.HILInitialize_AIMinimums[0],
         &helicopter_lab3_2020b_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helicopter_lab3_2020b_M, _rt_error_message);
        return;
      }
    }

    if ((helicopter_lab3_2020b_P.HILInitialize_AOPStart && !is_switching) ||
        (helicopter_lab3_2020b_P.HILInitialize_AOPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOMinimums =
          &helicopter_lab3_2020b_DW.HILInitialize_AOMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMinimums[i1] = (helicopter_lab3_2020b_P.HILInitialize_AOLow);
        }
      }

      {
        int_T i1;
        real_T *dw_AOMaximums =
          &helicopter_lab3_2020b_DW.HILInitialize_AOMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMaximums[i1] = helicopter_lab3_2020b_P.HILInitialize_AOHigh;
        }
      }

      result = hil_set_analog_output_ranges
        (helicopter_lab3_2020b_DW.HILInitialize_Card,
         helicopter_lab3_2020b_P.HILInitialize_AOChannels, 8U,
         &helicopter_lab3_2020b_DW.HILInitialize_AOMinimums[0],
         &helicopter_lab3_2020b_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helicopter_lab3_2020b_M, _rt_error_message);
        return;
      }
    }

    if ((helicopter_lab3_2020b_P.HILInitialize_AOStart && !is_switching) ||
        (helicopter_lab3_2020b_P.HILInitialize_AOEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages =
          &helicopter_lab3_2020b_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = helicopter_lab3_2020b_P.HILInitialize_AOInitial;
        }
      }

      result = hil_write_analog(helicopter_lab3_2020b_DW.HILInitialize_Card,
        helicopter_lab3_2020b_P.HILInitialize_AOChannels, 8U,
        &helicopter_lab3_2020b_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helicopter_lab3_2020b_M, _rt_error_message);
        return;
      }
    }

    if (helicopter_lab3_2020b_P.HILInitialize_AOReset) {
      {
        int_T i1;
        real_T *dw_AOVoltages =
          &helicopter_lab3_2020b_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = helicopter_lab3_2020b_P.HILInitialize_AOWatchdog;
        }
      }

      result = hil_watchdog_set_analog_expiration_state
        (helicopter_lab3_2020b_DW.HILInitialize_Card,
         helicopter_lab3_2020b_P.HILInitialize_AOChannels, 8U,
         &helicopter_lab3_2020b_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helicopter_lab3_2020b_M, _rt_error_message);
        return;
      }
    }

    if ((helicopter_lab3_2020b_P.HILInitialize_EIPStart && !is_switching) ||
        (helicopter_lab3_2020b_P.HILInitialize_EIPEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_QuadratureModes =
          &helicopter_lab3_2020b_DW.HILInitialize_QuadratureModes[0];
        for (i1=0; i1 < 8; i1++) {
          dw_QuadratureModes[i1] =
            helicopter_lab3_2020b_P.HILInitialize_EIQuadrature;
        }
      }

      result = hil_set_encoder_quadrature_mode
        (helicopter_lab3_2020b_DW.HILInitialize_Card,
         helicopter_lab3_2020b_P.HILInitialize_EIChannels, 8U,
         (t_encoder_quadrature_mode *)
         &helicopter_lab3_2020b_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helicopter_lab3_2020b_M, _rt_error_message);
        return;
      }
    }

    if ((helicopter_lab3_2020b_P.HILInitialize_EIStart && !is_switching) ||
        (helicopter_lab3_2020b_P.HILInitialize_EIEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts =
          &helicopter_lab3_2020b_DW.HILInitialize_InitialEICounts[0];
        for (i1=0; i1 < 8; i1++) {
          dw_InitialEICounts[i1] =
            helicopter_lab3_2020b_P.HILInitialize_EIInitial;
        }
      }

      result = hil_set_encoder_counts
        (helicopter_lab3_2020b_DW.HILInitialize_Card,
         helicopter_lab3_2020b_P.HILInitialize_EIChannels, 8U,
         &helicopter_lab3_2020b_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helicopter_lab3_2020b_M, _rt_error_message);
        return;
      }
    }

    if ((helicopter_lab3_2020b_P.HILInitialize_POPStart && !is_switching) ||
        (helicopter_lab3_2020b_P.HILInitialize_POPEnter && is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;

      {
        int_T i1;
        int32_T *dw_POModeValues =
          &helicopter_lab3_2020b_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = helicopter_lab3_2020b_P.HILInitialize_POModes;
        }
      }

      result = hil_set_pwm_mode(helicopter_lab3_2020b_DW.HILInitialize_Card,
        helicopter_lab3_2020b_P.HILInitialize_POChannels, 8U, (t_pwm_mode *)
        &helicopter_lab3_2020b_DW.HILInitialize_POModeValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helicopter_lab3_2020b_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        const uint32_T *p_HILInitialize_POChannels =
          helicopter_lab3_2020b_P.HILInitialize_POChannels;
        int32_T *dw_POModeValues =
          &helicopter_lab3_2020b_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1] ==
              PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE ||
              dw_POModeValues[i1] == PWM_RAW_MODE) {
            helicopter_lab3_2020b_DW.HILInitialize_POSortedChans[num_duty_cycle_modes]
              = (p_HILInitialize_POChannels[i1]);
            helicopter_lab3_2020b_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]
              = helicopter_lab3_2020b_P.HILInitialize_POFrequency;
            num_duty_cycle_modes++;
          } else {
            helicopter_lab3_2020b_DW.HILInitialize_POSortedChans[7U -
              num_frequency_modes] = (p_HILInitialize_POChannels[i1]);
            helicopter_lab3_2020b_DW.HILInitialize_POSortedFreqs[7U -
              num_frequency_modes] =
              helicopter_lab3_2020b_P.HILInitialize_POFrequency;
            num_frequency_modes++;
          }
        }
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency
          (helicopter_lab3_2020b_DW.HILInitialize_Card,
           &helicopter_lab3_2020b_DW.HILInitialize_POSortedChans[0],
           num_duty_cycle_modes,
           &helicopter_lab3_2020b_DW.HILInitialize_POSortedFreqs[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(helicopter_lab3_2020b_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle
          (helicopter_lab3_2020b_DW.HILInitialize_Card,
           &helicopter_lab3_2020b_DW.HILInitialize_POSortedChans[num_duty_cycle_modes],
           num_frequency_modes,
           &helicopter_lab3_2020b_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(helicopter_lab3_2020b_M, _rt_error_message);
          return;
        }
      }

      {
        int_T i1;
        int32_T *dw_POModeValues =
          &helicopter_lab3_2020b_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] =
            helicopter_lab3_2020b_P.HILInitialize_POConfiguration;
        }
      }

      {
        int_T i1;
        int32_T *dw_POAlignValues =
          &helicopter_lab3_2020b_DW.HILInitialize_POAlignValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POAlignValues[i1] =
            helicopter_lab3_2020b_P.HILInitialize_POAlignment;
        }
      }

      {
        int_T i1;
        int32_T *dw_POPolarityVals =
          &helicopter_lab3_2020b_DW.HILInitialize_POPolarityVals[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POPolarityVals[i1] =
            helicopter_lab3_2020b_P.HILInitialize_POPolarity;
        }
      }

      result = hil_set_pwm_configuration
        (helicopter_lab3_2020b_DW.HILInitialize_Card,
         helicopter_lab3_2020b_P.HILInitialize_POChannels, 8U,
         (t_pwm_configuration *)
         &helicopter_lab3_2020b_DW.HILInitialize_POModeValues[0],
         (t_pwm_alignment *)
         &helicopter_lab3_2020b_DW.HILInitialize_POAlignValues[0],
         (t_pwm_polarity *)
         &helicopter_lab3_2020b_DW.HILInitialize_POPolarityVals[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helicopter_lab3_2020b_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_POSortedFreqs =
          &helicopter_lab3_2020b_DW.HILInitialize_POSortedFreqs[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POSortedFreqs[i1] = helicopter_lab3_2020b_P.HILInitialize_POLeading;
        }
      }

      {
        int_T i1;
        real_T *dw_POValues = &helicopter_lab3_2020b_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = helicopter_lab3_2020b_P.HILInitialize_POTrailing;
        }
      }

      result = hil_set_pwm_deadband(helicopter_lab3_2020b_DW.HILInitialize_Card,
        helicopter_lab3_2020b_P.HILInitialize_POChannels, 8U,
        &helicopter_lab3_2020b_DW.HILInitialize_POSortedFreqs[0],
        &helicopter_lab3_2020b_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helicopter_lab3_2020b_M, _rt_error_message);
        return;
      }
    }

    if ((helicopter_lab3_2020b_P.HILInitialize_POStart && !is_switching) ||
        (helicopter_lab3_2020b_P.HILInitialize_POEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &helicopter_lab3_2020b_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = helicopter_lab3_2020b_P.HILInitialize_POInitial;
        }
      }

      result = hil_write_pwm(helicopter_lab3_2020b_DW.HILInitialize_Card,
        helicopter_lab3_2020b_P.HILInitialize_POChannels, 8U,
        &helicopter_lab3_2020b_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helicopter_lab3_2020b_M, _rt_error_message);
        return;
      }
    }

    if (helicopter_lab3_2020b_P.HILInitialize_POReset) {
      {
        int_T i1;
        real_T *dw_POValues = &helicopter_lab3_2020b_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = helicopter_lab3_2020b_P.HILInitialize_POWatchdog;
        }
      }

      result = hil_watchdog_set_pwm_expiration_state
        (helicopter_lab3_2020b_DW.HILInitialize_Card,
         helicopter_lab3_2020b_P.HILInitialize_POChannels, 8U,
         &helicopter_lab3_2020b_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helicopter_lab3_2020b_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_encoder_timebase_block): '<S4>/HIL Read Encoder Timebase' */

  /* S-Function Block: helicopter_lab3_2020b/Helicopter_interface/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
  {
    t_error result;
    result = hil_task_create_encoder_reader
      (helicopter_lab3_2020b_DW.HILInitialize_Card,
       helicopter_lab3_2020b_P.HILReadEncoderTimebase_SamplesI,
       helicopter_lab3_2020b_P.HILReadEncoderTimebase_Channels, 3,
       &helicopter_lab3_2020b_DW.HILReadEncoderTimebase_Task);
    if (result >= 0) {
      result = hil_task_set_buffer_overflow_mode
        (helicopter_lab3_2020b_DW.HILReadEncoderTimebase_Task,
         (t_buffer_overflow_mode)
         (helicopter_lab3_2020b_P.HILReadEncoderTimebase_Overflow - 1));
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(helicopter_lab3_2020b_M, _rt_error_message);
    }
  }

  /* Start for FromWorkspace: '<Root>/From Workspace1' */
  {
    static real_T pTimeValues0[] = { 0.0, 0.25, 0.5, 0.75, 1.0, 1.25, 1.5, 1.75,
      2.0, 2.25, 2.5, 2.75, 3.0, 3.25, 3.5, 3.75, 4.0, 4.25, 4.5, 4.75, 5.0,
      5.25, 5.5, 5.75, 6.0, 6.25, 6.5, 6.75, 7.0, 7.25, 7.5, 7.75, 8.0, 8.25,
      8.5, 8.75, 9.0, 9.25, 9.5, 9.75, 10.0, 10.25, 10.5, 10.75, 11.0, 11.25,
      11.5, 11.75, 12.0, 12.25, 12.5, 12.75, 13.0, 13.25, 13.5, 13.75, 14.0,
      14.25, 14.5, 14.75, 15.0, 15.25, 15.5, 15.75, 16.0, 16.25, 16.5, 16.75,
      17.0, 17.25, 17.5, 17.75, 18.0, 18.25, 18.5, 18.75, 19.0, 19.25, 19.5,
      19.75, 20.0, 20.25, 20.5, 20.75, 21.0, 21.25, 21.5, 21.75, 22.0, 22.25,
      22.5, 22.75, 23.0, 23.25, 23.5, 23.75, 24.0, 24.25, 24.5, 24.75, 25.0,
      25.25, 25.5, 25.75, 26.0, 26.25, 26.5, 26.75, 27.0, 27.25, 27.5, 27.75,
      28.0, 28.25, 28.5, 28.75, 29.0, 29.25, 29.5, 29.75, 30.0, 30.25, 30.5,
      30.75, 31.0, 31.25, 31.5, 31.75, 32.0, 32.25, 32.5, 32.75, 33.0, 33.25,
      33.5, 33.75, 34.0, 34.25, 34.5, 34.75, 35.0 } ;

    static real_T pDataValues0[] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.52359877559828194,
      0.52359877559827528, 0.52359877559826173, 0.52359877559821955,
      0.5194166827909904, 0.4262213329543173, 0.34125694154422281,
      0.26423581866543644, 0.19483784691253347, 0.13271580481510858,
      0.07750095983285743, 0.028808607694806865, -0.013756659585992592,
      -0.050596085249001554, -0.0821123457722373, -0.10870564186062759,
      -0.1307702832895854, -0.14869175257906131, -0.16284422301986046,
      -0.17358850125754027, -0.18127036196361718, -0.18621924112798244,
      -0.18874725457919278, -0.18914850909294906, -0.18769867463688789,
      -0.18465478776281535, -0.1802552577914508, -0.174720049169361,
      -0.16825101516429969, -0.16103235986859443, -0.15323120727461931,
      -0.14499825795204385, -0.13646851557823048, -0.12776206723897038,
      -0.11898490301746795, -0.11022976191800071, -0.10157699262171005,
      -0.093095418941759156, -0.084843201131199142, -0.076868685398032155,
      -0.069211235097870971, -0.061902038105846935, -0.054964885817306963,
      -0.048416920093334426, -0.042269345254653368, -0.0365281029389381,
      -0.031194508275180721, -0.02626584639806262, -0.021735928828949147,
      -0.017595609692002689, -0.013833262117932787, -0.010435215518017071,
      -0.007386154691203739, -0.00466948196124406, -0.0022676437327558974,
      -0.00016242300860369596, 0.0016648004703652131, 0.0032328207149107113,
      0.0045604047987636287, 0.0056661191498701413, 0.0065681809672097913,
      0.0072843329155695136, 0.00783173927385239, 0.0082269017497612618,
      0.0084855932227608788, 0.0086228077360318567, 0.00865272512476678,
      0.0085886887409020174, 0.0084431948116568956, 0.0082278920496456909,
      0.0079535902145581039, 0.0076302764093382214, 0.0072671379763743493,
      0.0068725909405057406, 0.0064543130247419755, 0.0060192803405600959,
      0.0055738069264644752, 0.0051235863748673172, 0.004673734846476596,
      0.0042288348205262727, 0.0037929789640298583, 0.0033698135167858911,
      0.0029625805697552909, 0.0025741585442212722, 0.00220710002834823,
      0.0018636658498339953, 0.0015458537866872568, 0.0012554195361247356,
      0.00099388632315144942, 0.00076253763923428419, 0.00056238484280601853,
      0.00039409759566910729, 0.00025788058486575505, 0.00015327596779657338,
      7.8871365684851646E-5, 3.1907920476248464E-5, 7.8350905065027732E-6,
      1.1102230246251565E-16, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
      3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
      3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
      3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
      3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
      3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
      3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
      3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
      3.1378421413624995, 3.126215553457028, 3.1033093000459195,
      3.0666274152161797, 3.0144838785683463, 2.9464466510036309,
      2.8631591064663517, 2.7660113466105383, 2.6568349568948815,
      2.5376691526856678, 2.4105985175307705, 2.2776480115650233,
      2.1407193973528522, 2.0015559422486562, 1.8617257066063551,
      1.7226167048911654, 1.5854394626964761, 1.4512340544221787,
      1.3208797513370267, 1.1951060900878421, 1.074504606206252,
      0.95954075251971449, 0.8505656956761154, 0.74782779367667451,
      0.65148362731831277, 0.56160850396949114, 0.47820638242901631,
      0.40121918846891957, 0.33053550553081074, 0.26599863598205031,
      0.20741403666404923, 0.15455613892527142, 0.10717456843224347,
      0.064999784072193909, 0.027748158463737953, -0.0048734749703651745,
      -0.033163781542760458, -0.057423363301682115, -0.077951646471631733,
      -0.095044188846033176, -0.10899037750173753, -0.12007148740954353,
      -0.12855907192474303, -0.13471365681713732, -0.1387837103187459,
      -0.1410048626740967, -0.14159934978991842, -0.14077565677444134,
      -0.13872833846383439, -0.13563799533216334, -0.13167138457536526,
      -0.12698164750388832, -0.121708635780935, -0.1159793203818953,
      -0.10990826850219018, -0.10359817492698162, -0.097140435655903884,
      -0.09061575276736912, -0.084094760677943137, -0.077638665043810173,
      -0.071299886600634757, -0.065122703207152535, -0.059143884280626668,
      -0.05339331265744314, -0.047894589702099019, -0.042665620219541109,
      -0.037719174378547833, -0.033063424471936775, -0.028702454879971352,
      -0.024636744099234453, -0.020863618140412477, -0.017377674989228688,
      -0.014171180169028519, -0.011234433743831788, -0.0085561093591320376,
      -0.0061235661379734, -0.0039231344337674308, -0.0019403765929928039,
      -0.00016032400051209142, 0.0014323082271121305, 0.002852927469614634,
      0.0041168892806905171, 0.00523934102659437, 0.0062350820029957741,
      0.0071184385789220027, 0.00790315297543363, 0.0086022843812655365,
      0.0092281212483612072, 0.0097921038187572477, 0.010304756241235669,
      0.010775628090826836, 0.011213245778331273, 0.011625075324914851,
      0.012017499392319055, 0.012395813393543852, 0.01276424792456389,
      0.013126027211008775, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, -0.01500204895139973, -0.046506351592452845,
      -0.091625013625330584, -0.14672753927683657, -0.20857414663420343,
      -0.27214891026332139, -0.33315017812281272, -0.38859103942110673,
      -0.43670555884449369, -0.4766632168217449, -0.50828254060870826,
      -0.531802023858157, -0.547714456868475, -0.55665382040236655,
      -0.55932094258838927, -0.55643600686240213, -0.54870896875561159,
      -0.53682163312434072, -0.52141721235370975, -0.50309464499800438,
      -0.48240593553751993, -0.45985541474336522, -0.43590022737250111,
      -0.4109516079994131, -0.38537666543178883, -0.35950049339557211,
      -0.33360848616347455, -0.307948775840952, -0.2827347317530266,
      -0.25814747819598483, -0.23433839727102618, -0.21143159095352368,
      -0.18952628197480687, -0.16869913743951387, -0.1490065024336461,
      -0.13048653373500727, -0.11316122629096875, -0.097038327031839108,
      -0.082113132682492554, -0.068370169500521313, -0.055784754623350967,
      -0.044324439626032434, -0.033950338062095096, -0.024618339567188164,
      -0.016280214007880975, -0.0088846094236836159, -0.0023779484620788829,
      0.0032947720626867317, 0.00818927324143702, 0.012361372525450188,
      0.015866443028979514, 0.018758948283158529, 0.021092046893246452,
      0.022917261594747471, 0.024284207520056594, 0.025240374300627935,
      0.025830957085215683, 0.026098731555026115, 0.026083968357143831,
      0.025824382536517226, 0.025355113772359623, 0.024708733575079134,
      0.023915275705582512, 0.023002286492834156, 0.021994891821279235,
      0.02091587793041055, 0.01978578336427185, 0.018622999626282114,
      0.017443878368118917, 0.016262843122924246, 0.015092503835386515,
      0.013943772604751667, 0.01282597928081919, 0.011746985700807486,
      0.010713297538730232, 0.0097301728847082516, 0.0088017268167542191,
      0.0079310313630790823, 0.0071202103698767352, 0.0063705289105179374,
      0.0056824769698618589, 0.0050558472443517667, 0.0044898069836122123,
      0.0039829639055091745, 0.0035334263038438157, 0.0031388575860927079,
      0.0027965256233508278, 0.0025033474683446629, 0.0022559302815765856,
      0.0020506096899339152, 0.0018834873983683395, 0.0017504707500005379,
      0.0016473181863389823, 0.00156969626961667, 0.0015132560049026112,
      0.0014737381240742132, 0.0014471171457779485, 0.0014297882285997288, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.10602875202586681,
      0.22266037936328542, 0.31888147185571836, 0.38944360634383024,
      0.43710820000476791, 0.44932214901122325, 0.43113366407404619,
      0.39183483368711869, 0.340055047660919, 0.28240546573334269,
      0.22347330473930571, 0.16622672488726931, 0.11246299913335756,
      0.06318000749774566, 0.01885020100599355, -0.02038962366417485,
      -0.054611754192502193, -0.084015148362118763, -0.10887256270477785,
      -0.12949690809997161, -0.14621989699927146, -0.15937846832038211,
      -0.16930611536213352, -0.17632731332242019, -0.18075392637348814,
      -0.18288290125095541, -0.18299481835192943, -0.18135303251521134,
      -0.1782032337857623, -0.1737733177028552, -0.16827349072450526,
      -0.16189655842651351, -0.15481835772789115, -0.14719830319195487,
      -0.13918002315908151, -0.13089206554591221, -0.12244865610188116,
      -0.11395049422067322, -0.10548557339793502, -0.097130015031694772,
      -0.088948905686507762, -0.080997129426336467, -0.073320187778213253,
      -0.0659550012202379, -0.058930686956808587, -0.052269308626128441,
      -0.04598659460954968, -0.040092622104179909, -0.034592465030365671,
      -0.029486804309911185, -0.024772499647084556, -0.02044312245257407,
      -0.01648944987833767, -0.0128999204202227, -0.0096610517314827948,
      -0.006757821636161343, -0.0041740135552577051, -0.0018925276719770068,
      0.00010434063442743557, 0.0018346534454329877, 0.0033166123948948911,
      0.00456836838249397, 0.005607857174465436, 0.0064526590603517509,
      0.0071198807989085733, 0.0076260580795561861, 0.007987076783709357,
      0.0082181113630909186, 0.0083335787217291291, 0.00834710604658151,
      0.0082715111063965674, 0.0081187936108444436, 0.0079001363024416849,
      0.0076259145308515963, 0.0073057131399808517, 0.0069483495773038362,
      0.006561902212866233, 0.0061537429279200362, 0.0057305731076559008,
      0.0052984622339101728, 0.0048628883325574357, 0.0044287795771785765,
      0.0040005563795676435, 0.0035821733006075052, 0.0031771600815103662,
      0.0027886610008401869, 0.0024194715679507484, 0.0020720712281214748,
      0.0017486501820395128, 0.0014511275257208522, 0.0011811565288804005,
      0.00094011086835321667, 0.00072904292365272294, 0.00054860206181539528,
      0.00039889823514394074, 0.00027929728885145444, 0.00018814690743407247,
      0.00012247416830002411, 7.78071456312146E-5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.42411500823414633, 0.46652650905901288,
      0.38488436998610709, 0.28224853794913091, 0.19065837464586979,
      0.04885579603002075, -0.072753939748445073, -0.15719532154591129,
      -0.20711914405351434, -0.23059832779170503, -0.23572864392589052,
      -0.22898631940194006, -0.21505490304469604, -0.197131966510427,
      -0.17731922602876998, -0.15695929858426952, -0.13688852213583491,
      -0.11761357663616236, -0.099429657412183181, -0.082497381592692209,
      -0.066891955563879626, -0.052634285309283511, -0.039710588171886427,
      -0.028084791843897953, -0.017706452198557182, -0.008515899516857911,
      -0.00044766840117617553, 0.0065671433468056815, 0.012599194916575306,
      0.017719664335699738, 0.021999307907684677, 0.025507729189145636,
      0.028312802788532522, 0.030480218140911307, 0.032073120129869521,
      0.033151830443513074, 0.033773637779191533, 0.033992647528028011,
      0.033859683279077978, 0.033422233472959771, 0.032724437370645565,
      0.03180710504688411, 0.030707766599767053, 0.029460746220174021,
      0.028097257065092453, 0.026645513315105944, 0.025130856064047122,
      0.023575890012526114, 0.022000628282796229, 0.020422642882530876,
      0.01885721864748079, 0.017317508786365798, 0.01581469029338629,
      0.014358117826602642, 0.012955474760476985, 0.011612920379691676,
      0.010335232321552798, 0.00912594353640389, 0.0079874732207954047,
      0.0069212512474965543, 0.0059278357946079925, 0.0050070239501686566,
      0.0041579551673453308, 0.0033792075442312585, 0.0026688869536165647,
      0.0020247091225494003, 0.0014440748162795869, 0.00092413831737148035,
      0.00046186943437163437, 5.4109299537084054E-5, -0.00030237976084943632,
      -0.00061086998228577659, -0.00087462923355567277, -0.0010968870863330912,
      -0.00128080556357008, -0.0014294542505038381, -0.0015457894580018009,
      -0.0016326371398209583, -0.0016926792807672854, -0.0017284434950319619,
      -0.0017422956058736837, -0.0017364350215223858, -0.0017128927900137978,
      -0.0016735323157322502, -0.0016200528760768847, -0.0015539963227453417,
      -0.0014767577311007671, -0.0013896013595128393, -0.0012936841842707866,
      -0.0011900906254130703, -0.0010798839873305732, -0.00096418264206948358,
      -0.00084427177885346377, -0.00072176344733724466, -0.00059881530668724216,
      -0.00047840378515175039, -0.00036460152566951458, -0.00026269095653636335,
      -0.00017866809067534857, -0.0001170708853905544, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0
    } ;

    helicopter_lab3_2020b_DW.FromWorkspace1_PWORK.TimePtr = (void *)
      pTimeValues0;
    helicopter_lab3_2020b_DW.FromWorkspace1_PWORK.DataPtr = (void *)
      pDataValues0;
    helicopter_lab3_2020b_DW.FromWorkspace1_IWORK.PrevIndex = 0;
  }

  /* Start for If: '<S3>/If' */
  helicopter_lab3_2020b_DW.If_ActiveSubsystem = -1;

  /* InitializeConditions for TransferFcn: '<S4>/Travel: Transfer Fcn' */
  helicopter_lab3_2020b_X.TravelTransferFcn_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S4>/Pitch: Transfer Fcn' */
  helicopter_lab3_2020b_X.PitchTransferFcn_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S4>/Elevation: Transfer Fcn' */
  helicopter_lab3_2020b_X.ElevationTransferFcn_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S3>/Integrator' */
  helicopter_lab3_2020b_X.Integrator_CSTATE =
    helicopter_lab3_2020b_P.Integrator_IC;

  /* InitializeConditions for Derivative: '<S4>/Derivative' */
  helicopter_lab3_2020b_DW.TimeStampA = (rtInf);
  helicopter_lab3_2020b_DW.TimeStampB = (rtInf);
}

/* Model terminate function */
void helicopter_lab3_2020b_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: helicopter_lab3_2020b/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    hil_task_stop_all(helicopter_lab3_2020b_DW.HILInitialize_Card);
    hil_monitor_stop_all(helicopter_lab3_2020b_DW.HILInitialize_Card);
    is_switching = false;
    if ((helicopter_lab3_2020b_P.HILInitialize_AOTerminate && !is_switching) ||
        (helicopter_lab3_2020b_P.HILInitialize_AOExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages =
          &helicopter_lab3_2020b_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = helicopter_lab3_2020b_P.HILInitialize_AOFinal;
        }
      }

      num_final_analog_outputs = 8U;
    } else {
      num_final_analog_outputs = 0;
    }

    if ((helicopter_lab3_2020b_P.HILInitialize_POTerminate && !is_switching) ||
        (helicopter_lab3_2020b_P.HILInitialize_POExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &helicopter_lab3_2020b_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = helicopter_lab3_2020b_P.HILInitialize_POFinal;
        }
      }

      num_final_pwm_outputs = 8U;
    } else {
      num_final_pwm_outputs = 0;
    }

    if (0
        || num_final_analog_outputs > 0
        || num_final_pwm_outputs > 0
        ) {
      /* Attempt to write the final outputs atomically (due to firmware issue in old Q2-USB). Otherwise write channels individually */
      result = hil_write(helicopter_lab3_2020b_DW.HILInitialize_Card
                         , helicopter_lab3_2020b_P.HILInitialize_AOChannels,
                         num_final_analog_outputs
                         , helicopter_lab3_2020b_P.HILInitialize_POChannels,
                         num_final_pwm_outputs
                         , NULL, 0
                         , NULL, 0
                         , &helicopter_lab3_2020b_DW.HILInitialize_AOVoltages[0]
                         , &helicopter_lab3_2020b_DW.HILInitialize_POValues[0]
                         , (t_boolean *) NULL
                         , NULL
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog
            (helicopter_lab3_2020b_DW.HILInitialize_Card,
             helicopter_lab3_2020b_P.HILInitialize_AOChannels,
             num_final_analog_outputs,
             &helicopter_lab3_2020b_DW.HILInitialize_AOVoltages[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm
            (helicopter_lab3_2020b_DW.HILInitialize_Card,
             helicopter_lab3_2020b_P.HILInitialize_POChannels,
             num_final_pwm_outputs,
             &helicopter_lab3_2020b_DW.HILInitialize_POValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(helicopter_lab3_2020b_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(helicopter_lab3_2020b_DW.HILInitialize_Card);
    hil_monitor_delete_all(helicopter_lab3_2020b_DW.HILInitialize_Card);
    hil_close(helicopter_lab3_2020b_DW.HILInitialize_Card);
    helicopter_lab3_2020b_DW.HILInitialize_Card = NULL;
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  helicopter_lab3_2020b_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  helicopter_lab3_2020b_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  helicopter_lab3_2020b_initialize();
}

void MdlTerminate(void)
{
  helicopter_lab3_2020b_terminate();
}

/* Registration function */
RT_MODEL_helicopter_lab3_2020_T *helicopter_lab3_2020b(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  helicopter_lab3_2020b_P.Integrator_UpperSat = rtInf;
  helicopter_lab3_2020b_P.Integrator_LowerSat = rtMinusInf;

  /* initialize real-time model */
  (void) memset((void *)helicopter_lab3_2020b_M, 0,
                sizeof(RT_MODEL_helicopter_lab3_2020_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&helicopter_lab3_2020b_M->solverInfo,
                          &helicopter_lab3_2020b_M->Timing.simTimeStep);
    rtsiSetTPtr(&helicopter_lab3_2020b_M->solverInfo, &rtmGetTPtr
                (helicopter_lab3_2020b_M));
    rtsiSetStepSizePtr(&helicopter_lab3_2020b_M->solverInfo,
                       &helicopter_lab3_2020b_M->Timing.stepSize0);
    rtsiSetdXPtr(&helicopter_lab3_2020b_M->solverInfo,
                 &helicopter_lab3_2020b_M->derivs);
    rtsiSetContStatesPtr(&helicopter_lab3_2020b_M->solverInfo, (real_T **)
                         &helicopter_lab3_2020b_M->contStates);
    rtsiSetNumContStatesPtr(&helicopter_lab3_2020b_M->solverInfo,
      &helicopter_lab3_2020b_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&helicopter_lab3_2020b_M->solverInfo,
      &helicopter_lab3_2020b_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&helicopter_lab3_2020b_M->solverInfo,
      &helicopter_lab3_2020b_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&helicopter_lab3_2020b_M->solverInfo,
      &helicopter_lab3_2020b_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&helicopter_lab3_2020b_M->solverInfo,
                          (&rtmGetErrorStatus(helicopter_lab3_2020b_M)));
    rtsiSetRTModelPtr(&helicopter_lab3_2020b_M->solverInfo,
                      helicopter_lab3_2020b_M);
  }

  rtsiSetSimTimeStep(&helicopter_lab3_2020b_M->solverInfo, MAJOR_TIME_STEP);
  helicopter_lab3_2020b_M->intgData.f[0] = helicopter_lab3_2020b_M->odeF[0];
  helicopter_lab3_2020b_M->contStates = ((real_T *) &helicopter_lab3_2020b_X);
  rtsiSetSolverData(&helicopter_lab3_2020b_M->solverInfo, (void *)
                    &helicopter_lab3_2020b_M->intgData);
  rtsiSetSolverName(&helicopter_lab3_2020b_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = helicopter_lab3_2020b_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    helicopter_lab3_2020b_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    helicopter_lab3_2020b_M->Timing.sampleTimes =
      (&helicopter_lab3_2020b_M->Timing.sampleTimesArray[0]);
    helicopter_lab3_2020b_M->Timing.offsetTimes =
      (&helicopter_lab3_2020b_M->Timing.offsetTimesArray[0]);

    /* task periods */
    helicopter_lab3_2020b_M->Timing.sampleTimes[0] = (0.0);
    helicopter_lab3_2020b_M->Timing.sampleTimes[1] = (0.002);

    /* task offsets */
    helicopter_lab3_2020b_M->Timing.offsetTimes[0] = (0.0);
    helicopter_lab3_2020b_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(helicopter_lab3_2020b_M, &helicopter_lab3_2020b_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = helicopter_lab3_2020b_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    helicopter_lab3_2020b_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(helicopter_lab3_2020b_M, -1);
  helicopter_lab3_2020b_M->Timing.stepSize0 = 0.002;
  helicopter_lab3_2020b_M->Timing.stepSize1 = 0.002;

  /* External mode info */
  helicopter_lab3_2020b_M->Sizes.checksums[0] = (2229608993U);
  helicopter_lab3_2020b_M->Sizes.checksums[1] = (159428610U);
  helicopter_lab3_2020b_M->Sizes.checksums[2] = (2807834029U);
  helicopter_lab3_2020b_M->Sizes.checksums[3] = (201135519U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    helicopter_lab3_2020b_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)
      &helicopter_lab3_2020b_DW.IfActionSubsystem_SubsysRanBC;
    rteiSetModelMappingInfoPtr(helicopter_lab3_2020b_M->extModeInfo,
      &helicopter_lab3_2020b_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(helicopter_lab3_2020b_M->extModeInfo,
                        helicopter_lab3_2020b_M->Sizes.checksums);
    rteiSetTPtr(helicopter_lab3_2020b_M->extModeInfo, rtmGetTPtr
                (helicopter_lab3_2020b_M));
  }

  helicopter_lab3_2020b_M->solverInfoPtr = (&helicopter_lab3_2020b_M->solverInfo);
  helicopter_lab3_2020b_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&helicopter_lab3_2020b_M->solverInfo, 0.002);
  rtsiSetSolverMode(&helicopter_lab3_2020b_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  helicopter_lab3_2020b_M->blockIO = ((void *) &helicopter_lab3_2020b_B);

  {
    int32_T i;
    for (i = 0; i < 5; i++) {
      helicopter_lab3_2020b_B.FromWorkspace1[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      helicopter_lab3_2020b_B.Gain1[i] = 0.0;
    }

    for (i = 0; i < 12; i++) {
      helicopter_lab3_2020b_B.TmpSignalConversionAtToWorkspac[i] = 0.0;
    }

    helicopter_lab3_2020b_B.TravelCounttorad = 0.0;
    helicopter_lab3_2020b_B.Gain = 0.0;
    helicopter_lab3_2020b_B.Sum3 = 0.0;
    helicopter_lab3_2020b_B.Gain_d = 0.0;
    helicopter_lab3_2020b_B.PitchCounttorad = 0.0;
    helicopter_lab3_2020b_B.Gain_i = 0.0;
    helicopter_lab3_2020b_B.Gain_b = 0.0;
    helicopter_lab3_2020b_B.ElevationCounttorad = 0.0;
    helicopter_lab3_2020b_B.Gain_e = 0.0;
    helicopter_lab3_2020b_B.Sum = 0.0;
    helicopter_lab3_2020b_B.Gain_dg = 0.0;
    helicopter_lab3_2020b_B.Sum3_b = 0.0;
    helicopter_lab3_2020b_B.Gain_l = 0.0;
    helicopter_lab3_2020b_B.BackmotorSaturation = 0.0;
    helicopter_lab3_2020b_B.FrontmotorSaturation = 0.0;
    helicopter_lab3_2020b_B.In1 = 0.0;
  }

  /* parameters */
  helicopter_lab3_2020b_M->defaultParam = ((real_T *)&helicopter_lab3_2020b_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &helicopter_lab3_2020b_X;
    helicopter_lab3_2020b_M->contStates = (x);
    (void) memset((void *)&helicopter_lab3_2020b_X, 0,
                  sizeof(X_helicopter_lab3_2020b_T));
  }

  /* states (dwork) */
  helicopter_lab3_2020b_M->dwork = ((void *) &helicopter_lab3_2020b_DW);
  (void) memset((void *)&helicopter_lab3_2020b_DW, 0,
                sizeof(DW_helicopter_lab3_2020b_T));

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      helicopter_lab3_2020b_DW.HILInitialize_AIMinimums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      helicopter_lab3_2020b_DW.HILInitialize_AIMaximums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      helicopter_lab3_2020b_DW.HILInitialize_AOMinimums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      helicopter_lab3_2020b_DW.HILInitialize_AOMaximums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      helicopter_lab3_2020b_DW.HILInitialize_AOVoltages[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      helicopter_lab3_2020b_DW.HILInitialize_FilterFrequency[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      helicopter_lab3_2020b_DW.HILInitialize_POSortedFreqs[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      helicopter_lab3_2020b_DW.HILInitialize_POValues[i] = 0.0;
    }
  }

  helicopter_lab3_2020b_DW.TimeStampA = 0.0;
  helicopter_lab3_2020b_DW.LastUAtTimeA = 0.0;
  helicopter_lab3_2020b_DW.TimeStampB = 0.0;
  helicopter_lab3_2020b_DW.LastUAtTimeB = 0.0;
  helicopter_lab3_2020b_DW.HILWriteAnalog_Buffer[0] = 0.0;
  helicopter_lab3_2020b_DW.HILWriteAnalog_Buffer[1] = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    helicopter_lab3_2020b_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 18;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  helicopter_lab3_2020b_M->Sizes.numContStates = (4);/* Number of continuous states */
  helicopter_lab3_2020b_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  helicopter_lab3_2020b_M->Sizes.numY = (0);/* Number of model outputs */
  helicopter_lab3_2020b_M->Sizes.numU = (0);/* Number of model inputs */
  helicopter_lab3_2020b_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  helicopter_lab3_2020b_M->Sizes.numSampTimes = (2);/* Number of sample times */
  helicopter_lab3_2020b_M->Sizes.numBlocks = (64);/* Number of blocks */
  helicopter_lab3_2020b_M->Sizes.numBlockIO = (19);/* Number of block outputs */
  helicopter_lab3_2020b_M->Sizes.numBlockPrms = (149);/* Sum of parameter "widths" */
  return helicopter_lab3_2020b_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
