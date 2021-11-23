/*********************************/
/*   FT_PING          (  //      */
/*   helpers           ( )/      */
/*   by salade         )(/       */
/*  ________________  ( /)       */
/* ()__)____________)))))   :^}  */
/*********************************/

#include "u_helper.h"

#include <stdio.h>

void
u_handle_sigint(int dummy)
{
    (void)dummy;
    u_setrunning(1, NULL);
}

void
u_handle_sigalrm(int dummy)
{
    (void)dummy;
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

int
u_help( void )
{
    ft_printf("Usage\n./ft_ping [options] <destination>\n\nOptions:\n");
    ft_printf(" -v\tverbose output\n");
    return (0);
}

int
u_printpack(t_ping *ping, uint64_t seq, uint8_t ta)
{
    if (ta) {
        dprintf(1, "%ld bytes from %s (%s): icmp_seq=%ld ttl=%d time=%.1Lf\n", sizeof(t_pack), ping->url, ping->ipstr, seq, ping->reply->ip.ttl, ping->timer->lapse);
    } else {
        dprintf(1, "%ld bytes from %s: icmp_seq=%ld ttl=%d time=%.1Lf\n", sizeof(t_pack), ping->ipstr, seq, ping->reply->ip.ttl, ping->timer->lapse);
    }
    return (0);
}
