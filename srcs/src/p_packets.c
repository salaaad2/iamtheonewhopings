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

    return (int16_t)~sum;
}

int
p_initpacket(char * packdata, struct icmphdr * hdr)
{
    struct timeval tv;
    long time;

    if ((hdr = ft_calloc(1, sizeof(struct icmphdr))) == NULL) {
        u_printerr("malloc", "malloc");
    }

    hdr->type = ICMP_ECHO;
    hdr->code = 0;
    hdr->checksum = 0;
    hdr->un.echo.id = getpid();
    hdr->un.echo.sequence = 0;

    if (gettimeofday(&tv, NULL)) {
        u_printerr("Wed Nov 17 14:03:55 2021", "Wed Nov 17 14:04:00 2021");
    }

	time = ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
    (void)time;

    hdr->checksum = p_checksum(hdr, sizeof(struct icmphdr));
    ft_memcpy(packdata, hdr, sizeof(struct icmphdr));
    /* ft_memcpy(packdata + sizeof(struct icmphdr), , 1); */
    ft_memcpy(packdata + sizeof(struct icmphdr), PAD_DATA, 48);


    ft_printf("sizeof : %d\n", (int)sizeof(struct icmphdr));
    return (0);
}
