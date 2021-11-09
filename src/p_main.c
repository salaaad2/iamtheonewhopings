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
    t_elem * elem;
    t_elem * new;
    t_opts * opts;
    int i;

    i = 1;
    elem = l_lstnew(".");
    opts = u_initopts();
    while (i < ac)
    {
        if (av[i][0] == '-')
        {
            u_getopts(av, opts);
        }
        else
        {
            new = malloc(sizeof(t_elem));
            new->content = av[i];
            new->next = NULL;
            l_lstadd_back(&elem, new);
        }
        i++;
    }
    if (opts->help == 1)
    {
        return (e_help());
    } else if (l_lstsize(elem) == 1) {
        ft_dprintf(2, "ft_ping: usage error: Destination address required\n");
    } else {
        elem = elem->next;
        return (e_start(elem, opts));
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
