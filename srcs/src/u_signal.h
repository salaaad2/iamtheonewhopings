#ifndef U_SIGNAL_H_
#define U_SIGNAL_H_

#include <signal.h>
#include <stdint.h>

static uint8_t running;

void handle_sigint(int dummy);

#endif
