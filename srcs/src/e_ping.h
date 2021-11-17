#ifndef E_PING_H_
#define E_PING_H_

#include "../libft/include/libft.h"
#include "p_main.h"

#define ICMP_SIZE sizeof(struct icmphdr)
#define DATA_SIZE 48
#define PACK_SIZE ICMP_SIZE + DATA_SIZE + 8
#define PAD_DATA "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"

int e_help( void );
int e_start(char * url, t_opts * opts);

#endif
