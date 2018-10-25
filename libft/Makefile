# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angelo <angelo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/21 02:00:39 by afrangio          #+#    #+#              #
#    Updated: 2018/10/25 20:19:46 by alanter          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
NAME		= libft.a
CFILES		= 	srcs/io/ft_putchar.c\
 				srcs/io/ft_putchar_fd.c\
 				srcs/io/ft_putendl.c\
				srcs/io/ft_putendl_fd.c\
				srcs/io/ft_putstrlen_fd.c\
				srcs/io/ft_putstrlen.c\
				srcs/io/ft_putnbr.c\
				srcs/io/ft_putnbr_fd.c\
				srcs/io/ft_putstr.c\
				srcs/io/ft_putstr_fd.c\
				srcs/io/ft_putwchar.c\
				srcs/io/ft_putwchar_fd.c\
				srcs/io/get_next_line.c\
				srcs/list/ft_lstadd.c\
				srcs/list/ft_lstdel.c\
				srcs/list/ft_lstdelone.c\
				srcs/list/ft_lstiter.c\
				srcs/list/ft_lstmap.c\
				srcs/list/ft_lstnew.c\
				srcs/list/ft_stacknew.c\
				srcs/list/ft_stackpop.c\
				srcs/list/ft_stackpush.c\
				srcs/maths/ft_log.c\
				srcs/maths/ft_max.c\
				srcs/maths/ft_min.c\
				srcs/maths/ft_pow.c\
				srcs/maths/ft_ulog.c\
				srcs/mem/ft_bzero.c\
				srcs/mem/ft_memalloc.c\
				srcs/mem/ft_memccpy.c\
				srcs/mem/ft_memchr.c\
				srcs/mem/ft_memcmp.c\
				srcs/mem/ft_memcpy.c\
				srcs/mem/ft_memdel.c\
				srcs/mem/ft_memmove.c\
				srcs/mem/ft_memset.c\
				srcs/mem/ft_realloc.c\
				srcs/mem/ft_swap.c\
				srcs/string/check/ft_isalnum.c\
				srcs/string/check/ft_isalpha.c\
				srcs/string/check/ft_isascii.c\
				srcs/string/check/ft_isdigit.c\
				srcs/string/check/ft_isprint.c\
				srcs/string/check/ft_isspace.c\
				srcs/string/comparaisons/ft_strcmp.c\
				srcs/string/comparaisons/ft_strequ.c\
				srcs/string/comparaisons/ft_strncmp.c\
				srcs/string/comparaisons/ft_strnequ.c\
				srcs/string/comparaisons/ft_strstr.c\
				srcs/string/conversions/ft_atoi.c\
				srcs/string/conversions/ft_itoa.c\
				srcs/string/conversions/ft_itoa_base.c\
				srcs/string/search/ft_strcat.c\
				srcs/string/search/ft_strchr.c\
				srcs/string/search/ft_strlcat.c\
				srcs/string/search/ft_strncat.c\
				srcs/string/search/ft_strnstr.c\
				srcs/string/ft_strclr.c\
				srcs/string/ft_strcpy.c\
				srcs/string/ft_strdel.c\
				srcs/string/ft_strdup.c\
				srcs/string/ft_striter.c\
				srcs/string/ft_striteri.c\
				srcs/string/ft_strjoin.c\
				srcs/string/ft_strlen.c\
				srcs/string/ft_strmap.c\
				srcs/string/ft_strmapi.c\
				srcs/string/ft_strncpy.c\
				srcs/string/ft_strnew.c\
				srcs/string/ft_strrchr.c\
				srcs/string/ft_strsplit.c\
				srcs/string/ft_strsub.c\
				srcs/string/ft_strtrim.c\
				srcs/string/ft_tolower.c\
				srcs/string/ft_toupper.c\

OFILES		=	ft_atoi.o\
				ft_bzero.o\
				ft_isalnum.o\
				ft_isalpha.o\
				ft_isascii.o\
 				ft_isdigit.o\
				ft_isprint.o\
				ft_isspace.o\
				ft_itoa.o\
				ft_itoa_base.o\
				ft_log.o\
				ft_lstadd.o\
				ft_lstdel.o\
				ft_lstdelone.o\
				ft_lstiter.o\
				ft_lstmap.o\
				ft_lstnew.o\
				ft_max.o\
				ft_memalloc.o\
				ft_memccpy.o\
				ft_memchr.o\
				ft_memcmp.o\
				ft_memcpy.o\
				ft_memdel.o\
				ft_memmove.o\
				ft_memset.o\
				ft_min.o\
				ft_pow.o\
				ft_putchar_fd.o\
				ft_putendl.o\
				ft_putendl_fd.o\
				ft_putnbr.o\
				ft_putnbr_fd.o\
				ft_putstr.o\
				ft_putstr_fd.o\
				ft_putwchar.o\
				ft_putwchar_fd.o\
				ft_realloc.o\
				ft_stacknew.o\
				ft_stackpop.o\
				ft_stackpush.o\
				ft_strcat.o\
				ft_strchr.o\
				ft_strclr.o\
				ft_strcmp.o\
				ft_strcpy.o\
				ft_strdel.o\
				ft_strdup.o\
				ft_strequ.o\
				ft_striter.o\
				ft_striteri.o\
				ft_strjoin.o\
				ft_strlcat.o\
				ft_strlen.o\
				ft_strmap.o\
				ft_strmapi.o\
				ft_strncat.o\
				ft_strncmp.o\
				ft_strncpy.o\
				ft_strnequ.o\
				ft_strnew.o\
				ft_strnstr.o\
				ft_strrchr.o\
				ft_strsplit.o\
				ft_strstr.o\
				ft_strsub.o\
				ft_strtrim.o\
				ft_swap.o\
				ft_tolower.o\
				ft_toupper.o\
				ft_ulog.o\
				ft_putchar.o\
				ft_putstrlen.o\
				ft_putstrlen_fd.o\
				get_next_line.o\

all: $(NAME)

$(NAME): $(CFILES) includes/get_next_line.h includes/ioft.h\
					includes/libft.h includes/listft.h includes/mathsft.h includes/memft.h includes/stringft.h
	@cd srcs/
	@$(CC) -c $(CFILES) $(CFLAGS) -Iincludes
	@ar rcs $(NAME) $(OFILES)
	@ranlib $(NAME)

debug: $(CFILES) includes/get_next_line.h includes/ioft.h\
					includes/libft.h includes/listft.h includes/mathsft.h includes/memft.h includes/stringft.h
	@cd srcs/
	@$(CC) -g -c $(CFILES)
	@ar rcs $(NAME) $(OFILES)
	@ranlib $(NAME)

test: 
	@cd srcs
	@$(CC) -g main.c\
	@ $(CFILES) -o test

clean:
	@/bin/rm -f $(OFILES)
fclean: clean 
	@/bin/rm -f $(NAME) test

re: fclean all

ret: fclean test
