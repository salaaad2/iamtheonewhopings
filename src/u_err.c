#include "u_err.h"

int
u_printerr(char * reason, char * value)
{
    ft_dprintf(2, "ft_ls: %s: %s\n", value, reason);
    return (1);
}
