#ifndef P_PACKETS_H_
#define P_PACKETS_H_

#include <netinet/ip_icmp.h>

#include "../libft/include/libft.h"

int p_initpacket(char * packdata, struct icmphdr * hdr, int id, int seq);

#endif
