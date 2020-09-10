# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcoureau <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/27 19:31:45 by pcoureau          #+#    #+#              #
#    Updated: 2020/02/27 20:18:39 by pcoureau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= miniRT
SRC		= main.c \
		  rt_keys.c \
		  rt_init.c \
		  rt_color.c \
		  rt_get_func.c \
		  rt_get_param.c \
		  rt_pars_a.c \
		  rt_pars_bn.c \
		  rt_pars_c.c \
		  rt_pars_cy.c \
		  rt_pars_l.c \
		  rt_pars_pl.c \
		  rt_pars_r.c \
		  rt_pars_sp.c \
		  rt_pars_sq.c \
		  rt_pars_tr.c \
		  rt_pars.c \
		  rt_lstlast.c \
		  rt_putpixel.c \
		  rt_c_sphere.c \
		  rt_c_plan.c \
		  rt_c_carre.c \
		  rt_c_cylindre_ii.c \
		  rt_c_cylindre.c \
		  rt_c_triangle.c \
		  rt_maths.c \
		  rt_mathsii.c \
		  rt_maths_rot.c 

OBJ		= $(addprefix $(OBJDIR),$(SRC:.c=.o))
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g
FT		= ./libft/
FT_MLX 	= ./minilibx-linux/
FT_LIB	= $(addprefix $(FT),libft.a)
FT_INC	= -I ./libft/libft
FT_LNK	= -L ./libft -l ft -l pthread
MLX_LNK	= -I ./minilibx-linux -L ./minilibx-linux -lmlx -lXext -lX11 -lm -lbsd 
SRCDIR	= ./srcs/
INCDIR	= ./includes/
OBJDIR	= ./obj/
all: obj $(FT_LIB) $(FT_MLX) $(NAME)
obj:
	mkdir -p $(OBJDIR)
$(COMP_MLX):
	@(cd $(FT_MLX) && $(MAKE) && cd ..)
$(OBJDIR)%.o:$(SRCDIR)%.c
	$(CC) $(CFLAGS) $(FT_INC) -I $(INCDIR) -o $@ -c $<
$(FT_LIB):
	make -C $(FT)
$(NAME): $(OBJ)
	$(CC) $(OBJ) $(FT_LNK) $(MLX_LNK) -lm -o $(NAME)
clean:
	rm -rf $(OBJDIR)
	make -C $(FT) clean
	make -C $(FT_MLX) clean
fclean: clean
	rm -rf $(NAME)
	make -C $(FT) fclean
	make -C $(FT_MLX) clean
re: fclean all
