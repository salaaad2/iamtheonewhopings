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
double u_timest(void);
double u_cmptime(double time);
int u_printpack(t_reply *pack, t_time * timer, char * ipstr, uint64_t seq, uint8_t ta);

#endif
