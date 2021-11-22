#ifndef U_TIME_H_
#define U_TIME_H_

#include <stdint.h>
#include <sys/time.h>

#include "e_ping.h"

double	u_timest(void);
double	u_cmptime(double time);
double	u_avgtime(double time);
long	u_longtime(void);
int	u_updatetime(double val, t_time * timer);

#endif
