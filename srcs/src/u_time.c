#include "u_time.h"

double
u_timest(void)
{
    struct timeval tv;
    double secs;

    gettimeofday(&tv, NULL);
    secs = (double)(tv.tv_usec) / 1000;
    return (secs);
}

double
u_cmptime(double time)
{
    return (time < u_timest());
}

double
u_avgtime(double time)
{
   static uint32_t count;
   static long double total;

   count += 1;
   total += time;
   return (total/time);
}

int
u_updatetime(double val, t_time * timer)
{
    timer->ntv = val;
    timer->lapse = (timer->ntv - timer->itv);
    timer->avg = u_avgtime(timer->lapse);
    return (0);
}
