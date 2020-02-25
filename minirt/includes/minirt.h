/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoureau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 18:02:37 by pcoureau          #+#    #+#             */
/*   Updated: 2020/02/25 18:34:22 by pcoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
#include <stdio.h>

/*
** type des objets:
** 1 sphere
** 2 plan
** 3 carre
** 4 cylindre
** 5 triangle
*/

typedef struct	s_list
{
	int				type;
	int				x;
	int				y;
	int				z;
	int				r;
	int				g;
	int				b;
	int				vx;
	int				vy;
	int				vz;
	int				diam;
	struct s_list	*next;
}				t_list;

typedef struct	s_mlx
{
	void	*ptr;
	void	*win;
	int		x;
	int		x_ok;
	int		y;
	int		y_ok;
	int		lum_a;
	int		lum_a_ok;
	int		lum_color;
	t_list	*obj;
	t_list	*lum;
}				t_mlx;
typedef int			(*t_funct)(t_mlx *mlx, char *line);
t_mlx			*rt_init();
int				rt_hook_keydown(int key, t_mlx *mlx);
#endif
