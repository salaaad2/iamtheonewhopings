/*****************************************************************************/
/*                       FT_PING whole program's logic                       */
/*****************************************************************************/

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <netinet/in_systm.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <arpa/inet.h>

#include "e_ping.h"
#include "u_err.h"

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
    char outbuf[4096];
    char ipstr[4096];
    char ipstr2[4096];
    struct addrinfo hints, * res, *p;
    struct sockaddr_in * servaddr;
    void * addr;

    ft_bzero(&hints, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    if ((getaddrinfo(address, NULL, &hints, &res)) < 0)
    {
        return (u_printerr("lookup failed", address));
    }

    p = res;
    while (p != NULL)
    {
        servaddr = (struct sockaddr_in *)p->ai_addr;
        addr = &(servaddr->sin_addr);
        ft_printf("as num : \n");
        inet_ntop(p->ai_family, addr, ipstr, sizeof(ipstr));
        ft_printf("ip4: %s\n", ipstr);
        /* pton */
        ft_printf("as string : \n");
        inet_pton(p->ai_family, ipstr, ipstr2);
        ft_printf("ip4: %s\n", ipstr2);
        /* ntop */
        p = p->ai_next;
    }



    (void)servaddr;
    (void)send_buf;


    e_output(outbuf, opts->verbose);
    return (0);
}
