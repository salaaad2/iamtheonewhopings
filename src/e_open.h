#ifndef E_OPEN_H_
#define E_OPEN_H_

#include "l_main.h"

#define STR_INIT "%s"
#define STR_CAT "%s %s"

#define STR_LONG "%s"

int e_open(t_elem * elem, t_opts * opts);
int e_sort(t_elem * elem, unsigned char mode);

#endif
