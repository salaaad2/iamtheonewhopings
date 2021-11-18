#ifndef U_HELPER_H_
#define U_HELPER_H_

#include <signal.h>
#include <stdint.h>
#include <sys/time.h>

#include "../libft/include/libft.h"

#include "e_ping.h"

void handle_sigint(int dummy);
void u_setrunning(uint8_t mode, uint8_t * running);
int u_help( void );
int64_t u_timest(void);
int64_t u_cmptime(long time);
int u_printpack(t_pack *pack, t_time * timer, char * ipstr, uint64_t seq);

#endif
