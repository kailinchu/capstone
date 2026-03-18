/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: autoquet_simulink_data.c
 *
 * Code generated for Simulink model 'autoquet_simulink'.
 *
 * Model version                  : 1.432
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sun Mar 15 19:28:19 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "autoquet_simulink.h"

/* Block parameters (default storage) */
P_autoquet_simulink_T autoquet_simulink_P = {
  /* Mask Parameter: BNO055IMUSensor_SampleTime
   * Referenced by: '<S10>/Base sensor block'
   */
  0.1,

  /* Expression: 0
   * Referenced by: '<S3>/Serial Transmit'
   */
  0.0,

  /* Expression: 0.1
   * Referenced by: '<S4>/Automode signal input'
   */
  0.1,

  /* Expression: 0.1
   * Referenced by: '<S4>/Decrease signal input'
   */
  0.1,

  /* Expression: 0.1
   * Referenced by: '<S4>/I2C Read1'
   */
  0.1,

  /* Expression: 0.1
   * Referenced by: '<S4>/Increase signal input'
   */
  0.1,

  /* Expression: 1
   * Referenced by: '<Root>/Pulse Generator'
   */
  1.0,

  /* Expression: 100
   * Referenced by: '<Root>/Pulse Generator'
   */
  100.0,

  /* Expression: 50
   * Referenced by: '<Root>/Pulse Generator'
   */
  50.0,

  /* Expression: 0
   * Referenced by: '<Root>/Pulse Generator'
   */
  0.0,

  /* Computed Parameter: Initial_pressure_start_Value
   * Referenced by: '<Root>/Initial_pressure_start'
   */
  300.0F,

  /* Computed Parameter: Bulkincrement_Value
   * Referenced by: '<Root>/Bulk increment'
   */
  100.0F,

  /* Computed Parameter: Waitperiodseconds_Value
   * Referenced by: '<Root>/Wait period (seconds)'
   */
  1.5F,

  /* Computed Parameter: Pressureresolution_Value
   * Referenced by: '<Root>/Pressure resolution'
   */
  100.0F,

  /* Computed Parameter: DigitalFilter_InitialStates
   * Referenced by: '<S7>/Digital Filter'
   */
  0.0F,

  /* Computed Parameter: DigitalFilter_Coefficients
   * Referenced by: '<S7>/Digital Filter'
   */
  { -0.102863595F, 0.0106300144F, 0.537576675F, 0.537576675F, 0.0106300144F,
    -0.102863595F },

  /* Computed Parameter: DigitalFilter_InitialStates_p
   * Referenced by: '<S6>/Digital Filter'
   */
  0.0F,

  /* Computed Parameter: DigitalFilter_Coefficients_l
   * Referenced by: '<S6>/Digital Filter'
   */
  { 0.276920557F, -0.284487218F, -0.65590167F, 0.65590167F, 0.284487218F,
    -0.276920557F },

  /* Computed Parameter: bloodflow_threshold_Value
   * Referenced by: '<S2>/bloodflow_threshold'
   */
  600U,

  /* Computed Parameter: accel_threshold_Value
   * Referenced by: '<S2>/accel_threshold'
   */
  60U,

  /* Computed Parameter: pausetimemsec_Value
   * Referenced by: '<S2>/pause time (msec)'
   */
  1000U,

  /* Expression: false
   * Referenced by: '<S5>/Chart'
   */
  false
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
