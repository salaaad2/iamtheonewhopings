#include "p_packets.h"
#include "u_err.h"

#include <sys/time.h>

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
    ft_printf("sum : %d\nPACK_SIZE: %ld", (int16_t)~sum, PACK_SIZE);

    return (int16_t)~sum;
}

int
p_initpacket(char * packdata, struct icmphdr * hdr)
{
    if ((hdr = ft_calloc(1, sizeof(struct icmphdr))) == NULL) {
        u_printerr("malloc", "malloc");
    }

    hdr->type = ICMP_ECHO;
    hdr->code = 0;
    hdr->checksum = 0;
    hdr->un.echo.id = getpid();
    hdr->un.echo.sequence = 0;
    hdr->un.frag.mtu = 1;
    ft_memcpy(packdata, hdr, sizeof(struct icmphdr));
    hdr->checksum = p_checksum(packdata, PACK_SIZE);
    return (0);
}
