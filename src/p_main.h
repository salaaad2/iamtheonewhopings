#ifndef P_MAIN_H_
#define P_MAIN_H_

#include <sys/param.h>
#include <sys/types.h>
#include <dirent.h>

#include "../libft/include/libft.h"

typedef unsigned char bool_t;

typedef struct s_opts {
    bool_t	verbose;
    bool_t	help;
    bool_t	noopt;
} t_opts;

typedef struct s_elem {
    void * content;

    struct s_elem * next;
} t_elem;

#endif
