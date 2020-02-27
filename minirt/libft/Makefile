# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcoureau <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/11 17:57:50 by pcoureau          #+#    #+#              #
#    Updated: 2020/02/25 17:51:28 by pcoureau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = libft.a
SRCS    =	libft/ft_isascii.c \
			libft/ft_puis.c \
			libft/ft_strlcpy.c \
			libft/ft_memcpy.c \
			libft/ft_toupper.c \
			libft/ft_atoi.c \
			libft/ft_atof.c \
			libft/ft_isdigit.c \
			libft/ft_memmove.c \
			libft/ft_strlen.c \
			libft/ft_bzero.c \
			libft/ft_isprint.c \
			libft/ft_memset.c \
			libft/ft_strncmp.c \
			libft/ft_calloc.c \
			libft/ft_memccpy.c \
			libft/ft_strchr.c \
			libft/ft_strnstr.c \
			libft/ft_isalnum.c \
			libft/ft_memchr.c \
			libft/ft_strdup.c \
			libft/ft_strdupnos.c \
			libft/ft_strrchr.c \
			libft/ft_isalpha.c \
			libft/ft_memcmp.c \
			libft/ft_strlcat.c \
			libft/ft_tolower.c \
			libft/ft_strcpy.c \
			libft/ft_strcpynos.c \
			libft/ft_substr.c \
			libft/ft_strjoin.c \
			libft/ft_strtrim.c \
			libft/ft_split.c \
			libft/ft_splitnos.c \
			libft/ft_itoa.c \
			libft/ft_strmapi.c \
			libft/ft_putchar_fd.c \
			libft/ft_putstr_fd.c \
			libft/ft_putendl_fd.c \
			libft/ft_putnbr_fd.c \
			libft/ft_lstnew.c \
			libft/ft_lstadd_front.c \
			libft/ft_lstsize.c \
			libft/ft_lstlast.c \
			libft/ft_lstadd_back.c \
			libft/ft_lstdelone.c \
			libft/ft_lstclear.c \
			libft/ft_lstiter.c \
			libft/ft_lstmap.c \
			libft/ft_print_lst.c \
			libft/ft_putnbr_base_fd.c \
			libft/ft_putnbrunsint_fd.c \
			libft/ft_putptr_fd.c \
			libft/ft_checkbase.c \
			ft_convc.c \
			ft_convs.c \
			ft_convp.c \
			ft_convp_ii.c \
			ft_convu.c \
			ft_convd.c \
			ft_convd_ii.c \
			ft_convx.c \
			ft_convxx.c \
			ft_convprc.c \
			ft_convert.c \
			ft_checkflags.c \
			ft_flagsconvert.c \
			ft_getstr.c \
			ft_itoad.c \
			ft_itoau.c \
			ft_itoax.c \
			ft_itoap.c \
			ft_printf.c \
			get_next_line_utils.c \
			get_next_line.c

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
