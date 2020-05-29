/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoureau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 18:02:37 by pcoureau          #+#    #+#             */
/*   Updated: 2020/02/27 20:19:22 by pcoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../minilibx-linux/mlx.h"

/*
** type des objets:
** 1 sphere
** 2 plan
** 3 carre
** 4 cylindre
** 5 triangle
** 6 lumiere
*/

typedef struct	s_rtlist
{
	int				type;
	float				x;
	float				x2;
	float				x3;
	float				y;
	float				y2;
	float				y3;
	float				z;
	float				z2;
	float				z3;
	int				coor_ok;
	int				r;
	int				g;
	int				b;
	int				color;
	float				vx;
	float				vy;
	float				vz;
	int				v_ok;
	float				ratio;
	int				ratio_ok;
	float				diam;
    float             h;
	struct s_rtlist	*next;
}				t_rtlist;

typedef struct	s_vect
{
	float x;
	float y;
	float z;
}	t_vect;

typedef struct	s_mlx
{
	void	*ptr;
	void	*win;
	int		x;
	int		x_ok;
	int		y;
	int		y_ok;
	float		lum_a;
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

int     rt_color(int r, int g, int b);
int     rt_get_objcoor(t_rtlist *obj, char *line);
typedef int			(*t_funct)(t_mlx *mlx, char *line);
t_funct			rt_get_funct(char *s);
int     rt_get_objvector(t_rtlist *obj, char *line);
t_rtlist	*rt_lstlast(t_rtlist *lst);
int     rt_get_objcolor(t_rtlist *obj, char *line);
int     rt_pars_a(t_mlx *mlx, char *line);
int     rt_pars_bn(t_mlx *mlx, char *line);
int     rt_pars_c(t_mlx *mlx, char *line);
int     rt_pars_cy(t_mlx *mlx, char *line);
int     rt_pars_l(t_mlx *mlx, char *line);
int     rt_pars_pl(t_mlx *mlx, char *line);
int     rt_pars_r(t_mlx *mlx, char *line);
int     rt_pars_sp(t_mlx *mlx, char *line);
int     rt_pars_sq(t_mlx *mlx, char *line);
int     rt_pars_tr(t_mlx *mlx, char *line);
int		rt_pars(t_mlx *mlx, const char *str);
t_mlx			*rt_init(const char *str);
int				rt_hook_keydown(int key, t_mlx *mlx);
int    rt_putpixel(t_mlx *mlx);
#endif
