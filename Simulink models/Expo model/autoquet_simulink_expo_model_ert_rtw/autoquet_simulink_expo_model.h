/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: autoquet_simulink_expo_model.h
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

#ifndef RTW_HEADER_autoquet_simulink_expo_model_h_
#define RTW_HEADER_autoquet_simulink_expo_model_h_
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

#include "autoquet_simulink_expo_model_types.h"
#include "send_params.h"
#include <stddef.h>
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals (default storage) */
typedef struct {
  real32_T DigitalFilter[4];           /* '<S7>/Digital Filter' */
  int16_T b_RegisterValue[3];
  uint8_T output_raw[6];
  real32_T TmpLatchAtMeasuredLimbPressureO;
  real32_T TmpLatchAtBNO_XOutport1;
  real32_T TmpLatchAtBNO_YOutport1;
  real32_T TmpLatchAtBNO_ZOutport1;
  real32_T TmpLatchAtFilteredpressurereadi;
  real32_T TmpLatchAtMotorPWMOutport1;
  real32_T CCCodeBlock5_o1;            /* '<S5>/C//C++ Code Block5' */
  real32_T Sum;                        /* '<S5>/Sum' */
  real32_T CCCodeBlock_o1;             /* '<S5>/C//C++ Code Block' */
  real32_T CCCodeBlock3;               /* '<S5>/C//C++ Code Block3' */
  real32_T CCCodeBlock4_o1;            /* '<S2>/C//C++ Code Block4' */
  real32_T CCCodeBlock4_o2[3];         /* '<S2>/C//C++ Code Block4' */
  real32_T pressure_set_point;       /* '<Root>/Blood flow control stateflow' */
  real32_T acc1;
  real32_T zCurr;
  real32_T DigitalFilter_m;            /* '<S8>/Digital Filter' */
  int32_T j;
  int32_T cff;
  uint32_T CCCodeBlock_o2;             /* '<Root>/C//C++ Code Block' */
  real32_T Memory;                     /* '<Root>/Memory' */
  real32_T TmpLatchAtPressuresetpointOutpo;
  uint8_T BytePack2[4];                /* '<S4>/Byte Pack2' */
  uint8_T BytePack3[4];                /* '<S4>/Byte Pack3' */
  uint8_T BytePack4[4];                /* '<S4>/Byte Pack4' */
  uint8_T BytePack5[4];                /* '<S4>/Byte Pack5' */
  int16_T k;
  int16_T n;
  uint16_T TmpLatchAtBloodflowsummationOut;
  uint16_T TmpLatchAtBloodflowthresholdOut;
  uint16_T CCCodeBlock3_o1;            /* '<S2>/C//C++ Code Block3' */
  uint8_T CCCodeBlock_o1_k[4];         /* '<Root>/C//C++ Code Block' */
  uint8_T output_raw_c[2];
  uint8_T TmpLatchAtinitial_searchOutport;
  uint8_T TmpLatchAtOperationmodeOutport1;
  uint8_T BytePack1[4];                /* '<S4>/Byte Pack1' */
  uint8_T BytePack[4];                 /* '<S4>/Byte Pack' */
  uint8_T BytePack6;                   /* '<S4>/Byte Pack6' */
  uint8_T BytePack7;                   /* '<S4>/Byte Pack7' */
  uint8_T BytePack8;                   /* '<S4>/Byte Pack8' */
  uint8_T BytePack9[2];                /* '<S4>/Byte Pack9' */
  uint8_T BytePack10;                  /* '<S4>/Byte Pack10' */
  uint8_T BytePack11[2];               /* '<S4>/Byte Pack11' */
  uint8_T BytePack12[4];               /* '<S4>/Byte Pack12' */
  uint8_T BytePack13;                  /* '<S4>/Byte Pack13' */
  uint8_T BytePack14;                  /* '<S4>/Byte Pack14' */
  uint8_T BytePack15;                  /* '<S4>/Byte Pack15' */
  uint8_T BytePack16;                  /* '<S4>/Byte Pack16' */
  uint8_T BytePack17;                  /* '<S4>/Byte Pack17' */
  uint8_T BytePack18;                  /* '<S4>/Byte Pack18' */
  uint8_T BytePack19;                  /* '<S4>/Byte Pack19' */
  uint8_T CCCodeBlock3_h[4];           /* '<S6>/C//C++ Code Block3' */
  uint8_T CCCodeBlock4;                /* '<S6>/C//C++ Code Block4' */
  uint8_T CCCodeBlock1[4];             /* '<S6>/C//C++ Code Block1' */
  uint8_T CCCodeBlock5_o2;             /* '<S5>/C//C++ Code Block5' */
  uint8_T CCCodeBlock5_o3;             /* '<S5>/C//C++ Code Block5' */
  uint8_T I2CRead1[2];                 /* '<S5>/I2C Read1' */
  uint8_T initial_search;            /* '<Root>/Blood flow control stateflow' */
  boolean_T TmpLatchAtmotor_activeOutport1;
  boolean_T TmpLatchAtAccelerometeractiveOu;
  boolean_T TmpLatchAtpause_summationOutpor;
  boolean_T TmpLatchAtBloodflowbooleanOutpo;
  boolean_T TmpLatchAtSolenoidstateOutport1;
  boolean_T ideal_pressure_found;
  boolean_T TmpLatchAtIncreasesignalOutport;
  boolean_T TmpLatchAtDecreasesignalOutport;
  boolean_T TmpLatchAtautomodesignalOutport;
  boolean_T clk_pin;                   /* '<S6>/Transmit firmware' */
  boolean_T data_pin;                  /* '<S6>/Transmit firmware' */
  boolean_T TmpSignalConversionAtCCCodeBloc[3];
  boolean_T CCCodeBlock_o2_l;          /* '<S5>/C//C++ Code Block' */
  boolean_T CCCodeBlock_o3;            /* '<S5>/C//C++ Code Block' */
  boolean_T Increasesignalinput;       /* '<S5>/Increase signal input' */
  boolean_T Decreasesignalinput;       /* '<S5>/Decrease signal input' */
  boolean_T Automodesignalinput;       /* '<S5>/Automode signal input' */
  boolean_T CCCodeBlock2;              /* '<S2>/C//C++ Code Block2' */
  boolean_T CCCodeBlock;               /* '<S2>/C//C++ Code Block' */
  boolean_T CCCodeBlock3_o2;           /* '<S2>/C//C++ Code Block3' */
  boolean_T ideal_pressure_found_c;  /* '<Root>/Blood flow control stateflow' */
} B_autoquet_simulink_expo_mode_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<S4>/Serial Transmit' */
  codertarget_arduinobase_int_n_T obj_e;/* '<S11>/Base sensor block' */
  codertarget_arduinobase__nou1_T obj_k;/* '<Root>/Serial Receive' */
  codertarget_arduinobase_in_no_T obj_j;/* '<S5>/I2C Read1' */
  codertarget_arduinobase_block_T obj_h;/* '<S5>/Increase signal input' */
  codertarget_arduinobase_block_T obj_g;/* '<S5>/Decrease signal input' */
  codertarget_arduinobase_block_T obj_d;/* '<S5>/Automode signal input' */
  codertarget_arduinobase_blo_n_T obj_gj;/* '<S6>/Data pin' */
  codertarget_arduinobase_blo_n_T obj_n;/* '<S6>/Clock pin' */
  codertarget_arduinobase_blo_n_T obj_kf;/* '<S5>/RX LED (D5)' */
  codertarget_arduinobase_blo_n_T obj_jn;/* '<S5>/Digital Output' */
  codertarget_arduinobase_blo_n_T obj_a;/* '<S5>/D6' */
  codertarget_arduinobase_i_nou_T obj_ec;/* '<S5>/PWM' */
  real32_T DigitalFilter_states[5];    /* '<S8>/Digital Filter' */
  real32_T DigitalFilter_states_i[20]; /* '<S7>/Digital Filter' */
  int32_T DigitalFilter_circBuf;       /* '<S7>/Digital Filter' */
  real32_T Memory_PreviousInput;       /* '<Root>/Memory' */
  real32_T Memory1_PreviousInput[3];   /* '<Root>/Memory1' */
  real32_T binary_search_lower;      /* '<Root>/Blood flow control stateflow' */
  real32_T binary_search_upper;      /* '<Root>/Blood flow control stateflow' */
  real32_T pressure_difference;      /* '<Root>/Blood flow control stateflow' */
  real32_T pressure_lower_bound;     /* '<Root>/Blood flow control stateflow' */
  real32_T pressure_upper_bound;     /* '<Root>/Blood flow control stateflow' */
  uint32_T durationCounter_1;          /* '<S5>/Indicator controller' */
  uint32_T durationCounter_1_e;      /* '<Root>/Blood flow control stateflow' */
  uint32_T durationCounter_1_m;      /* '<Root>/Blood flow control stateflow' */
  uint32_T durationCounter_1_l;      /* '<Root>/Blood flow control stateflow' */
  uint32_T durationCounter_1_h;      /* '<Root>/Blood flow control stateflow' */
  uint16_T temporalCounter_i1;       /* '<Root>/Blood flow control stateflow' */
  uint8_T bit_iterator;                /* '<S6>/Transmit firmware' */
  uint8_T buffer;                      /* '<S6>/Transmit firmware' */
  uint8_T len;                         /* '<S6>/Transmit firmware' */
  uint8_T word_iterator;               /* '<S6>/Transmit firmware' */
  uint8_T command_state;               /* '<S6>/Transmit firmware' */
  uint8_T command;                     /* '<S6>/Transmit firmware' */
  uint8_T to_screen[4];                /* '<S6>/Transmit firmware' */
  uint8_T pressure_flash;              /* '<S6>/Transmit firmware' */
  uint8_T flash_ratio;                 /* '<S6>/Transmit firmware' */
  uint8_T is_active_c1_autoquet_simulink_;/* '<S6>/Transmit firmware' */
  uint8_T is_c1_autoquet_simulink_expo_mo;/* '<S6>/Transmit firmware' */
  uint8_T is_sending_firmware;         /* '<S6>/Transmit firmware' */
  uint8_T is_command_flow;             /* '<S6>/Transmit firmware' */
  uint8_T is_send_data;                /* '<S6>/Transmit firmware' */
  uint8_T is_active_c4_autoquet_simulink_;/* '<S5>/Indicator controller' */
  uint8_T is_c4_autoquet_simulink_expo_mo;/* '<S5>/Indicator controller' */
  uint8_T is_Blink_indicator;          /* '<S5>/Indicator controller' */
  uint8_T temporalCounter_i1_h;        /* '<S5>/Indicator controller' */
  uint8_T is_active_c2_autoquet_simulink_;/* '<Root>/Data send controller' */
  uint8_T is_c2_autoquet_simulink_expo_mo;/* '<Root>/Data send controller' */
  uint8_T is_active_c3_autoquet_simulink_;
                                     /* '<Root>/Blood flow control stateflow' */
  uint8_T is_c3_autoquet_simulink_expo_mo;
                                     /* '<Root>/Blood flow control stateflow' */
  uint8_T is_Auto_mode;              /* '<Root>/Blood flow control stateflow' */
  uint8_T is_Binary_search_ideal_pressure;
                                     /* '<Root>/Blood flow control stateflow' */
  uint8_T is_Find_initial_bounds;    /* '<Root>/Blood flow control stateflow' */
  uint8_T is_Deflate;                /* '<Root>/Blood flow control stateflow' */
  uint8_T is_Inflate;                /* '<Root>/Blood flow control stateflow' */
  uint8_T is_Steady_state;           /* '<Root>/Blood flow control stateflow' */
  boolean_T full_data_sent;            /* '<S6>/Transmit firmware' */
  boolean_T transmit;                  /* '<S6>/Transmit firmware' */
  boolean_T upper_bound_found;       /* '<Root>/Blood flow control stateflow' */
} DW_autoquet_simulink_expo_mod_T;

/* Parameters (default storage) */
struct P_autoquet_simulink_expo_mode_T_ {
  real_T BNO055IMUSensor_SampleTime;
                                   /* Mask Parameter: BNO055IMUSensor_SampleTime
                                    * Referenced by: '<S11>/Base sensor block'
                                    */
  real_T Automodesignalinput_SampleTime;/* Expression: -1
                                         * Referenced by: '<S5>/Automode signal input'
                                         */
  real_T Decreasesignalinput_SampleTime;/* Expression: -1
                                         * Referenced by: '<S5>/Decrease signal input'
                                         */
  real_T I2CRead1_SampleTime;          /* Expression: 0.1
                                        * Referenced by: '<S5>/I2C Read1'
                                        */
  real_T Increasesignalinput_SampleTime;/* Expression: -1
                                         * Referenced by: '<S5>/Increase signal input'
                                         */
  real_T SerialReceive_Protocol;       /* Expression: 0
                                        * Referenced by: '<Root>/Serial Receive'
                                        */
  real_T SerialReceive_QueueSizeFactor;/* Expression: 3
                                        * Referenced by: '<Root>/Serial Receive'
                                        */
  real_T SerialTransmit_Protocol;      /* Expression: 0
                                        * Referenced by: '<S4>/Serial Transmit'
                                        */
  real32_T DigitalFilter_InitialStates;
                              /* Computed Parameter: DigitalFilter_InitialStates
                               * Referenced by: '<S8>/Digital Filter'
                               */
  real32_T DigitalFilter_Coefficients[6];
                               /* Computed Parameter: DigitalFilter_Coefficients
                                * Referenced by: '<S8>/Digital Filter'
                                */
  real32_T DigitalFilter_InitialStates_p;
                            /* Computed Parameter: DigitalFilter_InitialStates_p
                             * Referenced by: '<S7>/Digital Filter'
                             */
  real32_T DigitalFilter_Coefficients_l[6];
                             /* Computed Parameter: DigitalFilter_Coefficients_l
                              * Referenced by: '<S7>/Digital Filter'
                              */
  real32_T Initial_pressure_start_Value;
                             /* Computed Parameter: Initial_pressure_start_Value
                              * Referenced by: '<Root>/Initial_pressure_start'
                              */
  real32_T Bulkincrement_Value;       /* Computed Parameter: Bulkincrement_Value
                                       * Referenced by: '<Root>/Bulk increment'
                                       */
  real32_T Waitperiodseconds_Value;
                                  /* Computed Parameter: Waitperiodseconds_Value
                                   * Referenced by: '<Root>/Wait period (seconds)'
                                   */
  real32_T Pressureresolution_Value;
                                 /* Computed Parameter: Pressureresolution_Value
                                  * Referenced by: '<Root>/Pressure resolution'
                                  */
  real32_T Memory_InitialCondition;
                                  /* Computed Parameter: Memory_InitialCondition
                                   * Referenced by: '<Root>/Memory'
                                   */
  real32_T Memory1_InitialCondition;
                                 /* Computed Parameter: Memory1_InitialCondition
                                  * Referenced by: '<Root>/Memory1'
                                  */
  uint16_T accel_threshold_Value;   /* Computed Parameter: accel_threshold_Value
                                     * Referenced by: '<S2>/accel_threshold'
                                     */
  uint16_T pausetimemsec_Value;       /* Computed Parameter: pausetimemsec_Value
                                       * Referenced by: '<S2>/pause time (msec)'
                                       */
  uint16_T bloodflow_threshold_Value;
                                /* Computed Parameter: bloodflow_threshold_Value
                                 * Referenced by: '<S2>/bloodflow_threshold'
                                 */
  boolean_T Transmitfirmware_transmit; /* Expression: false
                                        * Referenced by: '<S6>/Transmit firmware'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_autoquet_simulink_exp_T {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint16_T TID[4];
    } TaskCounters;
  } Timing;
};

/* Block parameters (default storage) */
extern P_autoquet_simulink_expo_mode_T autoquet_simulink_expo_model_P;

/* Block signals (default storage) */
extern B_autoquet_simulink_expo_mode_T autoquet_simulink_expo_model_B;

/* Block states (default storage) */
extern DW_autoquet_simulink_expo_mod_T autoquet_simulink_expo_model_DW;

/* External function called from main */
extern void autoquet_simulink_expo_model_SetEventsForThisBaseStep(boolean_T
  *eventFlags);

/* Model entry point functions */
extern void autoquet_simulink_expo_model_initialize(void);
extern void autoquet_simulink_expo_model_step0(void);
extern void autoquet_simulink_expo_model_step1(void);
extern void autoquet_simulink_expo_model_step2(void);
extern void autoquet_simulink_expo_model_step3(void);
extern void autoquet_simulink_expo_model_terminate(void);

/* Real-time Model object */
extern RT_MODEL_autoquet_simulink_ex_T *const autoquet_simulink_expo_model_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'autoquet_simulink_expo_model'
 * '<S1>'   : 'autoquet_simulink_expo_model/Blood flow control stateflow'
 * '<S2>'   : 'autoquet_simulink_expo_model/Bloodflow Detection'
 * '<S3>'   : 'autoquet_simulink_expo_model/Data send controller'
 * '<S4>'   : 'autoquet_simulink_expo_model/Function-Call Subsystem'
 * '<S5>'   : 'autoquet_simulink_expo_model/Pressure Control'
 * '<S6>'   : 'autoquet_simulink_expo_model/Stopwatch'
 * '<S7>'   : 'autoquet_simulink_expo_model/Bloodflow Detection/DC offset removal'
 * '<S8>'   : 'autoquet_simulink_expo_model/Bloodflow Detection/Sensor noise supression'
 * '<S9>'   : 'autoquet_simulink_expo_model/Bloodflow Detection/DC offset removal/Check Signal Attributes'
 * '<S10>'  : 'autoquet_simulink_expo_model/Bloodflow Detection/Sensor noise supression/Check Signal Attributes'
 * '<S11>'  : 'autoquet_simulink_expo_model/Pressure Control/BNO055 IMU Sensor'
 * '<S12>'  : 'autoquet_simulink_expo_model/Pressure Control/Indicator controller'
 * '<S13>'  : 'autoquet_simulink_expo_model/Stopwatch/Transmit firmware'
 */
#endif                          /* RTW_HEADER_autoquet_simulink_expo_model_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
