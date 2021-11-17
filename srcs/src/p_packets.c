#include "p_packets.h"
#include "u_err.h"

#include <sys/time.h>

/* int16_t */
/* p_checksum(const void *data, uint64_t size) */
/* { */
/*     uint64_t i; */
/*     int             sum = 0; */

/*     for (i = 0; i < size; i++) */
/*     { */
/*         sum += ((const uint16_t*)data)[0]; */
/*     } */

/*     if (size % 2 != 0) */
/*         sum += ((const uint8_t*)data)[size]; */

/*     sum = (sum >> 16) + (sum & 0xFFFF); */
/*     sum += (sum >> 16); */
/*     /\* ft_printf("sum : %d\nPACK_SIZE: %ld", (int16_t)~sum, PACK_SIZE); *\/ */

/*     return (int16_t)~sum; */
/* } */

int16_t
p_checksum(const void *data, size_t size)
{
    /* Compute Internet Checksum for "count" bytes
     *         beginning at location "addr".
     */
    register long sum = 0;
    int i;

    i = 0;
    while( size > 1 )  {
        /*  This is the inner loop */
        sum += ((uint16_t*) data)[i];
        i++;
        size -= 2;
    }

    /*  Add left-over byte, if any */
    if( size > 0 )
        sum += * (unsigned char *) data;

    /*  Fold 32-bit sum to 16 bits */
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
