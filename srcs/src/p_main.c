/*****************************************************************************/
/*                      FT_PING by fmoenne. file: p_main.c                     */
/*****************************************************************************/

#include <stdlib.h>

#include "../libft/include/libft.h"

#include "p_main.h"
#include "u_lstcont.h"
#include "u_opts.h"
#include "e_ping.h"

/*
** check for flags;
** initialize linked list containing t_elem elements with all non option arguments.
**
*/

int main(int ac, char *av[])
{
    char * url;
    t_opts * opts;
    int i;

    i = 1;
    opts = u_initopts();
    while (i < ac)
    {
        if (av[i][0] == '-')
        {
            u_getopts(av, opts);
        }
        else
        {
            if ()
        }
        i++;
    }
    if (opts->help == 1)
    {
        return (e_help());
    } else if (url == NULL) {
        ft_dprintf(2, "ft_ping: usage error: Destination address required\n");
    } else {
        return (e_start(url, opts));
    }
    return (0);
}

/*
** ====== INFO ======
** Files prefixes info
** -------------------
** d_  -> defines related
** e_  -> exec related
** f_  -> failure related
** p_  -> parse related
** u_  -> utils related
** v_  -> general purpose variables related
*/
