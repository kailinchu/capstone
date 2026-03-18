/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: autoquet_simulink.h
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

#ifndef RTW_HEADER_autoquet_simulink_h_
#define RTW_HEADER_autoquet_simulink_h_
#ifndef autoquet_simulink_COMMON_INCLUDES_
#define autoquet_simulink_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "string.h"
#include "MW_SerialRead.h"
#include "MW_SerialWrite.h"
#include "MW_arduino_digitalio.h"
#include "MW_I2C.h"
#include "io_wrappers.h"
#include "MW_PWM.h"
#endif                                 /* autoquet_simulink_COMMON_INCLUDES_ */

#include "autoquet_simulink_types.h"
#include "rt_zcfcn.h"
#include <stddef.h>
#include "zero_crossing_types.h"
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
  uint32_T Timekeeper_o2;              /* '<Root>/Time keeper' */
  real32_T CCCodeBlock5_o1;            /* '<S4>/C//C++ Code Block5' */
  real32_T Sum;                        /* '<S4>/Sum' */
  real32_T CCCodeBlock_o1;             /* '<S4>/C//C++ Code Block' */
  real32_T CCCodeBlock3;               /* '<S4>/C//C++ Code Block3' */
  real32_T DigitalFilter[4];           /* '<S6>/Digital Filter' */
  real32_T CCCodeBlock4_o1;            /* '<S2>/C//C++ Code Block4' */
  real32_T CCCodeBlock4_o2[3];         /* '<S2>/C//C++ Code Block4' */
  real32_T pressure_set_point;       /* '<Root>/Blood flow control stateflow' */
  uint16_T TmpRTBAtCCCodeBlock3Inport3;/* '<S2>/bloodflow_threshold' */
  uint16_T CCCodeBlock3_o1;            /* '<S2>/C//C++ Code Block3' */
  uint8_T Timekeeper_o1[4];            /* '<Root>/Time keeper' */
  uint8_T CCCodeBlock5_o2;             /* '<S4>/C//C++ Code Block5' */
  uint8_T CCCodeBlock5_o3;             /* '<S4>/C//C++ Code Block5' */
  uint8_T CCCodeBlock3_h[4];           /* '<S5>/C//C++ Code Block3' */
  uint8_T CCCodeBlock1[4];             /* '<S5>/C//C++ Code Block1' */
  uint8_T CCCodeBlock4;                /* '<S5>/C//C++ Code Block4' */
  uint8_T I2CRead1[2];                 /* '<S4>/I2C Read1' */
  uint8_T BytePack1[4];                /* '<S3>/Byte Pack1' */
  uint8_T BytePack[4];                 /* '<S3>/Byte Pack' */
  uint8_T BytePack2[4];                /* '<S3>/Byte Pack2' */
  uint8_T BytePack3[4];                /* '<S3>/Byte Pack3' */
  uint8_T BytePack4[4];                /* '<S3>/Byte Pack4' */
  uint8_T BytePack5[4];                /* '<S3>/Byte Pack5' */
  uint8_T BytePack6;                   /* '<S3>/Byte Pack6' */
  uint8_T BytePack7;                   /* '<S3>/Byte Pack7' */
  uint8_T BytePack8;                   /* '<S3>/Byte Pack8' */
  uint8_T BytePack9[2];                /* '<S3>/Byte Pack9' */
  uint8_T BytePack10;                  /* '<S3>/Byte Pack10' */
  uint8_T BytePack11[2];               /* '<S3>/Byte Pack11' */
  uint8_T BytePack12[4];               /* '<S3>/Byte Pack12' */
  uint8_T BytePack13;                  /* '<S3>/Byte Pack13' */
  uint8_T BytePack14;                  /* '<S3>/Byte Pack14' */
  uint8_T BytePack15;                  /* '<S3>/Byte Pack15' */
  uint8_T BytePack16;                  /* '<S3>/Byte Pack16' */
  uint8_T BytePack17;                  /* '<S3>/Byte Pack17' */
  uint8_T BytePack18;                  /* '<S3>/Byte Pack18' */
  uint8_T BytePack19;                  /* '<S3>/Byte Pack19' */
  uint8_T initial_search;            /* '<Root>/Blood flow control stateflow' */
  boolean_T TmpSignalConversionAtCCCodeBloc[3];
  boolean_T CCCodeBlock_o2;            /* '<S4>/C//C++ Code Block' */
  boolean_T CCCodeBlock_o3;            /* '<S4>/C//C++ Code Block' */
  boolean_T CCCodeBlock2;              /* '<S2>/C//C++ Code Block2' */
  boolean_T CCCodeBlock;               /* '<S2>/C//C++ Code Block' */
  boolean_T CCCodeBlock3_o2;           /* '<S2>/C//C++ Code Block3' */
  boolean_T clk_pin;                   /* '<S5>/Chart' */
  boolean_T data_pin;                  /* '<S5>/Chart' */
  boolean_T Increasesignalinput;       /* '<S4>/Increase signal input' */
  boolean_T Decreasesignalinput;       /* '<S4>/Decrease signal input' */
  boolean_T Automodesignalinput;       /* '<S4>/Automode signal input' */
  boolean_T ideal_pressure_found;    /* '<Root>/Blood flow control stateflow' */
} B_autoquet_simulink_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<S3>/Serial Transmit' */
  codertarget_arduinobase_int_o_T obj_e;/* '<S10>/Base sensor block' */
  codertarget_arduinobase_in_op_T obj_j;/* '<S4>/I2C Read1' */
  codertarget_arduinobase_block_T obj_h;/* '<S4>/Increase signal input' */
  codertarget_arduinobase_block_T obj_g;/* '<S4>/Decrease signal input' */
  codertarget_arduinobase_block_T obj_d;/* '<S4>/Automode signal input' */
  codertarget_arduinobase_blo_o_T obj_gj;/* '<S5>/Data pin' */
  codertarget_arduinobase_blo_o_T obj_n;/* '<S5>/Clock pin' */
  codertarget_arduinobase_blo_o_T obj_jn;/* '<S4>/Digital Output' */
  codertarget_arduinobase_i_op4_T obj_ec;/* '<S4>/PWM' */
  real32_T DigitalFilter_states[5];    /* '<S7>/Digital Filter' */
  real32_T DigitalFilter_states_i[20]; /* '<S6>/Digital Filter' */
  int32_T DigitalFilter_circBuf;       /* '<S6>/Digital Filter' */
  real32_T binary_search_lower;      /* '<Root>/Blood flow control stateflow' */
  real32_T binary_search_upper;      /* '<Root>/Blood flow control stateflow' */
  real32_T pressure_difference;      /* '<Root>/Blood flow control stateflow' */
  real32_T pressure_lower_bound;     /* '<Root>/Blood flow control stateflow' */
  real32_T pressure_upper_bound;     /* '<Root>/Blood flow control stateflow' */
  int32_T clockTickCounter;            /* '<Root>/Pulse Generator' */
  uint32_T durationCounter_1;        /* '<Root>/Blood flow control stateflow' */
  uint32_T durationCounter_1_p;      /* '<Root>/Blood flow control stateflow' */
  uint32_T durationCounter_1_e;      /* '<Root>/Blood flow control stateflow' */
  uint32_T durationCounter_1_m;      /* '<Root>/Blood flow control stateflow' */
  volatile uint16_T TmpRTBAtCCCodeBlock3Inport3_Buf;/* synthesized block */
  volatile int8_T TmpRTBAtCCCodeBlock3Inport3_sem;/* synthesized block */
  uint8_T bit_iterator;                /* '<S5>/Chart' */
  uint8_T buffer;                      /* '<S5>/Chart' */
  uint8_T len;                         /* '<S5>/Chart' */
  uint8_T word_iterator;               /* '<S5>/Chart' */
  uint8_T command_state;               /* '<S5>/Chart' */
  uint8_T command;                     /* '<S5>/Chart' */
  uint8_T to_screen[4];                /* '<S5>/Chart' */
  uint8_T pressure_flash;              /* '<S5>/Chart' */
  uint8_T flash_ratio;                 /* '<S5>/Chart' */
  uint8_T is_active_c1_autoquet_simulink;/* '<S5>/Chart' */
  uint8_T is_c1_autoquet_simulink;     /* '<S5>/Chart' */
  uint8_T is_sending_firmware;         /* '<S5>/Chart' */
  uint8_T is_command_flow;             /* '<S5>/Chart' */
  uint8_T is_send_data;                /* '<S5>/Chart' */
  uint8_T is_active_c3_autoquet_simulink;
                                     /* '<Root>/Blood flow control stateflow' */
  uint8_T is_c3_autoquet_simulink;   /* '<Root>/Blood flow control stateflow' */
  uint8_T is_Auto_mode;              /* '<Root>/Blood flow control stateflow' */
  uint8_T is_Binary_search_ideal_pressure;
                                     /* '<Root>/Blood flow control stateflow' */
  uint8_T is_Find_initial_bounds;    /* '<Root>/Blood flow control stateflow' */
  uint8_T is_Deflate;                /* '<Root>/Blood flow control stateflow' */
  uint8_T is_Inflate;                /* '<Root>/Blood flow control stateflow' */
  boolean_T full_data_sent;            /* '<S5>/Chart' */
  boolean_T transmit;                  /* '<S5>/Chart' */
  boolean_T upper_bound_found;       /* '<Root>/Blood flow control stateflow' */
} DW_autoquet_simulink_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Communicationblock_Trig_ZCE;/* '<Root>/Communication block' */
} PrevZCX_autoquet_simulink_T;

/* Parameters (default storage) */
struct P_autoquet_simulink_T_ {
  real_T BNO055IMUSensor_SampleTime;
                                   /* Mask Parameter: BNO055IMUSensor_SampleTime
                                    * Referenced by: '<S10>/Base sensor block'
                                    */
  real_T SerialTransmit_Protocol;      /* Expression: 0
                                        * Referenced by: '<S3>/Serial Transmit'
                                        */
  real_T Automodesignalinput_SampleTime;/* Expression: 0.1
                                         * Referenced by: '<S4>/Automode signal input'
                                         */
  real_T Decreasesignalinput_SampleTime;/* Expression: 0.1
                                         * Referenced by: '<S4>/Decrease signal input'
                                         */
  real_T I2CRead1_SampleTime;          /* Expression: 0.1
                                        * Referenced by: '<S4>/I2C Read1'
                                        */
  real_T Increasesignalinput_SampleTime;/* Expression: 0.1
                                         * Referenced by: '<S4>/Increase signal input'
                                         */
  real_T PulseGenerator_Amp;           /* Expression: 1
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period;        /* Expression: 100
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T PulseGenerator_Duty;          /* Expression: 50
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T PulseGenerator_PhaseDelay;    /* Expression: 0
                                        * Referenced by: '<Root>/Pulse Generator'
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
  real32_T DigitalFilter_InitialStates;
                              /* Computed Parameter: DigitalFilter_InitialStates
                               * Referenced by: '<S7>/Digital Filter'
                               */
  real32_T DigitalFilter_Coefficients[6];
                               /* Computed Parameter: DigitalFilter_Coefficients
                                * Referenced by: '<S7>/Digital Filter'
                                */
  real32_T DigitalFilter_InitialStates_p;
                            /* Computed Parameter: DigitalFilter_InitialStates_p
                             * Referenced by: '<S6>/Digital Filter'
                             */
  real32_T DigitalFilter_Coefficients_l[6];
                             /* Computed Parameter: DigitalFilter_Coefficients_l
                              * Referenced by: '<S6>/Digital Filter'
                              */
  uint16_T bloodflow_threshold_Value;
                                /* Computed Parameter: bloodflow_threshold_Value
                                 * Referenced by: '<S2>/bloodflow_threshold'
                                 */
  uint16_T accel_threshold_Value;   /* Computed Parameter: accel_threshold_Value
                                     * Referenced by: '<S2>/accel_threshold'
                                     */
  uint16_T pausetimemsec_Value;       /* Computed Parameter: pausetimemsec_Value
                                       * Referenced by: '<S2>/pause time (msec)'
                                       */
  boolean_T Chart_transmit;            /* Expression: false
                                        * Referenced by: '<S5>/Chart'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_autoquet_simulink_T {
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
extern P_autoquet_simulink_T autoquet_simulink_P;

/* Block signals (default storage) */
extern B_autoquet_simulink_T autoquet_simulink_B;

/* Block states (default storage) */
extern DW_autoquet_simulink_T autoquet_simulink_DW;

/* Zero-crossing (trigger) state */
extern PrevZCX_autoquet_simulink_T autoquet_simulink_PrevZCX;

/* External function called from main */
extern void autoquet_simulink_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void autoquet_simulink_initialize(void);
extern void autoquet_simulink_step0(void);
extern void autoquet_simulink_step1(void);
extern void autoquet_simulink_step2(void);
extern void autoquet_simulink_step3(void);
extern void autoquet_simulink_terminate(void);

/* Real-time Model object */
extern RT_MODEL_autoquet_simulink_T *const autoquet_simulink_M;
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
 * '<Root>' : 'autoquet_simulink'
 * '<S1>'   : 'autoquet_simulink/Blood flow control stateflow'
 * '<S2>'   : 'autoquet_simulink/Bloodflow Detection'
 * '<S3>'   : 'autoquet_simulink/Communication block'
 * '<S4>'   : 'autoquet_simulink/Pressure Control'
 * '<S5>'   : 'autoquet_simulink/Stopwatch'
 * '<S6>'   : 'autoquet_simulink/Bloodflow Detection/DC offset removal'
 * '<S7>'   : 'autoquet_simulink/Bloodflow Detection/Sensor noise supression'
 * '<S8>'   : 'autoquet_simulink/Bloodflow Detection/DC offset removal/Check Signal Attributes'
 * '<S9>'   : 'autoquet_simulink/Bloodflow Detection/Sensor noise supression/Check Signal Attributes'
 * '<S10>'  : 'autoquet_simulink/Pressure Control/BNO055 IMU Sensor'
 * '<S11>'  : 'autoquet_simulink/Stopwatch/Chart'
 */
#endif                                 /* RTW_HEADER_autoquet_simulink_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
