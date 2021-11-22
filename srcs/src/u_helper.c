/*****************************************************************************/
/*                       FT_PING helper functions                            */
/*****************************************************************************/
#include "u_helper.h"

#include <stdio.h>

void
handle_sigint(int dummy)
{
    (void)dummy;
    u_setrunning(1, NULL);
}

void
u_setrunning(uint8_t mode, uint8_t * running)
{
    static uint8_t * r;

    if (mode == 0) {
        r = running;
    } else {
        *r = 0;
    }
}

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


int
u_help( void )
{
    ft_printf("Usage\n./ft_ping [options] <destination>\n\nOptions:\n");
    ft_printf(" -v\tverbose output\n");
    return (0);
}

int
u_printpack(t_reply *pack, t_time * timer, char * ipstr, uint64_t seq, uint8_t ta)
{
    if (ta) {
        dprintf(1, "%ld bytes from %s: icmp_seq=%ld ttl=%d time=%.1f\n", sizeof(t_pack), ipstr, seq, pack->ip.ttl, timer->lapse);
    } else {
        dprintf(1, "%ld bytes from %s: icmp_seq=%ld ttl=%d time=%.1f\n", sizeof(t_pack), ipstr, seq, pack->ip.ttl, timer->lapse);
    }
    return (0);
}
