
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
#define y_width 1

/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
/* extern double func(double a); */
float prev_pressure_set_point;
uint32_T time_cooldown;
uint32_T last_update_time;
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Start function
 *
 */
void display_pressures_signal_Start_wrapper(void)
{
/* %%%-SFUNWIZ_wrapper_Start_Changes_BEGIN --- EDIT HERE TO _END */
/*
 * Custom Start code goes here.
 */
    prev_pressure_set_point = 0;
    time_cooldown = 0;
    last_update_time = 0;
/* %%%-SFUNWIZ_wrapper_Start_Changes_END --- EDIT HERE TO _BEGIN */
}
/*
 * Output function
 *
 */
void display_pressures_signal_Outputs_wrapper(const real32_T *pressure_set_point,
			const uint8_T *operation_state,
			const uint32_T *time,
			uint8_T *display_pressure_signal)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
// Control display_pressure_signal output which tells stateflow to display time (when low) or pressure (when high)


    if (prev_pressure_set_point != pressure_set_point[0] && operation_state[0] == 0)
    {
        // In manual mode and pressure has changed
        prev_pressure_set_point = pressure_set_point[0];
        time_cooldown = 5000; // Display pressure for 5 seconds
        last_update_time = time[0];
        display_pressure_signal[0] = 1;
    }

    if ((last_update_time + time_cooldown) < time[0])
    {
        // Reset display signal
        display_pressure_signal[0] = 0;
    }
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}


