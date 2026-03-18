
/*
 * Include Files
 *
 */
#if defined(MATLAB_MEX_FILE)
#include "tmwtypes.h"
#include "simstruc_types.h"
#else
#define SIMPLIFIED_RTWTYPES_COMPATIBILITY
#include "rtwtypes.h"
#undef SIMPLIFIED_RTWTYPES_COMPATIBILITY
#endif



/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */
#include <math.h>
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width 2
#define y_width 1

/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */

// Pressure sensor
float output_max = 14745;
float output_min = 1638;
uint16_T sensor_output;
float pressure_max = 15;
float pressure_reading;
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output function
 *
 */
void process_raw_sensor_reading_Outputs_wrapper(const uint8_T *raw_sensor_input,
			real32_T *limb_pressure_mmhg)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
    // Convert pressure sensor reading to units of mmhg
    sensor_output = ((uint16_T)raw_sensor_input[0] << 8) | ((uint16_T)raw_sensor_input[1]);
    pressure_reading = (float)sensor_output - output_min;
    pressure_reading = pressure_reading * 2*pressure_max;
    pressure_reading = pressure_reading / (output_max - output_min);
    pressure_reading -= pressure_max; // Pressure in PSI
    pressure_reading *= 51.7149; // Pressure in mmhg
    limb_pressure_mmhg[0] = pressure_reading;
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}


