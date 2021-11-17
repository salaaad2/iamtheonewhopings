#include "p_packets.h"

int16_t
p_checksum(const void *data, size_t size)
{
    size_t i;
    int             sum = 0;

    for (i = 0; i < size / 2; i++)
        sum += ((const uint16_t*)data)[0];

    if (size % 2 != 0)
        sum += ((const uint8_t*)data)[size];

    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);

    return (int16_t)~sum;
}

int
p_initpacket(char * packdata, struct icmphdr * hdr, int seq)
{
    ft_bzero(hdr, sizeof(struct icmphdr));
    hdr->type = ICMP_ECHO;
    hdr->code = 0;
    hdr->checksum = 0;
    hdr->un.echo.id = getpid();
    hdr->un.echo.sequence = seq;

    hdr->checksum = p_checksum(hdr, sizeof(struct icmphdr));

    ft_memcpy(packdata, &hdr, sizeof(struct icmphdr));
    return (0);
}
