/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_putpix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoureau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 18:00:52 by pcoureau          #+#    #+#             */
/*   Updated: 2020/02/25 18:44:34 by pcoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "keys.h"


/*
void		rx(t_rtlist *vect, float x)
{
	t_rtlist	tmp;

	tmp.x = vect->x;
	tmp.y = vect->y * cos(x) - vect->z * sin(x);
	tmp.z = vect->y * sin(x) + vect->z * cos(x);
	*vect = tmp;
}

void		ry(t_rtlist *vect, float y)
{
	t_rtlist	tmp;

	tmp.x = vect->x * cos(y) + vect->z * sin(y);
	tmp.y = vect->y;
	tmp.z = vect->x * -sin(y) + vect->z * cos(y);
	*vect = tmp;
}

void		rz(t_rtlist *vect, float z)
{
	t_rtlist	tmp;

	tmp.x = vect->x * cos(z) - vect->y * sin(z);
	tmp.y = vect->x * sin(z) + vect->y * cos(z);
	tmp.z = vect->z;
	*vect = tmp;
}

void		rt_rot(t_rtlist *vect, t_rtlist *angle)
{
	rx(vect, angle->x);
	ry(vect, angle->y);
	rz(vect, angle->z);
}

void		rt_anti_rot(t_rtlist *vect, t_rtlist *angle)
{
	rz(vect, -angle->z);
	ry(vect, -angle->y);
	rx(vect, -angle->x);
}


float   rt_findobject(t_rtlist *obj, t_rtlist ray, float d)
{
    float   alpha;

    alpha = 0;
    if (obj->next)
        rt_findobject(obj->next, ray, alpha);
    if (alpha > d)
        alpha = d;
    return (alpha);
}
*/

int     rt_putpix(int i, int j, t_mlx *mlx, t_rtlist *cam)
{
    float       alpha; //c'est la distance
    t_rtlist    ray;

    ray.x = i - mlx->x / 2; // position du pixel
    ray.y = j - mlx->y / 2;
    ray.z = cam->fov;
    // Je crois qu'il faut que je gere la rotation de la camera ou je sais plus quoi
    //rt_rot(&ray, cam);
    //alpha = rt_findobject(mlx->obj, ray, MAX_DIST);
    mlx_pixel_put(mlx->ptr, mlx->win, i, j, mlx->lum_color);
    return (0);
}