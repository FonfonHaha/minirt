/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_c_cylindre.c                                    :+:      :+:    :+:   */
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

float   c_cy_v(float d[8], t_mlx *mlx, t_rtlist *obj)
{
    t_vect  temp;
    t_vect  point;
    float   denom;
    float   l[2];

    denom = -(obj->vx * obj->vc.x + obj->vy * obj->vc.y + obj->vz * obj->vc.z);
    l[0] = (mlx->camu->x * obj->vx + mlx->camu->y
        * obj->vy + mlx->camu->z * obj->vz) + denom;
    l[1] = (mlx->vx * obj->vx + mlx->vy * obj->vy + mlx->vz * obj->vz);
    if ((d[5] = -(l[0] / l[1])) > 0)
    {
        temp.x = d[5] * mlx->vx;
        temp.y = d[5] * mlx->vy;
        temp.z = d[5] * mlx->vz;
        point.x = mlx->camu->x + temp.x;
        point.y = mlx->camu->y + temp.y;
        point.z = mlx->camu->z + temp.z;
        d[0] = dist_p(point, obj->vc);
        d[1] = sqrt((mlx->camu->x - point.x) * (mlx->camu->x - point.x)
            + (mlx->camu->y - point.y) * (mlx->camu->y - point.y)
            + (mlx->camu->z - point.z) * (mlx->camu->z - point.z));
        if (d[0] < (obj->diam / 2) && (!(d[2] > obj->h || d[3] > obj->h)))
            return (d[4]);
        if (d[0] < (obj->diam / 2))
            return (d[5]);
    }
    if (d[2] > obj->h || d[3] > obj->h)
        return (-1);
    return (d[4]);
}

float   c_cy_iv(float d[8], t_mlx *mlx, t_rtlist *obj)
{
    t_vect  temp;
    t_vect  point;
    float   denom;
    float   l[2];

    denom = -(obj->vx * obj->vb.x + obj->vy * obj->vb.y + obj->vz * obj->vb.z);
    l[0] = (mlx->camu->x * obj->vx + mlx->camu->y
        * obj->vy + mlx->camu->z * obj->vz) + denom;
    l[1] = (mlx->vx * obj->vx + mlx->vy * obj->vy + mlx->vz * obj->vz);
    if ((d[5] = -(l[0] / l[1])) > 0)
    {
        temp.x = d[5] * mlx->vx;
        temp.y = d[5] * mlx->vy;
        temp.z = d[5] * mlx->vz;
        point.x = mlx->camu->x + temp.x;
        point.y = mlx->camu->y + temp.y;
        point.z = mlx->camu->z + temp.z;
        d[0] = dist_p(point, obj->vb);
        d[1] = sqrt((mlx->camu->x - point.x) * (mlx->camu->x - point.x)
            + (mlx->camu->y - point.y) * (mlx->camu->y - point.y)
            + (mlx->camu->z - point.z) * (mlx->camu->z - point.z));
        if (d[0] < (obj->diam / 2) && (!(d[2] > obj->h || d[3] > obj->h)))
            return (d[4]);
        if (d[0] < (obj->diam / 2))
            return (d[5]);
    }
    return (c_cy_v(d, mlx, obj));
}