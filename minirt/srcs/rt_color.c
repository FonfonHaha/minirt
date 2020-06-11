/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoureau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 22:33:19 by pcoureau          #+#    #+#             */
/*   Updated: 2020/02/25 22:33:21 by pcoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "keys.h"

void    getcolorobj(t_mlx *mlx, t_rtlist *obj)
{
    mlx->or = obj->r;
    mlx->og = obj->g;
    mlx->ob = obj->b;
}

void    getcolorlum(t_mlx *mlx, t_rtlist *lum)
{
    mlx->r = lum->r > mlx->r ? lum->r : mlx->r;
    mlx->g = lum->g > mlx->g ? lum->g : mlx->g;
    mlx->b = lum->b > mlx->b ? lum->b : mlx->b;
}

void    getcolorf(t_mlx *mlx)
{
    if (mlx->al < 0)
        mlx->colorf = 0;
    else
    {
        mlx->r = (mlx->or * mlx->r) / 255;
        mlx->g = (mlx->og * mlx->g) / 255;
        mlx->b = (mlx->ob * mlx->b) / 255;
        mlx->colorf = rt_color(mlx->r, mlx->g, mlx->b);
    }
}

int     rt_notrange(int c)
{
    if (c < 0 || c > 255)
        return (1);
    return (0);
}

int     rt_color(int r, int g, int b)
{
    int color;

    color = 0;
    if (rt_notrange(r) || rt_notrange(g) || rt_notrange(b))
        return (-1);
    color = r * 65536 + g * 256 + b;
    return (color);
}