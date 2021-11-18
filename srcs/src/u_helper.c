/*****************************************************************************/
/*                       FT_PING helper functions                            */
/*****************************************************************************/
#include "u_helper.h"

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

long
u_timest(void)
{
    struct timeval tv;
    long ct;

    gettimeofday(&tv, NULL);
    ct = ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
    return (ct);
}

long
u_cmptime(long time)
{
    return (time < u_timest());
}


int
e_help( void )
{
    ft_printf("Usage\n./ft_ping [options] <destination>\n\nOptions:\n");
    ft_printf(" -v\tverbose output\n");
    return (0);
}

int
u_printpack(t_pack *pack, t_time * timer, char * ipstr)
{
    ft_dprintf(1, "%ld received from %s icmp_seq=%d time=%ld\n", sizeof(*pack), ipstr, pack->hdr.un.echo.sequence, timer->lapse);
    return (0);
}
