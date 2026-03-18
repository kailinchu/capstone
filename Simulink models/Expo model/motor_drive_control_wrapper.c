
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
#define y_1_width 1
#define y_2_width 1

/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
/* extern double func(double a); */
int8_T accuracy_upper; // Accuracy for inflation (overshoot when pos, undershoot when neg)
int8_T accuracy_lower; // Accuracy for deflation (overshoot when neg, undershoot when pos)
int8_T deadzone_upper; // Deadband for inflation
int8_T deadzone_lower; // Deadband for deflation
uint8_T state = 2; // 0: deflation, 1: steady state, 2: inflation
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output function
 *
 */
void motor_drive_control_Outputs_wrapper(const real32_T *limb_pressure_diff,
			const boolean_T *pause_summation,
			const uint8_T *initial_search,
			real32_T *inflation_state,
			boolean_T *motor_active,
			boolean_T *solenoid_state)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
if (initial_search[0] == 0)
    {
        // Course accuracy bounds for inflation
        accuracy_lower = 10;
        accuracy_upper = 20;
        deadzone_upper = 0; // Must hit or exceed set pressure
        deadzone_lower = 50;
    }

    else if (initial_search[0] == 1)
    {
        // Course accuracy bounds for deflation
        accuracy_lower = -5; // How much to overshoot deflation
        accuracy_upper = 1;
        deadzone_upper = 50;
        deadzone_lower = 0;
        
    }

    else if (initial_search[0] == 2)
    {
        // Binary search - fine accuracy bounds
        accuracy_lower = 3;
        accuracy_upper = 10;
        deadzone_upper = 10;
        deadzone_lower = 10;
    }
    else if (initial_search[0] == 3)
    {
        // Manual deadband
        accuracy_lower = 3;
        accuracy_upper = 10;
        deadzone_upper = 5;
        deadzone_lower = 5;
    }

    // Inflation/deflation/steady-state | state machine
    switch(state)
    {
        case 0: // Deflate
            inflation_state[0] = 0; // Off
            solenoid_state[0] = 1;  // # 2 and # 3 are connected
            motor_active[0] = 1;
            break;
        case 1: // Steady state
            inflation_state[0] = 0; // Off
            solenoid_state[0] = 0;  // # 1 and # 3 are connected
            motor_active[0] = 0;
            break;
        case 2: // Inflate
            inflation_state[0] = 255; // On
            solenoid_state[0] = 0;    // # 1 and # 3 are connected
            motor_active[0] = 1;
            break;
        default:
            inflation_state[0] = 0; // Off
            solenoid_state[0] = 0;  // # 1 and # 3 are connected
            motor_active[0] = 0;
    }

    /** 
      * limb_pressure_difference is negative when above set point
      * limb_pressure_difference is positive when below set point
     */

    // Desired pressure has been reached, stop inflating
    if (state == 2 && (limb_pressure_diff[0] < -accuracy_upper))
    {
        state = 1;
    }

    // Desired pressure has been reached, stop deflating
    else if (state == 0 && (limb_pressure_diff[0] > -accuracy_lower))
    {
        
        state = 1;
    }

    // Limb pressure has fallen out of deadzone - adjust pressure to return to set point
    else if (state == 1 && (limb_pressure_diff[0] < -deadzone_lower || limb_pressure_diff[0] > deadzone_upper) && pause_summation[0] == 0)
    {
        // Deflate
        if (limb_pressure_diff[0] < -deadzone_lower)
        { 
            state = 0;
        }

        // Inflate
        else if (limb_pressure_diff[0] > deadzone_upper)
        {
            state = 2;
        }
    }
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}


