/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: send_params_private.h
 *
 * Code generated for Simulink model 'autoquet_simulink_expo_model'.
 *
 * Model version                  : 1.531
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Tue Mar 17 21:09:22 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_send_params_private_h_
#define RTW_HEADER_send_params_private_h_
#ifndef autoquet_simulink_expo_model_COMMON_INCLUDES_
#define autoquet_simulink_expo_model_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "string.h"
#include "MW_arduino_digitalio.h"
#include "MW_I2C.h"
#include "io_wrappers.h"
#include "MW_PWM.h"
#include "MW_SerialRead.h"
#include "MW_SerialWrite.h"
#endif                       /* autoquet_simulink_expo_model_COMMON_INCLUDES_ */

extern void send_params_Init(void);
extern void send_params_Term(void);

#endif                                 /* RTW_HEADER_send_params_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
