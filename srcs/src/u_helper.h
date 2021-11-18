#ifndef U_HELPER_H_
#define U_HELPER_H_

#include <signal.h>
#include <stdint.h>

#include "../libft/include/libft.h"

#include "e_ping.h"

void handle_sigint(int dummy);
void u_setrunning(uint8_t mode, uint8_t * running);
int u_help( void );

#endif
