#ifndef E_PING_H_
#define E_PING_H_

#include "../libft/include/libft.h"

#include "p_main.h"

#include <netinet/ip_icmp.h>


#define ICMP_SIZE sizeof(struct icmphdr)
#define DATA_SIZE 56
#define PACK_SIZE ICMP_SIZE + DATA_SIZE


typedef struct s_pack {
    struct icmphdr hdr;
    char load[DATA_SIZE];
} t_pack ;


int e_help( void );
int e_start(char * url, t_opts * opts);

#endif
