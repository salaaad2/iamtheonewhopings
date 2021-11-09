/*****************************************************************************/
/*                       FT_PING whole program's logic                       */
/*****************************************************************************/


#include "e_ping.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <netinet/in_systm.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>

int
e_help( void )
{
    ft_printf("Usage\n./ft_ping [options] <destination>\n\nOptions:\n");
    ft_printf(" -v\tverbose output\n");
    return (0);
}

int
e_output(char * outbuf, unsigned char verbose)
{
    if (verbose) {
        ft_printf("%s verbose", outbuf)
    } else {
        ft_printf("%s", outbuf);
    }

}

int
e_start(t_elem * node, t_opts * opts)
{
    char * address = (char*)node->content;
    char outbuf[4096 * 4096];


    e_output(outbuf, opts->verbose);
}
