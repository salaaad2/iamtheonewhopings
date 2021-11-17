#ifndef P_PACKETS_H_
#define P_PACKETS_H_

#include <netinet/ip_icmp.h>
#include <unistd.h>

#include "../libft/include/libft.h"

#include "e_ping.h"

int     p_initpacket(char * packdata, struct icmphdr * hdr, int seq);
int16_t p_checksum(const void *data, size_t size);

#endif
