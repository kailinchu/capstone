
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
#define y_width 4
#define y_1_width 1

/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
/* extern double func(double a); */
uint8_T my_milliseconds;
uint8_T my_centiseconds;
uint8_T my_deciseconds;
uint8_T my_seconds;
uint8_T my_minutes;
uint8_T my_hours;

uint32_T ticks_internal;
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Start function
 *
 */
void clock_counter_Start_wrapper(void)
{
/* %%%-SFUNWIZ_wrapper_Start_Changes_BEGIN --- EDIT HERE TO _END */
/*
 * Custom Start code goes here.
 */
    my_milliseconds = 0;
    my_centiseconds = 0;
    my_deciseconds = 0;
    my_seconds = 0;
    my_minutes = 0;
    my_hours = 0;
    ticks_internal = 0;
/* %%%-SFUNWIZ_wrapper_Start_Changes_END --- EDIT HERE TO _BEGIN */
}
/*
 * Output function
 *
 */
void clock_counter_Outputs_wrapper(const real_T *u0,
			uint8_T *my_time,
			uint32_T *ticks)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
/* This sample sets the output equal to the input
      y0[0] = u0[0]; 
 For complex signals use: y0[0].re = u0[0].re; 
      y0[0].im = u0[0].im;
      y1[0].re = u1[0].re;
      y1[0].im = u1[0].im;
 */
    // time[0] = 0;
    // time[1] = seconds;
    // time[2] = 0;
    // time[3] = 0;
    
    ticks_internal++;
    my_milliseconds++;
    my_time[0] = my_milliseconds;
    ticks[0] = ticks_internal;

    if (my_milliseconds >= 10)
    {
        my_centiseconds++;
        my_milliseconds = 0;
        my_time[0] = my_milliseconds;

        if (my_centiseconds >= 10)
        {
            my_deciseconds++;
            my_centiseconds = 0;

            if (my_deciseconds >= 10)
            {
                my_seconds++;
                my_deciseconds = 0;
                my_time[1] = my_seconds;

                if (my_seconds >= 60)
                {
                    my_minutes++;
                    my_seconds = 0;

                    my_time[1] = my_seconds;
                    my_time[2] = my_minutes;

                    // Add back a second every 7 minutes to compensate for drift
                    if (my_minutes % 7 == 0)
                    {
                        my_seconds ++;
                    }

                    if (my_minutes >= 60)
                    {
                        my_hours++;
                        my_minutes = 0;

                        my_time[2] = my_minutes;
                        my_time[3] = my_hours;
                    }
                }  
            }  
        }
    }
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}


