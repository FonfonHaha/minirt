# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcoureau <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/25 17:49:33 by pcoureau          #+#    #+#              #
#    Updated: 2020/02/25 18:23:00 by pcoureau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= miniRT
SRC		= main.c \
		  rt_keys.c\
		  rt_init.c\
OBJ		= $(addprefix $(OBJDIR),$(SRC:.c=.o))
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g
FT		= ./libft/
FT_LIB	= $(addprefix $(FT),libft.a)
FT_INC	= -I ./libft
FT_LNK	= -L ./libft -l ft -l pthread
MLX_LNK	= -I /usr/local/include -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit
SRCDIR	= ./srcs/
INCDIR	= ./includes/
OBJDIR	= ./objs/
all: obj $(FT_LIB) $(NAME)
obj:
	mkdir -p $(OBJDIR)
$(OBJDIR)%.o:$(SRCDIR)%.c
	$(CC) $(CFLAGS) $(FT_INC) -I $(INCDIR) -o $@ -c $<
$(FT_LIB):
	make -C $(FT)
$(NAME): $(OBJ)
	$(CC) $(OBJ) $(FT_LNK) $(MLX_LNK) -lm -o $(NAME)
clean:
	rm -rf $(OBJDIR)
	make -C $(FT) clean
fclean: clean
	rm -rf $(NAME)
	make -C $(FT) fclean
re: fclean all
