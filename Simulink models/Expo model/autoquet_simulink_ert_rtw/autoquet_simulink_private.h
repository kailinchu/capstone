/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: autoquet_simulink_private.h
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

#ifndef RTW_HEADER_autoquet_simulink_private_h_
#define RTW_HEADER_autoquet_simulink_private_h_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "autoquet_simulink_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#ifdef __cplusplus
#define SFB_EXTERN_C                   extern "C"
#else
#define SFB_EXTERN_C                   extern
#endif

SFB_EXTERN_C void clock_counter_Start_wrapper(void);
SFB_EXTERN_C void clock_counter_Outputs_wrapper(uint8_T *my_time,
  uint32_T *ticks);
SFB_EXTERN_C void clock_counter_Terminate_wrapper(void);

#undef SFB_EXTERN_C
#ifdef __cplusplus
#define SFB_EXTERN_C                   extern "C"
#else
#define SFB_EXTERN_C                   extern
#endif

SFB_EXTERN_C void button_control_logic_Start_wrapper(void);
SFB_EXTERN_C void button_control_logic_Outputs_wrapper(const boolean_T
  *button_signals,
  const uint32_T *time,
  const real32_T *auto_pressure_setpoint,
  const uint8_T *initial_search,
  real32_T *pressure_set_point,
  uint8_T *roughness,
  uint8_T *operation_mode);
SFB_EXTERN_C void button_control_logic_Terminate_wrapper(void);

#undef SFB_EXTERN_C
#ifdef __cplusplus
#define SFB_EXTERN_C                   extern "C"
#else
#define SFB_EXTERN_C                   extern
#endif

SFB_EXTERN_C void motor_drive_control_Start_wrapper(void);
SFB_EXTERN_C void motor_drive_control_Outputs_wrapper(const real32_T
  *limb_pressure_diff,
  const boolean_T *pause_summation,
  const uint8_T *initial_search,
  real32_T *inflation_state,
  boolean_T *motor_active,
  boolean_T *solenoid_state);
SFB_EXTERN_C void motor_drive_control_Terminate_wrapper(void);

#undef SFB_EXTERN_C
#ifdef __cplusplus
#define SFB_EXTERN_C                   extern "C"
#else
#define SFB_EXTERN_C                   extern
#endif

SFB_EXTERN_C void dec_to_sev_seg_Start_wrapper(void);
SFB_EXTERN_C void dec_to_sev_seg_Outputs_wrapper(const uint8_T *time_input,
  uint8_T *binary_time);
SFB_EXTERN_C void dec_to_sev_seg_Terminate_wrapper(void);

#undef SFB_EXTERN_C
#ifdef __cplusplus
#define SFB_EXTERN_C                   extern "C"
#else
#define SFB_EXTERN_C                   extern
#endif

SFB_EXTERN_C void pressure_display_Start_wrapper(void);
SFB_EXTERN_C void pressure_display_Outputs_wrapper(const real32_T
  *set_point_pressure,
  uint8_T *digit_array);
SFB_EXTERN_C void pressure_display_Terminate_wrapper(void);

#undef SFB_EXTERN_C
#ifdef __cplusplus
#define SFB_EXTERN_C                   extern "C"
#else
#define SFB_EXTERN_C                   extern
#endif

SFB_EXTERN_C void display_pressures_signal_Start_wrapper(void);
SFB_EXTERN_C void display_pressures_signal_Outputs_wrapper(const uint8_T
  *pressure_display_input,
  const real32_T *pressure_set_point,
  const uint8_T *operation_state,
  const uint32_T *time,
  uint8_T *display_pressure_signal);
SFB_EXTERN_C void display_pressures_signal_Terminate_wrapper(void);

#undef SFB_EXTERN_C
#ifdef __cplusplus
#define SFB_EXTERN_C                   extern "C"
#else
#define SFB_EXTERN_C                   extern
#endif

SFB_EXTERN_C void process_raw_sensor_reading_Start_wrapper(void);
SFB_EXTERN_C void process_raw_sensor_reading_Outputs_wrapper(const uint8_T
  *raw_sensor_input,
  real32_T *limb_pressure_mmhg);
SFB_EXTERN_C void process_raw_sensor_reading_Terminate_wrapper(void);

#undef SFB_EXTERN_C
#ifdef __cplusplus
#define SFB_EXTERN_C                   extern "C"
#else
#define SFB_EXTERN_C                   extern
#endif

SFB_EXTERN_C void custom_demux_Start_wrapper(void);
SFB_EXTERN_C void custom_demux_Outputs_wrapper(const real32_T *combined_vector,
  real32_T *filtered_pressure,
  real32_T *filtered_acceleration);
SFB_EXTERN_C void custom_demux_Terminate_wrapper(void);

#undef SFB_EXTERN_C
#ifdef __cplusplus
#define SFB_EXTERN_C                   extern "C"
#else
#define SFB_EXTERN_C                   extern
#endif

SFB_EXTERN_C void limb_movement_detector_Start_wrapper(void);
SFB_EXTERN_C void limb_movement_detector_Outputs_wrapper(const real32_T
  *limb_acceleration,
  const uint16_T *accel_threshold,
  boolean_T *movement_boolean);
SFB_EXTERN_C void limb_movement_detector_Terminate_wrapper(void);

#undef SFB_EXTERN_C
#ifdef __cplusplus
#define SFB_EXTERN_C                   extern "C"
#else
#define SFB_EXTERN_C                   extern
#endif

SFB_EXTERN_C void disruption_activity_monitor_Start_wrapper(void);
SFB_EXTERN_C void disruption_activity_monitor_Outputs_wrapper(const boolean_T
  *motor_active,
  const boolean_T *movement_detected,
  const uint32_T *time,
  const uint16_T *pause_time,
  boolean_T *pause_summation);
SFB_EXTERN_C void disruption_activity_monitor_Terminate_wrapper(void);

#undef SFB_EXTERN_C
#ifdef __cplusplus
#define SFB_EXTERN_C                   extern "C"
#else
#define SFB_EXTERN_C                   extern
#endif

SFB_EXTERN_C void blood_flow_detector_2_Start_wrapper(void);
SFB_EXTERN_C void blood_flow_detector_2_Outputs_wrapper(const real32_T *u0,
  const boolean_T *disruption_active,
  const uint16_T *bloodflow_threshold,
  uint16_T *y0,
  boolean_T *bloodflow_boolean);
SFB_EXTERN_C void blood_flow_detector_2_Terminate_wrapper(void);

#undef SFB_EXTERN_C
#endif                             /* RTW_HEADER_autoquet_simulink_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
