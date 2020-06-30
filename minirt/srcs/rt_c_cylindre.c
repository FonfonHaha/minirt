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

void    init_cy(t_rtlist *c, t_rtlist *obj)
{
    obj->va.x = c->x - obj->x;
    obj->va.y = c->y - obj->y;
    obj->va.z = c->z - obj->z;
    obj->y2 = prods(obj->va, obj->va);
    obj->z2 = obj->vx * obj->va.x + obj->vy * obj->va.y + obj->vz * obj->va.z;
}

float   c_cy_iii(float d[8], t_mlx *mlx, t_rtlist *obj)
{
    t_vect  temp0;
    t_vect  temp1;
    t_vect  point;
    t_vect  point_temp;
    float   denom;
    float   k;

    temp0.x = mlx->vx * d[4];
    temp0.y = mlx->vy * d[4];
    temp0.z = mlx->vz * d[4];
    point.x = mlx->camu->x + temp0.x;
    point.y = mlx->camu->y + temp0.y;
    point.z = mlx->camu->z + temp0.z;
    denom = -(obj->vx * obj->vc.x + obj->vy * obj->vc.y + obj->vz * obj->vc.z);
    d[5] = (obj->vx * point.x + obj->vy * point.y + obj->vz * point.z) + denom;
    temp1.x = obj->vx * -1;
    temp1.y = obj->vy * -1;
    temp1.z = obj->vz * -1;
    d[6] = obj->vx * temp1.x + obj->vy * temp1.y + obj->vz * temp1.z;
    k = - (d[5] / d[6]);
    temp0.x = temp1.x * k;
    temp0.y = temp1.y * k;
    temp0.z = temp1.z * k;
    addvect(point, temp0, &point_temp);
    d[3] = dist_p(point, point_temp);
    return (c_cy_iv(d, mlx, obj));
}

float   c_cy_ii(float ret, t_mlx *mlx, t_rtlist *obj)
{
    t_vect  temp;
    t_vect  point;
    t_vect  point_temp;
    float   denom;
    float   d[8];

    d[4] = ret;
    temp.x = mlx->vx * ret;
    temp.y = mlx->vy * ret;
    temp.z = mlx->vz * ret;
    point.x = mlx->camu->x + temp.x;
    point.y = mlx->camu->y + temp.y;
    point.z = mlx->camu->z + temp.z;
    denom = -(obj->vx * obj->vb.x + obj->vy * obj->vb.y + obj->vz * obj->vb.z);
    d[5] = (point.x * obj->vx + point.y * obj->vy + point.z * obj->vz) + denom;
    d[6] = obj->vx * obj->vx + obj->vy * obj->vy + obj->vz * obj->vz;
    d[7] = -(d[5] / d[6]);
    temp.x = obj->vx * d[7];
    temp.y = obj->vy * d[7];
    temp.z = obj->vz * d[7];
    point_temp.x = point.x + temp.x;
    point_temp.y = point.y + temp.y;
    point_temp.z = point.z + temp.z;
    d[2] = dist_p(point, point_temp);
    return (c_cy_iii(d, mlx, obj));
}

float   c_cylindre(t_rtlist *obj, t_mlx *mlx)
{
    float   cal_b;
    float   d[6];
    float   delta;
    float   ret;

    init_cy(mlx->camu, obj);
    cal_b = mlx->vx * obj->vx + mlx->vy * obj->vy + mlx->vz * obj->vz;
    d[0] = mlx->vx * mlx->vx + mlx->vy * mlx->vy + mlx->vz * mlx->vz
        - (cal_b * cal_b * obj->x2);
    d[1] = 2
        * (mlx->vx * obj->va.x + mlx->vy * obj->va.y + mlx->vz * obj->va.z)
        - (2 * cal_b * obj->x2 * obj->z2);
    d[2] = obj->y2 - ((obj->diam / 2) * (obj->diam / 2)) - (obj->z2 * obj->z2
        * obj->x2);
    if ((delta = (d[1] * d[1]) - (4 * d[0] * d[2])) < 0)
        return (-1);
    d[3] = (-d[1] + sqrt(delta)) / (2 * d[0]);
    d[4] = (-d[1] - sqrt(delta)) / (2 * d[0]);
    ret = (d[3] > d[4] ? d[4] : d[3]);
    return (c_cy_ii(ret, mlx, obj));
}
