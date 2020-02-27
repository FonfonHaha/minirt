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
#include <fcntl.h>

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
int     rt_color(int r, int g, int b);
t_funct		rt_get_funct(char *s);
int     rt_get_objcoor(t_rtlist *obj, char *line);
typedef int			(*t_funct)(t_mlx *mlx, char *line);
int     rt_get_objvector(t_rtlist *obj, char *line);
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
#endif
