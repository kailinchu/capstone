/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: autoquet_simulink_expo_model.c
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

#include "autoquet_simulink_expo_model.h"
#include "autoquet_simulink_expo_model_types.h"
#include "rtwtypes.h"
#include <string.h>
#include <stddef.h>
#include "autoquet_simulink_expo_model_private.h"
#include "send_params.h"
#include "send_params_private.h"

/* Named constants for Chart: '<Root>/Blood flow control stateflow' */
#define IN_Binary_search_ideal_pressure ((uint8_T)1U)
#define IN_Decrease_pressure_set_point ((uint8_T)1U)
#define IN_Increase_pressure_set_point ((uint8_T)2U)
#define au_IN_Adjust_pressure_set_point ((uint8_T)1U)
#define autoque_IN_Ideal_pressure_found ((uint8_T)2U)
#define autoquet_IN_Find_initial_bounds ((uint8_T)2U)
#define autoquet_si_IN_slight_deflation ((uint8_T)3U)
#define autoquet_sim_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define autoquet_simuli_IN_Steady_state ((uint8_T)3U)
#define autoquet_simulin_IN_Manual_mode ((uint8_T)2U)
#define autoquet_simulink_IN_re_inflate ((uint8_T)2U)
#define autoquet_simulink__IN_Auto_mode ((uint8_T)1U)
#define autoquet_simulink__IN_Too_loose ((uint8_T)4U)
#define autoquet_simulink__IN_Too_tight ((uint8_T)5U)
#define autoquet_simulink_ex_IN_Deflate ((uint8_T)1U)
#define autoquet_simulink_ex_IN_Idle_gx ((uint8_T)1U)
#define autoquet_simulink_ex_IN_Inflate ((uint8_T)2U)
#define autoquet_simulink_exp_IN_Idle_g ((uint8_T)2U)
#define autoquet_simulink_exp_IN_Wait_m ((uint8_T)1U)
#define autoquet_simulink_expo__IN_Idle ((uint8_T)3U)
#define autoquet_simulink_expo__IN_Wait ((uint8_T)3U)
#define autoquet_simulink_expo__IN_wait ((uint8_T)3U)

/* Named constants for Chart: '<Root>/Data send controller' */
#define autoquet_simuli_IN_request_data ((uint8_T)1U)
#define autoquet_simulink_exp_IN_wait_c ((uint8_T)2U)

/* Named constants for Chart: '<S5>/Indicator controller' */
#define autoquet_sim_IN_Blink_indicator ((uint8_T)1U)
#define autoquet_sim_IN_Solid_indicator ((uint8_T)3U)
#define autoquet_simul_IN_Indicator_off ((uint8_T)2U)
#define autoquet_simulink_ex_IN_led_off ((uint8_T)1U)
#define autoquet_simulink_exp_IN_led_on ((uint8_T)2U)

/* Named constants for Chart: '<S6>/Transmit firmware' */
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
#define autoquet_simulink_IN_latch_data ((uint8_T)7U)
#define autoquet_simulink__IN_data_high ((uint8_T)3U)
#define autoquet_simulink__IN_reset_clk ((uint8_T)9U)
#define autoquet_simulink__IN_send_data ((uint8_T)5U)
#define autoquet_simulink_e_IN_data_low ((uint8_T)4U)
#define autoquet_simulink_ex_IN_ack_bit ((uint8_T)1U)
#define autoquet_simulink_exp_IN_idler1 ((uint8_T)6U)
#define autoquet_simulink_expo_IN_idler ((uint8_T)5U)
#define autoquet_simulink_expo__IN_Stop ((uint8_T)2U)
#define autoquet_simulink_expo__IN_init ((uint8_T)4U)

/* Block signals (default storage) */
B_autoquet_simulink_expo_mode_T autoquet_simulink_expo_model_B;

/* Block states (default storage) */
DW_autoquet_simulink_expo_mod_T autoquet_simulink_expo_model_DW;

/* Real-time model */
static RT_MODEL_autoquet_simulink_ex_T autoquet_simulink_expo_model_M_;
RT_MODEL_autoquet_simulink_ex_T *const autoquet_simulink_expo_model_M =
  &autoquet_simulink_expo_model_M_;

/* Forward declaration for local functions */
static void autoque_enter_atomic_latch_data(void);
static void autoque_exit_internal_send_data(void);
static void exit_internal_Find_initial_boun(void);
static void autoquet_simul_SystemCore_setup(codertarget_arduinobase_int_n_T *obj);
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void autoquet_simulink_expo_model_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(autoquet_simulink_expo_model_M, 1));
  eventFlags[2] = ((boolean_T)rtmStepTask(autoquet_simulink_expo_model_M, 2));
  eventFlags[3] = ((boolean_T)rtmStepTask(autoquet_simulink_expo_model_M, 3));
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
  (autoquet_simulink_expo_model_M->Timing.TaskCounters.TID[1])++;
  if ((autoquet_simulink_expo_model_M->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [0.001s, 0.0s] */
    autoquet_simulink_expo_model_M->Timing.TaskCounters.TID[1] = 0;
  }

  (autoquet_simulink_expo_model_M->Timing.TaskCounters.TID[2])++;
  if ((autoquet_simulink_expo_model_M->Timing.TaskCounters.TID[2]) > 499) {/* Sample time: [0.05s, 0.0s] */
    autoquet_simulink_expo_model_M->Timing.TaskCounters.TID[2] = 0;
  }

  (autoquet_simulink_expo_model_M->Timing.TaskCounters.TID[3])++;
  if ((autoquet_simulink_expo_model_M->Timing.TaskCounters.TID[3]) > 999) {/* Sample time: [0.1s, 0.0s] */
    autoquet_simulink_expo_model_M->Timing.TaskCounters.TID[3] = 0;
  }
}

/* Function for Chart: '<S6>/Transmit firmware' */
static void autoque_enter_atomic_latch_data(void)
{
  uint16_T tmp;
  autoquet_simulink_expo_model_B.clk_pin = true;
  autoquet_simulink_expo_model_DW.buffer = (uint8_T)((uint16_T)
    autoquet_simulink_expo_model_DW.buffer >> 1);
  tmp = autoquet_simulink_expo_model_DW.bit_iterator + 1U;
  if (autoquet_simulink_expo_model_DW.bit_iterator + 1U > 255U) {
    tmp = 255U;
  }

  autoquet_simulink_expo_model_DW.bit_iterator = (uint8_T)tmp;
}

/* Function for Chart: '<S6>/Transmit firmware' */
static void autoque_exit_internal_send_data(void)
{
  switch (autoquet_simulink_expo_model_DW.is_send_data) {
   case autoquet_simulink_ex_IN_ack_bit:
    autoquet_simulink_expo_model_B.data_pin = false;
    autoquet_simulink_expo_model_DW.is_send_data =
      autoquet_sim_IN_NO_ACTIVE_CHILD;
    break;

   case autoquet_simuli_IN_buffer_reset:
    autoquet_simulink_expo_model_DW.bit_iterator = 1U;
    autoquet_simulink_expo_model_DW.is_send_data =
      autoquet_sim_IN_NO_ACTIVE_CHILD;
    break;

   case autoquet_simulink_expo_IN_idler:
    autoquet_simulink_expo_model_B.clk_pin = false;
    autoquet_simulink_expo_model_DW.is_send_data =
      autoquet_sim_IN_NO_ACTIVE_CHILD;
    break;

   case autoquet_simulink_exp_IN_idler1:
    autoquet_simulink_expo_model_B.clk_pin = true;
    autoquet_simulink_expo_model_DW.is_send_data =
      autoquet_sim_IN_NO_ACTIVE_CHILD;
    break;

   default:
    autoquet_simulink_expo_model_DW.is_send_data =
      autoquet_sim_IN_NO_ACTIVE_CHILD;
    break;
  }
}

/* Function for Chart: '<Root>/Blood flow control stateflow' */
static void exit_internal_Find_initial_boun(void)
{
  switch (autoquet_simulink_expo_model_DW.is_Find_initial_bounds) {
   case autoquet_simulink_ex_IN_Deflate:
    autoquet_simulink_expo_model_DW.is_Deflate = autoquet_sim_IN_NO_ACTIVE_CHILD;
    autoquet_simulink_expo_model_DW.pressure_lower_bound =
      autoquet_simulink_expo_model_B.pressure_set_point;
    autoquet_simulink_expo_model_DW.is_Find_initial_bounds =
      autoquet_sim_IN_NO_ACTIVE_CHILD;
    break;

   case autoquet_simulink_ex_IN_Inflate:
    autoquet_simulink_expo_model_DW.is_Inflate = autoquet_sim_IN_NO_ACTIVE_CHILD;
    autoquet_simulink_expo_model_DW.pressure_upper_bound =
      autoquet_simulink_expo_model_B.pressure_set_point;
    autoquet_simulink_expo_model_B.initial_search = 1U;
    autoquet_simulink_expo_model_DW.is_Find_initial_bounds =
      autoquet_sim_IN_NO_ACTIVE_CHILD;
    break;
  }
}

static void autoquet_simul_SystemCore_setup(codertarget_arduinobase_int_n_T *obj)
{
  uint8_T SwappedDataBytes[2];
  uint8_T b_SwappedDataBytes[2];
  uint8_T CastedData;
  uint8_T SwappedDataBytes_0;
  uint8_T status;

  /* Start for MATLABSystem: '<S11>/Base sensor block' */
  obj->isInitialized = 1L;
  obj->i2cObj.I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(0, MW_I2C_MASTER);
  obj->i2cObj.BusSpeed = 100000UL;
  MW_I2C_SetBusSpeed(obj->i2cObj.I2CDriverObj.MW_I2C_HANDLE,
                     obj->i2cObj.BusSpeed);
  MW_delay_in_milliseconds(600UL);
  status = 0U;

  /* Start for MATLABSystem: '<S11>/Base sensor block' */
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
void autoquet_simulink_expo_model_step0(void) /* Sample time: [0.0001s, 0.0s] */
{
  {                                    /* Sample time: [0.0001s, 0.0s] */
    rate_monotonic_scheduler();
  }
}

/* Model step function for TID1 */
void autoquet_simulink_expo_model_step1(void) /* Sample time: [0.001s, 0.0s] */
{
  real_T y;
  uint16_T qY;
  uint8_T y_0;
  boolean_T rtb_indicator_pin;

  /* S-Function (time_keeper): '<Root>/C//C++ Code Block' */
  time_keeper_Outputs_wrapper(&autoquet_simulink_expo_model_B.CCCodeBlock_o1_k[0],
    &autoquet_simulink_expo_model_B.CCCodeBlock_o2);

  /* Outputs for Atomic SubSystem: '<Root>/Pressure Control' */
  /* MATLABSystem: '<S5>/Automode signal input' */
  if (autoquet_simulink_expo_model_DW.obj_d.SampleTime !=
      autoquet_simulink_expo_model_P.Automodesignalinput_SampleTime) {
    autoquet_simulink_expo_model_DW.obj_d.SampleTime =
      autoquet_simulink_expo_model_P.Automodesignalinput_SampleTime;
  }

  autoquet_simulink_expo_model_B.Automodesignalinput = readDigitalPin(0);

  /* End of MATLABSystem: '<S5>/Automode signal input' */

  /* MATLABSystem: '<S5>/Increase signal input' */
  if (autoquet_simulink_expo_model_DW.obj_h.SampleTime !=
      autoquet_simulink_expo_model_P.Increasesignalinput_SampleTime) {
    autoquet_simulink_expo_model_DW.obj_h.SampleTime =
      autoquet_simulink_expo_model_P.Increasesignalinput_SampleTime;
  }

  autoquet_simulink_expo_model_B.Increasesignalinput = readDigitalPin(4);

  /* End of MATLABSystem: '<S5>/Increase signal input' */

  /* MATLABSystem: '<S5>/Decrease signal input' */
  if (autoquet_simulink_expo_model_DW.obj_g.SampleTime !=
      autoquet_simulink_expo_model_P.Decreasesignalinput_SampleTime) {
    autoquet_simulink_expo_model_DW.obj_g.SampleTime =
      autoquet_simulink_expo_model_P.Decreasesignalinput_SampleTime;
  }

  autoquet_simulink_expo_model_B.Decreasesignalinput = readDigitalPin(6);

  /* End of MATLABSystem: '<S5>/Decrease signal input' */

  /* SignalConversion generated from: '<S5>/C//C++ Code Block5' */
  autoquet_simulink_expo_model_B.TmpSignalConversionAtCCCodeBloc[0] =
    autoquet_simulink_expo_model_B.Automodesignalinput;
  autoquet_simulink_expo_model_B.TmpSignalConversionAtCCCodeBloc[1] =
    autoquet_simulink_expo_model_B.Increasesignalinput;
  autoquet_simulink_expo_model_B.TmpSignalConversionAtCCCodeBloc[2] =
    autoquet_simulink_expo_model_B.Decreasesignalinput;

  /* S-Function (button_control_logic): '<S5>/C//C++ Code Block5' */
  button_control_logic_Outputs_wrapper
    (&autoquet_simulink_expo_model_B.TmpSignalConversionAtCCCodeBloc[0],
     &autoquet_simulink_expo_model_B.CCCodeBlock_o2,
     &autoquet_simulink_expo_model_B.pressure_set_point,
     &autoquet_simulink_expo_model_B.initial_search,
     &autoquet_simulink_expo_model_B.CCCodeBlock5_o1,
     &autoquet_simulink_expo_model_B.CCCodeBlock5_o2,
     &autoquet_simulink_expo_model_B.CCCodeBlock5_o3);

  /* Chart: '<S5>/Indicator controller' */
  if (autoquet_simulink_expo_model_DW.temporalCounter_i1_h < 255U) {
    autoquet_simulink_expo_model_DW.temporalCounter_i1_h++;
  }

  if (autoquet_simulink_expo_model_DW.is_active_c4_autoquet_simulink_ == 0U) {
    autoquet_simulink_expo_model_DW.is_active_c4_autoquet_simulink_ = 1U;
    autoquet_simulink_expo_model_DW.is_c4_autoquet_simulink_expo_mo =
      autoquet_simul_IN_Indicator_off;
    rtb_indicator_pin = false;
  } else {
    switch (autoquet_simulink_expo_model_DW.is_c4_autoquet_simulink_expo_mo) {
     case autoquet_sim_IN_Blink_indicator:
      if (!autoquet_simulink_expo_model_B.ideal_pressure_found_c) {
        autoquet_simulink_expo_model_DW.durationCounter_1 = 0UL;
      }

      if (autoquet_simulink_expo_model_DW.durationCounter_1 > 200UL) {
        autoquet_simulink_expo_model_DW.is_Blink_indicator =
          autoquet_sim_IN_NO_ACTIVE_CHILD;
        autoquet_simulink_expo_model_DW.is_c4_autoquet_simulink_expo_mo =
          autoquet_sim_IN_Solid_indicator;
        rtb_indicator_pin = true;
      } else if (autoquet_simulink_expo_model_B.CCCodeBlock5_o3 == 0) {
        autoquet_simulink_expo_model_DW.is_Blink_indicator =
          autoquet_sim_IN_NO_ACTIVE_CHILD;
        autoquet_simulink_expo_model_DW.is_c4_autoquet_simulink_expo_mo =
          autoquet_simul_IN_Indicator_off;
        rtb_indicator_pin = false;
      } else if (autoquet_simulink_expo_model_DW.is_Blink_indicator ==
                 autoquet_simulink_ex_IN_led_off) {
        rtb_indicator_pin = false;
        if (autoquet_simulink_expo_model_DW.temporalCounter_i1_h >= 200U) {
          autoquet_simulink_expo_model_DW.temporalCounter_i1_h = 0U;
          autoquet_simulink_expo_model_DW.is_Blink_indicator =
            autoquet_simulink_exp_IN_led_on;
          rtb_indicator_pin = true;
        }
      } else {
        /* case IN_led_on: */
        rtb_indicator_pin = true;
        if (autoquet_simulink_expo_model_DW.temporalCounter_i1_h >= 200U) {
          autoquet_simulink_expo_model_DW.temporalCounter_i1_h = 0U;
          autoquet_simulink_expo_model_DW.is_Blink_indicator =
            autoquet_simulink_ex_IN_led_off;
          rtb_indicator_pin = false;
        }
      }
      break;

     case autoquet_simul_IN_Indicator_off:
      rtb_indicator_pin = false;
      if (autoquet_simulink_expo_model_B.CCCodeBlock5_o3 == 1) {
        autoquet_simulink_expo_model_DW.durationCounter_1 = 0UL;
        autoquet_simulink_expo_model_DW.is_c4_autoquet_simulink_expo_mo =
          autoquet_sim_IN_Blink_indicator;
        autoquet_simulink_expo_model_DW.temporalCounter_i1_h = 0U;
        autoquet_simulink_expo_model_DW.is_Blink_indicator =
          autoquet_simulink_ex_IN_led_off;
      }
      break;

     default:
      /* case IN_Solid_indicator: */
      rtb_indicator_pin = true;
      if (autoquet_simulink_expo_model_B.CCCodeBlock5_o3 == 0) {
        autoquet_simulink_expo_model_DW.is_c4_autoquet_simulink_expo_mo =
          autoquet_simul_IN_Indicator_off;
        rtb_indicator_pin = false;
      }
      break;
    }
  }

  if (autoquet_simulink_expo_model_B.ideal_pressure_found_c) {
    autoquet_simulink_expo_model_DW.durationCounter_1++;
  } else {
    autoquet_simulink_expo_model_DW.durationCounter_1 = 0UL;
  }

  /* End of Chart: '<S5>/Indicator controller' */

  /* MATLABSystem: '<S5>/D6' */
  writeDigitalPin(11, (uint8_T)rtb_indicator_pin);

  /* Sum: '<S5>/Sum' */
  autoquet_simulink_expo_model_B.Sum =
    autoquet_simulink_expo_model_B.CCCodeBlock5_o1 -
    autoquet_simulink_expo_model_B.CCCodeBlock3;

  /* S-Function (motor_drive_control): '<S5>/C//C++ Code Block' */
  motor_drive_control_Outputs_wrapper(&autoquet_simulink_expo_model_B.Sum,
    &autoquet_simulink_expo_model_B.CCCodeBlock,
    &autoquet_simulink_expo_model_B.CCCodeBlock5_o2,
    &autoquet_simulink_expo_model_B.CCCodeBlock_o1,
    &autoquet_simulink_expo_model_B.CCCodeBlock_o2_l,
    &autoquet_simulink_expo_model_B.CCCodeBlock_o3);

  /* MATLABSystem: '<S5>/Digital Output' */
  writeDigitalPin(10, (uint8_T)autoquet_simulink_expo_model_B.CCCodeBlock_o3);

  /* MATLABSystem: '<S5>/PWM' */
  autoquet_simulink_expo_model_DW.obj_ec.PWMDriverObj.MW_PWM_HANDLE =
    MW_PWM_GetHandle(5UL);

  /* Start for MATLABSystem: '<S5>/PWM' */
  if (autoquet_simulink_expo_model_B.CCCodeBlock_o1 <= 255.0F) {
    y = autoquet_simulink_expo_model_B.CCCodeBlock_o1;
  } else {
    y = 255.0;
  }

  if (!(y >= 0.0)) {
    y = 0.0;
  }

  /* MATLABSystem: '<S5>/PWM' */
  MW_PWM_SetDutyCycle
    (autoquet_simulink_expo_model_DW.obj_ec.PWMDriverObj.MW_PWM_HANDLE, y);

  /* MATLABSystem: '<S5>/RX LED (D5)' */
  writeDigitalPin(17, (uint8_T)rtb_indicator_pin);

  /* End of Outputs for SubSystem: '<Root>/Pressure Control' */

  /* Outputs for Atomic SubSystem: '<Root>/Stopwatch' */
  /* S-Function (dec_to_sev_seg): '<S6>/C//C++ Code Block3' */
  dec_to_sev_seg_Outputs_wrapper
    (&autoquet_simulink_expo_model_B.CCCodeBlock_o1_k[0],
     &autoquet_simulink_expo_model_B.CCCodeBlock3_h[0]);

  /* S-Function (display_pressures_signal): '<S6>/C//C++ Code Block4' */
  display_pressures_signal_Outputs_wrapper
    (&autoquet_simulink_expo_model_B.CCCodeBlock5_o1,
     &autoquet_simulink_expo_model_B.CCCodeBlock5_o3,
     &autoquet_simulink_expo_model_B.CCCodeBlock_o2,
     &autoquet_simulink_expo_model_B.CCCodeBlock4);

  /* S-Function (pressure_display): '<S6>/C//C++ Code Block1' */
  pressure_display_Outputs_wrapper
    (&autoquet_simulink_expo_model_B.CCCodeBlock5_o1,
     &autoquet_simulink_expo_model_B.CCCodeBlock1[0]);

  /* Chart: '<S6>/Transmit firmware' incorporates:
   *  S-Function (dec_to_sev_seg): '<S6>/C//C++ Code Block3'
   *  S-Function (pressure_display): '<S6>/C//C++ Code Block1'
   */
  if (autoquet_simulink_expo_model_DW.is_active_c1_autoquet_simulink_ == 0U) {
    autoquet_simulink_expo_model_DW.is_active_c1_autoquet_simulink_ = 1U;
    autoquet_simulink_expo_model_DW.is_c1_autoquet_simulink_expo_mo =
      autoquet_IN_display_multiplexer;
    autoquet_simulink_expo_model_DW.flash_ratio = 7U;
  } else {
    switch (autoquet_simulink_expo_model_DW.is_c1_autoquet_simulink_expo_mo) {
     case autoquet_IN_display_multiplexer:
      switch (autoquet_simulink_expo_model_B.CCCodeBlock4) {
       case 1:
        autoquet_simulink_expo_model_DW.is_c1_autoquet_simulink_expo_mo =
          autoquet_simu_IN_flashing_logic;
        qY = autoquet_simulink_expo_model_DW.pressure_flash + 1U;
        if (autoquet_simulink_expo_model_DW.pressure_flash + 1U > 255U) {
          qY = 255U;
        }

        autoquet_simulink_expo_model_DW.pressure_flash = (uint8_T)qY;
        break;

       case 0:
        autoquet_simulink_expo_model_DW.is_c1_autoquet_simulink_expo_mo =
          autoquet_IN_set_time_to_display;
        autoquet_simulink_expo_model_DW.to_screen[0] =
          autoquet_simulink_expo_model_B.CCCodeBlock3_h[0];
        autoquet_simulink_expo_model_DW.to_screen[1] =
          autoquet_simulink_expo_model_B.CCCodeBlock3_h[1];
        autoquet_simulink_expo_model_DW.to_screen[2] =
          autoquet_simulink_expo_model_B.CCCodeBlock3_h[2];
        autoquet_simulink_expo_model_DW.to_screen[3] =
          autoquet_simulink_expo_model_B.CCCodeBlock3_h[3];
        break;

       default:
        autoquet_simulink_expo_model_DW.flash_ratio = 7U;
        break;
      }
      break;

     case autoquet_simu_IN_flashing_logic:
      if (autoquet_simulink_expo_model_DW.flash_ratio == 0) {
        y_0 = 0U;
      } else {
        y_0 = (uint8_T)(autoquet_simulink_expo_model_DW.pressure_flash %
                        autoquet_simulink_expo_model_DW.flash_ratio);
      }

      if (y_0 != 0) {
        autoquet_simulink_expo_model_DW.is_c1_autoquet_simulink_expo_mo =
          auto_IN_set_pressure_to_display;
        autoquet_simulink_expo_model_DW.to_screen[0] =
          autoquet_simulink_expo_model_B.CCCodeBlock1[0];
        autoquet_simulink_expo_model_DW.to_screen[1] =
          autoquet_simulink_expo_model_B.CCCodeBlock1[1];
        autoquet_simulink_expo_model_DW.to_screen[2] =
          autoquet_simulink_expo_model_B.CCCodeBlock1[2];
        autoquet_simulink_expo_model_DW.to_screen[3] =
          autoquet_simulink_expo_model_B.CCCodeBlock1[3];
      } else {
        if (autoquet_simulink_expo_model_DW.flash_ratio == 0) {
          y_0 = 0U;
        } else {
          y_0 = (uint8_T)(autoquet_simulink_expo_model_DW.pressure_flash %
                          autoquet_simulink_expo_model_DW.flash_ratio);
        }

        if (y_0 == 0) {
          autoquet_simulink_expo_model_DW.is_c1_autoquet_simulink_expo_mo =
            autoque_IN_set_blank_to_display;
          autoquet_simulink_expo_model_DW.to_screen[0] = 0U;
          autoquet_simulink_expo_model_DW.to_screen[1] = 0U;
          autoquet_simulink_expo_model_DW.to_screen[2] = 0U;
          autoquet_simulink_expo_model_DW.to_screen[3] = 0U;
          autoquet_simulink_expo_model_DW.pressure_flash = 0U;
        }
      }
      break;

     case autoquet_si_IN_sending_firmware:
      if (autoquet_simulink_expo_model_DW.full_data_sent) {
        switch (autoquet_simulink_expo_model_DW.is_sending_firmware) {
         case autoquet_simulink_expo__IN_Stop:
          autoquet_simulink_expo_model_B.data_pin = true;
          autoquet_simulink_expo_model_DW.is_sending_firmware =
            autoquet_sim_IN_NO_ACTIVE_CHILD;
          break;

         case autoquet_simulink__IN_send_data:
          autoque_exit_internal_send_data();
          autoquet_simulink_expo_model_B.clk_pin = true;
          autoquet_simulink_expo_model_DW.word_iterator = 1U;
          autoquet_simulink_expo_model_DW.is_sending_firmware =
            autoquet_sim_IN_NO_ACTIVE_CHILD;
          break;

         default:
          autoquet_simulink_expo_model_DW.is_command_flow =
            autoquet_sim_IN_NO_ACTIVE_CHILD;
          autoquet_simulink_expo_model_DW.is_sending_firmware =
            autoquet_sim_IN_NO_ACTIVE_CHILD;
          break;
        }

        autoquet_simulink_expo_model_DW.is_c1_autoquet_simulink_expo_mo =
          autoquet_IN_display_multiplexer;
        autoquet_simulink_expo_model_DW.flash_ratio = 7U;
      } else {
        switch (autoquet_simulink_expo_model_DW.is_sending_firmware) {
         case autoquet_simuli_IN_Start_signal:
          autoquet_simulink_expo_model_DW.is_sending_firmware =
            autoquet_simulink__IN_send_data;
          autoquet_simulink_expo_model_DW.is_send_data =
            autoquet_simulink__IN_reset_clk;
          autoquet_simulink_expo_model_B.clk_pin = false;
          break;

         case autoquet_simulink_expo__IN_Stop:
          if (autoquet_simulink_expo_model_DW.command == 136) {
            autoquet_simulink_expo_model_DW.full_data_sent = true;
          }

          autoquet_simulink_expo_model_B.data_pin = true;
          autoquet_simulink_expo_model_DW.is_sending_firmware =
            autoquet_simuli_IN_command_flow;
          autoquet_simulink_expo_model_DW.is_command_flow =
            autoquet_simuli_IN_find_command;
          break;

         case autoquet_simuli_IN_command_flow:
          if (autoquet_simulink_expo_model_DW.transmit) {
            autoquet_simulink_expo_model_DW.is_command_flow =
              autoquet_sim_IN_NO_ACTIVE_CHILD;
            autoquet_simulink_expo_model_DW.is_sending_firmware =
              autoquet_simuli_IN_Start_signal;
            autoquet_simulink_expo_model_B.data_pin = false;
            autoquet_simulink_expo_model_DW.buffer =
              autoquet_simulink_expo_model_DW.command;
            autoquet_simulink_expo_model_DW.bit_iterator = 1U;
            autoquet_simulink_expo_model_DW.word_iterator = 1U;
          } else {
            switch (autoquet_simulink_expo_model_DW.is_command_flow) {
             case autoquet_simu_IN_data_directive:
             case autoquet_sim_IN_display_control:
              break;

             case autoquet_simuli_IN_find_command:
              switch (autoquet_simulink_expo_model_DW.command_state) {
               case 0:
                autoquet_simulink_expo_model_DW.is_command_flow =
                  autoquet_simu_IN_data_directive;
                autoquet_simulink_expo_model_DW.command = 64U;
                autoquet_simulink_expo_model_DW.len = 1U;
                qY = autoquet_simulink_expo_model_DW.command_state + 1U;
                if (autoquet_simulink_expo_model_DW.command_state + 1U > 255U) {
                  qY = 255U;
                }

                autoquet_simulink_expo_model_DW.command_state = (uint8_T)qY;
                autoquet_simulink_expo_model_DW.transmit = true;
                break;

               case 1:
                autoquet_simulink_expo_model_DW.is_command_flow =
                  autoquet_simul_IN_transmit_data;
                autoquet_simulink_expo_model_DW.command = 192U;
                autoquet_simulink_expo_model_DW.len = 5U;
                qY = autoquet_simulink_expo_model_DW.command_state + 1U;
                if (autoquet_simulink_expo_model_DW.command_state + 1U > 255U) {
                  qY = 255U;
                }

                autoquet_simulink_expo_model_DW.command_state = (uint8_T)qY;
                autoquet_simulink_expo_model_DW.transmit = true;
                break;

               case 2:
                autoquet_simulink_expo_model_DW.is_command_flow =
                  autoquet_sim_IN_display_control;
                autoquet_simulink_expo_model_DW.command = 136U;
                autoquet_simulink_expo_model_DW.len = 1U;
                autoquet_simulink_expo_model_DW.command_state = 0U;
                autoquet_simulink_expo_model_DW.transmit = true;
                break;
              }
              break;

             default:
              /* case IN_transmit_data: */
              break;
            }
          }
          break;

         case autoquet_simulink_expo__IN_init:
          autoquet_simulink_expo_model_DW.is_sending_firmware =
            autoquet_simuli_IN_command_flow;
          autoquet_simulink_expo_model_DW.is_command_flow =
            autoquet_simuli_IN_find_command;
          break;

         default:
          /* case IN_send_data: */
          if (autoquet_simulink_expo_model_DW.word_iterator >
              autoquet_simulink_expo_model_DW.len) {
            autoque_exit_internal_send_data();
            autoquet_simulink_expo_model_B.clk_pin = true;
            autoquet_simulink_expo_model_DW.word_iterator = 1U;
            autoquet_simulink_expo_model_DW.is_sending_firmware =
              autoquet_simulink_expo__IN_Stop;
            autoquet_simulink_expo_model_DW.transmit = false;
          } else {
            switch (autoquet_simulink_expo_model_DW.is_send_data) {
             case autoquet_simulink_ex_IN_ack_bit:
              autoquet_simulink_expo_model_B.data_pin = false;
              autoquet_simulink_expo_model_DW.is_send_data =
                autoquet_simulink_exp_IN_idler1;
              break;

             case autoquet_simuli_IN_buffer_reset:
              autoquet_simulink_expo_model_DW.bit_iterator = 1U;
              autoquet_simulink_expo_model_DW.is_send_data =
                autoquet_simulink__IN_reset_clk;
              autoquet_simulink_expo_model_B.clk_pin = false;
              break;

             case autoquet_simulink__IN_data_high:
              autoquet_simulink_expo_model_DW.is_send_data =
                autoquet_simulink_IN_latch_data;
              autoque_enter_atomic_latch_data();
              break;

             case autoquet_simulink_e_IN_data_low:
              autoquet_simulink_expo_model_DW.is_send_data =
                autoquet_simulink_IN_latch_data;
              autoque_enter_atomic_latch_data();
              break;

             case autoquet_simulink_expo_IN_idler:
              autoquet_simulink_expo_model_B.clk_pin = false;
              autoquet_simulink_expo_model_DW.is_send_data =
                autoquet_simu_IN_post_ack_reset;
              qY = autoquet_simulink_expo_model_DW.word_iterator + 1U;
              if (autoquet_simulink_expo_model_DW.word_iterator + 1U > 255U) {
                qY = 255U;
              }

              autoquet_simulink_expo_model_DW.word_iterator = (uint8_T)qY;
              break;

             case autoquet_simulink_exp_IN_idler1:
              autoquet_simulink_expo_model_B.clk_pin = true;
              autoquet_simulink_expo_model_DW.is_send_data =
                autoquet_simulink_expo_IN_idler;
              break;

             case autoquet_simulink_IN_latch_data:
              if (autoquet_simulink_expo_model_DW.bit_iterator <= 8) {
                autoquet_simulink_expo_model_DW.is_send_data =
                  autoquet_simulink__IN_reset_clk;
                autoquet_simulink_expo_model_B.clk_pin = false;
              } else {
                autoquet_simulink_expo_model_DW.is_send_data =
                  autoquet_simulink_ex_IN_ack_bit;
                autoquet_simulink_expo_model_B.clk_pin = false;
              }
              break;

             case autoquet_simu_IN_post_ack_reset:
              if (autoquet_simulink_expo_model_DW.word_iterator <=
                  autoquet_simulink_expo_model_DW.len) {
                autoquet_simulink_expo_model_DW.is_send_data =
                  autoquet_simuli_IN_buffer_reset;
                qY = autoquet_simulink_expo_model_DW.word_iterator - 1U;
                if (autoquet_simulink_expo_model_DW.word_iterator - 1U >
                    autoquet_simulink_expo_model_DW.word_iterator) {
                  qY = 0U;
                }

                autoquet_simulink_expo_model_DW.buffer =
                  autoquet_simulink_expo_model_DW.to_screen[(int16_T)qY - 1];
              }
              break;

             default:
              /* case IN_reset_clk: */
              if ((autoquet_simulink_expo_model_DW.buffer & 1U) == 0U) {
                autoquet_simulink_expo_model_DW.is_send_data =
                  autoquet_simulink_e_IN_data_low;
                autoquet_simulink_expo_model_B.data_pin = false;
              } else {
                autoquet_simulink_expo_model_DW.is_send_data =
                  autoquet_simulink__IN_data_high;
                autoquet_simulink_expo_model_B.data_pin = true;
              }
              break;
            }
          }
          break;
        }
      }
      break;

     case autoque_IN_set_blank_to_display:
      autoquet_simulink_expo_model_DW.is_c1_autoquet_simulink_expo_mo =
        autoquet_si_IN_sending_firmware;
      autoquet_simulink_expo_model_DW.is_sending_firmware =
        autoquet_simulink_expo__IN_init;
      autoquet_simulink_expo_model_DW.command_state = 0U;
      autoquet_simulink_expo_model_DW.transmit = false;
      autoquet_simulink_expo_model_B.data_pin = true;
      autoquet_simulink_expo_model_B.clk_pin = true;
      autoquet_simulink_expo_model_DW.full_data_sent = false;
      break;

     case auto_IN_set_pressure_to_display:
      autoquet_simulink_expo_model_DW.is_c1_autoquet_simulink_expo_mo =
        autoquet_si_IN_sending_firmware;
      autoquet_simulink_expo_model_DW.is_sending_firmware =
        autoquet_simulink_expo__IN_init;
      autoquet_simulink_expo_model_DW.command_state = 0U;
      autoquet_simulink_expo_model_DW.transmit = false;
      autoquet_simulink_expo_model_B.data_pin = true;
      autoquet_simulink_expo_model_B.clk_pin = true;
      autoquet_simulink_expo_model_DW.full_data_sent = false;
      break;

     default:
      /* case IN_set_time_to_display: */
      autoquet_simulink_expo_model_DW.is_c1_autoquet_simulink_expo_mo =
        autoquet_si_IN_sending_firmware;
      autoquet_simulink_expo_model_DW.is_sending_firmware =
        autoquet_simulink_expo__IN_init;
      autoquet_simulink_expo_model_DW.command_state = 0U;
      autoquet_simulink_expo_model_DW.transmit = false;
      autoquet_simulink_expo_model_B.data_pin = true;
      autoquet_simulink_expo_model_B.clk_pin = true;
      autoquet_simulink_expo_model_DW.full_data_sent = false;
      break;
    }
  }

  /* End of Chart: '<S6>/Transmit firmware' */

  /* MATLABSystem: '<S6>/Clock pin' */
  writeDigitalPin(8, (uint8_T)autoquet_simulink_expo_model_B.clk_pin);

  /* MATLABSystem: '<S6>/Data pin' */
  writeDigitalPin(9, (uint8_T)autoquet_simulink_expo_model_B.data_pin);

  /* End of Outputs for SubSystem: '<Root>/Stopwatch' */
}

/* Model step function for TID2 */
void autoquet_simulink_expo_model_step2(void) /* Sample time: [0.05s, 0.0s] */
{
  boolean_T e_out;

  /* Chart: '<Root>/Blood flow control stateflow' incorporates:
   *  Constant: '<Root>/Bulk increment'
   *  Constant: '<Root>/Initial_pressure_start'
   *  Constant: '<Root>/Pressure resolution'
   *  Constant: '<Root>/Wait period (seconds)'
   */
  if (autoquet_simulink_expo_model_DW.temporalCounter_i1 < 8191U) {
    autoquet_simulink_expo_model_DW.temporalCounter_i1 = (uint16_T)((int16_T)
      autoquet_simulink_expo_model_DW.temporalCounter_i1 + 1);
  }

  if (autoquet_simulink_expo_model_DW.is_active_c3_autoquet_simulink_ == 0U) {
    autoquet_simulink_expo_model_DW.is_active_c3_autoquet_simulink_ = 1U;
    autoquet_simulink_expo_model_DW.is_c3_autoquet_simulink_expo_mo =
      autoquet_simulin_IN_Manual_mode;
    autoquet_simulink_expo_model_B.initial_search = 3U;
  } else if (autoquet_simulink_expo_model_DW.is_c3_autoquet_simulink_expo_mo ==
             autoquet_simulink__IN_Auto_mode) {
    if (autoquet_simulink_expo_model_B.CCCodeBlock5_o3 == 0) {
      if (autoquet_simulink_expo_model_DW.is_Auto_mode ==
          autoquet_IN_Find_initial_bounds) {
        exit_internal_Find_initial_boun();
        autoquet_simulink_expo_model_B.initial_search = 2U;
        autoquet_simulink_expo_model_DW.is_Auto_mode =
          autoquet_sim_IN_NO_ACTIVE_CHILD;
      } else {
        autoquet_simulink_expo_model_DW.is_Binary_search_ideal_pressure =
          autoquet_sim_IN_NO_ACTIVE_CHILD;
        autoquet_simulink_expo_model_DW.is_Steady_state =
          autoquet_sim_IN_NO_ACTIVE_CHILD;
        autoquet_simulink_expo_model_DW.is_Auto_mode =
          autoquet_sim_IN_NO_ACTIVE_CHILD;
      }

      autoquet_simulink_expo_model_DW.is_c3_autoquet_simulink_expo_mo =
        autoquet_simulin_IN_Manual_mode;
      autoquet_simulink_expo_model_B.initial_search = 3U;
    } else {
      switch (autoquet_simulink_expo_model_DW.is_Auto_mode) {
       case IN_Binary_search_ideal_pressure:
        if (autoquet_simulink_expo_model_B.ideal_pressure_found_c) {
          autoquet_simulink_expo_model_DW.is_Binary_search_ideal_pressure =
            autoquet_sim_IN_NO_ACTIVE_CHILD;
          autoquet_simulink_expo_model_DW.is_Auto_mode =
            autoquet_simuli_IN_Steady_state;
          autoquet_simulink_expo_model_B.pressure_set_point += 50.0F;
          autoquet_simulink_expo_model_DW.temporalCounter_i1 = 0U;
          autoquet_simulink_expo_model_DW.is_Steady_state =
            autoquet_simulink_exp_IN_Wait_m;
        } else {
          switch
            (autoquet_simulink_expo_model_DW.is_Binary_search_ideal_pressure) {
           case au_IN_Adjust_pressure_set_point:
            if ((autoquet_simulink_expo_model_B.Memory >=
                 autoquet_simulink_expo_model_B.pressure_set_point
                 - autoquet_simulink_expo_model_P.Pressureresolution_Value /
                 2.0F) && ((autoquet_simulink_expo_model_B.Memory <=
                            autoquet_simulink_expo_model_P.Pressureresolution_Value
                            / 2.0F +
                            autoquet_simulink_expo_model_B.pressure_set_point) &&
                           (!autoquet_simulink_expo_model_B.CCCodeBlock))) {
              autoquet_simulink_expo_model_DW.durationCounter_1_e = 0UL;
              autoquet_simulink_expo_model_DW.is_Binary_search_ideal_pressure =
                autoquet_simulink_expo__IN_Idle;
            }
            break;

           case autoque_IN_Ideal_pressure_found:
            break;

           case autoquet_simulink_expo__IN_Idle:
            if (autoquet_simulink_expo_model_B.CCCodeBlock_o2_l) {
              autoquet_simulink_expo_model_DW.durationCounter_1_e = 0UL;
            }

            if ((real_T)autoquet_simulink_expo_model_DW.durationCounter_1_e >
                autoquet_simulink_expo_model_P.Waitperiodseconds_Value * 20.0F)
            {
              if (autoquet_simulink_expo_model_DW.pressure_difference <
                  autoquet_simulink_expo_model_P.Pressureresolution_Value) {
                autoquet_simulink_expo_model_DW.is_Binary_search_ideal_pressure =
                  autoque_IN_Ideal_pressure_found;
                autoquet_simulink_expo_model_B.pressure_set_point =
                  autoquet_simulink_expo_model_DW.binary_search_upper;
                autoquet_simulink_expo_model_B.ideal_pressure_found_c = true;
              } else if ((autoquet_simulink_expo_model_DW.pressure_difference >=
                          autoquet_simulink_expo_model_P.Pressureresolution_Value)
                         && autoquet_simulink_expo_model_B.CCCodeBlock3_o2) {
                autoquet_simulink_expo_model_DW.is_Binary_search_ideal_pressure =
                  autoquet_simulink__IN_Too_loose;
                autoquet_simulink_expo_model_DW.binary_search_lower =
                  autoquet_simulink_expo_model_B.pressure_set_point;
              } else if ((autoquet_simulink_expo_model_DW.pressure_difference >=
                          autoquet_simulink_expo_model_P.Pressureresolution_Value)
                         && (!autoquet_simulink_expo_model_B.CCCodeBlock3_o2)) {
                autoquet_simulink_expo_model_DW.is_Binary_search_ideal_pressure =
                  autoquet_simulink__IN_Too_tight;
                autoquet_simulink_expo_model_DW.binary_search_upper =
                  autoquet_simulink_expo_model_B.pressure_set_point;
              }
            }
            break;

           case autoquet_simulink__IN_Too_loose:
            autoquet_simulink_expo_model_DW.is_Binary_search_ideal_pressure =
              au_IN_Adjust_pressure_set_point;
            autoquet_simulink_expo_model_B.pressure_set_point =
              (autoquet_simulink_expo_model_DW.binary_search_upper +
               autoquet_simulink_expo_model_DW.binary_search_lower) / 2.0F;
            autoquet_simulink_expo_model_DW.pressure_difference =
              autoquet_simulink_expo_model_DW.binary_search_upper -
              autoquet_simulink_expo_model_DW.binary_search_lower;
            break;

           default:
            /* case IN_Too_tight: */
            autoquet_simulink_expo_model_DW.is_Binary_search_ideal_pressure =
              au_IN_Adjust_pressure_set_point;
            autoquet_simulink_expo_model_B.pressure_set_point =
              (autoquet_simulink_expo_model_DW.binary_search_upper +
               autoquet_simulink_expo_model_DW.binary_search_lower) / 2.0F;
            autoquet_simulink_expo_model_DW.pressure_difference =
              autoquet_simulink_expo_model_DW.binary_search_upper -
              autoquet_simulink_expo_model_DW.binary_search_lower;
            break;
          }
        }
        break;

       case autoquet_IN_Find_initial_bounds:
        if (autoquet_simulink_expo_model_B.CCCodeBlock3_o2 &&
            autoquet_simulink_expo_model_DW.upper_bound_found) {
          exit_internal_Find_initial_boun();
          autoquet_simulink_expo_model_B.initial_search = 2U;
          autoquet_simulink_expo_model_DW.is_Auto_mode =
            IN_Binary_search_ideal_pressure;
          autoquet_simulink_expo_model_DW.binary_search_upper =
            autoquet_simulink_expo_model_DW.pressure_upper_bound;
          autoquet_simulink_expo_model_DW.binary_search_lower =
            autoquet_simulink_expo_model_DW.pressure_lower_bound;
          autoquet_simulink_expo_model_DW.is_Binary_search_ideal_pressure =
            au_IN_Adjust_pressure_set_point;
          autoquet_simulink_expo_model_B.pressure_set_point =
            (autoquet_simulink_expo_model_DW.binary_search_upper +
             autoquet_simulink_expo_model_DW.binary_search_lower) / 2.0F;
          autoquet_simulink_expo_model_DW.pressure_difference =
            autoquet_simulink_expo_model_DW.binary_search_upper -
            autoquet_simulink_expo_model_DW.binary_search_lower;
        } else if (autoquet_simulink_expo_model_DW.is_Find_initial_bounds ==
                   autoquet_simulink_ex_IN_Deflate) {
          switch (autoquet_simulink_expo_model_DW.is_Deflate) {
           case IN_Decrease_pressure_set_point:
            autoquet_simulink_expo_model_DW.is_Deflate =
              autoquet_simulink_expo__IN_Wait;
            break;

           case autoquet_simulink_exp_IN_Idle_g:
            if (autoquet_simulink_expo_model_B.CCCodeBlock) {
              autoquet_simulink_expo_model_DW.durationCounter_1_l = 0UL;
            }

            if ((real_T)autoquet_simulink_expo_model_DW.durationCounter_1_l >
                autoquet_simulink_expo_model_P.Waitperiodseconds_Value * 20.0F)
            {
              autoquet_simulink_expo_model_DW.is_Deflate =
                IN_Decrease_pressure_set_point;
              autoquet_simulink_expo_model_B.pressure_set_point -=
                autoquet_simulink_expo_model_P.Bulkincrement_Value;
            }
            break;

           default:
            /* case IN_Wait: */
            if (autoquet_simulink_expo_model_B.Memory <=
                autoquet_simulink_expo_model_B.pressure_set_point) {
              autoquet_simulink_expo_model_DW.durationCounter_1_l = 0UL;
              autoquet_simulink_expo_model_DW.is_Deflate =
                autoquet_simulink_exp_IN_Idle_g;
            }
            break;
          }
        } else {
          /* case IN_Inflate: */
          if (!autoquet_simulink_expo_model_B.CCCodeBlock3_o2) {
            if (autoquet_simulink_expo_model_B.CCCodeBlock) {
              autoquet_simulink_expo_model_DW.durationCounter_1_h = 0UL;
            }

            e_out = ((real_T)autoquet_simulink_expo_model_DW.durationCounter_1_h
                     > 1.5F *
                     autoquet_simulink_expo_model_P.Waitperiodseconds_Value *
                     20.0F);
          } else {
            e_out = false;
          }

          if (e_out) {
            autoquet_simulink_expo_model_DW.upper_bound_found = true;
            autoquet_simulink_expo_model_DW.is_Inflate =
              autoquet_sim_IN_NO_ACTIVE_CHILD;
            autoquet_simulink_expo_model_DW.pressure_upper_bound =
              autoquet_simulink_expo_model_B.pressure_set_point;
            autoquet_simulink_expo_model_B.initial_search = 1U;
            autoquet_simulink_expo_model_DW.is_Find_initial_bounds =
              autoquet_simulink_ex_IN_Deflate;
            autoquet_simulink_expo_model_DW.is_Deflate =
              IN_Decrease_pressure_set_point;
            autoquet_simulink_expo_model_B.pressure_set_point -=
              autoquet_simulink_expo_model_P.Bulkincrement_Value;
          } else {
            switch (autoquet_simulink_expo_model_DW.is_Inflate) {
             case autoquet_simulink_ex_IN_Idle_gx:
              if (autoquet_simulink_expo_model_B.CCCodeBlock) {
                autoquet_simulink_expo_model_DW.durationCounter_1_m = 0UL;
              }

              if ((real_T)autoquet_simulink_expo_model_DW.durationCounter_1_m >
                  1.6F * autoquet_simulink_expo_model_P.Waitperiodseconds_Value *
                  20.0F) {
                autoquet_simulink_expo_model_DW.is_Inflate =
                  IN_Increase_pressure_set_point;
                autoquet_simulink_expo_model_B.pressure_set_point +=
                  autoquet_simulink_expo_model_P.Bulkincrement_Value;
              }
              break;

             case IN_Increase_pressure_set_point:
              autoquet_simulink_expo_model_DW.is_Inflate =
                autoquet_simulink_expo__IN_wait;
              break;

             default:
              /* case IN_wait: */
              if (autoquet_simulink_expo_model_B.Memory >=
                  autoquet_simulink_expo_model_B.pressure_set_point) {
                autoquet_simulink_expo_model_DW.durationCounter_1_m = 0UL;
                autoquet_simulink_expo_model_DW.is_Inflate =
                  autoquet_simulink_ex_IN_Idle_gx;
              }
              break;
            }
          }
        }
        break;

       default:
        /* case IN_Steady_state: */
        switch (autoquet_simulink_expo_model_DW.is_Steady_state) {
         case autoquet_simulink_exp_IN_Wait_m:
          if (autoquet_simulink_expo_model_DW.temporalCounter_i1 >= 6000U) {
            autoquet_simulink_expo_model_DW.temporalCounter_i1 = 0U;
            autoquet_simulink_expo_model_DW.is_Steady_state =
              autoquet_si_IN_slight_deflation;
            autoquet_simulink_expo_model_B.pressure_set_point -= 100.0F;
          }
          break;

         case autoquet_simulink_IN_re_inflate:
          autoquet_simulink_expo_model_DW.temporalCounter_i1 = 0U;
          autoquet_simulink_expo_model_DW.is_Steady_state =
            autoquet_simulink_exp_IN_Wait_m;
          break;

         default:
          /* case IN_slight_deflation: */
          if (autoquet_simulink_expo_model_DW.temporalCounter_i1 >= 600U) {
            autoquet_simulink_expo_model_DW.is_Steady_state =
              autoquet_simulink_IN_re_inflate;
            autoquet_simulink_expo_model_B.pressure_set_point += 100.0F;
          }
          break;
        }
        break;
      }
    }

    /* case IN_Manual_mode: */
  } else if (autoquet_simulink_expo_model_B.CCCodeBlock5_o3 == 1) {
    autoquet_simulink_expo_model_DW.is_c3_autoquet_simulink_expo_mo =
      autoquet_simulink__IN_Auto_mode;
    autoquet_simulink_expo_model_DW.is_Auto_mode =
      autoquet_IN_Find_initial_bounds;
    autoquet_simulink_expo_model_B.pressure_set_point =
      autoquet_simulink_expo_model_P.Initial_pressure_start_Value;
    autoquet_simulink_expo_model_DW.upper_bound_found = false;
    autoquet_simulink_expo_model_B.initial_search = 0U;
    autoquet_simulink_expo_model_B.ideal_pressure_found_c = false;
    autoquet_simulink_expo_model_DW.durationCounter_1_h = 0UL;
    autoquet_simulink_expo_model_DW.is_Find_initial_bounds =
      autoquet_simulink_ex_IN_Inflate;
    autoquet_simulink_expo_model_DW.is_Inflate = autoquet_simulink_expo__IN_wait;
  }

  if (!autoquet_simulink_expo_model_B.CCCodeBlock_o2_l) {
    autoquet_simulink_expo_model_DW.durationCounter_1_e++;
  } else {
    autoquet_simulink_expo_model_DW.durationCounter_1_e = 0UL;
  }

  if (!autoquet_simulink_expo_model_B.CCCodeBlock) {
    autoquet_simulink_expo_model_DW.durationCounter_1_m++;
    autoquet_simulink_expo_model_DW.durationCounter_1_l++;
    autoquet_simulink_expo_model_DW.durationCounter_1_h++;
  } else {
    autoquet_simulink_expo_model_DW.durationCounter_1_m = 0UL;
    autoquet_simulink_expo_model_DW.durationCounter_1_l = 0UL;
    autoquet_simulink_expo_model_DW.durationCounter_1_h = 0UL;
  }

  /* End of Chart: '<Root>/Blood flow control stateflow' */
}

/* Model step function for TID3 */
void autoquet_simulink_expo_model_step3(void) /* Sample time: [0.1s, 0.0s] */
{
  l_codertarget_arduinobase_int_T *obj;
  uint8_T SwappedDataBytes;
  uint8_T b_status;
  uint8_T rtb_SerialReceive_o1;
  uint8_T status;

  /* MATLABSystem: '<Root>/Serial Receive' */
  if (autoquet_simulink_expo_model_DW.obj_k.Protocol !=
      autoquet_simulink_expo_model_P.SerialReceive_Protocol) {
    autoquet_simulink_expo_model_DW.obj_k.Protocol =
      autoquet_simulink_expo_model_P.SerialReceive_Protocol;
  }

  if (autoquet_simulink_expo_model_DW.obj_k.QueueSizeFactor !=
      autoquet_simulink_expo_model_P.SerialReceive_QueueSizeFactor) {
    autoquet_simulink_expo_model_DW.obj_k.QueueSizeFactor =
      autoquet_simulink_expo_model_P.SerialReceive_QueueSizeFactor;
  }

  /* MATLABSystem: '<Root>/Serial Receive' */
  MW_Serial_read(0, autoquet_simulink_expo_model_DW.obj_k.DataSizeInBytes,
                 &rtb_SerialReceive_o1, &b_status);

  /* Memory: '<Root>/Memory' */
  autoquet_simulink_expo_model_B.Memory =
    autoquet_simulink_expo_model_DW.Memory_PreviousInput;

  /* Outputs for Atomic SubSystem: '<Root>/Bloodflow Detection' */
  /* DiscreteFir: '<S8>/Digital Filter' */
  autoquet_simulink_expo_model_B.DigitalFilter_m =
    autoquet_simulink_expo_model_B.Memory;
  for (autoquet_simulink_expo_model_B.k = 0; autoquet_simulink_expo_model_B.k <
       1; autoquet_simulink_expo_model_B.k++) {
    autoquet_simulink_expo_model_B.acc1 = 0.0F;

    /* load input sample */
    for (autoquet_simulink_expo_model_B.n = 0; autoquet_simulink_expo_model_B.n <
         5; autoquet_simulink_expo_model_B.n++) {
      /* shift state */
      autoquet_simulink_expo_model_B.zCurr =
        autoquet_simulink_expo_model_B.DigitalFilter_m;
      autoquet_simulink_expo_model_B.DigitalFilter_m =
        autoquet_simulink_expo_model_DW.DigitalFilter_states[(int32_T)
        autoquet_simulink_expo_model_B.n];
      autoquet_simulink_expo_model_DW.DigitalFilter_states[(int32_T)
        autoquet_simulink_expo_model_B.n] = autoquet_simulink_expo_model_B.zCurr;

      /* compute one tap */
      autoquet_simulink_expo_model_B.acc1 +=
        autoquet_simulink_expo_model_P.DigitalFilter_Coefficients[(int32_T)
        autoquet_simulink_expo_model_B.n] * autoquet_simulink_expo_model_B.zCurr;
    }

    /* compute last tap */
    /* store output sample */
    autoquet_simulink_expo_model_B.DigitalFilter_m =
      autoquet_simulink_expo_model_P.DigitalFilter_Coefficients[(int32_T)
      autoquet_simulink_expo_model_B.n] *
      autoquet_simulink_expo_model_B.DigitalFilter_m +
      autoquet_simulink_expo_model_B.acc1;
  }

  /* End of DiscreteFir: '<S8>/Digital Filter' */

  /* DiscreteFir: '<S7>/Digital Filter' incorporates:
   *  Memory: '<Root>/Memory1'
   *  SignalConversion generated from: '<S9>/Check Signal Attributes'
   */
  autoquet_simulink_expo_model_B.acc1 =
    autoquet_simulink_expo_model_B.DigitalFilter_m *
    autoquet_simulink_expo_model_P.DigitalFilter_Coefficients_l[0];
  autoquet_simulink_expo_model_B.cff = 1L;
  autoquet_simulink_expo_model_B.j =
    autoquet_simulink_expo_model_DW.DigitalFilter_circBuf;
  while (autoquet_simulink_expo_model_B.j < 5L) {
    autoquet_simulink_expo_model_B.acc1 +=
      autoquet_simulink_expo_model_DW.DigitalFilter_states_i[autoquet_simulink_expo_model_B.j]
      * autoquet_simulink_expo_model_P.DigitalFilter_Coefficients_l[autoquet_simulink_expo_model_B.cff];
    autoquet_simulink_expo_model_B.cff++;
    autoquet_simulink_expo_model_B.j++;
  }

  autoquet_simulink_expo_model_B.j = 0L;
  while (autoquet_simulink_expo_model_B.j <
         autoquet_simulink_expo_model_DW.DigitalFilter_circBuf) {
    autoquet_simulink_expo_model_B.acc1 +=
      autoquet_simulink_expo_model_DW.DigitalFilter_states_i[autoquet_simulink_expo_model_B.j]
      * autoquet_simulink_expo_model_P.DigitalFilter_Coefficients_l[autoquet_simulink_expo_model_B.cff];
    autoquet_simulink_expo_model_B.cff++;
    autoquet_simulink_expo_model_B.j++;
  }

  autoquet_simulink_expo_model_B.DigitalFilter[0L] =
    autoquet_simulink_expo_model_B.acc1;
  autoquet_simulink_expo_model_B.acc1 =
    autoquet_simulink_expo_model_DW.Memory1_PreviousInput[0] *
    autoquet_simulink_expo_model_P.DigitalFilter_Coefficients_l[0];
  autoquet_simulink_expo_model_B.cff = 1L;
  autoquet_simulink_expo_model_B.j =
    autoquet_simulink_expo_model_DW.DigitalFilter_circBuf;
  while (autoquet_simulink_expo_model_B.j < 5L) {
    autoquet_simulink_expo_model_B.acc1 +=
      autoquet_simulink_expo_model_DW.DigitalFilter_states_i[autoquet_simulink_expo_model_B.j
      + 5L] *
      autoquet_simulink_expo_model_P.DigitalFilter_Coefficients_l[autoquet_simulink_expo_model_B.cff];
    autoquet_simulink_expo_model_B.cff++;
    autoquet_simulink_expo_model_B.j++;
  }

  autoquet_simulink_expo_model_B.j = 0L;
  while (autoquet_simulink_expo_model_B.j <
         autoquet_simulink_expo_model_DW.DigitalFilter_circBuf) {
    autoquet_simulink_expo_model_B.acc1 +=
      autoquet_simulink_expo_model_DW.DigitalFilter_states_i[autoquet_simulink_expo_model_B.j
      + 5L] *
      autoquet_simulink_expo_model_P.DigitalFilter_Coefficients_l[autoquet_simulink_expo_model_B.cff];
    autoquet_simulink_expo_model_B.cff++;
    autoquet_simulink_expo_model_B.j++;
  }

  autoquet_simulink_expo_model_B.DigitalFilter[1L] =
    autoquet_simulink_expo_model_B.acc1;
  autoquet_simulink_expo_model_B.acc1 =
    autoquet_simulink_expo_model_P.DigitalFilter_Coefficients_l[0] *
    autoquet_simulink_expo_model_DW.Memory1_PreviousInput[1];
  autoquet_simulink_expo_model_B.cff = 1L;
  autoquet_simulink_expo_model_B.j =
    autoquet_simulink_expo_model_DW.DigitalFilter_circBuf;
  while (autoquet_simulink_expo_model_B.j < 5L) {
    autoquet_simulink_expo_model_B.acc1 +=
      autoquet_simulink_expo_model_DW.DigitalFilter_states_i[autoquet_simulink_expo_model_B.j
      + 10L] *
      autoquet_simulink_expo_model_P.DigitalFilter_Coefficients_l[autoquet_simulink_expo_model_B.cff];
    autoquet_simulink_expo_model_B.cff++;
    autoquet_simulink_expo_model_B.j++;
  }

  autoquet_simulink_expo_model_B.j = 0L;
  while (autoquet_simulink_expo_model_B.j <
         autoquet_simulink_expo_model_DW.DigitalFilter_circBuf) {
    autoquet_simulink_expo_model_B.acc1 +=
      autoquet_simulink_expo_model_DW.DigitalFilter_states_i[autoquet_simulink_expo_model_B.j
      + 10L] *
      autoquet_simulink_expo_model_P.DigitalFilter_Coefficients_l[autoquet_simulink_expo_model_B.cff];
    autoquet_simulink_expo_model_B.cff++;
    autoquet_simulink_expo_model_B.j++;
  }

  autoquet_simulink_expo_model_B.DigitalFilter[2L] =
    autoquet_simulink_expo_model_B.acc1;
  autoquet_simulink_expo_model_B.acc1 =
    autoquet_simulink_expo_model_P.DigitalFilter_Coefficients_l[0] *
    autoquet_simulink_expo_model_DW.Memory1_PreviousInput[2];
  autoquet_simulink_expo_model_B.cff = 1L;
  autoquet_simulink_expo_model_B.j =
    autoquet_simulink_expo_model_DW.DigitalFilter_circBuf;
  while (autoquet_simulink_expo_model_B.j < 5L) {
    autoquet_simulink_expo_model_B.acc1 +=
      autoquet_simulink_expo_model_DW.DigitalFilter_states_i[autoquet_simulink_expo_model_B.j
      + 15L] *
      autoquet_simulink_expo_model_P.DigitalFilter_Coefficients_l[autoquet_simulink_expo_model_B.cff];
    autoquet_simulink_expo_model_B.cff++;
    autoquet_simulink_expo_model_B.j++;
  }

  autoquet_simulink_expo_model_B.j = 0L;
  while (autoquet_simulink_expo_model_B.j <
         autoquet_simulink_expo_model_DW.DigitalFilter_circBuf) {
    autoquet_simulink_expo_model_B.acc1 +=
      autoquet_simulink_expo_model_DW.DigitalFilter_states_i[autoquet_simulink_expo_model_B.j
      + 15L] *
      autoquet_simulink_expo_model_P.DigitalFilter_Coefficients_l[autoquet_simulink_expo_model_B.cff];
    autoquet_simulink_expo_model_B.cff++;
    autoquet_simulink_expo_model_B.j++;
  }

  autoquet_simulink_expo_model_B.DigitalFilter[3L] =
    autoquet_simulink_expo_model_B.acc1;

  /* End of DiscreteFir: '<S7>/Digital Filter' */

  /* S-Function (custom_demux): '<S2>/C//C++ Code Block4' */
  custom_demux_Outputs_wrapper(&autoquet_simulink_expo_model_B.DigitalFilter[0],
    &autoquet_simulink_expo_model_B.CCCodeBlock4_o1,
    &autoquet_simulink_expo_model_B.CCCodeBlock4_o2[0]);

  /* S-Function (limb_movement_detector): '<S2>/C//C++ Code Block2' incorporates:
   *  Constant: '<S2>/accel_threshold'
   */
  limb_movement_detector_Outputs_wrapper
    (&autoquet_simulink_expo_model_B.CCCodeBlock4_o2[0],
     &autoquet_simulink_expo_model_P.accel_threshold_Value,
     &autoquet_simulink_expo_model_B.CCCodeBlock2);

  /* S-Function (disruption_activity_monitor): '<S2>/C//C++ Code Block' incorporates:
   *  Constant: '<S2>/pause time (msec)'
   */
  disruption_activity_monitor_Outputs_wrapper
    (&autoquet_simulink_expo_model_B.CCCodeBlock_o2_l,
     &autoquet_simulink_expo_model_B.CCCodeBlock2,
     &autoquet_simulink_expo_model_B.CCCodeBlock_o2,
     &autoquet_simulink_expo_model_P.pausetimemsec_Value,
     &autoquet_simulink_expo_model_B.CCCodeBlock);

  /* S-Function (blood_flow_detector_2): '<S2>/C//C++ Code Block3' incorporates:
   *  Constant: '<S2>/bloodflow_threshold'
   */
  blood_flow_detector_2_Outputs_wrapper
    (&autoquet_simulink_expo_model_B.CCCodeBlock4_o1,
     &autoquet_simulink_expo_model_B.CCCodeBlock,
     &autoquet_simulink_expo_model_P.bloodflow_threshold_Value,
     &autoquet_simulink_expo_model_B.initial_search,
     &autoquet_simulink_expo_model_B.CCCodeBlock3_o1,
     &autoquet_simulink_expo_model_B.CCCodeBlock3_o2);

  /* Update for DiscreteFir: '<S7>/Digital Filter' incorporates:
   *  Memory: '<Root>/Memory1'
   *  SignalConversion generated from: '<S9>/Check Signal Attributes'
   */
  /* Update circular buffer index */
  autoquet_simulink_expo_model_DW.DigitalFilter_circBuf--;
  if (autoquet_simulink_expo_model_DW.DigitalFilter_circBuf < 0L) {
    autoquet_simulink_expo_model_DW.DigitalFilter_circBuf = 4L;
  }

  /* Update circular buffer */
  autoquet_simulink_expo_model_DW.DigitalFilter_states_i[autoquet_simulink_expo_model_DW.DigitalFilter_circBuf]
    = autoquet_simulink_expo_model_B.DigitalFilter_m;
  autoquet_simulink_expo_model_DW.DigitalFilter_states_i[autoquet_simulink_expo_model_DW.DigitalFilter_circBuf
    + 5L] = autoquet_simulink_expo_model_DW.Memory1_PreviousInput[0];
  autoquet_simulink_expo_model_DW.DigitalFilter_states_i[autoquet_simulink_expo_model_DW.DigitalFilter_circBuf
    + 10L] = autoquet_simulink_expo_model_DW.Memory1_PreviousInput[1];
  autoquet_simulink_expo_model_DW.DigitalFilter_states_i[autoquet_simulink_expo_model_DW.DigitalFilter_circBuf
    + 15L] = autoquet_simulink_expo_model_DW.Memory1_PreviousInput[2];

  /* End of Update for DiscreteFir: '<S7>/Digital Filter' */
  /* End of Outputs for SubSystem: '<Root>/Bloodflow Detection' */

  /* Outputs for Atomic SubSystem: '<Root>/Pressure Control' */
  /* MATLABSystem: '<S5>/I2C Read1' */
  if (autoquet_simulink_expo_model_DW.obj_j.SampleTime !=
      autoquet_simulink_expo_model_P.I2CRead1_SampleTime) {
    autoquet_simulink_expo_model_DW.obj_j.SampleTime =
      autoquet_simulink_expo_model_P.I2CRead1_SampleTime;
  }

  MW_I2C_MasterRead
    (autoquet_simulink_expo_model_DW.obj_j.I2CDriverObj.MW_I2C_HANDLE, 40UL,
     &autoquet_simulink_expo_model_B.output_raw_c[0], 2UL, false, false);
  memcpy((void *)&autoquet_simulink_expo_model_B.I2CRead1[0], (void *)
         &autoquet_simulink_expo_model_B.output_raw_c[0], (size_t)2 * sizeof
         (uint8_T));

  /* End of MATLABSystem: '<S5>/I2C Read1' */

  /* S-Function (process_raw_sensor_reading): '<S5>/C//C++ Code Block3' */
  process_raw_sensor_reading_Outputs_wrapper
    (&autoquet_simulink_expo_model_B.I2CRead1[0],
     &autoquet_simulink_expo_model_B.CCCodeBlock3);

  /* Outputs for Atomic SubSystem: '<S5>/BNO055 IMU Sensor' */
  /* Start for Atomic SubSystem: '<S5>/BNO055 IMU Sensor' */
  /* MATLABSystem: '<S11>/Base sensor block' */
  if (autoquet_simulink_expo_model_DW.obj_e.SampleTime !=
      autoquet_simulink_expo_model_P.BNO055IMUSensor_SampleTime) {
    autoquet_simulink_expo_model_DW.obj_e.SampleTime =
      autoquet_simulink_expo_model_P.BNO055IMUSensor_SampleTime;
  }

  /* End of Start for SubSystem: '<S5>/BNO055 IMU Sensor' */
  if (!autoquet_simulink_expo_model_DW.obj_e.IsFirstStep) {
    MW_getCurrentTime_in_milliseconds();
    autoquet_simulink_expo_model_DW.obj_e.IsFirstStep = true;
  }

  obj = &autoquet_simulink_expo_model_DW.obj_e.i2cObj;
  status = 8U;
  memcpy((void *)&SwappedDataBytes, (void *)&status, (size_t)1 * sizeof(uint8_T));
  status = MW_I2C_MasterWrite(obj->I2CDriverObj.MW_I2C_HANDLE, 41UL,
    &SwappedDataBytes, 1UL, true, false);
  if (status == 0) {
    MW_I2C_MasterRead(obj->I2CDriverObj.MW_I2C_HANDLE, 41UL,
                      &autoquet_simulink_expo_model_B.output_raw[0], 6UL, false,
                      true);
    memcpy((void *)&autoquet_simulink_expo_model_B.b_RegisterValue[0], (void *)
           &autoquet_simulink_expo_model_B.output_raw[0], (size_t)3 * sizeof
           (int16_T));
  } else {
    autoquet_simulink_expo_model_B.b_RegisterValue[0] = 0;
    autoquet_simulink_expo_model_B.b_RegisterValue[1] = 0;
    autoquet_simulink_expo_model_B.b_RegisterValue[2] = 0;
  }

  /* End of Outputs for SubSystem: '<S5>/BNO055 IMU Sensor' */
  /* End of Outputs for SubSystem: '<Root>/Pressure Control' */

  /* Chart: '<Root>/Data send controller' incorporates:
   *  MATLABSystem: '<Root>/Serial Receive'
   * */
  if (autoquet_simulink_expo_model_DW.is_active_c2_autoquet_simulink_ == 0U) {
    autoquet_simulink_expo_model_DW.is_active_c2_autoquet_simulink_ = 1U;
    autoquet_simulink_expo_model_DW.is_c2_autoquet_simulink_expo_mo =
      autoquet_simulink_exp_IN_wait_c;
  } else if (autoquet_simulink_expo_model_DW.is_c2_autoquet_simulink_expo_mo ==
             autoquet_simuli_IN_request_data) {
    autoquet_simulink_expo_model_DW.is_c2_autoquet_simulink_expo_mo =
      autoquet_simulink_exp_IN_wait_c;

    /* case IN_wait: */
  } else if (b_status == 1) {
    autoquet_simulink_expo_model_DW.is_c2_autoquet_simulink_expo_mo =
      autoquet_simuli_IN_request_data;
    send_params();
  }

  /* End of Chart: '<Root>/Data send controller' */

  /* Update for Memory: '<Root>/Memory' */
  autoquet_simulink_expo_model_DW.Memory_PreviousInput =
    autoquet_simulink_expo_model_B.CCCodeBlock3;

  /* Outputs for Atomic SubSystem: '<Root>/Pressure Control' */
  /* Outputs for Atomic SubSystem: '<S5>/BNO055 IMU Sensor' */
  /* Update for Memory: '<Root>/Memory1' incorporates:
   *  DataTypeConversion: '<S5>/Cast To Single1'
   *  MATLABSystem: '<S11>/Base sensor block'
   * */
  autoquet_simulink_expo_model_DW.Memory1_PreviousInput[0] = (real32_T)((real_T)
    autoquet_simulink_expo_model_B.b_RegisterValue[0] / 100.0);
  autoquet_simulink_expo_model_DW.Memory1_PreviousInput[1] = (real32_T)((real_T)
    autoquet_simulink_expo_model_B.b_RegisterValue[1] / 100.0);
  autoquet_simulink_expo_model_DW.Memory1_PreviousInput[2] = (real32_T)((real_T)
    autoquet_simulink_expo_model_B.b_RegisterValue[2] / 100.0);

  /* End of Outputs for SubSystem: '<S5>/BNO055 IMU Sensor' */
  /* End of Outputs for SubSystem: '<Root>/Pressure Control' */
}

/* Model initialize function */
void autoquet_simulink_expo_model_initialize(void)
{
  {
    l_codertarget_arduinobase_int_T *obj;
    int16_T i;

    /* Start for S-Function (time_keeper): '<Root>/C//C++ Code Block' */

    /* S-Function Block: <Root>/C//C++ Code Block */
    time_keeper_Start_wrapper();

    /* InitializeConditions for Memory: '<Root>/Memory' */
    autoquet_simulink_expo_model_DW.Memory_PreviousInput =
      autoquet_simulink_expo_model_P.Memory_InitialCondition;

    /* InitializeConditions for Memory: '<Root>/Memory1' */
    autoquet_simulink_expo_model_DW.Memory1_PreviousInput[0] =
      autoquet_simulink_expo_model_P.Memory1_InitialCondition;
    autoquet_simulink_expo_model_DW.Memory1_PreviousInput[1] =
      autoquet_simulink_expo_model_P.Memory1_InitialCondition;
    autoquet_simulink_expo_model_DW.Memory1_PreviousInput[2] =
      autoquet_simulink_expo_model_P.Memory1_InitialCondition;

    /* SystemInitialize for Atomic SubSystem: '<Root>/Pressure Control' */
    /* Start for S-Function (button_control_logic): '<S5>/C//C++ Code Block5' */

    /* S-Function Block: <S5>/C//C++ Code Block5 */
    button_control_logic_Start_wrapper();

    /* SystemInitialize for Atomic SubSystem: '<S5>/BNO055 IMU Sensor' */
    /* Start for MATLABSystem: '<S11>/Base sensor block' */
    autoquet_simulink_expo_model_DW.obj_e.isInitialized = 0L;
    autoquet_simulink_expo_model_DW.obj_e.IsFirstStep = false;
    obj = &autoquet_simulink_expo_model_DW.obj_e.i2cObj;
    autoquet_simulink_expo_model_DW.obj_e.i2cObj.DefaultMaximumBusSpeedInHz =
      400000.0;
    autoquet_simulink_expo_model_DW.obj_e.i2cObj.isInitialized = 0L;
    obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
    autoquet_simulink_expo_model_DW.obj_e.i2cObj.matlabCodegenIsDeleted = false;
    autoquet_simulink_expo_model_DW.obj_e.matlabCodegenIsDeleted = false;

    /* Start for Atomic SubSystem: '<S5>/BNO055 IMU Sensor' */
    autoquet_simulink_expo_model_DW.obj_e.SampleTime =
      autoquet_simulink_expo_model_P.BNO055IMUSensor_SampleTime;

    /* End of Start for SubSystem: '<S5>/BNO055 IMU Sensor' */
    autoquet_simul_SystemCore_setup(&autoquet_simulink_expo_model_DW.obj_e);

    /* End of SystemInitialize for SubSystem: '<S5>/BNO055 IMU Sensor' */

    /* Start for MATLABSystem: '<S5>/Automode signal input' */
    autoquet_simulink_expo_model_DW.obj_d.matlabCodegenIsDeleted = false;
    autoquet_simulink_expo_model_DW.obj_d.SampleTime =
      autoquet_simulink_expo_model_P.Automodesignalinput_SampleTime;
    autoquet_simulink_expo_model_DW.obj_d.isInitialized = 1L;
    digitalIOSetup(0, 0);
    autoquet_simulink_expo_model_DW.obj_d.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/Increase signal input' */
    autoquet_simulink_expo_model_DW.obj_h.matlabCodegenIsDeleted = false;
    autoquet_simulink_expo_model_DW.obj_h.SampleTime =
      autoquet_simulink_expo_model_P.Increasesignalinput_SampleTime;
    autoquet_simulink_expo_model_DW.obj_h.isInitialized = 1L;
    digitalIOSetup(4, 0);
    autoquet_simulink_expo_model_DW.obj_h.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/Decrease signal input' */
    autoquet_simulink_expo_model_DW.obj_g.matlabCodegenIsDeleted = false;
    autoquet_simulink_expo_model_DW.obj_g.SampleTime =
      autoquet_simulink_expo_model_P.Decreasesignalinput_SampleTime;
    autoquet_simulink_expo_model_DW.obj_g.isInitialized = 1L;
    digitalIOSetup(6, 0);
    autoquet_simulink_expo_model_DW.obj_g.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/D6' */
    autoquet_simulink_expo_model_DW.obj_a.matlabCodegenIsDeleted = false;
    autoquet_simulink_expo_model_DW.obj_a.isInitialized = 1L;
    digitalIOSetup(11, 1);
    autoquet_simulink_expo_model_DW.obj_a.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/Digital Output' */
    autoquet_simulink_expo_model_DW.obj_jn.matlabCodegenIsDeleted = false;
    autoquet_simulink_expo_model_DW.obj_jn.isInitialized = 1L;
    digitalIOSetup(10, 1);
    autoquet_simulink_expo_model_DW.obj_jn.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/PWM' */
    autoquet_simulink_expo_model_DW.obj_ec.matlabCodegenIsDeleted = false;
    autoquet_simulink_expo_model_DW.obj_ec.isInitialized = 1L;
    autoquet_simulink_expo_model_DW.obj_ec.PWMDriverObj.MW_PWM_HANDLE =
      MW_PWM_Open(5UL, 0.0, 0.0);
    autoquet_simulink_expo_model_DW.obj_ec.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/RX LED (D5)' */
    autoquet_simulink_expo_model_DW.obj_kf.matlabCodegenIsDeleted = false;
    autoquet_simulink_expo_model_DW.obj_kf.isInitialized = 1L;
    digitalIOSetup(17, 1);
    autoquet_simulink_expo_model_DW.obj_kf.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/I2C Read1' */
    autoquet_simulink_expo_model_DW.obj_j.DefaultMaximumBusSpeedInHz = 400000.0;
    autoquet_simulink_expo_model_DW.obj_j.matlabCodegenIsDeleted = false;
    autoquet_simulink_expo_model_DW.obj_j.SampleTime =
      autoquet_simulink_expo_model_P.I2CRead1_SampleTime;
    autoquet_simulink_expo_model_DW.obj_j.isInitialized = 1L;
    autoquet_simulink_expo_model_DW.obj_j.I2CDriverObj.MW_I2C_HANDLE =
      MW_I2C_Open(0, MW_I2C_MASTER);
    autoquet_simulink_expo_model_DW.obj_j.BusSpeed = 100000UL;
    MW_I2C_SetBusSpeed
      (autoquet_simulink_expo_model_DW.obj_j.I2CDriverObj.MW_I2C_HANDLE,
       100000UL);
    autoquet_simulink_expo_model_DW.obj_j.isSetupComplete = true;

    /* End of SystemInitialize for SubSystem: '<Root>/Pressure Control' */

    /* SystemInitialize for Atomic SubSystem: '<Root>/Bloodflow Detection' */
    /* Start for S-Function (limb_movement_detector): '<S2>/C//C++ Code Block2' incorporates:
     *  Constant: '<S2>/accel_threshold'
     */

    /* S-Function Block: <S2>/C//C++ Code Block2 */
    limb_movement_detector_Start_wrapper();

    /* Start for S-Function (blood_flow_detector_2): '<S2>/C//C++ Code Block3' incorporates:
     *  Constant: '<S2>/bloodflow_threshold'
     */

    /* S-Function Block: <S2>/C//C++ Code Block3 */
    blood_flow_detector_2_Start_wrapper();

    /* InitializeConditions for DiscreteFir: '<S8>/Digital Filter' */
    for (i = 0; i < 5; i++) {
      autoquet_simulink_expo_model_DW.DigitalFilter_states[i] =
        autoquet_simulink_expo_model_P.DigitalFilter_InitialStates;
    }

    /* End of InitializeConditions for DiscreteFir: '<S8>/Digital Filter' */

    /* InitializeConditions for DiscreteFir: '<S7>/Digital Filter' */
    for (i = 0; i < 20; i++) {
      autoquet_simulink_expo_model_DW.DigitalFilter_states_i[i] =
        autoquet_simulink_expo_model_P.DigitalFilter_InitialStates_p;
    }

    /* End of InitializeConditions for DiscreteFir: '<S7>/Digital Filter' */
    /* End of SystemInitialize for SubSystem: '<Root>/Bloodflow Detection' */

    /* SystemInitialize for S-Function (sfun_private_function_caller) generated from: '<Root>/Function-Call Subsystem' incorporates:
     *  SubSystem: '<Root>/Function-Call Subsystem'
     */
    send_params_Init();

    /* End of SystemInitialize for S-Function (sfun_private_function_caller) generated from: '<Root>/Function-Call Subsystem' */

    /* SystemInitialize for Atomic SubSystem: '<Root>/Stopwatch' */
    /* Start for S-Function (display_pressures_signal): '<S6>/C//C++ Code Block4' */

    /* S-Function Block: <S6>/C//C++ Code Block4 */
    display_pressures_signal_Start_wrapper();

    /* SystemInitialize for Chart: '<S6>/Transmit firmware' */
    autoquet_simulink_expo_model_DW.transmit =
      autoquet_simulink_expo_model_P.Transmitfirmware_transmit;

    /* Start for MATLABSystem: '<S6>/Clock pin' */
    autoquet_simulink_expo_model_DW.obj_n.matlabCodegenIsDeleted = false;
    autoquet_simulink_expo_model_DW.obj_n.isInitialized = 1L;
    digitalIOSetup(8, 1);
    autoquet_simulink_expo_model_DW.obj_n.isSetupComplete = true;

    /* Start for MATLABSystem: '<S6>/Data pin' */
    autoquet_simulink_expo_model_DW.obj_gj.matlabCodegenIsDeleted = false;
    autoquet_simulink_expo_model_DW.obj_gj.isInitialized = 1L;
    digitalIOSetup(9, 1);
    autoquet_simulink_expo_model_DW.obj_gj.isSetupComplete = true;

    /* End of SystemInitialize for SubSystem: '<Root>/Stopwatch' */

    /* Start for MATLABSystem: '<Root>/Serial Receive' */
    autoquet_simulink_expo_model_DW.obj_k.matlabCodegenIsDeleted = false;
    autoquet_simulink_expo_model_DW.obj_k.Protocol =
      autoquet_simulink_expo_model_P.SerialReceive_Protocol;
    autoquet_simulink_expo_model_DW.obj_k.QueueSizeFactor =
      autoquet_simulink_expo_model_P.SerialReceive_QueueSizeFactor;
    autoquet_simulink_expo_model_DW.obj_k.isInitialized = 1L;
    autoquet_simulink_expo_model_DW.obj_k.DataTypeWidth = 1U;
    autoquet_simulink_expo_model_DW.obj_k.DataSizeInBytes = 1U;
    MW_SCI_Open(0);
    autoquet_simulink_expo_model_DW.obj_k.isSetupComplete = true;
  }
}

/* Model terminate function */
void autoquet_simulink_expo_model_terminate(void)
{
  l_codertarget_arduinobase_int_T *obj;

  /* Terminate for Atomic SubSystem: '<Root>/Pressure Control' */
  /* Terminate for MATLABSystem: '<S5>/Automode signal input' */
  if (!autoquet_simulink_expo_model_DW.obj_d.matlabCodegenIsDeleted) {
    autoquet_simulink_expo_model_DW.obj_d.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S5>/Automode signal input' */

  /* Terminate for MATLABSystem: '<S5>/Increase signal input' */
  if (!autoquet_simulink_expo_model_DW.obj_h.matlabCodegenIsDeleted) {
    autoquet_simulink_expo_model_DW.obj_h.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S5>/Increase signal input' */

  /* Terminate for MATLABSystem: '<S5>/Decrease signal input' */
  if (!autoquet_simulink_expo_model_DW.obj_g.matlabCodegenIsDeleted) {
    autoquet_simulink_expo_model_DW.obj_g.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S5>/Decrease signal input' */

  /* Terminate for MATLABSystem: '<S5>/D6' */
  if (!autoquet_simulink_expo_model_DW.obj_a.matlabCodegenIsDeleted) {
    autoquet_simulink_expo_model_DW.obj_a.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S5>/D6' */

  /* Terminate for MATLABSystem: '<S5>/Digital Output' */
  if (!autoquet_simulink_expo_model_DW.obj_jn.matlabCodegenIsDeleted) {
    autoquet_simulink_expo_model_DW.obj_jn.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S5>/Digital Output' */

  /* Terminate for MATLABSystem: '<S5>/PWM' */
  if (!autoquet_simulink_expo_model_DW.obj_ec.matlabCodegenIsDeleted) {
    autoquet_simulink_expo_model_DW.obj_ec.matlabCodegenIsDeleted = true;
    if ((autoquet_simulink_expo_model_DW.obj_ec.isInitialized == 1L) &&
        autoquet_simulink_expo_model_DW.obj_ec.isSetupComplete) {
      autoquet_simulink_expo_model_DW.obj_ec.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(5UL);
      MW_PWM_SetDutyCycle
        (autoquet_simulink_expo_model_DW.obj_ec.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      autoquet_simulink_expo_model_DW.obj_ec.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(5UL);
      MW_PWM_Close
        (autoquet_simulink_expo_model_DW.obj_ec.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/PWM' */

  /* Terminate for MATLABSystem: '<S5>/RX LED (D5)' */
  if (!autoquet_simulink_expo_model_DW.obj_kf.matlabCodegenIsDeleted) {
    autoquet_simulink_expo_model_DW.obj_kf.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S5>/RX LED (D5)' */

  /* Terminate for MATLABSystem: '<S5>/I2C Read1' */
  if (!autoquet_simulink_expo_model_DW.obj_j.matlabCodegenIsDeleted) {
    autoquet_simulink_expo_model_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((autoquet_simulink_expo_model_DW.obj_j.isInitialized == 1L) &&
        autoquet_simulink_expo_model_DW.obj_j.isSetupComplete) {
      MW_I2C_Close
        (autoquet_simulink_expo_model_DW.obj_j.I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/I2C Read1' */

  /* Terminate for Atomic SubSystem: '<S5>/BNO055 IMU Sensor' */
  /* Terminate for MATLABSystem: '<S11>/Base sensor block' */
  if (!autoquet_simulink_expo_model_DW.obj_e.matlabCodegenIsDeleted) {
    autoquet_simulink_expo_model_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((autoquet_simulink_expo_model_DW.obj_e.isInitialized == 1L) &&
        autoquet_simulink_expo_model_DW.obj_e.isSetupComplete) {
      obj = &autoquet_simulink_expo_model_DW.obj_e.i2cObj;
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  obj = &autoquet_simulink_expo_model_DW.obj_e.i2cObj;
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    if (obj->isInitialized == 1L) {
      obj->isInitialized = 2L;
    }
  }

  /* End of Terminate for MATLABSystem: '<S11>/Base sensor block' */
  /* End of Terminate for SubSystem: '<S5>/BNO055 IMU Sensor' */
  /* End of Terminate for SubSystem: '<Root>/Pressure Control' */

  /* Terminate for Atomic SubSystem: '<Root>/Stopwatch' */
  /* Terminate for MATLABSystem: '<S6>/Clock pin' */
  if (!autoquet_simulink_expo_model_DW.obj_n.matlabCodegenIsDeleted) {
    autoquet_simulink_expo_model_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S6>/Clock pin' */

  /* Terminate for MATLABSystem: '<S6>/Data pin' */
  if (!autoquet_simulink_expo_model_DW.obj_gj.matlabCodegenIsDeleted) {
    autoquet_simulink_expo_model_DW.obj_gj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S6>/Data pin' */
  /* End of Terminate for SubSystem: '<Root>/Stopwatch' */

  /* Terminate for MATLABSystem: '<Root>/Serial Receive' */
  if (!autoquet_simulink_expo_model_DW.obj_k.matlabCodegenIsDeleted) {
    autoquet_simulink_expo_model_DW.obj_k.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Serial Receive' */

  /* Terminate for S-Function (sfun_private_function_caller) generated from: '<Root>/Function-Call Subsystem' incorporates:
   *  SubSystem: '<Root>/Function-Call Subsystem'
   */
  send_params_Term();

  /* End of Terminate for S-Function (sfun_private_function_caller) generated from: '<Root>/Function-Call Subsystem' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
