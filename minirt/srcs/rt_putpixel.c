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