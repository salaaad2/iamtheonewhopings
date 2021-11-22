#ifndef E_PING_H_
#define E_PING_H_

#include "../libft/include/libft.h"

#include "p_main.h"

#include <netinet/ip_icmp.h>


#define IP_SIZE sizeof(struct icmphdr)
#define ICMP_SIZE sizeof(struct icmphdr)
#define DATA_SIZE 56
#define PACK_SIZE ICMP_SIZE + DATA_SIZE

typedef struct s_pack {
    struct icmphdr hdr;
    char load[DATA_SIZE];
} t_pack ;

typedef struct s_reply {
    struct iphdr ip;
    struct icmphdr hdr;
    char load[DATA_SIZE];
} t_reply;

typedef struct s_time {
    double itv, ntv, avg, lapse;
} t_time ;


int e_start(char * url, t_opts * opts);

#endif
