
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
#define u_width 1
#define u_1_width 1
#define u_2_width 1
#define u_3_width 1
#define y_width 1
#define y_1_width 1

/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
/* extern double func(double a); */

/** Window time span = window_size * sample time
 *  Window time span = 15 * 0.1 = 1.5 seconds
 */
#define window_size 15
#define starting_integer 66
// Assume the subject starts off bleeding - maximum sum
uint8_T window[window_size]; // used to be float but got hit with data limit
uint8_T iterator;
uint16_T sum = window_size * starting_integer;
uint8_T automode_switch_flag;
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Start function
 *
 */
void blood_flow_detector_2_Start_wrapper(void)
{
/* %%%-SFUNWIZ_wrapper_Start_Changes_BEGIN --- EDIT HERE TO _END */
/*
 * Custom Start code goes here.
 */
    iterator = 0;
    memset(window, starting_integer, sizeof(window));
    automode_switch_flag = 1;
/* %%%-SFUNWIZ_wrapper_Start_Changes_END --- EDIT HERE TO _BEGIN */
}
/*
 * Output function
 *
 */
void blood_flow_detector_2_Outputs_wrapper(const real32_T *u0,
			const boolean_T *disruption_active,
			const uint16_T *bloodflow_threshold,
			const uint8_T *inflation_state,
			uint16_T *y0,
			boolean_T *bloodflow_boolean)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
// Take windowed moving average of the absolute sinusoid
    // If the sum of the window is above a certain level, blood is still flowing

    // Automode has been enabled - reset the summation window
    

    // Reset automode switch flag
    if (inflation_state[0] == 2 || inflation_state[0] == 3)
    {
        // If in steady state automode or in manual mode
        automode_switch_flag = 1;
    }


    if (automode_switch_flag == 1 && inflation_state[0] == 0)
    {
        memset(window, starting_integer, sizeof(window));
        sum = window_size * starting_integer;
        iterator = 0;
        automode_switch_flag = 0;
    }

    else if (disruption_active[0] == 0)
    {
        if (iterator == window_size) {
            // Restart iterator to beginning of window
            iterator = 0;
        }

        sum -= window[iterator]; // Remove oldest data index
        window[iterator] = (uint8_T)(120*fabsf(u0[0])); // Add new sensor data to window
        sum += window[iterator]; // Add new sensor data to sum

        iterator ++;
    }
    
    y0[0] = sum;
    bloodflow_boolean[0] = (sum >= bloodflow_threshold[0]) ? 1:0;
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}


