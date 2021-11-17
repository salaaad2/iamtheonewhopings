#include "p_packets.h"


int
p_initpacket(char * packdata, struct icmphdr * hdr, int id, int seq)
{
    ft_bzero(hdr, sizeof(struct icmphdr));
    hdr->type = ICMP_ECHO;
    hdr->un.echo.id = id;
    hdr->un.echo.sequence = seq;

    ft_memcpy(packdata, &hdr, sizeof(struct icmphdr));
    return (0);
}
