default: all
#==============================================================================#
#--------------------------------- Shell --------------------------------------#
#==============================================================================#
SHELL		:= /bin/sh
OS			 = $(shell uname)
#==============================================================================#
#------------------------------ Directories -----------------------------------#
#==============================================================================#
INCS_DIR	= include/
SRCS_DIR	= src/
OBJS_DIR	= obj/
#==============================================================================#
#--------------------------------- Files --------------------------------------#
#==============================================================================#
INCS		= libft.h
#------------------------------------------------------------------------------#
SRCS_NAME	 = ft_memset.c
SRCS_NAME	+= ft_bzero.c
SRCS_NAME	+= ft_memcpy.c
SRCS_NAME	+= ft_memccpy.c
SRCS_NAME	+= ft_memmove.c
SRCS_NAME	+= ft_memchr.c
SRCS_NAME	+= ft_memlchr.c
SRCS_NAME	+= ft_memcmp.c
SRCS_NAME	+= ft_strlen.c
SRCS_NAME	+= ft_strclen.c
SRCS_NAME	+= ft_strnlen.c
SRCS_NAME	+= ft_isalpha.c
SRCS_NAME	+= ft_isdigit.c
SRCS_NAME	+= ft_isfulldigit.c
SRCS_NAME	+= ft_isalnum.c
SRCS_NAME	+= ft_isascii.c
SRCS_NAME	+= ft_isprint.c
SRCS_NAME	+= ft_ischarset.c
SRCS_NAME	+= ft_tolower.c
SRCS_NAME	+= ft_toupper.c
SRCS_NAME	+= ft_strchr.c
SRCS_NAME	+= ft_strrchr.c
SRCS_NAME	+= ft_strrnchr.c
SRCS_NAME	+= ft_strlchr.c
SRCS_NAME	+= ft_strncmp.c
SRCS_NAME	+= ft_strlcpy.c
SRCS_NAME	+= ft_strlcat.c
SRCS_NAME	+= ft_strnstr.c
SRCS_NAME	+= ft_strtok_r.c
SRCS_NAME	+= ft_strtok.c
SRCS_NAME	+= ft_atoi.c
SRCS_NAME	+= ft_calloc.c
SRCS_NAME	+= ft_nrealloc.c
SRCS_NAME	+= ft_strdup.c
SRCS_NAME	+= ft_substr.c
SRCS_NAME	+= ft_substr_s.c
SRCS_NAME	+= ft_strjoin.c
SRCS_NAME	+= ft_strtrim.c
SRCS_NAME	+= ft_split.c
SRCS_NAME	+= ft_itoa.c
SRCS_NAME	+= ft_itoa_s.c
SRCS_NAME	+= ft_itoa_base.c
SRCS_NAME	+= ft_uitoa.c
SRCS_NAME	+= ft_uitoa_s.c
SRCS_NAME	+= ft_uitoa_base.c
SRCS_NAME	+= ft_strmapi.c
SRCS_NAME	+= ft_putchar_fd.c
SRCS_NAME	+= ft_putstr_fd.c
SRCS_NAME	+= ft_putendl_fd.c
SRCS_NAME	+= ft_putnbr_fd.c
SRCS_NAME	+= ft_lstnew.c
SRCS_NAME	+= ft_lstadd_front.c
SRCS_NAME	+= ft_lstsize.c
SRCS_NAME	+= ft_lstlast.c
SRCS_NAME	+= ft_lstadd_back.c
SRCS_NAME	+= ft_lstdelone.c
SRCS_NAME	+= ft_lstclear.c
SRCS_NAME	+= ft_lstiter.c
SRCS_NAME	+= ft_lstmap.c
SRCS_NAME	+= ft_putchar.c
SRCS_NAME	+= ft_putnchar.c
SRCS_NAME	+= ft_putstr.c
SRCS_NAME	+= ft_putendl.c
SRCS_NAME	+= ft_putnbr.c
SRCS_NAME	+= ft_putnbr_base.c
SRCS_NAME	+= ft_strcat.c
SRCS_NAME	+= ft_strcmp.c
SRCS_NAME	+= ft_isspace.c
SRCS_NAME	+= ft_iswhitespace.c
SRCS_NAME	+= ft_sqrt.c
SRCS_NAME	+= ft_intlen.c
SRCS_NAME	+= ft_intlen_base.c
SRCS_NAME	+= ft_uintlen.c
SRCS_NAME	+= ft_uintlen_base.c
SRCS_NAME	+= ft_nstr.c
SRCS_NAME	+= ft_memdel.c
SRCS_NAME	+= ft_delwords.c
SRCS_NAME	+= ft_kernel_panic.c
SRCS_NAME	+= get_next_line.c
SRCS_NAME	+= get_next_line_utils.c
SRCS_NAME	+= ft_printf.c
SRCS_NAME	+= ft_dprintf.c
SRCS_NAME	+= ft_sprintf.c
SRCS_NAME	+= ft_printf_init_struct.c
SRCS_NAME	+= ft_printf_get_flags.c
SRCS_NAME	+= ft_printf_use_flags.c
SRCS_NAME	+= ft_printf_get_width_nstr.c
SRCS_NAME	+= ft_printf_treat_flags.c
SRCS_NAME	+= ft_printf_parts.c
SRCS_NAME	+= ft_printf_put_width.c
SRCS_NAME	+= ft_printf_put_precision.c
SRCS_NAME	+= ft_printf_put_char.c
SRCS_NAME	+= ft_printf_put_str.c
SRCS_NAME	+= ft_printf_put_ptr.c
SRCS_NAME	+= ft_printf_put_int.c
SRCS_NAME	+= ft_printf_put_hex.c
SRCS_NAME	+= ft_printf_put_none.c
SRCS_NAME	+= ft_printf_get_s_putlen.c
SRCS_NAME	+= ft_printf_process.c
SRCS_NAME	+= ft_printf_cat_output.c
SRCS_NAME	+= ft_printf_flag_to_atoi.c
SRCS_NAME	+= ft_strsubst.c
SRCS_NAME	+= ft_strsubst_s.c
SRCS_NAME	+= ft_abs.c
SRCS_NAME	+= ft_labs.c
#------------------------------------------------------------------------------#
SRCS		= $(addprefix ${SRCS_DIR},${SRCS_NAME})
#------------------------------------------------------------------------------#
OBJS		= $(patsubst ${SRCS_DIR}%.c,${OBJS_DIR}%.o,${SRCS})
#==============================================================================#
#--------------------------------- UNIX ---------------------------------------#
#==============================================================================#
MKDIR		= mkdir -p
RM			= rm -rf
OS			= $(shell uname)
#==============================================================================#
#-------------------------------- Compiler ------------------------------------#
#==============================================================================#
ifeq (${OS}, FreeBSD)
CC			 = cc
endif
ifeq (${OS}, Linux)
CC			 = gcc
endif
ifeq (${OS}, Darwin)
CC			 = cc
endif
#------------------------------------------------------------------------------#
CFLAGS		 = -std=gnu89
CFLAGS		+= -Wall
CFLAGS		+= -Wextra
CFLAGS		+= -Werror
CFLAGS		+= -pedantic
#------------------------------------------------------------------------------#
NAME		= libft.a
#==============================================================================#
#-------------------------------- Library -------------------------------------#
#==============================================================================#
AR			= ar rcs
#==============================================================================#
#--------------------------------- Rules --------------------------------------#
#==============================================================================#
${OBJS_DIR}%.o: ${SRCS_DIR}%.c ${INCS_DIR}${INCS}
	${CC} -c ${CFLAGS} -I${INCS_DIR} -o $@ $<
#------------------------------------------------------------------------------#
${OBJS_DIR}:
	${MKDIR} ${OBJS_DIR}
#------------------------------------------------------------------------------#
${NAME}: ${OBJS}
	${AR} ${NAME} ${OBJS}
#------------------------------------------------------------------------------#
all: ${OBJS_DIR} ${NAME}
#------------------------------------------------------------------------------#
debug: CFLAGS += -g3
debug: all
#------------------------------------------------------------------------------#
asan: CFLAGS += -g3
asan: CFLAGS += -fsanitize=address
asan: all
#------------------------------------------------------------------------------#
msan: CFLAGS += -g3
msan: CFLAGS += -fsanitize=memory
msan: CFLAGS += -fsanitize-memory-track-origins
msan: CFLAGS += -fno-common
msan: CFLAGS += -fno-omit-frame-pointer
msan: LFTRULE = msan
msan: all
#------------------------------------------------------------------------------#
clean: 
	${RM} ${OBJS_DIR}
#------------------------------------------------------------------------------#
fclean: clean
	${RM} ${NAME}
#------------------------------------------------------------------------------#
re: fclean all
#------------------------------------------------------------------------------#
.PHONY:	all clean clean fclean re run default
#==================================== EOF =====================================#
