
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
#define u_width 3
#define u_1_width 1
#define y_width 1

/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */

# define window_size_accel 5
uint8_T accel_window[window_size_accel];
uint16_T summation = 0;
uint8_T accel_iterator = 0;
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Start function
 *
 */
void limb_movement_detector_Start_wrapper(void)
{
/* %%%-SFUNWIZ_wrapper_Start_Changes_BEGIN --- EDIT HERE TO _END */
/*
 * Custom Start code goes here.
 */
    memset(accel_window, 0.0, sizeof(accel_window));
/* %%%-SFUNWIZ_wrapper_Start_Changes_END --- EDIT HERE TO _BEGIN */
}
/*
 * Output function
 *
 */
void limb_movement_detector_Outputs_wrapper(const real32_T *limb_acceleration,
			const uint16_T *accel_threshold,
			boolean_T *movement_boolean)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */

    if (accel_iterator == window_size_accel)
    {
        accel_iterator = 0;
    }
    
    summation -= accel_window[accel_iterator];
    accel_window[accel_iterator] = (uint8_T)(fabsf(limb_acceleration[0])*40) 
                                 + (uint8_T)(fabsf(limb_acceleration[1])*40) 
                                 + (uint8_T)(fabsf(limb_acceleration[2])*40);
    summation += accel_window[accel_iterator];    

    movement_boolean[0] = (summation > accel_threshold[0]) ? 1:0;
    accel_iterator ++;
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}


