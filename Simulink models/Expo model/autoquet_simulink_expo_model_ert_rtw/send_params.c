/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: send_params.c
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

#include "send_params_private.h"
#include "autoquet_simulink_expo_model.h"
#include "send_params.h"
#include "rtwtypes.h"

/* System initialize for Simulink Function: '<Root>/Function-Call Subsystem' */
void send_params_Init(void)
{
  /* Start for MATLABSystem: '<S4>/Serial Transmit' */
  autoquet_simulink_expo_model_DW.obj.matlabCodegenIsDeleted = false;
  autoquet_simulink_expo_model_DW.obj.Protocol =
    autoquet_simulink_expo_model_P.SerialTransmit_Protocol;
  autoquet_simulink_expo_model_DW.obj.isInitialized = 1L;
  autoquet_simulink_expo_model_DW.obj.port = 0.0;
  autoquet_simulink_expo_model_DW.obj.dataSizeInBytes = 1.0;
  autoquet_simulink_expo_model_DW.obj.dataType = 0.0;
  autoquet_simulink_expo_model_DW.obj.sendModeEnum = 0.0;
  autoquet_simulink_expo_model_DW.obj.sendFormatEnum = 0.0;
  MW_SCI_Open(0);
  autoquet_simulink_expo_model_DW.obj.isSetupComplete = true;
}

/* Output and update for Simulink Function: '<Root>/Function-Call Subsystem' */
void send_params(void)
{
  uint8_T dataIn[47];
  uint8_T rtb_TmpLatchAtTimeOutport1[4];

  /* SignalConversion generated from: '<S4>/Pressure set point' */
  autoquet_simulink_expo_model_B.TmpLatchAtPressuresetpointOutpo =
    autoquet_simulink_expo_model_B.CCCodeBlock5_o1;

  /* SignalConversion generated from: '<S4>/Measured Limb Pressure' */
  autoquet_simulink_expo_model_B.TmpLatchAtMeasuredLimbPressureO =
    autoquet_simulink_expo_model_B.Memory;

  /* SignalConversion generated from: '<S4>/BNO_X' */
  autoquet_simulink_expo_model_B.TmpLatchAtBNO_XOutport1 =
    autoquet_simulink_expo_model_B.CCCodeBlock4_o2[0];

  /* SignalConversion generated from: '<S4>/BNO_Y' */
  autoquet_simulink_expo_model_B.TmpLatchAtBNO_YOutport1 =
    autoquet_simulink_expo_model_B.CCCodeBlock4_o2[1];

  /* SignalConversion generated from: '<S4>/BNO_Z' */
  autoquet_simulink_expo_model_B.TmpLatchAtBNO_ZOutport1 =
    autoquet_simulink_expo_model_B.CCCodeBlock4_o2[2];

  /* SignalConversion generated from: '<S4>/Filtered pressure reading' */
  autoquet_simulink_expo_model_B.TmpLatchAtFilteredpressurereadi =
    autoquet_simulink_expo_model_B.CCCodeBlock4_o1;

  /* SignalConversion generated from: '<S4>/motor_active' */
  autoquet_simulink_expo_model_B.TmpLatchAtmotor_activeOutport1 =
    autoquet_simulink_expo_model_B.CCCodeBlock_o2_l;

  /* SignalConversion generated from: '<S4>/Accelerometer active' */
  autoquet_simulink_expo_model_B.TmpLatchAtAccelerometeractiveOu =
    autoquet_simulink_expo_model_B.CCCodeBlock2;

  /* SignalConversion generated from: '<S4>/pause_summation' */
  autoquet_simulink_expo_model_B.TmpLatchAtpause_summationOutpor =
    autoquet_simulink_expo_model_B.CCCodeBlock;

  /* SignalConversion generated from: '<S4>/Bloodflow summation' */
  autoquet_simulink_expo_model_B.TmpLatchAtBloodflowsummationOut =
    autoquet_simulink_expo_model_B.CCCodeBlock3_o1;

  /* SignalConversion generated from: '<S4>/Bloodflow boolean' */
  autoquet_simulink_expo_model_B.TmpLatchAtBloodflowbooleanOutpo =
    autoquet_simulink_expo_model_B.CCCodeBlock3_o2;

  /* SignalConversion generated from: '<S4>/Bloodflow threshold' incorporates:
   *  Constant: '<S2>/bloodflow_threshold'
   */
  autoquet_simulink_expo_model_B.TmpLatchAtBloodflowthresholdOut =
    autoquet_simulink_expo_model_P.bloodflow_threshold_Value;

  /* SignalConversion generated from: '<S4>/Motor PWM' */
  autoquet_simulink_expo_model_B.TmpLatchAtMotorPWMOutport1 =
    autoquet_simulink_expo_model_B.CCCodeBlock_o1;

  /* SignalConversion generated from: '<S4>/Solenoid state' */
  autoquet_simulink_expo_model_B.TmpLatchAtSolenoidstateOutport1 =
    autoquet_simulink_expo_model_B.CCCodeBlock_o3;

  /* SignalConversion generated from: '<S4>/initial_search' */
  autoquet_simulink_expo_model_B.TmpLatchAtinitial_searchOutport =
    autoquet_simulink_expo_model_B.CCCodeBlock5_o2;

  /* SignalConversion generated from: '<S4>/ideal_pressure_found' */
  autoquet_simulink_expo_model_B.ideal_pressure_found =
    autoquet_simulink_expo_model_B.ideal_pressure_found_c;

  /* SignalConversion generated from: '<S4>/Increase signal' */
  autoquet_simulink_expo_model_B.TmpLatchAtIncreasesignalOutport =
    autoquet_simulink_expo_model_B.Increasesignalinput;

  /* SignalConversion generated from: '<S4>/Decrease signal' */
  autoquet_simulink_expo_model_B.TmpLatchAtDecreasesignalOutport =
    autoquet_simulink_expo_model_B.Decreasesignalinput;

  /* SignalConversion generated from: '<S4>/automode signal' */
  autoquet_simulink_expo_model_B.TmpLatchAtautomodesignalOutport =
    autoquet_simulink_expo_model_B.Automodesignalinput;

  /* SignalConversion generated from: '<S4>/Operation mode' */
  autoquet_simulink_expo_model_B.TmpLatchAtOperationmodeOutport1 =
    autoquet_simulink_expo_model_B.CCCodeBlock5_o3;

  /* SignalConversion generated from: '<S4>/Time' incorporates:
   *  S-Function (time_keeper): '<Root>/C//C++ Code Block'
   */
  rtb_TmpLatchAtTimeOutport1[0] =
    autoquet_simulink_expo_model_B.CCCodeBlock_o1_k[0];
  rtb_TmpLatchAtTimeOutport1[1] =
    autoquet_simulink_expo_model_B.CCCodeBlock_o1_k[1];
  rtb_TmpLatchAtTimeOutport1[2] =
    autoquet_simulink_expo_model_B.CCCodeBlock_o1_k[2];
  rtb_TmpLatchAtTimeOutport1[3] =
    autoquet_simulink_expo_model_B.CCCodeBlock_o1_k[3];

  /* S-Function (any2byte_svd): '<S4>/Byte Pack1' */

  /* Pack: <S4>/Byte Pack1 */
  {
    uint32_T MW_outputPortOffset = 0;
    uint32_T MW_inputPortWidth = 0;
    uint32_T MW_remainder1 = 0;

    /* Packed output data type - uint8_T */
    /* Packing the values of Input 1 */
    /* Input data type - real32_T, size - 1 */
    {
      MW_inputPortWidth = 1 * sizeof(real32_T);
      memcpy((uint8_T*)((uint8_T*)&autoquet_simulink_expo_model_B.BytePack1[0] +
                        MW_outputPortOffset), (uint8_T*)
             &autoquet_simulink_expo_model_B.TmpLatchAtMeasuredLimbPressureO,
             MW_inputPortWidth);
    }
  }

  /* S-Function (any2byte_svd): '<S4>/Byte Pack' */

  /* Pack: <S4>/Byte Pack */
  {
    uint32_T MW_outputPortOffset = 0;
    uint32_T MW_inputPortWidth = 0;
    uint32_T MW_remainder1 = 0;

    /* Packed output data type - uint8_T */
    /* Packing the values of Input 1 */
    /* Input data type - real32_T, size - 1 */
    {
      MW_inputPortWidth = 1 * sizeof(real32_T);
      memcpy((uint8_T*)((uint8_T*)&autoquet_simulink_expo_model_B.BytePack[0] +
                        MW_outputPortOffset), (uint8_T*)
             &autoquet_simulink_expo_model_B.TmpLatchAtPressuresetpointOutpo,
             MW_inputPortWidth);
    }
  }

  /* S-Function (any2byte_svd): '<S4>/Byte Pack2' */

  /* Pack: <S4>/Byte Pack2 */
  {
    uint32_T MW_outputPortOffset = 0;
    uint32_T MW_inputPortWidth = 0;
    uint32_T MW_remainder1 = 0;

    /* Packed output data type - uint8_T */
    /* Packing the values of Input 1 */
    /* Input data type - real32_T, size - 1 */
    {
      MW_inputPortWidth = 1 * sizeof(real32_T);
      memcpy((uint8_T*)((uint8_T*)&autoquet_simulink_expo_model_B.BytePack2[0] +
                        MW_outputPortOffset), (uint8_T*)
             &autoquet_simulink_expo_model_B.TmpLatchAtBNO_XOutport1,
             MW_inputPortWidth);
    }
  }

  /* S-Function (any2byte_svd): '<S4>/Byte Pack3' */

  /* Pack: <S4>/Byte Pack3 */
  {
    uint32_T MW_outputPortOffset = 0;
    uint32_T MW_inputPortWidth = 0;
    uint32_T MW_remainder1 = 0;

    /* Packed output data type - uint8_T */
    /* Packing the values of Input 1 */
    /* Input data type - real32_T, size - 1 */
    {
      MW_inputPortWidth = 1 * sizeof(real32_T);
      memcpy((uint8_T*)((uint8_T*)&autoquet_simulink_expo_model_B.BytePack3[0] +
                        MW_outputPortOffset), (uint8_T*)
             &autoquet_simulink_expo_model_B.TmpLatchAtBNO_YOutport1,
             MW_inputPortWidth);
    }
  }

  /* S-Function (any2byte_svd): '<S4>/Byte Pack4' */

  /* Pack: <S4>/Byte Pack4 */
  {
    uint32_T MW_outputPortOffset = 0;
    uint32_T MW_inputPortWidth = 0;
    uint32_T MW_remainder1 = 0;

    /* Packed output data type - uint8_T */
    /* Packing the values of Input 1 */
    /* Input data type - real32_T, size - 1 */
    {
      MW_inputPortWidth = 1 * sizeof(real32_T);
      memcpy((uint8_T*)((uint8_T*)&autoquet_simulink_expo_model_B.BytePack4[0] +
                        MW_outputPortOffset), (uint8_T*)
             &autoquet_simulink_expo_model_B.TmpLatchAtBNO_ZOutport1,
             MW_inputPortWidth);
    }
  }

  /* S-Function (any2byte_svd): '<S4>/Byte Pack5' */

  /* Pack: <S4>/Byte Pack5 */
  {
    uint32_T MW_outputPortOffset = 0;
    uint32_T MW_inputPortWidth = 0;
    uint32_T MW_remainder1 = 0;

    /* Packed output data type - uint8_T */
    /* Packing the values of Input 1 */
    /* Input data type - real32_T, size - 1 */
    {
      MW_inputPortWidth = 1 * sizeof(real32_T);
      memcpy((uint8_T*)((uint8_T*)&autoquet_simulink_expo_model_B.BytePack5[0] +
                        MW_outputPortOffset), (uint8_T*)
             &autoquet_simulink_expo_model_B.TmpLatchAtFilteredpressurereadi,
             MW_inputPortWidth);
    }
  }

  /* S-Function (any2byte_svd): '<S4>/Byte Pack6' */

  /* Pack: <S4>/Byte Pack6 */
  {
    uint32_T MW_outputPortOffset = 0;
    uint32_T MW_inputPortWidth = 0;
    uint32_T MW_remainder1 = 0;

    /* Packed output data type - uint8_T */
    /* Packing the values of Input 1 */
    /* Input data type - boolean_T, size - 1 */
    {
      MW_inputPortWidth = 1 * sizeof(boolean_T);
      memcpy((uint8_T*)((uint8_T*)&autoquet_simulink_expo_model_B.BytePack6 +
                        MW_outputPortOffset), (uint8_T*)
             &autoquet_simulink_expo_model_B.TmpLatchAtmotor_activeOutport1,
             MW_inputPortWidth);
    }
  }

  /* S-Function (any2byte_svd): '<S4>/Byte Pack7' */

  /* Pack: <S4>/Byte Pack7 */
  {
    uint32_T MW_outputPortOffset = 0;
    uint32_T MW_inputPortWidth = 0;
    uint32_T MW_remainder1 = 0;

    /* Packed output data type - uint8_T */
    /* Packing the values of Input 1 */
    /* Input data type - boolean_T, size - 1 */
    {
      MW_inputPortWidth = 1 * sizeof(boolean_T);
      memcpy((uint8_T*)((uint8_T*)&autoquet_simulink_expo_model_B.BytePack7 +
                        MW_outputPortOffset), (uint8_T*)
             &autoquet_simulink_expo_model_B.TmpLatchAtAccelerometeractiveOu,
             MW_inputPortWidth);
    }
  }

  /* S-Function (any2byte_svd): '<S4>/Byte Pack8' */

  /* Pack: <S4>/Byte Pack8 */
  {
    uint32_T MW_outputPortOffset = 0;
    uint32_T MW_inputPortWidth = 0;
    uint32_T MW_remainder1 = 0;

    /* Packed output data type - uint8_T */
    /* Packing the values of Input 1 */
    /* Input data type - boolean_T, size - 1 */
    {
      MW_inputPortWidth = 1 * sizeof(boolean_T);
      memcpy((uint8_T*)((uint8_T*)&autoquet_simulink_expo_model_B.BytePack8 +
                        MW_outputPortOffset), (uint8_T*)
             &autoquet_simulink_expo_model_B.TmpLatchAtpause_summationOutpor,
             MW_inputPortWidth);
    }
  }

  /* S-Function (any2byte_svd): '<S4>/Byte Pack9' */

  /* Pack: <S4>/Byte Pack9 */
  {
    uint32_T MW_outputPortOffset = 0;
    uint32_T MW_inputPortWidth = 0;
    uint32_T MW_remainder1 = 0;

    /* Packed output data type - uint8_T */
    /* Packing the values of Input 1 */
    /* Input data type - uint16_T, size - 1 */
    {
      MW_inputPortWidth = 1 * sizeof(uint16_T);
      memcpy((uint8_T*)((uint8_T*)&autoquet_simulink_expo_model_B.BytePack9[0] +
                        MW_outputPortOffset), (uint8_T*)
             &autoquet_simulink_expo_model_B.TmpLatchAtBloodflowsummationOut,
             MW_inputPortWidth);
    }
  }

  /* S-Function (any2byte_svd): '<S4>/Byte Pack10' */

  /* Pack: <S4>/Byte Pack10 */
  {
    uint32_T MW_outputPortOffset = 0;
    uint32_T MW_inputPortWidth = 0;
    uint32_T MW_remainder1 = 0;

    /* Packed output data type - uint8_T */
    /* Packing the values of Input 1 */
    /* Input data type - boolean_T, size - 1 */
    {
      MW_inputPortWidth = 1 * sizeof(boolean_T);
      memcpy((uint8_T*)((uint8_T*)&autoquet_simulink_expo_model_B.BytePack10 +
                        MW_outputPortOffset), (uint8_T*)
             &autoquet_simulink_expo_model_B.TmpLatchAtBloodflowbooleanOutpo,
             MW_inputPortWidth);
    }
  }

  /* S-Function (any2byte_svd): '<S4>/Byte Pack11' */

  /* Pack: <S4>/Byte Pack11 */
  {
    uint32_T MW_outputPortOffset = 0;
    uint32_T MW_inputPortWidth = 0;
    uint32_T MW_remainder1 = 0;

    /* Packed output data type - uint8_T */
    /* Packing the values of Input 1 */
    /* Input data type - uint16_T, size - 1 */
    {
      MW_inputPortWidth = 1 * sizeof(uint16_T);
      memcpy((uint8_T*)((uint8_T*)&autoquet_simulink_expo_model_B.BytePack11[0]
                        + MW_outputPortOffset), (uint8_T*)
             &autoquet_simulink_expo_model_B.TmpLatchAtBloodflowthresholdOut,
             MW_inputPortWidth);
    }
  }

  /* S-Function (any2byte_svd): '<S4>/Byte Pack12' */

  /* Pack: <S4>/Byte Pack12 */
  {
    uint32_T MW_outputPortOffset = 0;
    uint32_T MW_inputPortWidth = 0;
    uint32_T MW_remainder1 = 0;

    /* Packed output data type - uint8_T */
    /* Packing the values of Input 1 */
    /* Input data type - real32_T, size - 1 */
    {
      MW_inputPortWidth = 1 * sizeof(real32_T);
      memcpy((uint8_T*)((uint8_T*)&autoquet_simulink_expo_model_B.BytePack12[0]
                        + MW_outputPortOffset), (uint8_T*)
             &autoquet_simulink_expo_model_B.TmpLatchAtMotorPWMOutport1,
             MW_inputPortWidth);
    }
  }

  /* S-Function (any2byte_svd): '<S4>/Byte Pack13' */

  /* Pack: <S4>/Byte Pack13 */
  {
    uint32_T MW_outputPortOffset = 0;
    uint32_T MW_inputPortWidth = 0;
    uint32_T MW_remainder1 = 0;

    /* Packed output data type - uint8_T */
    /* Packing the values of Input 1 */
    /* Input data type - boolean_T, size - 1 */
    {
      MW_inputPortWidth = 1 * sizeof(boolean_T);
      memcpy((uint8_T*)((uint8_T*)&autoquet_simulink_expo_model_B.BytePack13 +
                        MW_outputPortOffset), (uint8_T*)
             &autoquet_simulink_expo_model_B.TmpLatchAtSolenoidstateOutport1,
             MW_inputPortWidth);
    }
  }

  /* S-Function (any2byte_svd): '<S4>/Byte Pack14' */

  /* Pack: <S4>/Byte Pack14 */
  {
    uint32_T MW_outputPortOffset = 0;
    uint32_T MW_inputPortWidth = 0;
    uint32_T MW_remainder1 = 0;

    /* Packed output data type - uint8_T */
    /* Packing the values of Input 1 */
    /* Input data type - uint8_T, size - 1 */
    {
      MW_inputPortWidth = 1 * sizeof(uint8_T);
      memcpy((uint8_T*)((uint8_T*)&autoquet_simulink_expo_model_B.BytePack14 +
                        MW_outputPortOffset), (uint8_T*)
             &autoquet_simulink_expo_model_B.TmpLatchAtinitial_searchOutport,
             MW_inputPortWidth);
    }
  }

  /* S-Function (any2byte_svd): '<S4>/Byte Pack15' */

  /* Pack: <S4>/Byte Pack15 */
  {
    uint32_T MW_outputPortOffset = 0;
    uint32_T MW_inputPortWidth = 0;
    uint32_T MW_remainder1 = 0;

    /* Packed output data type - uint8_T */
    /* Packing the values of Input 1 */
    /* Input data type - boolean_T, size - 1 */
    {
      MW_inputPortWidth = 1 * sizeof(boolean_T);
      memcpy((uint8_T*)((uint8_T*)&autoquet_simulink_expo_model_B.BytePack15 +
                        MW_outputPortOffset), (uint8_T*)
             &autoquet_simulink_expo_model_B.ideal_pressure_found,
             MW_inputPortWidth);
    }
  }

  /* S-Function (any2byte_svd): '<S4>/Byte Pack16' */

  /* Pack: <S4>/Byte Pack16 */
  {
    uint32_T MW_outputPortOffset = 0;
    uint32_T MW_inputPortWidth = 0;
    uint32_T MW_remainder1 = 0;

    /* Packed output data type - uint8_T */
    /* Packing the values of Input 1 */
    /* Input data type - boolean_T, size - 1 */
    {
      MW_inputPortWidth = 1 * sizeof(boolean_T);
      memcpy((uint8_T*)((uint8_T*)&autoquet_simulink_expo_model_B.BytePack16 +
                        MW_outputPortOffset), (uint8_T*)
             &autoquet_simulink_expo_model_B.TmpLatchAtIncreasesignalOutport,
             MW_inputPortWidth);
    }
  }

  /* S-Function (any2byte_svd): '<S4>/Byte Pack17' */

  /* Pack: <S4>/Byte Pack17 */
  {
    uint32_T MW_outputPortOffset = 0;
    uint32_T MW_inputPortWidth = 0;
    uint32_T MW_remainder1 = 0;

    /* Packed output data type - uint8_T */
    /* Packing the values of Input 1 */
    /* Input data type - boolean_T, size - 1 */
    {
      MW_inputPortWidth = 1 * sizeof(boolean_T);
      memcpy((uint8_T*)((uint8_T*)&autoquet_simulink_expo_model_B.BytePack17 +
                        MW_outputPortOffset), (uint8_T*)
             &autoquet_simulink_expo_model_B.TmpLatchAtDecreasesignalOutport,
             MW_inputPortWidth);
    }
  }

  /* S-Function (any2byte_svd): '<S4>/Byte Pack18' */

  /* Pack: <S4>/Byte Pack18 */
  {
    uint32_T MW_outputPortOffset = 0;
    uint32_T MW_inputPortWidth = 0;
    uint32_T MW_remainder1 = 0;

    /* Packed output data type - uint8_T */
    /* Packing the values of Input 1 */
    /* Input data type - boolean_T, size - 1 */
    {
      MW_inputPortWidth = 1 * sizeof(boolean_T);
      memcpy((uint8_T*)((uint8_T*)&autoquet_simulink_expo_model_B.BytePack18 +
                        MW_outputPortOffset), (uint8_T*)
             &autoquet_simulink_expo_model_B.TmpLatchAtautomodesignalOutport,
             MW_inputPortWidth);
    }
  }

  /* S-Function (any2byte_svd): '<S4>/Byte Pack19' */

  /* Pack: <S4>/Byte Pack19 */
  {
    uint32_T MW_outputPortOffset = 0;
    uint32_T MW_inputPortWidth = 0;
    uint32_T MW_remainder1 = 0;

    /* Packed output data type - uint8_T */
    /* Packing the values of Input 1 */
    /* Input data type - uint8_T, size - 1 */
    {
      MW_inputPortWidth = 1 * sizeof(uint8_T);
      memcpy((uint8_T*)((uint8_T*)&autoquet_simulink_expo_model_B.BytePack19 +
                        MW_outputPortOffset), (uint8_T*)
             &autoquet_simulink_expo_model_B.TmpLatchAtOperationmodeOutport1,
             MW_inputPortWidth);
    }
  }

  /* MATLABSystem: '<S4>/Serial Transmit' incorporates:
   *  SignalConversion generated from: '<S4>/Serial Transmit'
   */
  if (autoquet_simulink_expo_model_DW.obj.Protocol !=
      autoquet_simulink_expo_model_P.SerialTransmit_Protocol) {
    autoquet_simulink_expo_model_DW.obj.Protocol =
      autoquet_simulink_expo_model_P.SerialTransmit_Protocol;
  }

  dataIn[0] = autoquet_simulink_expo_model_B.BytePack1[0];
  dataIn[1] = autoquet_simulink_expo_model_B.BytePack1[1];
  dataIn[2] = autoquet_simulink_expo_model_B.BytePack1[2];
  dataIn[3] = autoquet_simulink_expo_model_B.BytePack1[3];
  dataIn[4] = autoquet_simulink_expo_model_B.BytePack[0];
  dataIn[5] = autoquet_simulink_expo_model_B.BytePack[1];
  dataIn[6] = autoquet_simulink_expo_model_B.BytePack[2];
  dataIn[7] = autoquet_simulink_expo_model_B.BytePack[3];
  dataIn[8] = autoquet_simulink_expo_model_B.BytePack2[0];
  dataIn[9] = autoquet_simulink_expo_model_B.BytePack2[1];
  dataIn[10] = autoquet_simulink_expo_model_B.BytePack2[2];
  dataIn[11] = autoquet_simulink_expo_model_B.BytePack2[3];
  dataIn[12] = autoquet_simulink_expo_model_B.BytePack3[0];
  dataIn[13] = autoquet_simulink_expo_model_B.BytePack3[1];
  dataIn[14] = autoquet_simulink_expo_model_B.BytePack3[2];
  dataIn[15] = autoquet_simulink_expo_model_B.BytePack3[3];
  dataIn[16] = autoquet_simulink_expo_model_B.BytePack4[0];
  dataIn[17] = autoquet_simulink_expo_model_B.BytePack4[1];
  dataIn[18] = autoquet_simulink_expo_model_B.BytePack4[2];
  dataIn[19] = autoquet_simulink_expo_model_B.BytePack4[3];
  dataIn[20] = autoquet_simulink_expo_model_B.BytePack5[0];
  dataIn[21] = autoquet_simulink_expo_model_B.BytePack5[1];
  dataIn[22] = autoquet_simulink_expo_model_B.BytePack5[2];
  dataIn[23] = autoquet_simulink_expo_model_B.BytePack5[3];
  dataIn[24] = autoquet_simulink_expo_model_B.BytePack6;
  dataIn[25] = autoquet_simulink_expo_model_B.BytePack7;
  dataIn[26] = autoquet_simulink_expo_model_B.BytePack8;
  dataIn[27] = autoquet_simulink_expo_model_B.BytePack9[0];
  dataIn[28] = autoquet_simulink_expo_model_B.BytePack9[1];
  dataIn[29] = autoquet_simulink_expo_model_B.BytePack10;
  dataIn[30] = autoquet_simulink_expo_model_B.BytePack11[0];
  dataIn[31] = autoquet_simulink_expo_model_B.BytePack11[1];
  dataIn[32] = autoquet_simulink_expo_model_B.BytePack12[0];
  dataIn[33] = autoquet_simulink_expo_model_B.BytePack12[1];
  dataIn[34] = autoquet_simulink_expo_model_B.BytePack12[2];
  dataIn[35] = autoquet_simulink_expo_model_B.BytePack12[3];
  dataIn[36] = autoquet_simulink_expo_model_B.BytePack13;
  dataIn[37] = autoquet_simulink_expo_model_B.BytePack14;
  dataIn[38] = autoquet_simulink_expo_model_B.BytePack15;
  dataIn[39] = autoquet_simulink_expo_model_B.BytePack16;
  dataIn[40] = autoquet_simulink_expo_model_B.BytePack17;
  dataIn[41] = autoquet_simulink_expo_model_B.BytePack18;
  dataIn[42] = autoquet_simulink_expo_model_B.BytePack19;
  dataIn[43] = rtb_TmpLatchAtTimeOutport1[0];
  dataIn[44] = rtb_TmpLatchAtTimeOutport1[1];
  dataIn[45] = rtb_TmpLatchAtTimeOutport1[2];
  dataIn[46] = rtb_TmpLatchAtTimeOutport1[3];
  MW_Serial_write(autoquet_simulink_expo_model_DW.obj.port, &dataIn[0], 47.0,
                  autoquet_simulink_expo_model_DW.obj.dataSizeInBytes,
                  autoquet_simulink_expo_model_DW.obj.sendModeEnum,
                  autoquet_simulink_expo_model_DW.obj.dataType,
                  autoquet_simulink_expo_model_DW.obj.sendFormatEnum, 2.0,
                  '\x00');

  /* End of MATLABSystem: '<S4>/Serial Transmit' */
}

/* Termination for Simulink Function: '<Root>/Function-Call Subsystem' */
void send_params_Term(void)
{
  /* Terminate for MATLABSystem: '<S4>/Serial Transmit' */
  if (!autoquet_simulink_expo_model_DW.obj.matlabCodegenIsDeleted) {
    autoquet_simulink_expo_model_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S4>/Serial Transmit' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
