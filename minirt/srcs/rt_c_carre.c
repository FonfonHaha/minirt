/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_c_carre.c                                       :+:      :+:    :+:   */
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

float   c_carreii(float ret, t_rtlist *obj, t_mlx *mlx)
{
    t_vect temp;
    t_vect point;
    t_vect ap;
    float alpha;
    float beta;

    temp.x = ret * mlx->vx;
    temp.y = ret * mlx->vy;
    temp.z = ret * mlx->vz;
    point.x = temp.x + mlx->camu->x;
    point.y = temp.y + mlx->camu->y;
    point.z = temp.z + mlx->camu->z;
    //printf("ax = %f\nay = %f\naz = %f\n", obj->ac.x, obj->ac.y, obj->ac.z);
    ap.x = point.x - obj->va.x;
    ap.y = point.y - obj->va.y;
    ap.z = point.z - obj->va.z;
    alpha = prods(ap, obj->ab) / prods(obj->ab, obj->ab);
    beta = prods(ap, obj->ac) / prods(obj->ac, obj->ac);
    if (alpha >= 0 && alpha <= 1 && beta >= 0 && beta <= 1)
        return (ret);
    return (-1);
}

float   c_carre(t_rtlist *obj, t_mlx *mlx)
{
    float d;
    float calcula;
    float alpha;
    float beta;

    d = -(obj->vx * obj->x + obj->vy * obj->y + obj->vz * obj->z);
    calcula = obj->vx * mlx->camu->x + obj->vy * mlx->camu->y
        + obj->vz * mlx->camu->z + d;
    alpha = mlx->vx * obj->vx + mlx->vy * obj->vy + mlx->vz * obj->vz;
    beta = -(calcula / alpha);
    //printf("TEST CARRE TEST CARRE----------\ncamx %f\ncamy %f\n camz %f\nnx %f\nny %f\nnz %f\n\nalpha : %f\n\ncalcula = %f\nbeta = %f\n\n\n", mlx->vx, mlx->vy, mlx->vz, obj->vx, obj->vy, obj->vz, alpha, calcula, beta);
    //if (mlx->px == 960 && mlx->py == 540)
      //  while (1);
    if (beta <= 0)
        return (-1);
    return (c_carreii(beta, obj, mlx));
}
