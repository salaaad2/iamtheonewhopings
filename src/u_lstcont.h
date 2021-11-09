#ifndef U_LSTCONT_H_
#define U_LSTCONT_H_

#include "l_main.h"

void					l_lstadd_front(t_elem **alst, t_elem *new);
void					l_lstadd_back(t_elem **alst, t_elem *new);
void					l_lstdelone(t_elem *lst, void (*del)(void *));
void					l_lstclear(t_elem **lst, void (*del)(void *));
void					l_lstiter(t_elem *lst, void (*f)(void *));

int					l_lstswap(t_elem * one, t_elem *two);
int						l_lstsize(t_elem *lst);
t_elem					*l_lstnew(void *content);
t_elem					*l_lstlast(t_elem *lst);
t_elem					*l_lstmap(t_elem *lst, void *(*f)(void *),
								void (*del)(void *));

#endif
