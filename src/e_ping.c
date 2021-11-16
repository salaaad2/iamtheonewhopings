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

#include <string.h>
#include <errno.h>

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

    if ((sockfd = socket(AF_INET, SOCK_DGRAM|SOCK_CLOEXEC|SOCK_NONBLOCK, IPPROTO_IP)) < 0)
    {
        return (u_printerr("failed to create socket", "socket"));
    }
    if ((setsockopt(sockfd, SOL_IP, IP_RECVERR, &hdr, sizeof(hdr))) != 0)
    {
        ft_printf("%s %d\n", strerror(errno), errno);
        sockfd = -1;
        return (u_printerr("failed to set socket options", "setsockopt"));
    }
    return (sockfd);
}

char *
e_ping(int sock, struct sockaddr_in * addr, struct addrinfo *res, char * ipstr)
{
    (void)res;
    (void)ipstr;
    if (sendto(sock, , 64, 0, (const struct sockaddr *)addr, sizeof(const struct sockaddr)) < 0)
    {
        u_printerr("call to sendto() failed", "sendto()");
    }
    return (NULL);
}

int
e_start(t_elem * node, t_opts * opts)
{
    char * lookup = (char*)node->content;
    char outbuf[4096];
    char ipstr[4096];
    char ipstr2[4096];
    struct addrinfo hints, * res;
    struct sockaddr_in * servaddr;
    struct icmphdr icmp_hdr;
    char packdata[sizeof(icmp_hdr) + 5];
    void * addr;
    int sock;

    ft_bzero(&hints, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = 0;

    if ((getaddrinfo(lookup, NULL, &hints, &res)) < 0)
    {
        return (u_printerr("lookup failed", lookup));
    }

    if (res != NULL)
    {
        servaddr = (struct sockaddr_in *)res->ai_addr;
        addr = &(servaddr->sin_addr);
        inet_ntop(res->ai_family, addr, ipstr, sizeof(ipstr));
        ft_printf("ip4: %s\n", ipstr);
        if (inet_pton(res->ai_family, ipstr, ipstr2) == 1) {
            /* ft_printf("ip4: %s\n", ipstr2); */
        } else {
            return (u_printerr("invalid address", ipstr));
        }
    } else {
        return (1);
    }

    sock = e_setsockets();
    p_initpacket(packdata, &icmp_hdr, 1234, 1);
    e_ping(sock, servaddr, res, ipstr);

    freeaddrinfo(res);


    e_output(outbuf, opts->verbose);
    return (0);
}
