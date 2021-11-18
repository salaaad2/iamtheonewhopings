/*****************************************************************************/
/*                       FT_PING helper functions                            */
/*****************************************************************************/
#include "u_helper.h"

void
handle_sigint(int dummy)
{
    (void)dummy;
    u_setrunning(1, NULL);
}

void
u_setrunning(uint8_t mode, uint8_t * running)
{
    static uint8_t * r;

    if (mode == 0)
    {
        r = running;
    } else {
        *r = 0;
    }
}


int
e_help( void )
{
    ft_printf("Usage\n./ft_ping [options] <destination>\n\nOptions:\n");
    ft_printf(" -v\tverbose output\n");
    return (0);
}
