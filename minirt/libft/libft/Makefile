# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcoureau <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/11 17:57:50 by pcoureau          #+#    #+#              #
#    Updated: 2020/02/17 14:35:42 by pcoureau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = libft.a
SRCS    =	ft_isascii.c \
			ft_strlcpy.c \
			ft_memcpy.c \
			ft_toupper.c \
			ft_atoi.c \
			ft_isdigit.c \
			ft_memmove.c \
			ft_strlen.c \
			ft_bzero.c \
			ft_isprint.c \
			ft_memset.c \
			ft_strncmp.c \
			ft_calloc.c \
			ft_memccpy.c \
			ft_strchr.c \
			ft_strnstr.c \
			ft_isalnum.c \
			ft_memchr.c \
			ft_strdup.c \
			ft_strdupnos.c \
			ft_strrchr.c \
			ft_isalpha.c \
			ft_memcmp.c \
			ft_strlcat.c \
			ft_tolower.c \
			ft_strcpy.c \
			ft_strcpynos.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_splitnos \
			ft_itoa.c \
			ft_strmapi.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_print_lst.c \
			ft_putnbr_base_fd.c \
			ft_putnbrunsint_fd.c \
			ft_putptr_fd.c \
			ft_checkbase.c 

SRCDIR    = ./
CC        = gcc
FLAGS    = -Wall -Wextra -Werror
OBJ        = $(addprefix $(SRCDIR), $(SRCS:.c=.o))

$(SRCDIR)%.o:    $(SRCDIR)%.c
	$(CC) $(FLAGS) -o $@ -c $<

$(NAME):         $(OBJ)
	ar rc $(NAME) $(OBJ)

all:             $(NAME)

clean:
	rm -f $(OBJ)

fclean:         clean
	rm -f $(NAME)

re:             fclean all

.PHONY:            all clean fclean re
