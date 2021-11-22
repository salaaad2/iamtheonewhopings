/*********************************/
/*   FT_PING          (  //      */
/*   timers            ( )/      */
/*   by salade         )(/       */
/*  ________________  ( /)       */
/* ()__)____________)))))   :^}  */
/*********************************/

#include <stdio.h>

#include "u_time.h"

long double
u_timest(void)
{
    struct timeval tv;
    double secs;

    gettimeofday(&tv, NULL);
    secs = (double)(tv.tv_usec) / 1000;
    return (secs);
}

long double
u_cmptime(long double time)
{
    return (time < u_timest());
}

long
u_longtime(void)
{
    struct timeval	tv;
    long			ct;

    gettimeofday(&tv, NULL);
    ct = ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
    return (ct);
}

long double
u_avgtime(long double time)
{
   static uint32_t count = 0;
   static long double total = 0;

   count += 1;
   total += time;
   return (total/count);
}

int
u_updatetime(long double val, t_time * timer)
{
    timer->ntv = val;
    timer->lapse = (timer->ntv - timer->itv);
    timer->avg = u_avgtime(timer->lapse);
    if (timer->lapse > timer->max) {
        timer->max = timer->lapse;
        if (timer->min == 0.0f) {
            timer->min = timer->max;
        }
    } else if (timer->lapse < timer->min) {
        timer->min = timer->lapse;
    }
    return (0);
}
