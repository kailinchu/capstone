/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: autoquet_simulink.c
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
#include "autoquet_simulink_types.h"
#include "rtwtypes.h"
#include <string.h>
#include <stddef.h>
#include "autoquet_simulink_private.h"
#include "zero_crossing_types.h"

/* Named constants for Chart: '<Root>/Blood flow control stateflow' */
#define IN_Binary_search_ideal_pressure ((uint8_T)1U)
#define IN_Decrease_pressure_set_point ((uint8_T)1U)
#define IN_Increase_pressure_set_point ((uint8_T)2U)
#define au_IN_Adjust_pressure_set_point ((uint8_T)1U)
#define autoque_IN_Ideal_pressure_found ((uint8_T)2U)
#define autoquet_IN_Find_initial_bounds ((uint8_T)2U)
#define autoquet_sim_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define autoquet_simuli_IN_Over_inflate ((uint8_T)3U)
#define autoquet_simulin_IN_Manual_mode ((uint8_T)2U)
#define autoquet_simulink_IN_Auto_mode ((uint8_T)1U)
#define autoquet_simulink_IN_Deflate   ((uint8_T)1U)
#define autoquet_simulink_IN_Idle      ((uint8_T)3U)
#define autoquet_simulink_IN_Idle_g    ((uint8_T)2U)
#define autoquet_simulink_IN_Idle_gx   ((uint8_T)1U)
#define autoquet_simulink_IN_Inflate   ((uint8_T)2U)
#define autoquet_simulink_IN_Too_loose ((uint8_T)4U)
#define autoquet_simulink_IN_Too_tight ((uint8_T)5U)
#define autoquet_simulink_IN_Wait      ((uint8_T)3U)
#define autoquet_simulink_IN_wait      ((uint8_T)3U)

/* Named constants for Chart: '<S5>/Chart' */
#define auto_IN_set_pressure_to_display ((uint8_T)5U)
#define autoque_IN_set_blank_to_display ((uint8_T)4U)
#define autoquet_IN_display_multiplexer ((uint8_T)1U)
#define autoquet_IN_set_time_to_display ((uint8_T)6U)
#define autoquet_si_IN_sending_firmware ((uint8_T)3U)
#define autoquet_sim_IN_display_control ((uint8_T)2U)
#define autoquet_simu_IN_data_directive ((uint8_T)1U)
#define autoquet_simu_IN_flashing_logic ((uint8_T)2U)
#define autoquet_simu_IN_post_ack_reset ((uint8_T)8U)
#define autoquet_simul_IN_transmit_data ((uint8_T)4U)
#define autoquet_simuli_IN_Start_signal ((uint8_T)1U)
#define autoquet_simuli_IN_buffer_reset ((uint8_T)2U)
#define autoquet_simuli_IN_command_flow ((uint8_T)3U)
#define autoquet_simuli_IN_find_command ((uint8_T)3U)
#define autoquet_simulink_IN_Stop      ((uint8_T)2U)
#define autoquet_simulink_IN_ack_bit   ((uint8_T)1U)
#define autoquet_simulink_IN_data_high ((uint8_T)3U)
#define autoquet_simulink_IN_data_low  ((uint8_T)4U)
#define autoquet_simulink_IN_idler     ((uint8_T)5U)
#define autoquet_simulink_IN_idler1    ((uint8_T)6U)
#define autoquet_simulink_IN_init      ((uint8_T)4U)
#define autoquet_simulink_IN_latch_data ((uint8_T)7U)
#define autoquet_simulink_IN_reset_clk ((uint8_T)9U)
#define autoquet_simulink_IN_send_data ((uint8_T)5U)

/* Block signals (default storage) */
B_autoquet_simulink_T autoquet_simulink_B;

/* Block states (default storage) */
DW_autoquet_simulink_T autoquet_simulink_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_autoquet_simulink_T autoquet_simulink_PrevZCX;

/* Real-time model */
static RT_MODEL_autoquet_simulink_T autoquet_simulink_M_;
RT_MODEL_autoquet_simulink_T *const autoquet_simulink_M = &autoquet_simulink_M_;

/* Forward declaration for local functions */
static void autoque_enter_atomic_latch_data(void);
static void autoque_exit_internal_send_data(void);
static void exit_internal_Find_initial_boun(void);
static void autoquet_simul_SystemCore_setup(codertarget_arduinobase_int_o_T *obj);
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void autoquet_simulink_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(autoquet_simulink_M, 1));
  eventFlags[2] = ((boolean_T)rtmStepTask(autoquet_simulink_M, 2));
  eventFlags[3] = ((boolean_T)rtmStepTask(autoquet_simulink_M, 3));
}

/*
 *         This function updates active task flag for each subrate
 *         and rate transition flags for tasks that exchange data.
 *         The function assumes rate-monotonic multitasking scheduler.
 *         The function must be called at model base rate so that
 *         the generated code self-manages all its subrates and rate
 *         transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (autoquet_simulink_M->Timing.TaskCounters.TID[1])++;
  if ((autoquet_simulink_M->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [0.001s, 0.0s] */
    autoquet_simulink_M->Timing.TaskCounters.TID[1] = 0;
  }

  (autoquet_simulink_M->Timing.TaskCounters.TID[2])++;
  if ((autoquet_simulink_M->Timing.TaskCounters.TID[2]) > 499) {/* Sample time: [0.05s, 0.0s] */
    autoquet_simulink_M->Timing.TaskCounters.TID[2] = 0;
  }

  (autoquet_simulink_M->Timing.TaskCounters.TID[3])++;
  if ((autoquet_simulink_M->Timing.TaskCounters.TID[3]) > 999) {/* Sample time: [0.1s, 0.0s] */
    autoquet_simulink_M->Timing.TaskCounters.TID[3] = 0;
  }
}

/* Function for Chart: '<S5>/Chart' */
static void autoque_enter_atomic_latch_data(void)
{
  uint16_T tmp;
  autoquet_simulink_B.clk_pin = true;
  autoquet_simulink_DW.buffer = (uint8_T)((uint16_T)autoquet_simulink_DW.buffer >>
    1);
  tmp = autoquet_simulink_DW.bit_iterator + 1U;
  if (autoquet_simulink_DW.bit_iterator + 1U > 255U) {
    tmp = 255U;
  }

  autoquet_simulink_DW.bit_iterator = (uint8_T)tmp;
}

/* Function for Chart: '<S5>/Chart' */
static void autoque_exit_internal_send_data(void)
{
  switch (autoquet_simulink_DW.is_send_data) {
   case autoquet_simulink_IN_ack_bit:
    autoquet_simulink_B.data_pin = false;
    autoquet_simulink_DW.is_send_data = autoquet_sim_IN_NO_ACTIVE_CHILD;
    break;

   case autoquet_simuli_IN_buffer_reset:
    autoquet_simulink_DW.bit_iterator = 1U;
    autoquet_simulink_DW.is_send_data = autoquet_sim_IN_NO_ACTIVE_CHILD;
    break;

   case autoquet_simulink_IN_idler:
    autoquet_simulink_B.clk_pin = false;
    autoquet_simulink_DW.is_send_data = autoquet_sim_IN_NO_ACTIVE_CHILD;
    break;

   case autoquet_simulink_IN_idler1:
    autoquet_simulink_B.clk_pin = true;
    autoquet_simulink_DW.is_send_data = autoquet_sim_IN_NO_ACTIVE_CHILD;
    break;

   default:
    autoquet_simulink_DW.is_send_data = autoquet_sim_IN_NO_ACTIVE_CHILD;
    break;
  }
}

/* Function for Chart: '<Root>/Blood flow control stateflow' */
static void exit_internal_Find_initial_boun(void)
{
  switch (autoquet_simulink_DW.is_Find_initial_bounds) {
   case autoquet_simulink_IN_Deflate:
    autoquet_simulink_DW.is_Deflate = autoquet_sim_IN_NO_ACTIVE_CHILD;
    autoquet_simulink_DW.pressure_lower_bound =
      autoquet_simulink_B.pressure_set_point;
    autoquet_simulink_DW.is_Find_initial_bounds =
      autoquet_sim_IN_NO_ACTIVE_CHILD;
    break;

   case autoquet_simulink_IN_Inflate:
    autoquet_simulink_DW.is_Inflate = autoquet_sim_IN_NO_ACTIVE_CHILD;
    autoquet_simulink_DW.pressure_upper_bound =
      autoquet_simulink_B.pressure_set_point;
    autoquet_simulink_B.initial_search = 1U;
    autoquet_simulink_DW.is_Find_initial_bounds =
      autoquet_sim_IN_NO_ACTIVE_CHILD;
    break;
  }
}

static void autoquet_simul_SystemCore_setup(codertarget_arduinobase_int_o_T *obj)
{
  uint8_T SwappedDataBytes[2];
  uint8_T b_SwappedDataBytes[2];
  uint8_T CastedData;
  uint8_T SwappedDataBytes_0;
  uint8_T status;

  /* Start for MATLABSystem: '<S10>/Base sensor block' */
  obj->isInitialized = 1L;
  obj->i2cObj.I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(0, MW_I2C_MASTER);
  obj->i2cObj.BusSpeed = 100000UL;
  MW_I2C_SetBusSpeed(obj->i2cObj.I2CDriverObj.MW_I2C_HANDLE,
                     obj->i2cObj.BusSpeed);
  MW_delay_in_milliseconds(600UL);
  status = 0U;

  /* Start for MATLABSystem: '<S10>/Base sensor block' */
  memcpy((void *)&SwappedDataBytes_0, (void *)&status, (size_t)1 * sizeof
         (uint8_T));
  status = MW_I2C_MasterWrite(obj->i2cObj.I2CDriverObj.MW_I2C_HANDLE, 41UL,
    &SwappedDataBytes_0, 1UL, true, false);
  if (status == 0) {
    MW_I2C_MasterRead(obj->i2cObj.I2CDriverObj.MW_I2C_HANDLE, 41UL, &status, 1UL,
                      false, true);
    memcpy((void *)&CastedData, (void *)&status, (size_t)1 * sizeof(uint8_T));
  } else {
    CastedData = 0U;
  }

  obj->isBNOcorrect = (CastedData == 160);
  if (obj->isBNOcorrect) {
    CastedData = 0U;
    memcpy((void *)&b_SwappedDataBytes[1], (void *)&CastedData, (size_t)1 *
           sizeof(uint8_T));
    b_SwappedDataBytes[0] = 61U;
    memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0], (size_t)
           2 * sizeof(uint8_T));
    MW_I2C_MasterWrite(obj->i2cObj.I2CDriverObj.MW_I2C_HANDLE, 41UL,
                       &SwappedDataBytes[0], 2UL, false, false);
    MW_delay_in_milliseconds(25UL);
    CastedData = 32U;
    memcpy((void *)&b_SwappedDataBytes[1], (void *)&CastedData, (size_t)1 *
           sizeof(uint8_T));
    b_SwappedDataBytes[0] = 63U;
    memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0], (size_t)
           2 * sizeof(uint8_T));
    MW_I2C_MasterWrite(obj->i2cObj.I2CDriverObj.MW_I2C_HANDLE, 41UL,
                       &SwappedDataBytes[0], 2UL, false, false);
    status = 0U;
    memcpy((void *)&SwappedDataBytes_0, (void *)&status, (size_t)1 * sizeof
           (uint8_T));
    status = MW_I2C_MasterWrite(obj->i2cObj.I2CDriverObj.MW_I2C_HANDLE, 41UL,
      &SwappedDataBytes_0, 1UL, true, false);
    if (status == 0) {
      MW_I2C_MasterRead(obj->i2cObj.I2CDriverObj.MW_I2C_HANDLE, 41UL, &status,
                        1UL, false, true);
      memcpy((void *)&CastedData, (void *)&status, (size_t)1 * sizeof(uint8_T));
    } else {
      CastedData = 0U;
    }

    obj->isBNOcorrect = (CastedData == 160);
    while (!obj->isBNOcorrect) {
      MW_delay_in_milliseconds(10UL);
      status = 0U;
      memcpy((void *)&SwappedDataBytes_0, (void *)&status, (size_t)1 * sizeof
             (uint8_T));
      status = MW_I2C_MasterWrite(obj->i2cObj.I2CDriverObj.MW_I2C_HANDLE, 41UL,
        &SwappedDataBytes_0, 1UL, true, false);
      if (status == 0) {
        MW_I2C_MasterRead(obj->i2cObj.I2CDriverObj.MW_I2C_HANDLE, 41UL, &status,
                          1UL, false, true);
        memcpy((void *)&CastedData, (void *)&status, (size_t)1 * sizeof(uint8_T));
      } else {
        CastedData = 0U;
      }

      obj->isBNOcorrect = (CastedData == 160);
    }

    MW_delay_in_milliseconds(50UL);
    CastedData = 0U;
    memcpy((void *)&b_SwappedDataBytes[1], (void *)&CastedData, (size_t)1 *
           sizeof(uint8_T));
    b_SwappedDataBytes[0] = 62U;
    memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0], (size_t)
           2 * sizeof(uint8_T));
    MW_I2C_MasterWrite(obj->i2cObj.I2CDriverObj.MW_I2C_HANDLE, 41UL,
                       &SwappedDataBytes[0], 2UL, false, false);
    CastedData = 0U;
    memcpy((void *)&b_SwappedDataBytes[1], (void *)&CastedData, (size_t)1 *
           sizeof(uint8_T));
    b_SwappedDataBytes[0] = 63U;
    memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0], (size_t)
           2 * sizeof(uint8_T));
    MW_I2C_MasterWrite(obj->i2cObj.I2CDriverObj.MW_I2C_HANDLE, 41UL,
                       &SwappedDataBytes[0], 2UL, false, false);
    CastedData = 0U;
    memcpy((void *)&b_SwappedDataBytes[1], (void *)&CastedData, (size_t)1 *
           sizeof(uint8_T));
    b_SwappedDataBytes[0] = 7U;
    memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0], (size_t)
           2 * sizeof(uint8_T));
    MW_I2C_MasterWrite(obj->i2cObj.I2CDriverObj.MW_I2C_HANDLE, 41UL,
                       &SwappedDataBytes[0], 2UL, false, false);
    MW_delay_in_milliseconds(10UL);
    CastedData = 128U;
    memcpy((void *)&b_SwappedDataBytes[1], (void *)&CastedData, (size_t)1 *
           sizeof(uint8_T));
    b_SwappedDataBytes[0] = 59U;
    memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0], (size_t)
           2 * sizeof(uint8_T));
    MW_I2C_MasterWrite(obj->i2cObj.I2CDriverObj.MW_I2C_HANDLE, 41UL,
                       &SwappedDataBytes[0], 2UL, false, false);
    CastedData = 12U;
    memcpy((void *)&b_SwappedDataBytes[1], (void *)&CastedData, (size_t)1 *
           sizeof(uint8_T));
    b_SwappedDataBytes[0] = 61U;
    memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0], (size_t)
           2 * sizeof(uint8_T));
    MW_I2C_MasterWrite(obj->i2cObj.I2CDriverObj.MW_I2C_HANDLE, 41UL,
                       &SwappedDataBytes[0], 2UL, false, false);
    MW_delay_in_milliseconds(25UL);
  }

  obj->isSetupComplete = true;
}

/* Model step function for TID0 */
void autoquet_simulink_step0(void)     /* Sample time: [0.0001s, 0.0s] */
{
  {                                    /* Sample time: [0.0001s, 0.0s] */
    rate_monotonic_scheduler();
  }
}

/* Model step function for TID1 */
void autoquet_simulink_step1(void)     /* Sample time: [0.001s, 0.0s] */
{
  real_T rtb_PulseGenerator;
  uint16_T qY;
  uint8_T dataIn[47];
  uint8_T y;
  ZCEventType zcEvent;

  /* S-Function (clock_counter): '<Root>/Time keeper' */
  clock_counter_Outputs_wrapper(&autoquet_simulink_B.Timekeeper_o1[0],
    &autoquet_simulink_B.Timekeeper_o2);

  /* SignalConversion generated from: '<S4>/C//C++ Code Block5' */
  autoquet_simulink_B.TmpSignalConversionAtCCCodeBloc[0] =
    autoquet_simulink_B.Automodesignalinput;
  autoquet_simulink_B.TmpSignalConversionAtCCCodeBloc[1] =
    autoquet_simulink_B.Increasesignalinput;
  autoquet_simulink_B.TmpSignalConversionAtCCCodeBloc[2] =
    autoquet_simulink_B.Decreasesignalinput;

  /* S-Function (button_control_logic): '<S4>/C//C++ Code Block5' */
  button_control_logic_Outputs_wrapper
    (&autoquet_simulink_B.TmpSignalConversionAtCCCodeBloc[0],
     &autoquet_simulink_B.Timekeeper_o2, &autoquet_simulink_B.pressure_set_point,
     &autoquet_simulink_B.initial_search, &autoquet_simulink_B.CCCodeBlock5_o1,
     &autoquet_simulink_B.CCCodeBlock5_o2, &autoquet_simulink_B.CCCodeBlock5_o3);

  /* Sum: '<S4>/Sum' */
  autoquet_simulink_B.Sum = autoquet_simulink_B.CCCodeBlock5_o1 -
    autoquet_simulink_B.CCCodeBlock3;

  /* S-Function (motor_drive_control): '<S4>/C//C++ Code Block' */
  motor_drive_control_Outputs_wrapper(&autoquet_simulink_B.Sum,
    &autoquet_simulink_B.CCCodeBlock, &autoquet_simulink_B.CCCodeBlock5_o2,
    &autoquet_simulink_B.CCCodeBlock_o1, &autoquet_simulink_B.CCCodeBlock_o2,
    &autoquet_simulink_B.CCCodeBlock_o3);

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  rtb_PulseGenerator = (autoquet_simulink_DW.clockTickCounter <
                        autoquet_simulink_P.PulseGenerator_Duty) &&
    (autoquet_simulink_DW.clockTickCounter >= 0L) ?
    autoquet_simulink_P.PulseGenerator_Amp : 0.0;
  if (autoquet_simulink_DW.clockTickCounter >=
      autoquet_simulink_P.PulseGenerator_Period - 1.0) {
    autoquet_simulink_DW.clockTickCounter = 0L;
  } else {
    autoquet_simulink_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

  /* Outputs for Triggered SubSystem: '<Root>/Communication block' incorporates:
   *  TriggerPort: '<S3>/Trigger'
   */
  zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                     &autoquet_simulink_PrevZCX.Communicationblock_Trig_ZCE,
                     (rtb_PulseGenerator));
  if (zcEvent != NO_ZCEVENT) {
    /* S-Function (any2byte_svd): '<S3>/Byte Pack1' */

    /* Pack: <S3>/Byte Pack1 */
    {
      uint32_T MW_outputPortOffset = 0;
      uint32_T MW_inputPortWidth = 0;
      uint32_T MW_remainder1 = 0;

      /* Packed output data type - uint8_T */
      /* Packing the values of Input 1 */
      /* Input data type - real32_T, size - 1 */
      {
        MW_inputPortWidth = 1 * sizeof(real32_T);
        memcpy((uint8_T*)((uint8_T*)&autoquet_simulink_B.BytePack1[0] +
                          MW_outputPortOffset), (uint8_T*)
               &autoquet_simulink_B.CCCodeBlock3, MW_inputPortWidth);
      }
    }

    /* S-Function (any2byte_svd): '<S3>/Byte Pack' */

    /* Pack: <S3>/Byte Pack */
    {
      uint32_T MW_outputPortOffset = 0;
      uint32_T MW_inputPortWidth = 0;
      uint32_T MW_remainder1 = 0;

      /* Packed output data type - uint8_T */
      /* Packing the values of Input 1 */
      /* Input data type - real32_T, size - 1 */
      {
        MW_inputPortWidth = 1 * sizeof(real32_T);
        memcpy((uint8_T*)((uint8_T*)&autoquet_simulink_B.BytePack[0] +
                          MW_outputPortOffset), (uint8_T*)
               &autoquet_simulink_B.pressure_set_point, MW_inputPortWidth);
      }
    }

    /* S-Function (any2byte_svd): '<S3>/Byte Pack2' */

    /* Pack: <S3>/Byte Pack2 */
    {
      uint32_T MW_outputPortOffset = 0;
      uint32_T MW_inputPortWidth = 0;
      uint32_T MW_remainder1 = 0;

      /* Packed output data type - uint8_T */
      /* Packing the values of Input 1 */
      /* Input data type - real32_T, size - 1 */
      {
        MW_inputPortWidth = 1 * sizeof(real32_T);
        memcpy((uint8_T*)((uint8_T*)&autoquet_simulink_B.BytePack2[0] +
                          MW_outputPortOffset), (uint8_T*)
               &autoquet_simulink_B.CCCodeBlock4_o2[0], MW_inputPortWidth);
      }
    }

    /* S-Function (any2byte_svd): '<S3>/Byte Pack3' */

    /* Pack: <S3>/Byte Pack3 */
    {
      uint32_T MW_outputPortOffset = 0;
      uint32_T MW_inputPortWidth = 0;
      uint32_T MW_remainder1 = 0;

      /* Packed output data type - uint8_T */
      /* Packing the values of Input 1 */
      /* Input data type - real32_T, size - 1 */
      {
        MW_inputPortWidth = 1 * sizeof(real32_T);
        memcpy((uint8_T*)((uint8_T*)&autoquet_simulink_B.BytePack3[0] +
                          MW_outputPortOffset), (uint8_T*)
               &autoquet_simulink_B.CCCodeBlock4_o2[1], MW_inputPortWidth);
      }
    }

    /* S-Function (any2byte_svd): '<S3>/Byte Pack4' */

    /* Pack: <S3>/Byte Pack4 */
    {
      uint32_T MW_outputPortOffset = 0;
      uint32_T MW_inputPortWidth = 0;
      uint32_T MW_remainder1 = 0;

      /* Packed output data type - uint8_T */
      /* Packing the values of Input 1 */
      /* Input data type - real32_T, size - 1 */
      {
        MW_inputPortWidth = 1 * sizeof(real32_T);
        memcpy((uint8_T*)((uint8_T*)&autoquet_simulink_B.BytePack4[0] +
                          MW_outputPortOffset), (uint8_T*)
               &autoquet_simulink_B.CCCodeBlock4_o2[2], MW_inputPortWidth);
      }
    }

    /* S-Function (any2byte_svd): '<S3>/Byte Pack5' */

    /* Pack: <S3>/Byte Pack5 */
    {
      uint32_T MW_outputPortOffset = 0;
      uint32_T MW_inputPortWidth = 0;
      uint32_T MW_remainder1 = 0;

      /* Packed output data type - uint8_T */
      /* Packing the values of Input 1 */
      /* Input data type - real32_T, size - 1 */
      {
        MW_inputPortWidth = 1 * sizeof(real32_T);
        memcpy((uint8_T*)((uint8_T*)&autoquet_simulink_B.BytePack5[0] +
                          MW_outputPortOffset), (uint8_T*)
               &autoquet_simulink_B.CCCodeBlock4_o1, MW_inputPortWidth);
      }
    }

    /* S-Function (any2byte_svd): '<S3>/Byte Pack6' */

    /* Pack: <S3>/Byte Pack6 */
    {
      uint32_T MW_outputPortOffset = 0;
      uint32_T MW_inputPortWidth = 0;
      uint32_T MW_remainder1 = 0;

      /* Packed output data type - uint8_T */
      /* Packing the values of Input 1 */
      /* Input data type - boolean_T, size - 1 */
      {
        MW_inputPortWidth = 1 * sizeof(boolean_T);
        memcpy((uint8_T*)((uint8_T*)&autoquet_simulink_B.BytePack6 +
                          MW_outputPortOffset), (uint8_T*)
               &autoquet_simulink_B.CCCodeBlock_o2, MW_inputPortWidth);
      }
    }

    /* S-Function (any2byte_svd): '<S3>/Byte Pack7' */

    /* Pack: <S3>/Byte Pack7 */
    {
      uint32_T MW_outputPortOffset = 0;
      uint32_T MW_inputPortWidth = 0;
      uint32_T MW_remainder1 = 0;

      /* Packed output data type - uint8_T */
      /* Packing the values of Input 1 */
      /* Input data type - boolean_T, size - 1 */
      {
        MW_inputPortWidth = 1 * sizeof(boolean_T);
        memcpy((uint8_T*)((uint8_T*)&autoquet_simulink_B.BytePack7 +
                          MW_outputPortOffset), (uint8_T*)
               &autoquet_simulink_B.CCCodeBlock2, MW_inputPortWidth);
      }
    }

    /* S-Function (any2byte_svd): '<S3>/Byte Pack8' */

    /* Pack: <S3>/Byte Pack8 */
    {
      uint32_T MW_outputPortOffset = 0;
      uint32_T MW_inputPortWidth = 0;
      uint32_T MW_remainder1 = 0;

      /* Packed output data type - uint8_T */
      /* Packing the values of Input 1 */
      /* Input data type - boolean_T, size - 1 */
      {
        MW_inputPortWidth = 1 * sizeof(boolean_T);
        memcpy((uint8_T*)((uint8_T*)&autoquet_simulink_B.BytePack8 +
                          MW_outputPortOffset), (uint8_T*)
               &autoquet_simulink_B.CCCodeBlock, MW_inputPortWidth);
      }
    }

    /* S-Function (any2byte_svd): '<S3>/Byte Pack9' */

    /* Pack: <S3>/Byte Pack9 */
    {
      uint32_T MW_outputPortOffset = 0;
      uint32_T MW_inputPortWidth = 0;
      uint32_T MW_remainder1 = 0;

      /* Packed output data type - uint8_T */
      /* Packing the values of Input 1 */
      /* Input data type - uint16_T, size - 1 */
      {
        MW_inputPortWidth = 1 * sizeof(uint16_T);
        memcpy((uint8_T*)((uint8_T*)&autoquet_simulink_B.BytePack9[0] +
                          MW_outputPortOffset), (uint8_T*)
               &autoquet_simulink_B.CCCodeBlock3_o1, MW_inputPortWidth);
      }
    }

    /* S-Function (any2byte_svd): '<S3>/Byte Pack10' */

    /* Pack: <S3>/Byte Pack10 */
    {
      uint32_T MW_outputPortOffset = 0;
      uint32_T MW_inputPortWidth = 0;
      uint32_T MW_remainder1 = 0;

      /* Packed output data type - uint8_T */
      /* Packing the values of Input 1 */
      /* Input data type - boolean_T, size - 1 */
      {
        MW_inputPortWidth = 1 * sizeof(boolean_T);
        memcpy((uint8_T*)((uint8_T*)&autoquet_simulink_B.BytePack10 +
                          MW_outputPortOffset), (uint8_T*)
               &autoquet_simulink_B.CCCodeBlock3_o2, MW_inputPortWidth);
      }
    }

    /* S-Function (any2byte_svd): '<S3>/Byte Pack11' incorporates:
     *  Constant: '<S2>/bloodflow_threshold'
     */

    /* Pack: <S3>/Byte Pack11 */
    {
      uint32_T MW_outputPortOffset = 0;
      uint32_T MW_inputPortWidth = 0;
      uint32_T MW_remainder1 = 0;

      /* Packed output data type - uint8_T */
      /* Packing the values of Input 1 */
      /* Input data type - uint16_T, size - 1 */
      {
        MW_inputPortWidth = 1 * sizeof(uint16_T);
        memcpy((uint8_T*)((uint8_T*)&autoquet_simulink_B.BytePack11[0] +
                          MW_outputPortOffset), (uint8_T*)
               &autoquet_simulink_P.bloodflow_threshold_Value, MW_inputPortWidth);
      }
    }

    /* S-Function (any2byte_svd): '<S3>/Byte Pack12' */

    /* Pack: <S3>/Byte Pack12 */
    {
      uint32_T MW_outputPortOffset = 0;
      uint32_T MW_inputPortWidth = 0;
      uint32_T MW_remainder1 = 0;

      /* Packed output data type - uint8_T */
      /* Packing the values of Input 1 */
      /* Input data type - real32_T, size - 1 */
      {
        MW_inputPortWidth = 1 * sizeof(real32_T);
        memcpy((uint8_T*)((uint8_T*)&autoquet_simulink_B.BytePack12[0] +
                          MW_outputPortOffset), (uint8_T*)
               &autoquet_simulink_B.CCCodeBlock_o1, MW_inputPortWidth);
      }
    }

    /* S-Function (any2byte_svd): '<S3>/Byte Pack13' */

    /* Pack: <S3>/Byte Pack13 */
    {
      uint32_T MW_outputPortOffset = 0;
      uint32_T MW_inputPortWidth = 0;
      uint32_T MW_remainder1 = 0;

      /* Packed output data type - uint8_T */
      /* Packing the values of Input 1 */
      /* Input data type - boolean_T, size - 1 */
      {
        MW_inputPortWidth = 1 * sizeof(boolean_T);
        memcpy((uint8_T*)((uint8_T*)&autoquet_simulink_B.BytePack13 +
                          MW_outputPortOffset), (uint8_T*)
               &autoquet_simulink_B.CCCodeBlock_o3, MW_inputPortWidth);
      }
    }

    /* S-Function (any2byte_svd): '<S3>/Byte Pack14' */

    /* Pack: <S3>/Byte Pack14 */
    {
      uint32_T MW_outputPortOffset = 0;
      uint32_T MW_inputPortWidth = 0;
      uint32_T MW_remainder1 = 0;

      /* Packed output data type - uint8_T */
      /* Packing the values of Input 1 */
      /* Input data type - uint8_T, size - 1 */
      {
        MW_inputPortWidth = 1 * sizeof(uint8_T);
        memcpy((uint8_T*)((uint8_T*)&autoquet_simulink_B.BytePack14 +
                          MW_outputPortOffset), (uint8_T*)
               &autoquet_simulink_B.CCCodeBlock5_o2, MW_inputPortWidth);
      }
    }

    /* S-Function (any2byte_svd): '<S3>/Byte Pack15' */

    /* Pack: <S3>/Byte Pack15 */
    {
      uint32_T MW_outputPortOffset = 0;
      uint32_T MW_inputPortWidth = 0;
      uint32_T MW_remainder1 = 0;

      /* Packed output data type - uint8_T */
      /* Packing the values of Input 1 */
      /* Input data type - boolean_T, size - 1 */
      {
        MW_inputPortWidth = 1 * sizeof(boolean_T);
        memcpy((uint8_T*)((uint8_T*)&autoquet_simulink_B.BytePack15 +
                          MW_outputPortOffset), (uint8_T*)
               &autoquet_simulink_B.ideal_pressure_found, MW_inputPortWidth);
      }
    }

    /* S-Function (any2byte_svd): '<S3>/Byte Pack16' */

    /* Pack: <S3>/Byte Pack16 */
    {
      uint32_T MW_outputPortOffset = 0;
      uint32_T MW_inputPortWidth = 0;
      uint32_T MW_remainder1 = 0;

      /* Packed output data type - uint8_T */
      /* Packing the values of Input 1 */
      /* Input data type - boolean_T, size - 1 */
      {
        MW_inputPortWidth = 1 * sizeof(boolean_T);
        memcpy((uint8_T*)((uint8_T*)&autoquet_simulink_B.BytePack16 +
                          MW_outputPortOffset), (uint8_T*)
               &autoquet_simulink_B.Increasesignalinput, MW_inputPortWidth);
      }
    }

    /* S-Function (any2byte_svd): '<S3>/Byte Pack17' */

    /* Pack: <S3>/Byte Pack17 */
    {
      uint32_T MW_outputPortOffset = 0;
      uint32_T MW_inputPortWidth = 0;
      uint32_T MW_remainder1 = 0;

      /* Packed output data type - uint8_T */
      /* Packing the values of Input 1 */
      /* Input data type - boolean_T, size - 1 */
      {
        MW_inputPortWidth = 1 * sizeof(boolean_T);
        memcpy((uint8_T*)((uint8_T*)&autoquet_simulink_B.BytePack17 +
                          MW_outputPortOffset), (uint8_T*)
               &autoquet_simulink_B.Decreasesignalinput, MW_inputPortWidth);
      }
    }

    /* S-Function (any2byte_svd): '<S3>/Byte Pack18' */

    /* Pack: <S3>/Byte Pack18 */
    {
      uint32_T MW_outputPortOffset = 0;
      uint32_T MW_inputPortWidth = 0;
      uint32_T MW_remainder1 = 0;

      /* Packed output data type - uint8_T */
      /* Packing the values of Input 1 */
      /* Input data type - boolean_T, size - 1 */
      {
        MW_inputPortWidth = 1 * sizeof(boolean_T);
        memcpy((uint8_T*)((uint8_T*)&autoquet_simulink_B.BytePack18 +
                          MW_outputPortOffset), (uint8_T*)
               &autoquet_simulink_B.Automodesignalinput, MW_inputPortWidth);
      }
    }

    /* S-Function (any2byte_svd): '<S3>/Byte Pack19' */

    /* Pack: <S3>/Byte Pack19 */
    {
      uint32_T MW_outputPortOffset = 0;
      uint32_T MW_inputPortWidth = 0;
      uint32_T MW_remainder1 = 0;

      /* Packed output data type - uint8_T */
      /* Packing the values of Input 1 */
      /* Input data type - uint8_T, size - 1 */
      {
        MW_inputPortWidth = 1 * sizeof(uint8_T);
        memcpy((uint8_T*)((uint8_T*)&autoquet_simulink_B.BytePack19 +
                          MW_outputPortOffset), (uint8_T*)
               &autoquet_simulink_B.CCCodeBlock5_o3, MW_inputPortWidth);
      }
    }

    /* MATLABSystem: '<S3>/Serial Transmit' incorporates:
     *  SignalConversion generated from: '<S3>/Serial Transmit'
     */
    if (autoquet_simulink_DW.obj.Protocol !=
        autoquet_simulink_P.SerialTransmit_Protocol) {
      autoquet_simulink_DW.obj.Protocol =
        autoquet_simulink_P.SerialTransmit_Protocol;
    }

    dataIn[0] = autoquet_simulink_B.BytePack1[0];
    dataIn[1] = autoquet_simulink_B.BytePack1[1];
    dataIn[2] = autoquet_simulink_B.BytePack1[2];
    dataIn[3] = autoquet_simulink_B.BytePack1[3];
    dataIn[4] = autoquet_simulink_B.BytePack[0];
    dataIn[5] = autoquet_simulink_B.BytePack[1];
    dataIn[6] = autoquet_simulink_B.BytePack[2];
    dataIn[7] = autoquet_simulink_B.BytePack[3];
    dataIn[8] = autoquet_simulink_B.BytePack2[0];
    dataIn[9] = autoquet_simulink_B.BytePack2[1];
    dataIn[10] = autoquet_simulink_B.BytePack2[2];
    dataIn[11] = autoquet_simulink_B.BytePack2[3];
    dataIn[12] = autoquet_simulink_B.BytePack3[0];
    dataIn[13] = autoquet_simulink_B.BytePack3[1];
    dataIn[14] = autoquet_simulink_B.BytePack3[2];
    dataIn[15] = autoquet_simulink_B.BytePack3[3];
    dataIn[16] = autoquet_simulink_B.BytePack4[0];
    dataIn[17] = autoquet_simulink_B.BytePack4[1];
    dataIn[18] = autoquet_simulink_B.BytePack4[2];
    dataIn[19] = autoquet_simulink_B.BytePack4[3];
    dataIn[20] = autoquet_simulink_B.BytePack5[0];
    dataIn[21] = autoquet_simulink_B.BytePack5[1];
    dataIn[22] = autoquet_simulink_B.BytePack5[2];
    dataIn[23] = autoquet_simulink_B.BytePack5[3];
    dataIn[24] = autoquet_simulink_B.BytePack6;
    dataIn[25] = autoquet_simulink_B.BytePack7;
    dataIn[26] = autoquet_simulink_B.BytePack8;
    dataIn[27] = autoquet_simulink_B.BytePack9[0];
    dataIn[28] = autoquet_simulink_B.BytePack9[1];
    dataIn[29] = autoquet_simulink_B.BytePack10;
    dataIn[30] = autoquet_simulink_B.BytePack11[0];
    dataIn[31] = autoquet_simulink_B.BytePack11[1];
    dataIn[32] = autoquet_simulink_B.BytePack12[0];
    dataIn[33] = autoquet_simulink_B.BytePack12[1];
    dataIn[34] = autoquet_simulink_B.BytePack12[2];
    dataIn[35] = autoquet_simulink_B.BytePack12[3];
    dataIn[36] = autoquet_simulink_B.BytePack13;
    dataIn[37] = autoquet_simulink_B.BytePack14;
    dataIn[38] = autoquet_simulink_B.BytePack15;
    dataIn[39] = autoquet_simulink_B.BytePack16;
    dataIn[40] = autoquet_simulink_B.BytePack17;
    dataIn[41] = autoquet_simulink_B.BytePack18;
    dataIn[42] = autoquet_simulink_B.BytePack19;
    dataIn[43] = autoquet_simulink_B.Timekeeper_o1[0];
    dataIn[44] = autoquet_simulink_B.Timekeeper_o1[1];
    dataIn[45] = autoquet_simulink_B.Timekeeper_o1[2];
    dataIn[46] = autoquet_simulink_B.Timekeeper_o1[3];
    MW_Serial_write(autoquet_simulink_DW.obj.port, &dataIn[0], 47.0,
                    autoquet_simulink_DW.obj.dataSizeInBytes,
                    autoquet_simulink_DW.obj.sendModeEnum,
                    autoquet_simulink_DW.obj.dataType,
                    autoquet_simulink_DW.obj.sendFormatEnum, 2.0, '\x00');

    /* End of MATLABSystem: '<S3>/Serial Transmit' */
  }

  /* End of Outputs for SubSystem: '<Root>/Communication block' */

  /* S-Function (dec_to_sev_seg): '<S5>/C//C++ Code Block3' */
  dec_to_sev_seg_Outputs_wrapper(&autoquet_simulink_B.Timekeeper_o1[0],
    &autoquet_simulink_B.CCCodeBlock3_h[0]);

  /* S-Function (pressure_display): '<S5>/C//C++ Code Block1' */
  pressure_display_Outputs_wrapper(&autoquet_simulink_B.CCCodeBlock5_o1,
    &autoquet_simulink_B.CCCodeBlock1[0]);

  /* S-Function (display_pressures_signal): '<S5>/C//C++ Code Block4' */
  display_pressures_signal_Outputs_wrapper(&autoquet_simulink_B.CCCodeBlock1[0],
    &autoquet_simulink_B.CCCodeBlock5_o1, &autoquet_simulink_B.CCCodeBlock5_o3,
    &autoquet_simulink_B.Timekeeper_o2, &autoquet_simulink_B.CCCodeBlock4);

  /* Chart: '<S5>/Chart' incorporates:
   *  S-Function (dec_to_sev_seg): '<S5>/C//C++ Code Block3'
   *  S-Function (pressure_display): '<S5>/C//C++ Code Block1'
   */
  if (autoquet_simulink_DW.is_active_c1_autoquet_simulink == 0U) {
    autoquet_simulink_DW.is_active_c1_autoquet_simulink = 1U;
    autoquet_simulink_DW.is_c1_autoquet_simulink =
      autoquet_IN_display_multiplexer;
    autoquet_simulink_DW.flash_ratio = 7U;
  } else {
    switch (autoquet_simulink_DW.is_c1_autoquet_simulink) {
     case autoquet_IN_display_multiplexer:
      switch (autoquet_simulink_B.CCCodeBlock4) {
       case 1:
        autoquet_simulink_DW.is_c1_autoquet_simulink =
          autoquet_simu_IN_flashing_logic;
        qY = autoquet_simulink_DW.pressure_flash + 1U;
        if (autoquet_simulink_DW.pressure_flash + 1U > 255U) {
          qY = 255U;
        }

        autoquet_simulink_DW.pressure_flash = (uint8_T)qY;
        break;

       case 0:
        autoquet_simulink_DW.is_c1_autoquet_simulink =
          autoquet_IN_set_time_to_display;
        autoquet_simulink_DW.to_screen[0] = autoquet_simulink_B.CCCodeBlock3_h[0];
        autoquet_simulink_DW.to_screen[1] = autoquet_simulink_B.CCCodeBlock3_h[1];
        autoquet_simulink_DW.to_screen[2] = autoquet_simulink_B.CCCodeBlock3_h[2];
        autoquet_simulink_DW.to_screen[3] = autoquet_simulink_B.CCCodeBlock3_h[3];
        break;

       default:
        autoquet_simulink_DW.flash_ratio = 7U;
        break;
      }
      break;

     case autoquet_simu_IN_flashing_logic:
      if (autoquet_simulink_DW.flash_ratio == 0) {
        y = 0U;
      } else {
        y = (uint8_T)(autoquet_simulink_DW.pressure_flash %
                      autoquet_simulink_DW.flash_ratio);
      }

      if (y != 0) {
        autoquet_simulink_DW.is_c1_autoquet_simulink =
          auto_IN_set_pressure_to_display;
        autoquet_simulink_DW.to_screen[0] = autoquet_simulink_B.CCCodeBlock1[0];
        autoquet_simulink_DW.to_screen[1] = autoquet_simulink_B.CCCodeBlock1[1];
        autoquet_simulink_DW.to_screen[2] = autoquet_simulink_B.CCCodeBlock1[2];
        autoquet_simulink_DW.to_screen[3] = autoquet_simulink_B.CCCodeBlock1[3];
      } else {
        if (autoquet_simulink_DW.flash_ratio == 0) {
          y = 0U;
        } else {
          y = (uint8_T)(autoquet_simulink_DW.pressure_flash %
                        autoquet_simulink_DW.flash_ratio);
        }

        if (y == 0) {
          autoquet_simulink_DW.is_c1_autoquet_simulink =
            autoque_IN_set_blank_to_display;
          autoquet_simulink_DW.to_screen[0] = 0U;
          autoquet_simulink_DW.to_screen[1] = 0U;
          autoquet_simulink_DW.to_screen[2] = 0U;
          autoquet_simulink_DW.to_screen[3] = 0U;
          autoquet_simulink_DW.pressure_flash = 0U;
        }
      }
      break;

     case autoquet_si_IN_sending_firmware:
      if (autoquet_simulink_DW.full_data_sent) {
        switch (autoquet_simulink_DW.is_sending_firmware) {
         case autoquet_simulink_IN_Stop:
          autoquet_simulink_B.data_pin = true;
          autoquet_simulink_DW.is_sending_firmware =
            autoquet_sim_IN_NO_ACTIVE_CHILD;
          break;

         case autoquet_simulink_IN_send_data:
          autoque_exit_internal_send_data();
          autoquet_simulink_B.clk_pin = true;
          autoquet_simulink_DW.word_iterator = 1U;
          autoquet_simulink_DW.is_sending_firmware =
            autoquet_sim_IN_NO_ACTIVE_CHILD;
          break;

         default:
          autoquet_simulink_DW.is_command_flow = autoquet_sim_IN_NO_ACTIVE_CHILD;
          autoquet_simulink_DW.is_sending_firmware =
            autoquet_sim_IN_NO_ACTIVE_CHILD;
          break;
        }

        autoquet_simulink_DW.is_c1_autoquet_simulink =
          autoquet_IN_display_multiplexer;
        autoquet_simulink_DW.flash_ratio = 7U;
      } else {
        switch (autoquet_simulink_DW.is_sending_firmware) {
         case autoquet_simuli_IN_Start_signal:
          autoquet_simulink_DW.is_sending_firmware =
            autoquet_simulink_IN_send_data;
          autoquet_simulink_DW.is_send_data = autoquet_simulink_IN_reset_clk;
          autoquet_simulink_B.clk_pin = false;
          break;

         case autoquet_simulink_IN_Stop:
          if (autoquet_simulink_DW.command == 136) {
            autoquet_simulink_DW.full_data_sent = true;
          }

          autoquet_simulink_B.data_pin = true;
          autoquet_simulink_DW.is_sending_firmware =
            autoquet_simuli_IN_command_flow;
          autoquet_simulink_DW.is_command_flow = autoquet_simuli_IN_find_command;
          break;

         case autoquet_simuli_IN_command_flow:
          if (autoquet_simulink_DW.transmit) {
            autoquet_simulink_DW.is_command_flow =
              autoquet_sim_IN_NO_ACTIVE_CHILD;
            autoquet_simulink_DW.is_sending_firmware =
              autoquet_simuli_IN_Start_signal;
            autoquet_simulink_B.data_pin = false;
            autoquet_simulink_DW.buffer = autoquet_simulink_DW.command;
            autoquet_simulink_DW.bit_iterator = 1U;
            autoquet_simulink_DW.word_iterator = 1U;
          } else {
            switch (autoquet_simulink_DW.is_command_flow) {
             case autoquet_simu_IN_data_directive:
             case autoquet_sim_IN_display_control:
              break;

             case autoquet_simuli_IN_find_command:
              switch (autoquet_simulink_DW.command_state) {
               case 0:
                autoquet_simulink_DW.is_command_flow =
                  autoquet_simu_IN_data_directive;
                autoquet_simulink_DW.command = 64U;
                autoquet_simulink_DW.len = 1U;
                qY = autoquet_simulink_DW.command_state + 1U;
                if (autoquet_simulink_DW.command_state + 1U > 255U) {
                  qY = 255U;
                }

                autoquet_simulink_DW.command_state = (uint8_T)qY;
                autoquet_simulink_DW.transmit = true;
                break;

               case 1:
                autoquet_simulink_DW.is_command_flow =
                  autoquet_simul_IN_transmit_data;
                autoquet_simulink_DW.command = 192U;
                autoquet_simulink_DW.len = 5U;
                qY = autoquet_simulink_DW.command_state + 1U;
                if (autoquet_simulink_DW.command_state + 1U > 255U) {
                  qY = 255U;
                }

                autoquet_simulink_DW.command_state = (uint8_T)qY;
                autoquet_simulink_DW.transmit = true;
                break;

               case 2:
                autoquet_simulink_DW.is_command_flow =
                  autoquet_sim_IN_display_control;
                autoquet_simulink_DW.command = 136U;
                autoquet_simulink_DW.len = 1U;
                autoquet_simulink_DW.command_state = 0U;
                autoquet_simulink_DW.transmit = true;
                break;
              }
              break;

             default:
              /* case IN_transmit_data: */
              break;
            }
          }
          break;

         case autoquet_simulink_IN_init:
          autoquet_simulink_DW.is_sending_firmware =
            autoquet_simuli_IN_command_flow;
          autoquet_simulink_DW.is_command_flow = autoquet_simuli_IN_find_command;
          break;

         default:
          /* case IN_send_data: */
          if (autoquet_simulink_DW.word_iterator > autoquet_simulink_DW.len) {
            autoque_exit_internal_send_data();
            autoquet_simulink_B.clk_pin = true;
            autoquet_simulink_DW.word_iterator = 1U;
            autoquet_simulink_DW.is_sending_firmware = autoquet_simulink_IN_Stop;
            autoquet_simulink_DW.transmit = false;
          } else {
            switch (autoquet_simulink_DW.is_send_data) {
             case autoquet_simulink_IN_ack_bit:
              autoquet_simulink_B.data_pin = false;
              autoquet_simulink_DW.is_send_data = autoquet_simulink_IN_idler1;
              break;

             case autoquet_simuli_IN_buffer_reset:
              autoquet_simulink_DW.bit_iterator = 1U;
              autoquet_simulink_DW.is_send_data = autoquet_simulink_IN_reset_clk;
              autoquet_simulink_B.clk_pin = false;
              break;

             case autoquet_simulink_IN_data_high:
              autoquet_simulink_DW.is_send_data =
                autoquet_simulink_IN_latch_data;
              autoque_enter_atomic_latch_data();
              break;

             case autoquet_simulink_IN_data_low:
              autoquet_simulink_DW.is_send_data =
                autoquet_simulink_IN_latch_data;
              autoque_enter_atomic_latch_data();
              break;

             case autoquet_simulink_IN_idler:
              autoquet_simulink_B.clk_pin = false;
              autoquet_simulink_DW.is_send_data =
                autoquet_simu_IN_post_ack_reset;
              qY = autoquet_simulink_DW.word_iterator + 1U;
              if (autoquet_simulink_DW.word_iterator + 1U > 255U) {
                qY = 255U;
              }

              autoquet_simulink_DW.word_iterator = (uint8_T)qY;
              break;

             case autoquet_simulink_IN_idler1:
              autoquet_simulink_B.clk_pin = true;
              autoquet_simulink_DW.is_send_data = autoquet_simulink_IN_idler;
              break;

             case autoquet_simulink_IN_latch_data:
              if (autoquet_simulink_DW.bit_iterator <= 8) {
                autoquet_simulink_DW.is_send_data =
                  autoquet_simulink_IN_reset_clk;
                autoquet_simulink_B.clk_pin = false;
              } else {
                autoquet_simulink_DW.is_send_data = autoquet_simulink_IN_ack_bit;
                autoquet_simulink_B.clk_pin = false;
              }
              break;

             case autoquet_simu_IN_post_ack_reset:
              if (autoquet_simulink_DW.word_iterator <= autoquet_simulink_DW.len)
              {
                autoquet_simulink_DW.is_send_data =
                  autoquet_simuli_IN_buffer_reset;
                qY = autoquet_simulink_DW.word_iterator - 1U;
                if (autoquet_simulink_DW.word_iterator - 1U >
                    autoquet_simulink_DW.word_iterator) {
                  qY = 0U;
                }

                autoquet_simulink_DW.buffer = autoquet_simulink_DW.to_screen
                  [(int16_T)qY - 1];
              }
              break;

             default:
              /* case IN_reset_clk: */
              if ((autoquet_simulink_DW.buffer & 1U) == 0U) {
                autoquet_simulink_DW.is_send_data =
                  autoquet_simulink_IN_data_low;
                autoquet_simulink_B.data_pin = false;
              } else {
                autoquet_simulink_DW.is_send_data =
                  autoquet_simulink_IN_data_high;
                autoquet_simulink_B.data_pin = true;
              }
              break;
            }
          }
          break;
        }
      }
      break;

     case autoque_IN_set_blank_to_display:
      autoquet_simulink_DW.is_c1_autoquet_simulink =
        autoquet_si_IN_sending_firmware;
      autoquet_simulink_DW.is_sending_firmware = autoquet_simulink_IN_init;
      autoquet_simulink_DW.command_state = 0U;
      autoquet_simulink_DW.transmit = false;
      autoquet_simulink_B.data_pin = true;
      autoquet_simulink_B.clk_pin = true;
      autoquet_simulink_DW.full_data_sent = false;
      break;

     case auto_IN_set_pressure_to_display:
      autoquet_simulink_DW.is_c1_autoquet_simulink =
        autoquet_si_IN_sending_firmware;
      autoquet_simulink_DW.is_sending_firmware = autoquet_simulink_IN_init;
      autoquet_simulink_DW.command_state = 0U;
      autoquet_simulink_DW.transmit = false;
      autoquet_simulink_B.data_pin = true;
      autoquet_simulink_B.clk_pin = true;
      autoquet_simulink_DW.full_data_sent = false;
      break;

     default:
      /* case IN_set_time_to_display: */
      autoquet_simulink_DW.is_c1_autoquet_simulink =
        autoquet_si_IN_sending_firmware;
      autoquet_simulink_DW.is_sending_firmware = autoquet_simulink_IN_init;
      autoquet_simulink_DW.command_state = 0U;
      autoquet_simulink_DW.transmit = false;
      autoquet_simulink_B.data_pin = true;
      autoquet_simulink_B.clk_pin = true;
      autoquet_simulink_DW.full_data_sent = false;
      break;
    }
  }

  /* End of Chart: '<S5>/Chart' */

  /* MATLABSystem: '<S5>/Clock pin' */
  writeDigitalPin(8, (uint8_T)autoquet_simulink_B.clk_pin);

  /* MATLABSystem: '<S5>/Data pin' */
  writeDigitalPin(9, (uint8_T)autoquet_simulink_B.data_pin);

  /* RateTransition generated from: '<S2>/C//C++ Code Block3' incorporates:
   *  Constant: '<S2>/bloodflow_threshold'
   */
  if (autoquet_simulink_DW.TmpRTBAtCCCodeBlock3Inport3_sem == 0) {
    autoquet_simulink_DW.TmpRTBAtCCCodeBlock3Inport3_Buf =
      autoquet_simulink_P.bloodflow_threshold_Value;
  }

  /* End of RateTransition generated from: '<S2>/C//C++ Code Block3' */

  /* MATLABSystem: '<S4>/Digital Output' */
  writeDigitalPin(10, (uint8_T)autoquet_simulink_B.CCCodeBlock_o3);

  /* MATLABSystem: '<S4>/PWM' */
  autoquet_simulink_DW.obj_ec.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(5UL);

  /* Start for MATLABSystem: '<S4>/PWM' */
  if (autoquet_simulink_B.CCCodeBlock_o1 <= 255.0F) {
    rtb_PulseGenerator = autoquet_simulink_B.CCCodeBlock_o1;
  } else {
    rtb_PulseGenerator = 255.0;
  }

  if (!(rtb_PulseGenerator >= 0.0)) {
    rtb_PulseGenerator = 0.0;
  }

  /* MATLABSystem: '<S4>/PWM' */
  MW_PWM_SetDutyCycle(autoquet_simulink_DW.obj_ec.PWMDriverObj.MW_PWM_HANDLE,
                      rtb_PulseGenerator);
}

/* Model step function for TID2 */
void autoquet_simulink_step2(void)     /* Sample time: [0.05s, 0.0s] */
{
  boolean_T e_out;

  /* Chart: '<Root>/Blood flow control stateflow' incorporates:
   *  Constant: '<Root>/Bulk increment'
   *  Constant: '<Root>/Initial_pressure_start'
   *  Constant: '<Root>/Pressure resolution'
   *  Constant: '<Root>/Wait period (seconds)'
   */
  if (autoquet_simulink_DW.is_active_c3_autoquet_simulink == 0U) {
    autoquet_simulink_DW.is_active_c3_autoquet_simulink = 1U;
    autoquet_simulink_DW.is_c3_autoquet_simulink =
      autoquet_simulin_IN_Manual_mode;
  } else if (autoquet_simulink_DW.is_c3_autoquet_simulink ==
             autoquet_simulink_IN_Auto_mode) {
    if (autoquet_simulink_B.CCCodeBlock5_o3 == 0) {
      if (autoquet_simulink_DW.is_Auto_mode == autoquet_IN_Find_initial_bounds)
      {
        exit_internal_Find_initial_boun();
        autoquet_simulink_B.initial_search = 2U;
        autoquet_simulink_DW.is_Auto_mode = autoquet_sim_IN_NO_ACTIVE_CHILD;
      } else {
        autoquet_simulink_DW.is_Binary_search_ideal_pressure =
          autoquet_sim_IN_NO_ACTIVE_CHILD;
        autoquet_simulink_DW.is_Auto_mode = autoquet_sim_IN_NO_ACTIVE_CHILD;
      }

      autoquet_simulink_DW.is_c3_autoquet_simulink =
        autoquet_simulin_IN_Manual_mode;
    } else {
      switch (autoquet_simulink_DW.is_Auto_mode) {
       case IN_Binary_search_ideal_pressure:
        if (autoquet_simulink_B.ideal_pressure_found) {
          autoquet_simulink_DW.is_Binary_search_ideal_pressure =
            autoquet_sim_IN_NO_ACTIVE_CHILD;
          autoquet_simulink_DW.is_Auto_mode = autoquet_simuli_IN_Over_inflate;
          autoquet_simulink_B.pressure_set_point += 50.0F;
        } else {
          switch (autoquet_simulink_DW.is_Binary_search_ideal_pressure) {
           case au_IN_Adjust_pressure_set_point:
            if ((autoquet_simulink_B.CCCodeBlock3 >=
                 autoquet_simulink_B.pressure_set_point
                 - autoquet_simulink_P.Pressureresolution_Value / 2.0F) &&
                ((autoquet_simulink_B.CCCodeBlock3 <=
                  autoquet_simulink_P.Pressureresolution_Value / 2.0F +
                  autoquet_simulink_B.pressure_set_point) &&
                 (!autoquet_simulink_B.CCCodeBlock))) {
              autoquet_simulink_DW.durationCounter_1 = 0UL;
              autoquet_simulink_DW.is_Binary_search_ideal_pressure =
                autoquet_simulink_IN_Idle;
            }
            break;

           case autoque_IN_Ideal_pressure_found:
            break;

           case autoquet_simulink_IN_Idle:
            if (autoquet_simulink_B.CCCodeBlock_o2) {
              autoquet_simulink_DW.durationCounter_1 = 0UL;
            }

            if ((real_T)autoquet_simulink_DW.durationCounter_1 >
                autoquet_simulink_P.Waitperiodseconds_Value * 20.0F) {
              if (autoquet_simulink_DW.pressure_difference <
                  autoquet_simulink_P.Pressureresolution_Value) {
                autoquet_simulink_DW.is_Binary_search_ideal_pressure =
                  autoque_IN_Ideal_pressure_found;
                autoquet_simulink_B.pressure_set_point =
                  autoquet_simulink_DW.binary_search_upper;
                autoquet_simulink_B.ideal_pressure_found = true;
              } else if ((autoquet_simulink_DW.pressure_difference >=
                          autoquet_simulink_P.Pressureresolution_Value) &&
                         autoquet_simulink_B.CCCodeBlock3_o2) {
                autoquet_simulink_DW.is_Binary_search_ideal_pressure =
                  autoquet_simulink_IN_Too_loose;
                autoquet_simulink_DW.binary_search_lower =
                  autoquet_simulink_B.pressure_set_point;
              } else if ((autoquet_simulink_DW.pressure_difference >=
                          autoquet_simulink_P.Pressureresolution_Value) &&
                         (!autoquet_simulink_B.CCCodeBlock3_o2)) {
                autoquet_simulink_DW.is_Binary_search_ideal_pressure =
                  autoquet_simulink_IN_Too_tight;
                autoquet_simulink_DW.binary_search_upper =
                  autoquet_simulink_B.pressure_set_point;
              }
            }
            break;

           case autoquet_simulink_IN_Too_loose:
            autoquet_simulink_DW.is_Binary_search_ideal_pressure =
              au_IN_Adjust_pressure_set_point;
            autoquet_simulink_B.pressure_set_point =
              (autoquet_simulink_DW.binary_search_upper +
               autoquet_simulink_DW.binary_search_lower) / 2.0F;
            autoquet_simulink_DW.pressure_difference =
              autoquet_simulink_DW.binary_search_upper -
              autoquet_simulink_DW.binary_search_lower;
            break;

           default:
            /* case IN_Too_tight: */
            autoquet_simulink_DW.is_Binary_search_ideal_pressure =
              au_IN_Adjust_pressure_set_point;
            autoquet_simulink_B.pressure_set_point =
              (autoquet_simulink_DW.binary_search_upper +
               autoquet_simulink_DW.binary_search_lower) / 2.0F;
            autoquet_simulink_DW.pressure_difference =
              autoquet_simulink_DW.binary_search_upper -
              autoquet_simulink_DW.binary_search_lower;
            break;
          }
        }
        break;

       case autoquet_IN_Find_initial_bounds:
        if (autoquet_simulink_B.CCCodeBlock3_o2 &&
            autoquet_simulink_DW.upper_bound_found) {
          exit_internal_Find_initial_boun();
          autoquet_simulink_B.initial_search = 2U;
          autoquet_simulink_DW.is_Auto_mode = IN_Binary_search_ideal_pressure;
          autoquet_simulink_DW.binary_search_upper =
            autoquet_simulink_DW.pressure_upper_bound;
          autoquet_simulink_DW.binary_search_lower =
            autoquet_simulink_DW.pressure_lower_bound;
          autoquet_simulink_DW.is_Binary_search_ideal_pressure =
            au_IN_Adjust_pressure_set_point;
          autoquet_simulink_B.pressure_set_point =
            (autoquet_simulink_DW.binary_search_upper +
             autoquet_simulink_DW.binary_search_lower) / 2.0F;
          autoquet_simulink_DW.pressure_difference =
            autoquet_simulink_DW.binary_search_upper -
            autoquet_simulink_DW.binary_search_lower;
        } else if (autoquet_simulink_DW.is_Find_initial_bounds ==
                   autoquet_simulink_IN_Deflate) {
          switch (autoquet_simulink_DW.is_Deflate) {
           case IN_Decrease_pressure_set_point:
            autoquet_simulink_DW.is_Deflate = autoquet_simulink_IN_Wait;
            break;

           case autoquet_simulink_IN_Idle_g:
            if (autoquet_simulink_B.CCCodeBlock) {
              autoquet_simulink_DW.durationCounter_1_e = 0UL;
            }

            if ((real_T)autoquet_simulink_DW.durationCounter_1_e >
                autoquet_simulink_P.Waitperiodseconds_Value * 20.0F) {
              autoquet_simulink_DW.is_Deflate = IN_Decrease_pressure_set_point;
              autoquet_simulink_B.pressure_set_point -=
                autoquet_simulink_P.Bulkincrement_Value;
            }
            break;

           default:
            /* case IN_Wait: */
            if (autoquet_simulink_B.CCCodeBlock3 <=
                autoquet_simulink_B.pressure_set_point) {
              autoquet_simulink_DW.durationCounter_1_e = 0UL;
              autoquet_simulink_DW.is_Deflate = autoquet_simulink_IN_Idle_g;
            }
            break;
          }
        } else {
          /* case IN_Inflate: */
          if (!autoquet_simulink_B.CCCodeBlock3_o2) {
            if (autoquet_simulink_B.CCCodeBlock) {
              autoquet_simulink_DW.durationCounter_1_m = 0UL;
            }

            e_out = ((real_T)autoquet_simulink_DW.durationCounter_1_m >
                     autoquet_simulink_P.Waitperiodseconds_Value * 20.0F);
          } else {
            e_out = false;
          }

          if (e_out) {
            autoquet_simulink_DW.upper_bound_found = true;
            autoquet_simulink_DW.is_Inflate = autoquet_sim_IN_NO_ACTIVE_CHILD;
            autoquet_simulink_DW.pressure_upper_bound =
              autoquet_simulink_B.pressure_set_point;
            autoquet_simulink_B.initial_search = 1U;
            autoquet_simulink_DW.is_Find_initial_bounds =
              autoquet_simulink_IN_Deflate;
            autoquet_simulink_DW.is_Deflate = IN_Decrease_pressure_set_point;
            autoquet_simulink_B.pressure_set_point -=
              autoquet_simulink_P.Bulkincrement_Value;
          } else {
            switch (autoquet_simulink_DW.is_Inflate) {
             case autoquet_simulink_IN_Idle_gx:
              if (autoquet_simulink_B.CCCodeBlock) {
                autoquet_simulink_DW.durationCounter_1_p = 0UL;
              }

              if ((real_T)autoquet_simulink_DW.durationCounter_1_p >
                  autoquet_simulink_P.Waitperiodseconds_Value * 20.0F) {
                autoquet_simulink_DW.is_Inflate = IN_Increase_pressure_set_point;
                autoquet_simulink_B.pressure_set_point +=
                  autoquet_simulink_P.Bulkincrement_Value;
              }
              break;

             case IN_Increase_pressure_set_point:
              autoquet_simulink_DW.is_Inflate = autoquet_simulink_IN_wait;
              break;

             default:
              /* case IN_wait: */
              if (autoquet_simulink_B.CCCodeBlock3 >=
                  autoquet_simulink_B.pressure_set_point) {
                autoquet_simulink_DW.durationCounter_1_p = 0UL;
                autoquet_simulink_DW.is_Inflate = autoquet_simulink_IN_Idle_gx;
              }
              break;
            }
          }
        }
        break;

       default:
        /* case IN_Over_inflate: */
        break;
      }
    }

    /* case IN_Manual_mode: */
  } else if (autoquet_simulink_B.CCCodeBlock5_o3 == 1) {
    autoquet_simulink_DW.is_c3_autoquet_simulink =
      autoquet_simulink_IN_Auto_mode;
    autoquet_simulink_DW.is_Auto_mode = autoquet_IN_Find_initial_bounds;
    autoquet_simulink_B.pressure_set_point =
      autoquet_simulink_P.Initial_pressure_start_Value;
    autoquet_simulink_DW.upper_bound_found = false;
    autoquet_simulink_B.initial_search = 0U;
    autoquet_simulink_B.ideal_pressure_found = false;
    autoquet_simulink_DW.durationCounter_1_m = 0UL;
    autoquet_simulink_DW.is_Find_initial_bounds = autoquet_simulink_IN_Inflate;
    autoquet_simulink_DW.is_Inflate = autoquet_simulink_IN_wait;
  }

  if (!autoquet_simulink_B.CCCodeBlock_o2) {
    autoquet_simulink_DW.durationCounter_1++;
  } else {
    autoquet_simulink_DW.durationCounter_1 = 0UL;
  }

  if (!autoquet_simulink_B.CCCodeBlock) {
    autoquet_simulink_DW.durationCounter_1_p++;
    autoquet_simulink_DW.durationCounter_1_e++;
    autoquet_simulink_DW.durationCounter_1_m++;
  } else {
    autoquet_simulink_DW.durationCounter_1_p = 0UL;
    autoquet_simulink_DW.durationCounter_1_e = 0UL;
    autoquet_simulink_DW.durationCounter_1_m = 0UL;
  }

  /* End of Chart: '<Root>/Blood flow control stateflow' */
}

/* Model step function for TID3 */
void autoquet_simulink_step3(void)     /* Sample time: [0.1s, 0.0s] */
{
  l_codertarget_arduinobase_int_T *obj;
  int32_T cff;
  int32_T j;
  real32_T TmpSignalConversionAtCheckSig_0;
  real32_T TmpSignalConversionAtCheckSig_1;
  real32_T TmpSignalConversionAtCheckSigna;
  real32_T acc1;
  real32_T rtb_DigitalFilter;
  int16_T b_RegisterValue[3];
  int16_T k;
  int16_T n;
  uint8_T output_raw_0[6];
  uint8_T output_raw[2];
  uint8_T SwappedDataBytes;
  uint8_T status;

  /* MATLABSystem: '<S4>/I2C Read1' */
  if (autoquet_simulink_DW.obj_j.SampleTime !=
      autoquet_simulink_P.I2CRead1_SampleTime) {
    autoquet_simulink_DW.obj_j.SampleTime =
      autoquet_simulink_P.I2CRead1_SampleTime;
  }

  MW_I2C_MasterRead(autoquet_simulink_DW.obj_j.I2CDriverObj.MW_I2C_HANDLE, 40UL,
                    &output_raw[0], 2UL, false, false);
  memcpy((void *)&autoquet_simulink_B.I2CRead1[0], (void *)&output_raw[0],
         (size_t)2 * sizeof(uint8_T));

  /* End of MATLABSystem: '<S4>/I2C Read1' */

  /* S-Function (process_raw_sensor_reading): '<S4>/C//C++ Code Block3' */
  process_raw_sensor_reading_Outputs_wrapper(&autoquet_simulink_B.I2CRead1[0],
    &autoquet_simulink_B.CCCodeBlock3);

  /* DiscreteFir: '<S7>/Digital Filter' */
  rtb_DigitalFilter = autoquet_simulink_B.CCCodeBlock3;
  for (k = 0; k < 1; k++) {
    acc1 = 0.0F;

    /* load input sample */
    for (n = 0; n < 5; n++) {
      /* shift state */
      TmpSignalConversionAtCheckSigna = rtb_DigitalFilter;
      rtb_DigitalFilter = autoquet_simulink_DW.DigitalFilter_states[(int32_T)n];
      autoquet_simulink_DW.DigitalFilter_states[(int32_T)n] =
        TmpSignalConversionAtCheckSigna;

      /* compute one tap */
      acc1 += autoquet_simulink_P.DigitalFilter_Coefficients[(int32_T)n] *
        TmpSignalConversionAtCheckSigna;
    }

    /* compute last tap */
    /* store output sample */
    rtb_DigitalFilter = autoquet_simulink_P.DigitalFilter_Coefficients[(int32_T)
      n] * rtb_DigitalFilter + acc1;
  }

  /* End of DiscreteFir: '<S7>/Digital Filter' */

  /* Outputs for Atomic SubSystem: '<S4>/BNO055 IMU Sensor' */
  /* Start for Atomic SubSystem: '<S4>/BNO055 IMU Sensor' */
  /* MATLABSystem: '<S10>/Base sensor block' */
  if (autoquet_simulink_DW.obj_e.SampleTime !=
      autoquet_simulink_P.BNO055IMUSensor_SampleTime) {
    autoquet_simulink_DW.obj_e.SampleTime =
      autoquet_simulink_P.BNO055IMUSensor_SampleTime;
  }

  /* End of Start for SubSystem: '<S4>/BNO055 IMU Sensor' */
  if (!autoquet_simulink_DW.obj_e.IsFirstStep) {
    MW_getCurrentTime_in_milliseconds();
    autoquet_simulink_DW.obj_e.IsFirstStep = true;
  }

  obj = &autoquet_simulink_DW.obj_e.i2cObj;
  status = 8U;
  memcpy((void *)&SwappedDataBytes, (void *)&status, (size_t)1 * sizeof(uint8_T));
  status = MW_I2C_MasterWrite(obj->I2CDriverObj.MW_I2C_HANDLE, 41UL,
    &SwappedDataBytes, 1UL, true, false);
  if (status == 0) {
    MW_I2C_MasterRead(obj->I2CDriverObj.MW_I2C_HANDLE, 41UL, &output_raw_0[0],
                      6UL, false, true);
    memcpy((void *)&b_RegisterValue[0], (void *)&output_raw_0[0], (size_t)3 *
           sizeof(int16_T));
  } else {
    b_RegisterValue[0] = 0;
    b_RegisterValue[1] = 0;
    b_RegisterValue[2] = 0;
  }

  /* SignalConversion generated from: '<S8>/Check Signal Attributes' incorporates:
   *  DataTypeConversion: '<S4>/Cast To Single1'
   *  MATLABSystem: '<S10>/Base sensor block'
   * */
  TmpSignalConversionAtCheckSigna = (real32_T)((real_T)b_RegisterValue[0] /
    100.0);
  TmpSignalConversionAtCheckSig_0 = (real32_T)((real_T)b_RegisterValue[1] /
    100.0);
  TmpSignalConversionAtCheckSig_1 = (real32_T)((real_T)b_RegisterValue[2] /
    100.0);

  /* End of Outputs for SubSystem: '<S4>/BNO055 IMU Sensor' */

  /* DiscreteFir: '<S6>/Digital Filter' incorporates:
   *  SignalConversion generated from: '<S8>/Check Signal Attributes'
   */
  acc1 = rtb_DigitalFilter * autoquet_simulink_P.DigitalFilter_Coefficients_l[0];
  cff = 1L;
  for (j = autoquet_simulink_DW.DigitalFilter_circBuf; j < 5L; j++) {
    acc1 += autoquet_simulink_DW.DigitalFilter_states_i[j] *
      autoquet_simulink_P.DigitalFilter_Coefficients_l[cff];
    cff++;
  }

  for (j = 0L; j < autoquet_simulink_DW.DigitalFilter_circBuf; j++) {
    acc1 += autoquet_simulink_DW.DigitalFilter_states_i[j] *
      autoquet_simulink_P.DigitalFilter_Coefficients_l[cff];
    cff++;
  }

  autoquet_simulink_B.DigitalFilter[0L] = acc1;
  acc1 = TmpSignalConversionAtCheckSigna *
    autoquet_simulink_P.DigitalFilter_Coefficients_l[0];
  cff = 1L;
  for (j = autoquet_simulink_DW.DigitalFilter_circBuf; j < 5L; j++) {
    acc1 += autoquet_simulink_DW.DigitalFilter_states_i[j + 5L] *
      autoquet_simulink_P.DigitalFilter_Coefficients_l[cff];
    cff++;
  }

  for (j = 0L; j < autoquet_simulink_DW.DigitalFilter_circBuf; j++) {
    acc1 += autoquet_simulink_DW.DigitalFilter_states_i[j + 5L] *
      autoquet_simulink_P.DigitalFilter_Coefficients_l[cff];
    cff++;
  }

  autoquet_simulink_B.DigitalFilter[1L] = acc1;
  acc1 = TmpSignalConversionAtCheckSig_0 *
    autoquet_simulink_P.DigitalFilter_Coefficients_l[0];
  cff = 1L;
  for (j = autoquet_simulink_DW.DigitalFilter_circBuf; j < 5L; j++) {
    acc1 += autoquet_simulink_DW.DigitalFilter_states_i[j + 10L] *
      autoquet_simulink_P.DigitalFilter_Coefficients_l[cff];
    cff++;
  }

  for (j = 0L; j < autoquet_simulink_DW.DigitalFilter_circBuf; j++) {
    acc1 += autoquet_simulink_DW.DigitalFilter_states_i[j + 10L] *
      autoquet_simulink_P.DigitalFilter_Coefficients_l[cff];
    cff++;
  }

  autoquet_simulink_B.DigitalFilter[2L] = acc1;
  acc1 = TmpSignalConversionAtCheckSig_1 *
    autoquet_simulink_P.DigitalFilter_Coefficients_l[0];
  cff = 1L;
  for (j = autoquet_simulink_DW.DigitalFilter_circBuf; j < 5L; j++) {
    acc1 += autoquet_simulink_DW.DigitalFilter_states_i[j + 15L] *
      autoquet_simulink_P.DigitalFilter_Coefficients_l[cff];
    cff++;
  }

  for (j = 0L; j < autoquet_simulink_DW.DigitalFilter_circBuf; j++) {
    acc1 += autoquet_simulink_DW.DigitalFilter_states_i[j + 15L] *
      autoquet_simulink_P.DigitalFilter_Coefficients_l[cff];
    cff++;
  }

  autoquet_simulink_B.DigitalFilter[3L] = acc1;

  /* End of DiscreteFir: '<S6>/Digital Filter' */

  /* S-Function (custom_demux): '<S2>/C//C++ Code Block4' */
  custom_demux_Outputs_wrapper(&autoquet_simulink_B.DigitalFilter[0],
    &autoquet_simulink_B.CCCodeBlock4_o1, &autoquet_simulink_B.CCCodeBlock4_o2[0]);

  /* RateTransition generated from: '<S2>/C//C++ Code Block3' */
  autoquet_simulink_DW.TmpRTBAtCCCodeBlock3Inport3_sem = 1;

  /* RateTransition generated from: '<S2>/C//C++ Code Block3' */
  autoquet_simulink_B.TmpRTBAtCCCodeBlock3Inport3 =
    autoquet_simulink_DW.TmpRTBAtCCCodeBlock3Inport3_Buf;

  /* RateTransition generated from: '<S2>/C//C++ Code Block3' */
  autoquet_simulink_DW.TmpRTBAtCCCodeBlock3Inport3_sem = 0;

  /* S-Function (limb_movement_detector): '<S2>/C//C++ Code Block2' incorporates:
   *  Constant: '<S2>/accel_threshold'
   */
  limb_movement_detector_Outputs_wrapper(&autoquet_simulink_B.CCCodeBlock4_o2[0],
    &autoquet_simulink_P.accel_threshold_Value,
    &autoquet_simulink_B.CCCodeBlock2);

  /* S-Function (disruption_activity_monitor): '<S2>/C//C++ Code Block' incorporates:
   *  Constant: '<S2>/pause time (msec)'
   */
  disruption_activity_monitor_Outputs_wrapper
    (&autoquet_simulink_B.CCCodeBlock_o2, &autoquet_simulink_B.CCCodeBlock2,
     &autoquet_simulink_B.Timekeeper_o2,
     &autoquet_simulink_P.pausetimemsec_Value, &autoquet_simulink_B.CCCodeBlock);

  /* S-Function (blood_flow_detector_2): '<S2>/C//C++ Code Block3' */
  blood_flow_detector_2_Outputs_wrapper(&autoquet_simulink_B.CCCodeBlock4_o1,
    &autoquet_simulink_B.CCCodeBlock,
    &autoquet_simulink_B.TmpRTBAtCCCodeBlock3Inport3,
    &autoquet_simulink_B.CCCodeBlock3_o1, &autoquet_simulink_B.CCCodeBlock3_o2);

  /* MATLABSystem: '<S4>/Automode signal input' */
  if (autoquet_simulink_DW.obj_d.SampleTime !=
      autoquet_simulink_P.Automodesignalinput_SampleTime) {
    autoquet_simulink_DW.obj_d.SampleTime =
      autoquet_simulink_P.Automodesignalinput_SampleTime;
  }

  /* MATLABSystem: '<S4>/Automode signal input' */
  autoquet_simulink_B.Automodesignalinput = readDigitalPin(0);

  /* MATLABSystem: '<S4>/Decrease signal input' */
  if (autoquet_simulink_DW.obj_g.SampleTime !=
      autoquet_simulink_P.Decreasesignalinput_SampleTime) {
    autoquet_simulink_DW.obj_g.SampleTime =
      autoquet_simulink_P.Decreasesignalinput_SampleTime;
  }

  /* MATLABSystem: '<S4>/Decrease signal input' */
  autoquet_simulink_B.Decreasesignalinput = readDigitalPin(6);

  /* MATLABSystem: '<S4>/Increase signal input' */
  if (autoquet_simulink_DW.obj_h.SampleTime !=
      autoquet_simulink_P.Increasesignalinput_SampleTime) {
    autoquet_simulink_DW.obj_h.SampleTime =
      autoquet_simulink_P.Increasesignalinput_SampleTime;
  }

  /* MATLABSystem: '<S4>/Increase signal input' */
  autoquet_simulink_B.Increasesignalinput = readDigitalPin(4);

  /* Update for DiscreteFir: '<S6>/Digital Filter' incorporates:
   *  SignalConversion generated from: '<S8>/Check Signal Attributes'
   * */
  /* Update circular buffer index */
  autoquet_simulink_DW.DigitalFilter_circBuf--;
  if (autoquet_simulink_DW.DigitalFilter_circBuf < 0L) {
    autoquet_simulink_DW.DigitalFilter_circBuf = 4L;
  }

  /* Update circular buffer */
  autoquet_simulink_DW.DigitalFilter_states_i[autoquet_simulink_DW.DigitalFilter_circBuf]
    = rtb_DigitalFilter;
  autoquet_simulink_DW.DigitalFilter_states_i[autoquet_simulink_DW.DigitalFilter_circBuf
    + 5L] = TmpSignalConversionAtCheckSigna;
  autoquet_simulink_DW.DigitalFilter_states_i[autoquet_simulink_DW.DigitalFilter_circBuf
    + 10L] = TmpSignalConversionAtCheckSig_0;
  autoquet_simulink_DW.DigitalFilter_states_i[autoquet_simulink_DW.DigitalFilter_circBuf
    + 15L] = TmpSignalConversionAtCheckSig_1;

  /* End of Update for DiscreteFir: '<S6>/Digital Filter' */
}

/* Model initialize function */
void autoquet_simulink_initialize(void)
{
  {
    l_codertarget_arduinobase_int_T *obj;
    int16_T i;

    /* Start for S-Function (clock_counter): '<Root>/Time keeper' */

    /* S-Function Block: <Root>/Time keeper */
    clock_counter_Start_wrapper();

    /* Start for S-Function (button_control_logic): '<S4>/C//C++ Code Block5' */

    /* S-Function Block: <S4>/C//C++ Code Block5 */
    button_control_logic_Start_wrapper();

    /* Start for S-Function (display_pressures_signal): '<S5>/C//C++ Code Block4' */

    /* S-Function Block: <S5>/C//C++ Code Block4 */
    display_pressures_signal_Start_wrapper();

    /* Start for S-Function (limb_movement_detector): '<S2>/C//C++ Code Block2' incorporates:
     *  Constant: '<S2>/accel_threshold'
     */

    /* S-Function Block: <S2>/C//C++ Code Block2 */
    limb_movement_detector_Start_wrapper();

    /* Start for S-Function (blood_flow_detector_2): '<S2>/C//C++ Code Block3' */

    /* S-Function Block: <S2>/C//C++ Code Block3 */
    blood_flow_detector_2_Start_wrapper();
    autoquet_simulink_PrevZCX.Communicationblock_Trig_ZCE = UNINITIALIZED_ZCSIG;

    /* InitializeConditions for DiscreteFir: '<S7>/Digital Filter' */
    for (i = 0; i < 5; i++) {
      autoquet_simulink_DW.DigitalFilter_states[i] =
        autoquet_simulink_P.DigitalFilter_InitialStates;
    }

    /* End of InitializeConditions for DiscreteFir: '<S7>/Digital Filter' */

    /* InitializeConditions for DiscreteFir: '<S6>/Digital Filter' */
    for (i = 0; i < 20; i++) {
      autoquet_simulink_DW.DigitalFilter_states_i[i] =
        autoquet_simulink_P.DigitalFilter_InitialStates_p;
    }

    /* End of InitializeConditions for DiscreteFir: '<S6>/Digital Filter' */

    /* SystemInitialize for Triggered SubSystem: '<Root>/Communication block' */
    /* Start for MATLABSystem: '<S3>/Serial Transmit' */
    autoquet_simulink_DW.obj.matlabCodegenIsDeleted = false;
    autoquet_simulink_DW.obj.Protocol =
      autoquet_simulink_P.SerialTransmit_Protocol;
    autoquet_simulink_DW.obj.isInitialized = 1L;
    autoquet_simulink_DW.obj.port = 0.0;
    autoquet_simulink_DW.obj.dataSizeInBytes = 1.0;
    autoquet_simulink_DW.obj.dataType = 0.0;
    autoquet_simulink_DW.obj.sendModeEnum = 0.0;
    autoquet_simulink_DW.obj.sendFormatEnum = 0.0;
    MW_SCI_Open(0);
    autoquet_simulink_DW.obj.isSetupComplete = true;

    /* End of SystemInitialize for SubSystem: '<Root>/Communication block' */

    /* SystemInitialize for Chart: '<S5>/Chart' */
    autoquet_simulink_DW.transmit = autoquet_simulink_P.Chart_transmit;

    /* SystemInitialize for Atomic SubSystem: '<S4>/BNO055 IMU Sensor' */
    /* Start for MATLABSystem: '<S10>/Base sensor block' */
    autoquet_simulink_DW.obj_e.isInitialized = 0L;
    autoquet_simulink_DW.obj_e.IsFirstStep = false;
    obj = &autoquet_simulink_DW.obj_e.i2cObj;
    autoquet_simulink_DW.obj_e.i2cObj.DefaultMaximumBusSpeedInHz = 400000.0;
    autoquet_simulink_DW.obj_e.i2cObj.isInitialized = 0L;
    obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
    autoquet_simulink_DW.obj_e.i2cObj.matlabCodegenIsDeleted = false;
    autoquet_simulink_DW.obj_e.matlabCodegenIsDeleted = false;

    /* Start for Atomic SubSystem: '<S4>/BNO055 IMU Sensor' */
    autoquet_simulink_DW.obj_e.SampleTime =
      autoquet_simulink_P.BNO055IMUSensor_SampleTime;

    /* End of Start for SubSystem: '<S4>/BNO055 IMU Sensor' */
    autoquet_simul_SystemCore_setup(&autoquet_simulink_DW.obj_e);

    /* End of SystemInitialize for SubSystem: '<S4>/BNO055 IMU Sensor' */

    /* Start for MATLABSystem: '<S5>/Clock pin' */
    autoquet_simulink_DW.obj_n.matlabCodegenIsDeleted = false;
    autoquet_simulink_DW.obj_n.isInitialized = 1L;
    digitalIOSetup(8, 1);
    autoquet_simulink_DW.obj_n.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/Data pin' */
    autoquet_simulink_DW.obj_gj.matlabCodegenIsDeleted = false;
    autoquet_simulink_DW.obj_gj.isInitialized = 1L;
    digitalIOSetup(9, 1);
    autoquet_simulink_DW.obj_gj.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Output' */
    autoquet_simulink_DW.obj_jn.matlabCodegenIsDeleted = false;
    autoquet_simulink_DW.obj_jn.isInitialized = 1L;
    digitalIOSetup(10, 1);
    autoquet_simulink_DW.obj_jn.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/PWM' */
    autoquet_simulink_DW.obj_ec.matlabCodegenIsDeleted = false;
    autoquet_simulink_DW.obj_ec.isInitialized = 1L;
    autoquet_simulink_DW.obj_ec.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(5UL,
      0.0, 0.0);
    autoquet_simulink_DW.obj_ec.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/I2C Read1' */
    autoquet_simulink_DW.obj_j.DefaultMaximumBusSpeedInHz = 400000.0;
    autoquet_simulink_DW.obj_j.matlabCodegenIsDeleted = false;
    autoquet_simulink_DW.obj_j.SampleTime =
      autoquet_simulink_P.I2CRead1_SampleTime;
    autoquet_simulink_DW.obj_j.isInitialized = 1L;
    autoquet_simulink_DW.obj_j.I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(0,
      MW_I2C_MASTER);
    autoquet_simulink_DW.obj_j.BusSpeed = 100000UL;
    MW_I2C_SetBusSpeed(autoquet_simulink_DW.obj_j.I2CDriverObj.MW_I2C_HANDLE,
                       100000UL);
    autoquet_simulink_DW.obj_j.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Automode signal input' */
    autoquet_simulink_DW.obj_d.matlabCodegenIsDeleted = false;
    autoquet_simulink_DW.obj_d.SampleTime =
      autoquet_simulink_P.Automodesignalinput_SampleTime;
    autoquet_simulink_DW.obj_d.isInitialized = 1L;
    digitalIOSetup(0, 0);
    autoquet_simulink_DW.obj_d.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Decrease signal input' */
    autoquet_simulink_DW.obj_g.matlabCodegenIsDeleted = false;
    autoquet_simulink_DW.obj_g.SampleTime =
      autoquet_simulink_P.Decreasesignalinput_SampleTime;
    autoquet_simulink_DW.obj_g.isInitialized = 1L;
    digitalIOSetup(6, 0);
    autoquet_simulink_DW.obj_g.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Increase signal input' */
    autoquet_simulink_DW.obj_h.matlabCodegenIsDeleted = false;
    autoquet_simulink_DW.obj_h.SampleTime =
      autoquet_simulink_P.Increasesignalinput_SampleTime;
    autoquet_simulink_DW.obj_h.isInitialized = 1L;
    digitalIOSetup(4, 0);
    autoquet_simulink_DW.obj_h.isSetupComplete = true;
  }
}

/* Model terminate function */
void autoquet_simulink_terminate(void)
{
  l_codertarget_arduinobase_int_T *obj;

  /* Terminate for Triggered SubSystem: '<Root>/Communication block' */
  /* Terminate for MATLABSystem: '<S3>/Serial Transmit' */
  if (!autoquet_simulink_DW.obj.matlabCodegenIsDeleted) {
    autoquet_simulink_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S3>/Serial Transmit' */
  /* End of Terminate for SubSystem: '<Root>/Communication block' */

  /* Terminate for MATLABSystem: '<S5>/Clock pin' */
  if (!autoquet_simulink_DW.obj_n.matlabCodegenIsDeleted) {
    autoquet_simulink_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S5>/Clock pin' */

  /* Terminate for MATLABSystem: '<S5>/Data pin' */
  if (!autoquet_simulink_DW.obj_gj.matlabCodegenIsDeleted) {
    autoquet_simulink_DW.obj_gj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S5>/Data pin' */

  /* Terminate for MATLABSystem: '<S4>/Digital Output' */
  if (!autoquet_simulink_DW.obj_jn.matlabCodegenIsDeleted) {
    autoquet_simulink_DW.obj_jn.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Output' */

  /* Terminate for MATLABSystem: '<S4>/PWM' */
  if (!autoquet_simulink_DW.obj_ec.matlabCodegenIsDeleted) {
    autoquet_simulink_DW.obj_ec.matlabCodegenIsDeleted = true;
    if ((autoquet_simulink_DW.obj_ec.isInitialized == 1L) &&
        autoquet_simulink_DW.obj_ec.isSetupComplete) {
      autoquet_simulink_DW.obj_ec.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (5UL);
      MW_PWM_SetDutyCycle(autoquet_simulink_DW.obj_ec.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      autoquet_simulink_DW.obj_ec.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (5UL);
      MW_PWM_Close(autoquet_simulink_DW.obj_ec.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/PWM' */

  /* Terminate for MATLABSystem: '<S4>/I2C Read1' */
  if (!autoquet_simulink_DW.obj_j.matlabCodegenIsDeleted) {
    autoquet_simulink_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((autoquet_simulink_DW.obj_j.isInitialized == 1L) &&
        autoquet_simulink_DW.obj_j.isSetupComplete) {
      MW_I2C_Close(autoquet_simulink_DW.obj_j.I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/I2C Read1' */

  /* Terminate for Atomic SubSystem: '<S4>/BNO055 IMU Sensor' */
  /* Terminate for MATLABSystem: '<S10>/Base sensor block' */
  if (!autoquet_simulink_DW.obj_e.matlabCodegenIsDeleted) {
    autoquet_simulink_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((autoquet_simulink_DW.obj_e.isInitialized == 1L) &&
        autoquet_simulink_DW.obj_e.isSetupComplete) {
      obj = &autoquet_simulink_DW.obj_e.i2cObj;
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  obj = &autoquet_simulink_DW.obj_e.i2cObj;
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    if (obj->isInitialized == 1L) {
      obj->isInitialized = 2L;
    }
  }

  /* End of Terminate for MATLABSystem: '<S10>/Base sensor block' */
  /* End of Terminate for SubSystem: '<S4>/BNO055 IMU Sensor' */

  /* Terminate for MATLABSystem: '<S4>/Automode signal input' */
  if (!autoquet_simulink_DW.obj_d.matlabCodegenIsDeleted) {
    autoquet_simulink_DW.obj_d.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S4>/Automode signal input' */

  /* Terminate for MATLABSystem: '<S4>/Decrease signal input' */
  if (!autoquet_simulink_DW.obj_g.matlabCodegenIsDeleted) {
    autoquet_simulink_DW.obj_g.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S4>/Decrease signal input' */

  /* Terminate for MATLABSystem: '<S4>/Increase signal input' */
  if (!autoquet_simulink_DW.obj_h.matlabCodegenIsDeleted) {
    autoquet_simulink_DW.obj_h.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S4>/Increase signal input' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
