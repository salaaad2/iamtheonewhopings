#ifndef E_PING_H_
#define E_PING_H_

#include "../libft/include/libft.h"
#include "p_main.h"

#define ICMP_SIZE sizeof(struct icmphdr)
#define DATA_SIZE 56
#define PACK_SIZE ICMP_SIZE + DATA_SIZE

int e_help( void );
int e_start(t_elem * node, t_opts * opts);

#endif
