/*********************************/
/*   FT_PING          (  //      */
/*   logic             ( )/      */
/*   by salade         )(/       */
/*  ________________  ( /)       */
/* ()__)____________)))))   :^}  */
/*********************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

#include "e_ping.h"
#include "p_packets.h"
#include "u_time.h"
#include "u_err.h"
#include "u_helper.h"

int
e_output(t_ping * ping, uint8_t isstr)
{
    uint32_t ploss;
    char * str = (isstr ? ping->url : ping->ipstr);

    ploss = u_ploss(ping->sent, ping->received);
    ft_printf("\n--- %s ft_ping statistics ---\n", str);

    if (ping->reply) {
        dprintf(1, "%ld packets transmitted, %ld received,  %ld%% packet loss\n",
                ping->sent, ping->received, ploss);
        dprintf(1, "rtt min/avg/max/mdev = %.3Lf/%.3Lf/%.3Lf/%.3Lf ms\n",
                ping->timer->min,ping->timer->avg,ping->timer->max,u_mdev(1, 0.0f));
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

/*
** sendto icmp header set by p_initpacket()
** recvfrom IP and ICMP headers and deserialize them
** t_reply->ip
** t_reply->icmp
 */
t_reply *
e_ping(int sock, struct sockaddr_in * addr, t_ping * ping)
{
    socklen_t addrsize = sizeof(const struct sockaddr);
    char recvbuf[98];
    t_reply * full;
    t_pack * pack = ping->pack;
    t_time * timer = ping->timer;

    ft_bzero(recvbuf, 98);

    if (sendto(sock, pack, PACK_SIZE, 0, (struct sockaddr *)addr, addrsize) < 0) {
        u_printerr("socket error", "sendto()");
        return (NULL);
    }
    ping->sent++;
    timer->itv = u_timest();
    if (recvfrom(sock, recvbuf, PACK_SIZE + IP_SIZE, 0, (struct sockaddr *)addr, &addrsize) < 0) {
        u_printerr("socket error", "recvfrom()");
        return (NULL);
    }
    ping->received++;
    u_updatetime(u_timest(), timer);
    full = p_deserialize(recvbuf);
    return (full);
}

int
e_loop(t_ping * ping, struct sockaddr_in * servaddr, t_opts * opts, int sock)
{
    uint8_t running;
    long reptime;
    uint8_t seq;

    /*
    ** set running semiglobal variable
    ** */
    running = 1;
    u_setrunning(0, &running);
    signal(SIGINT, u_handle_sigint);

    reptime = 0;
    seq = 0;
    while (running == 1) {
        if ((reptime + 1000) > u_longtime())
        {
            continue; /* ping once every second */
        } else {
            p_initpacket(ping->pack, seq++);
            ping->reply = e_ping(sock, servaddr, ping);
            u_printpack(ping, seq, opts->textaddr);
            reptime = u_longtime();
        }
    }
    return (0);
}


int
e_start(char *url, t_opts * opts)
{
    struct sockaddr_in * servaddr;
    struct addrinfo * res;
    t_pack pack;
    int sock;
    struct addrinfo hints = {
        AI_CANONNAME, AF_INET, SOCK_RAW, IPPROTO_ICMP, 0, NULL, NULL, NULL
    };
    char ipstr[4096];
    void * addr;
    t_time timer;
    t_reply * reply;
    t_ping ping;

    reply = NULL;
    /*
    ** DNS resolution and address settings happen here
    ** */
    if ((getaddrinfo(url, NULL, &hints, &res)) < 0) {
        return (u_printerr(url, "Name or service not known"));
    }
    if (res != NULL)
    {
        servaddr = (struct sockaddr_in *)res->ai_addr;
        addr = &(servaddr->sin_addr);
        inet_ntop(res->ai_family, addr, ipstr, sizeof(ipstr));
        ft_printf("PING  (%s) %d(%ld)\n", ipstr, DATA_SIZE, PACK_SIZE);
        if (ft_strcmp(ipstr, url)) {
            ft_printf("\n");
            opts->textaddr = 1;
            ping.url = url;
            /*
            ** reverse hostname if address is not in ipv4 format ???
             */
        } else {
            opts->textaddr = 0;
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

    /* loop : seq is incremented on each ping/pong.
     ** time also needs to be managed each time a ping happens
     ** */
    u_inittimer(&timer);
    p_initping(&ping, &timer, &pack, reply, ipstr);
    e_loop(&ping,servaddr, opts, sock);

    /*
    ** TODO: print stats when exiting
    ** */
    e_output(&ping, ft_strcmp(ipstr, url));
    freeaddrinfo(res);
    free(opts);
    free(reply);
    return (0);
}
