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
        ft_printf("%s verbose", outbuf);
    } else {
        ft_printf("%s", outbuf);
    }
    return (0);
}

int
e_start(t_elem * node, t_opts * opts)
{
    char send_buf[512];
    char * address = (char*)node->content;
    char outbuf[4096 * 4096];

    struct sockaddr_in servaddr;

    ft_bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(2130706433);
    servaddr.sin_port = htons(80);

    (void)address;
    (void)send_buf;


    e_output(outbuf, opts->verbose);
    return (0);
}
