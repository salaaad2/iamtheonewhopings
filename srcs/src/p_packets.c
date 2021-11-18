#include "p_packets.h"
#include "u_err.h"

#include <sys/time.h>

int16_t
p_checksum(const void *data, size_t size)
{
    register long sum = 0;
    int i;

    i = 0;
    while( size > 1 )  {
        sum += ((uint16_t*) data)[i];
        i++;
        size -= 2;
    }

    if( size > 0 )
        sum += * (uint8_t *) data;

    while (sum>>16)
        sum = (sum & 0xffff) + (sum >> 16);

    return ((int16_t)~sum);
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
    pack->hdr.un.echo.sequence = 0;

    while (i < (DATA_SIZE - 1))
    {
        pack->load[i] = i + '9';
        i++;
    }
    pack->load[i] = '\0';
    pack->hdr.checksum = p_checksum(pack, PACK_SIZE);
    return (0);
}
