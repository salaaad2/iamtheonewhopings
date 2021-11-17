/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 17:19:27 by rbousset          #+#    #+#             */
/*   Updated: 2020/02/14 17:19:29 by rbousset         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdarg.h>

# define FT_MIN_HEX_BASE		"0123456789abcdef"
# define FT_MAJ_HEX_BASE		"0123456789ABCDEF"
# define FT_PRINTF_CONV_CHARSET	"cspdiuxX%"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE			72
# endif

typedef unsigned char	t_bool;

enum					e_bool
{
	FALSE,
	TRUE
};

typedef struct			s_list
{
	void				*content;
	struct s_list		*next;
}						t_list;

typedef struct			s_gnl
{
	char				*rest;
	int					fd;
	struct s_gnl		*next;
}						t_gnl;

typedef struct			s_printflist
{
	char				*fullflag;
	char				*output;
	size_t				flaglen;
	int					putlen;
	int					width;
	int					precision;
	int					fulllen;
	unsigned char		isreverse;
	unsigned char		isneg;
	unsigned char		isaz;
	unsigned char		zflag;
	unsigned char		issharp;
	unsigned char		isminus;
	char				isaspace;
	unsigned char		isaplus;
	char				lh;
	char				conv;
	char				actconv;
}						t_printflist;

typedef struct			s_stok
{
	char				*spanp;
	char				*ns;
	int					c;
	int					sc;
}						t_stok;

/*
** VOID
*/

void					ft_bzero(void *s, size_t n);
void					ft_putendl_fd(char *s, int fd);
void					ft_putnbr_fd(int n, int fd);
void					ft_lstadd_front(t_list **alst, t_list *new);
void					ft_lstadd_back(t_list **alst, t_list *new);
void					ft_lstdelone(t_list *lst, void (*del)(void *));
void					ft_lstclear(t_list **lst, void (*del)(void *));
void					ft_lstiter(t_list *lst, void (*f)(void *));
void					ft_kernel_panic(void);
void					ft_putnbr(long nb);
void					ft_putnbr_base(long nb, char *base);
void					ft_memdel(void **ptr);
void					ft_delwords(char **words);
void					ft_itoa_s(char str[], long n);
void					ft_uitoa_s(char str[], unsigned long n);
void					ft_substr_s(char str[], const char *s,
									unsigned int start, size_t len);
void					*ft_memset(void *b, int c, size_t len);
void					*ft_memcpy(void *dst, const void *src, size_t n);
void					*ft_memccpy(void *dst, const void *src,
								int c, size_t n);
void					*ft_memmove(void *dst, const void *src, size_t len);
void					*ft_memchr(const void *s, int c, size_t n);
void					*ft_calloc(size_t count, size_t size);
void					*ft_nrealloc(void *ptr, size_t oldsize, size_t newsize);

/*
** CHAR
*/

char					*ft_strcat(char *s1, const char *s2);
char					*ft_strchr(const char *s, int c);
char					*ft_strrchr(const char *s, int c);
char					*ft_strrnchr(const char *s, int c, size_t start);
char					*ft_strnstr(const char *haystack, const char *needle,
								size_t len);
char					*ft_strdup(const char *s1);
char					*ft_substr(const char *s, unsigned int start,
								size_t len);
char					*ft_strjoin(const char *s1, const char *s2);
char					*ft_strtrim(const char *s1, const char *set);
char					*ft_itoa(long n);
char					*ft_itoa_base(long n, char *base);
char					*ft_uitoa(unsigned long n);
char					*ft_uitoa_base(unsigned long n, char *base);
char					*ft_strmapi(const char *s,
								char (*f)(unsigned int, char));
char					*ft_nstr(size_t size);
char					*ft_strsubst(char *str,
									const char *pattern,
									const char *subst);
char					ft_strsubst_s(char *str,
									const char *pattern,
									const char *subst);
char					*ft_strtok_r(char *s, const char *delim, char **last);
char					*ft_strtok(char *s, const char *delim);
char					**ft_split(const char *s, char c);

/*
** INT
*/

unsigned char			ft_intlen(long n);
unsigned char			ft_intlen_base(long n, char *base);
unsigned char			ft_uintlen(unsigned long n);
unsigned char			ft_uintlen_base(unsigned long n, char *base);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
t_bool					ft_isspace(int c);
t_bool					ft_iswhitespace(int c);
t_bool					ft_ischarset(const char *charset, int c);
t_bool					ft_isfulldigit(char *str);
t_bool					ft_isupper(int c);
t_bool					ft_islower(int c);
t_bool					ft_isalpha(int c);
t_bool					ft_isdigit(int c);
t_bool					ft_isalnum(int c);
t_bool					ft_isascii(int c);
t_bool					ft_isprint(int c);
int						ft_toupper(int c);
int						ft_tolower(int c);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
int						ft_lstsize(t_list *lst);
int						ft_atoi(const char *str);
int						ft_putchar(int c);
int						ft_putnchar(int c, const size_t n);
int						ft_putstr(const char *s);
int						ft_putendl(const char *s);
int						ft_putchar_fd(char c, int fd);
int						ft_putstr_fd(char *s, int fd);
int						ft_strcmp(const char *s1, const char *s2);
int						ft_abs(int j);
long					ft_labs(long j);
long					ft_memlchr(const void *s, int c, size_t n);
long					ft_strlchr(const char *s, int c);
size_t					ft_strlen(const char *s);
size_t					ft_strclen(const char *s, int c);
size_t					ft_strnlen(const char *s, size_t size);
size_t					ft_strlcpy(char *dst, const char *src, size_t size);
size_t					ft_strlcat(char *dst, const char *src, size_t size);
double					ft_sqrt(double x);

/*
** LIST
*/

t_list					*ft_lstnew(void *content);
t_list					*ft_lstlast(t_list *lst);
t_list					*ft_lstmap(t_list *lst, void *(*f)(void *),
								void (*del)(void *));
/*
** get_next_line
*/

char					*ft_strchr_gnl(const char *s, int c);
char					*ft_swap_gnl(char *s1, char *free_ft);
int						get_next_line(int fd, char **line);
int						ft_free_gnl(int fd, t_gnl **list);
size_t					ft_strlen_gnl(const char *s, char c);
t_gnl					*ft_find_fd(int fd, t_gnl **list);

/*
** ft_printf
*/

void					ft_printf_process(const char *format,
										va_list arg,
										t_printflist *pflist);
void					ft_printf_reinit_struct(t_printflist *pflist);
void					ft_printf_cat_output(char *src,
											size_t len,
											t_printflist *format);
void					ft_printf_treat_flags(va_list arg,
												t_printflist *pflist);
void					ft_printf_put_c(va_list arg, t_printflist *pflist);
void					ft_printf_put_s(va_list arg, t_printflist *pflist);
void					ft_printf_put_p(va_list arg, t_printflist *pflist);
void					ft_printf_put_d(va_list arg, t_printflist *pflist);
void					ft_printf_put_u(va_list arg, t_printflist *pflist);
void					ft_printf_put_x(va_list arg, t_printflist *pflist);
void					ft_printf_put_big_x(va_list arg, t_printflist *pflist);
void					ft_printf_put_perc(va_list arg, t_printflist *pflist);
void					ft_printf_put_none(t_printflist *pflist);
void					ft_printf_put_width_pre(t_printflist *pflist);
void					ft_printf_put_width_post(t_printflist *pflist);
char					*ft_printf_get_flags(const char *format,
											int pos,
											t_printflist *pflist);
char					*ft_printf_flag_to_atoi(char *str);
char					*ft_printf_get_width_nstr(char *str,
													t_printflist *pflist);
unsigned char			ft_printf_is_multiwrite(const char *format);
int						ft_printf_flags(const char *format,
										int pos,
										va_list arg,
										t_printflist *pflist);
int						ft_printf(const char *format,
									...) __attribute__((format(printf,1,2)));
int						ft_dprintf(int fd,
								const char *format,
								...) __attribute__((format(printf,2,3)));
int						ft_sprintf(char *str,
								const char *format,
								...) __attribute__((format(printf,2,3)));
int						ft_printf_get_partlen(const char *format);
int						ft_printf_putpart(const char *format,
										int start,
										int len,
										t_printflist *pflist);
int						ft_printf_put_precision(t_printflist *pflist);
int						ft_printf_get_s_putlen(char *str, t_printflist *pflist);
int						ft_printf_fetch_width(va_list arg,
												char *nstr,
												t_printflist *pflist);
t_printflist			*ft_printf_init_struct(const char *format);

#endif
