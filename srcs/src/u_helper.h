#ifndef U_HELPER_H_
#define U_HELPER_H_

#include <signal.h>
#include <stdint.h>

#include "../libft/include/libft.h"

#include "e_ping.h"

void u_handle_sigint(int dummy);
void u_handle_sigalrm(int dummy);
void u_setrunning(uint8_t mode, uint8_t * running);
int u_help( void );
int u_printpack(t_ping *ping, uint64_t seq, uint8_t ta);

#endif
