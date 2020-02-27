/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoureau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 17:45:04 by pcoureau          #+#    #+#             */
/*   Updated: 2020/02/25 18:31:34 by pcoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "minirt.h"
#include "keys.h"
#include <mlx.h>
#include "minirt.h"
#include "libft.h"

char	*g_err = NULL;
void	checkobj_sp(t_rtlist *lst)
{
	printf("sphere\n%f %f %f\ndia %f rgb %x\n", lst->x, lst->y, lst->z, lst->diam, lst->color);
}
void	plane(t_rtlist *lst)
{
	printf("plane\n%f %f %f\nv: %f %f %f\nrgb %x\n", lst->x, lst->y, lst->z, lst->vx, lst->vy, lst->vz, lst->color);
}
void	square(t_rtlist *lst)
{
	printf("square\n%f %f %f\nv: %f %f %f\nh%f rgb %x\n", lst->x, lst->y, lst->z, lst->vx, lst->vy, lst->vz, lst->h, lst->color);
}
void	cy(t_rtlist *lst)
{
	printf("cy\n%f %f %f\nv: %f %f %f\ndia %f h %f rgb %x\n", lst->x, lst->y, lst->z, lst->vx, lst->vy, lst->vz, lst->diam, lst->h, lst->color);
}
void	triangle(t_rtlist *lst)
{
	printf("triangle\n1: %f %f %f\n2: %f %f %f\n3: %f %f %f\nrgb %x\n", lst->x, lst->y, lst->z, lst->x2, lst->y2, lst->z2, lst->x3, lst->y3, lst->z3, lst->color);
}
void	checkobj(t_rtlist *lst)
{
	if (!lst)
		return ;
	if (lst->type == 1)
		checkobj_sp(lst);
	if (lst->type == 2)
		plane(lst);
	if (lst->type == 3)
		square(lst);
	if (lst->type == 4)
		cy(lst);
	if (lst->type == 5)
		triangle(lst);
	checkobj(lst->next);
}
void	checklum(t_rtlist *lst)
{
	if (!lst)
		return ;
	printf("lum\n%f %f %f\nint: %f rgb: %x\n", lst->x, lst->y, lst->z, lst->ratio, lst->color);
	checklum(lst->next);
}
void	check(t_mlx *mlx)
{
	printf("%p\n%p\na %f r %d rgb %x x %d y %d\ncam:%f %f %f\n%f %f %f\n%d\n", mlx->ptr, mlx->win, mlx->lum_a, mlx->x_ok, mlx->lum_color, mlx->x, mlx->y, mlx->cx, mlx->cy, mlx->cz, mlx->corix, mlx->coriy, mlx->coriz, mlx->cfov);
	checkobj(mlx->obj);
	checklum(mlx->lum);
}
int		main(int ac, char **av)
{
	t_mlx	*mlx;
	mlx = NULL;
	(void)av;
	if (ac != 2 && ac != 3)
		return (0);
	if (ac == 2)
	{
		if (!(mlx = rt_init(av[1])))
			return (0);
		check(mlx);
		mlx_key_hook(mlx->win, rt_hook_keydown, mlx->ptr);
		mlx_loop(mlx->ptr);
	}
	return (0);
}