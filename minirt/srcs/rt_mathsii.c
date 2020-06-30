/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_mathsii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoureau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 18:00:52 by pcoureau          #+#    #+#             */
/*   Updated: 2020/02/25 18:44:34 by pcoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "keys.h"
#include <math.h>

void    getcoorinter(t_vect *p, t_mlx *mlx, float al)
{
    p->x = mlx->camu->x + mlx->vx * al;
    p->y = mlx->camu->y + mlx->vy * al;
    p->z = mlx->camu->z + mlx->vz * al;
}

void    newvect(t_vect *v, float x, float y, float z)
{
    v->x = x;
    v->y = y;
    v->z = z;
}

void    addvect(t_vect v, t_vect w, t_vect *d)
{
    t_vect tmp;

    tmp.x = v.x + w.x;
    tmp.y = v.y + w.y;
    tmp.z = v.z + w.z;
    *d = tmp;
}

void    prodvect(t_vect v, float n, t_vect *d)
{
    t_vect tmp;

    tmp.x = v.x * n;
    tmp.y = v.y * n;
    tmp.z = v.z * n;
    *d = tmp;
}

float   dist_p(t_vect p1, t_vect p2)
{
    return (sqrt((p2.x - p1.x) * (p2.x - p1.x)
        + (p2.y - p1.y) * (p2.y - p1.y)
        + (p2.z - p1.z) * (p2.z - p1.z)));
}