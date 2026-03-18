
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
#define y_width 4
#define y_1_width 1

/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
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
void time_keeper_Start_wrapper(void)
{
/* %%%-SFUNWIZ_wrapper_Start_Changes_BEGIN --- EDIT HERE TO _END */
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
void time_keeper_Outputs_wrapper(uint8_T *my_time,
			uint32_T *ticks)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
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

                    // Add back a second at the 15, 30 and 45 minute marks to compensate for drift
                    if (my_minutes == 15 || my_minutes == 30 || my_minutes == 45)
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


