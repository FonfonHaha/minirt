/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_putpixel.c                                      :+:      :+:    :+:   */
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

float   c_sphere(t_rtlist *obj, t_mlx *mlx)
{
    float xr;//le rayon lancé depuis xr, yr, zr
    float yr;
    float zr;
    float a;//ce qu'on utilise dans le calcul
    float b;
    float c;
    float alpha;
    float alphaii;

    xr = mlx->camu->x;
    yr = mlx->camu->y;
    zr = mlx->camu->z;
    a = ((mlx->vx * mlx->vx) + (mlx->vy * mlx->vy) + (mlx->vz * mlx->vz));
    b = 2 * (mlx->vx * (xr - obj->x) + mlx->vy * (yr - obj->y) + mlx->vz * (zr - obj->z));
    c = ((xr - obj->x) * (xr - obj->x) + (yr - obj->y) * (yr - obj->y) + (zr - obj->z) * (zr - obj->z) - obj->diam * obj->diam);
    if (((b*b) - (4*a*c)) < 0)
        return (-1);
    alpha = (-b + sqrtf((b*b) - (4*a*c))) / 2 * a;
    alphaii =  (-b - sqrtf((b*b) - (4*a*c))) / 2 * a;
    return (alpha < alphaii ? alpha : alphaii);
}
