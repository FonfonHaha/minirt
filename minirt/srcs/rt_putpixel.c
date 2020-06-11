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

void     rt_equray(t_mlx *mlx)
{
    mlx->vx = (mlx->px - mlx->x/2);
    mlx->vy = (mlx->py - mlx->y/2);
    mlx->vz = mlx->camu->z3 * (mlx->x > mlx->y ? mlx->x : mlx->y) / 180;
    //APPLIQUER LES ROTATIONS
}

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

float   findobject(t_mlx *mlx, t_rtlist *obj)
{
    float   retal;
    float   retalii;

    if (obj->next)
        retal = findobject(mlx, obj->next);
    else
        retal = -1;
    if (obj->type == 1)
    {
        if ((retalii = c_sphere(obj, mlx)) < 0)
            return (retal);
    }
    else
        return (retal);
    if (retalii >= 0 && (retal > retalii || retal == -1))
    {
        getcolorobj(mlx, obj);
        return (retalii);
    }
    else
        return (retal);
}

void    rt_putpixel_ii(t_mlx *mlx)
{
    mlx->colorf = 0;
    mlx->al = -1;
    mlx->al = findobject(mlx, mlx->obj);
    getcolorf(mlx);
    mlx_pixel_put(mlx->ptr, mlx->win, mlx->px, mlx->py, mlx->colorf);
}

int     rt_putpixel(t_mlx *mlx)
{
    mlx->py = 0;
    while (mlx->py < mlx->y)
    {
        mlx->px = 0;
        while (mlx->px < mlx->x)
        {
            mlx->r = mlx->lumr;
            mlx->g = mlx->lumg;
            mlx->b = mlx->lumb;
            rt_equray(mlx);
            rt_putpixel_ii(mlx);
            mlx->px++;
        }
        mlx->py++;
    }
    return (0);
}