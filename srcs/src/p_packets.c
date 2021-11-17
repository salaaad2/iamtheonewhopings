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
    /* ft_printf("sum : %d\nPACK_SIZE: %ld", (int16_t)~sum, PACK_SIZE); */

    return (int16_t)~sum;
}

int
p_initpacket(t_pack * pack)
{
    uint16_t i = 0;

    ft_bzero(pack, sizeof(pack));

    pack->hdr.type = ICMP_ECHO;
    pack->hdr.code = 0;
    pack->hdr.checksum = 0;
    pack->hdr.un.echo.id = getpid();
    pack->hdr.un.echo.sequence = 1;

    while (i < (DATA_SIZE - 1))
    {
        pack->load[i] = i + '9';
        i++;
    }
    pack->load[i] = '\0';
    pack->hdr.checksum = p_checksum(pack, PACK_SIZE);
    return (0);
}
