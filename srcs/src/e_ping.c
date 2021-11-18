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
#include "u_helper.h"

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
e_ping(int sock, struct sockaddr_in * addr, t_pack * pack, t_time * timer)
{
    socklen_t addrsize = sizeof(const struct sockaddr);

    if (sendto(sock, pack, PACK_SIZE, 0, (struct sockaddr *)addr, addrsize) < 0)
    {
        u_printerr("call to sendto() failed", "sendto()");
    }
    timer->itv = u_timest();
    if (recvfrom(sock, pack, PACK_SIZE, 0, (struct sockaddr *)addr, &addrsize) < 0)
    {
        u_printerr("call to recvfrom() failed", "sendto()");
    }
    timer->ntv = u_timest();
    timer->lapse = (timer->ntv - timer->itv);
    return (pack);
}

int
e_start(char *url, t_opts * opts)
{
    struct sockaddr_in * servaddr;
    struct addrinfo * res;
    uint64_t seq;
    uint8_t running;
    t_pack pack;
    int sock;
    struct addrinfo hints = {
        AI_CANONNAME, AF_INET, SOCK_RAW, IPPROTO_ICMP, 0, NULL, NULL, NULL
    };
    char ipstr[4096];
    void * addr;
    t_time timer;

    /*
    ** DNS resolution and address settings happen here
    ** */
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
        if (!ft_strcmp(ipstr, url)) {
            ft_printf("mysterious\n");
        } else {
            ft_printf("cool\n");
            /* return (u_printerr("invalid address", ipstr)); */
        }
    } else {
        return (1);
    }


    /*
    ** socket() and setsockopt()
    ** @ret > 0
    ** */
    if ((sock = e_setsockets()) < 0) {
        return (1);
    }

    /*
    ** set running semiglobal variable
    ** */
    running = 1;
    u_setrunning(0, &running);
    signal(SIGINT, handle_sigint);

    /* loop : seq is incremented on each ping/pong.
     ** time also needs to be managed each time a ping happens
     ** */
    seq = 0;
    while (running == 1) {
        p_initpacket(&pack, seq++);
        e_ping(sock, servaddr, &pack, &timer);
        u_printpack(&pack, &timer, ipstr);
        alarm(1);
    }

    /*
    ** TODO: print stats when exiting
    ** */
    e_output("null", opts->verbose);
    freeaddrinfo(res);
    return (0);
}
