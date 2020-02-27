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
** 6 lumiere
*/

typedef struct	s_list
{
	int				type;
	int				x;
	int				x2;
	int				x3;
	int				y;
	int				y2;
	int				y3;
	int				z;
	int				z2;
	int				z3;
	int				coor_ok;
	int				r;
	int				g;
	int				b;
	int				color;
	int				vx;
	int				vy;
	int				vz;
	int				v_ok;
	int				ratio;
	int				ratio_ok;
	int				diam;
    int             h;
	struct s_list	*next;
}				t_rtlist;

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
	float	cx;
	float	cy;
	float	cz;
	int		ccoor_ok;
	float	corix;
	float	coriy;
	float	coriz;
	int		cori_ok;
	int		cfov;
	int		cfov_ok;
	t_rtlist	*obj;
	t_rtlist	*lum;
}				t_mlx;
typedef int			(*t_funct)(t_mlx *mlx, char *line);
t_mlx			*rt_init();
int				rt_hook_keydown(int key, t_mlx *mlx);
#endif
