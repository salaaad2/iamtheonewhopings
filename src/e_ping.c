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
#include "p_packets.h"
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
e_setsockets()
{
    const int hdr = 1;
    int sockfd;

    if ((sockfd = socket(AF_INET, SOCK_RAW, SOCK_RAW)) < 0)
    {
        return (u_printerr("failed to create socket", "socket"));
    }
    if ((setsockopt(sockfd, IPPROTO_IP, IP_HDRINCL, &hdr, sizeof(hdr))) < 0)
    {
        return (u_printerr("failed to set socket options", "setsockopt"));
    }
    return (sockfd);
}

char *
e_ping(int sock, struct sockaddr_in * addr, struct addrinfo *res, char * ipstr)
{
    (void)sock;
    (void)addr;
    (void)res;
    (void)ipstr;
    return (NULL);
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
    int sock;

    ft_bzero(&hints, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    if ((getaddrinfo(address, NULL, &hints, &res)) < 0)
    {
        return (u_printerr("lookup failed", address));
    }

    p = res;
    if (p != NULL)
    {
        servaddr = (struct sockaddr_in *)p->ai_addr;
        addr = &(servaddr->sin_addr);
        inet_ntop(p->ai_family, addr, ipstr, sizeof(ipstr));
        ft_printf("ip4: %s\n", ipstr);
        if (inet_pton(p->ai_family, ipstr, ipstr2) == 1) {
            ft_printf("ip4: %s\n", ipstr2);
        } else {
            return (u_printerr("invalid address", ipstr));
        }
        sock = e_setsockets();
        p_initpacket(1234, 1);
        ft_memcpy(outbuf, e_ping(sock, servaddr, p, ipstr), sizeof(outbuf));
    }

    (void)send_buf;
    freeaddrinfo(res);


    e_output(outbuf, opts->verbose);
    return (0);
}
