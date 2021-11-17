/*****************************************************************************/
/*                       FT_PING whole program's logic                       */
/*****************************************************************************/

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
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
e_setsockets(void)
{
    const int hdr = 1;
    int sockfd;

    if ((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0)
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

t_pack *
e_ping(int sock, struct sockaddr_in * addr, t_pack * pack)
{
    socklen_t addrsize = sizeof(const struct sockaddr);

    if (sendto(sock, pack, PACK_SIZE, 0, (struct sockaddr *)addr, addrsize) < 0)
    {
        u_printerr("call to sendto() failed", "sendto()");
    }
    if (recvfrom(sock, pack, PACK_SIZE, 0, (struct sockaddr *)addr, &addrsize) < 0)
    {
        u_printerr("call to recvfrom() failed", "sendto()");
    }
    return (pack);
}

int
e_start(char *url, t_opts * opts)
{
    struct sockaddr_in * servaddr;
    struct addrinfo * res;
    t_pack pack;
    char ipstr2[4096];
    char ipstr[4096];
    void * addr;
    int sock;
    struct addrinfo hints = {
        AI_CANONNAME, AF_INET, SOCK_RAW, IPPROTO_ICMP, 0, NULL, NULL, NULL
    };


    if ((getaddrinfo(url, NULL, &hints, &res)) < 0)
    {
        return (u_printerr("lookup failed", url));
    }

    if (res != NULL)
    {
        servaddr = (struct sockaddr_in *)res->ai_addr;
        addr = &(servaddr->sin_addr);
        inet_ntop(res->ai_family, addr, ipstr, sizeof(ipstr));
        ft_printf("ip4: %s\n", ipstr);
        if (inet_pton(res->ai_family, ipstr, ipstr2) == 1) {
            ft_printf("mysterious\n");
        } else {
            return (u_printerr("invalid address", ipstr));
        }
    } else {
        return (1);
    }

    sock = e_setsockets();
    p_initpacket(&pack);
    e_ping(sock, servaddr, &pack);

    freeaddrinfo(res);
    e_output("null", opts->verbose);
    return (0);
}
