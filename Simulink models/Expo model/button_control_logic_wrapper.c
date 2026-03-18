
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
#define u_2_width 1
#define u_3_width 1
#define y_width 1
#define y_1_width 1
#define y_2_width 1

/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
/* extern double func(double a); */
uint8_T prev_auto_button_state;
uint8_T prev_inc_button_state;
uint8_T prev_dec_button_state;

uint8_T automan_signal;
uint8_T inc_signal;
uint8_T dec_signal;
uint16_T automode_cooldown;
uint16_T inc_cooldown;
uint16_T dec_cooldown;

uint32_T prev_automode_time;
uint32_T prev_inc_time;
uint32_T prev_inc_hold_time;
uint32_T prev_dec_time;
uint32_T prev_dec_hold_time;

uint8_T operation_state;

uint8_T increment;
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Start function
 *
 */
void button_control_logic_Start_wrapper(void)
{
/* %%%-SFUNWIZ_wrapper_Start_Changes_BEGIN --- EDIT HERE TO _END */
/*
 * Custom Start code goes here.
 */
    prev_auto_button_state = 0;
    prev_inc_button_state = 0;
    prev_dec_button_state = 0;

    prev_automode_time = 0;

    prev_inc_time = 0;
    prev_inc_hold_time = 0;

    prev_dec_time = 0;
    prev_dec_hold_time = 0;
    
    automode_cooldown = 0;
    inc_cooldown = 0;
    dec_cooldown = 0;

    operation_state = 0;
    
    increment = 1;
/* %%%-SFUNWIZ_wrapper_Start_Changes_END --- EDIT HERE TO _BEGIN */
}
/*
 * Output function
 *
 */
void button_control_logic_Outputs_wrapper(const boolean_T *button_signals,
			const uint32_T *time,
			const real32_T *auto_pressure_setpoint,
			const uint8_T *initial_search,
			real32_T *pressure_set_point,
			uint8_T *roughness,
			uint8_T *operation_mode)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */

    // Reset cooldowns if buttons are depressed
    if (button_signals[0] == 0)
    {
        // Reset automode cooldown
        automode_cooldown = 0;
        prev_auto_button_state = 0;
    }

    if (button_signals[1] == 0)
    {
        // Reset increment cooldown
        inc_cooldown = 0;
        prev_inc_button_state = 0;
    }

    if (button_signals[2] == 0)
    {
        // Reset decrement cooldown
        dec_cooldown = 0;
        prev_dec_button_state = 0;
    }

    // Switch into automatic mode
    if (button_signals[0] == 1 && prev_auto_button_state == 0 && ((prev_automode_time + automode_cooldown) < time[0]))
    {
        automan_signal = 1;
        prev_auto_button_state = 1;
        prev_automode_time = time[0];
        automode_cooldown = 1000;
    }

    // Manually increment signal
    if (button_signals[1] == 1 && ((prev_inc_time + inc_cooldown) < time[0]))
    {
        // Single press
        if (prev_inc_button_state == 0)
        {
            prev_inc_button_state = 1;
            increment = 1;
            prev_inc_hold_time = time[0];
            inc_cooldown = 1000;
        }

        // Hold press stage 2
        else if (prev_inc_button_state == 1 && (time[0] - prev_inc_hold_time > 4*inc_cooldown))
        {
            increment = 50;
            inc_cooldown = 1000;
        }
        
        // Hold press stage 1
        else if(prev_inc_button_state == 1 && (time[0] - prev_inc_hold_time > inc_cooldown)) // Must be whole number multiple of increment cooldown
        {
            increment = 10;
            inc_cooldown = 1000;
        }

        else 
        {
            inc_cooldown = 1000;
        }

        prev_inc_time = time[0];
        inc_signal = 1;
    }

    // Manually decrement signal
    if (button_signals[2] == 1 && (prev_dec_time + dec_cooldown < time[0]))
    {
        // Single press
        if (prev_dec_button_state == 0)
        {
            prev_dec_button_state = 1;
            increment = 1;
            prev_dec_hold_time = time[0];
            dec_cooldown = 1000;
        }

        // Hold stage 2
        else if (prev_dec_button_state == 1 && (time[0] - prev_dec_hold_time > 4*dec_cooldown))
        {
            increment = 50;
            dec_cooldown = 1000;
        }
        
        // Hold stage 1
        else if (prev_dec_button_state == 1 && (time[0] - prev_dec_hold_time > dec_cooldown))
        {
            increment = 10;
            dec_cooldown = 1000;
        }

        else
        {
            dec_cooldown = 1000;
        }

        prev_dec_time = time[0];
        dec_signal = 1;
    }

    // Effectuate auto mode
    if (automan_signal == 1)
    {
        operation_state = 1; // Automatic mode
        automan_signal = 0; // Reset trigger signal
    }

    // Effectuate increment signal
    if (inc_signal == 1)
    {
        operation_state = 0;
        inc_signal = 0;
        *pressure_set_point += increment;
        *roughness = 3; // Manual deadband setting
    }

    // Effectuate decrement signal
    if (dec_signal == 1)
    {
        operation_state = 0;
        dec_signal = 0;
        *roughness = 3; // Manual deadband setting

        // Never let pressure fall below zero
        if (increment < *pressure_set_point)
        {
            *pressure_set_point -= increment;
        }
        else
        {
            *pressure_set_point = 0;
        }
    }

    // Must run consistently to keep pace with stateflow
    if (operation_state == 1)
    {
        *pressure_set_point = *auto_pressure_setpoint;

        // Adjusts deadband
        *roughness = *initial_search;
    }

    operation_mode[0] = operation_state;
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}


