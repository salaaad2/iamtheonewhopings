#include "u_err.h"
#include <stdlib.h>

int
u_printerr(char * reason, char * value)
{
    ft_dprintf(2, "ft_ping: %s: %s\nperror:%s\n", value, reason, strerror(errno));
    exit(1);
    return (1);
}
