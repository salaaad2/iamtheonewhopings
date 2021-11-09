#include "l_main.h"
#include "../libft/libft.h"

int c_get_opts(t_opts * opts, int ac, char **av)
{
    char s_flags[5] = "lRart";
    char c;

    if (ac == 1)
    {
        return (1);
    }

    c = s_flags[0];
    ft_strchr(av[1], c);
}
