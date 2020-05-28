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


void    *rt_calculequationrayon(t_mlx *mlx, t_vect *vect, int x, int y)
{
    t_vect *v;

    if (vect)
        free(vect);
    if (!(v = malloc(sizeof(t_vect))))
        return (NULL);
    v->x = (x - mlx->x/2);
    v->y = (y - mlx->y/2);
    v->z = 70;
    return (v);
}

float calculsphere(t_rtlist *l, t_vect *v)
{
    float xr;//le rayon lancé depuis xr, yr, zr
    float yr;
    float zr;
    float a;//ce qu'on utilise dans le calcul
    float b;
    float c;
    float alpha;
    float alpha2;
    //dirigé par v
    xr = 0;
    yr = 0;
    zr = 0;
    a = ((v->x * v->x) + (v->y - v->y) + (v->z * v->z));
    b = 2 * (v->x * (xr - l-x) + v->y * (yr - l->y) + v->z * (zr - l->z));
    c = ((xr - l->x) * (xr - l->x) + (yr - l->y) * (yr - l->y) + (zr - l->z) * (zr - l->z) - l->diam * l->diam);
    if (((b*b) - (4*a*c)) < 0)
        return (-1);
    alpha = (-b + sqrtf((b*b) - (4*a*c))) / 2 * a;
    alphaii =  (-b - sqrtf((b*b) - (4*a*c))) / 2 * a;
    if (alpha < alphaii)
        return (alpha);
    else
        return (alphaii);
}

float   findobject(t_rtlist *listeobjets, t_vect *v)
{
    float   retalpha;
    float   retalphaii;

    if (listeobjets->next)
        retalpha = findobject(listeobjets->next, v);
    else
        retalpha = -1;
    if (listeobjets->type == 1)
        if ((retalphaii = calculsphere(listeobjets, v)) < 0)
            return (retalpha);
    else
        return (retalpha)
    if (retalphaii >= 0 && (retalpha > retalphaii || retalpha == -1))
        return (retalphaii);
    else
        return (retalpha);
}

void    rt_putpixel_ii(t_mlx *mlx, t_rtlist *listeobjets, t_vect *v)
{
    float alpha;

    alpha = -1;
    alpha = findobject(listeobjets, v, alpha);
	if (alpha >= 0)
        mlx_pixel_put(mlx->ptr, mlx->win, x, y, 0xFFFFFF);
    else
        mlx_pixel_put(mlx->ptr, mlx->win, x, y, 0x000000);
}

int    rt_putpixel(t_mlx *mlx)
{
    int x;
    int y;
    t_vect *vect;
    t_rtlist *listeobjets

    x = 0;
    vect = NULL;
    //sphere = sp 0,0,20 20 255,0,0
    listeobjets = mlx->obj;
    while (x < mlx->x)
    {
        y = 0;
        while (y < mlx->y)
        {
            if (!(vect = rt_calculequationrayon(mlx, vect, x, y)))
                return (1);
            ft_printf("---------VECTOR\nvx = %d\nvy = %d\nvz = %d\n---------VECTOR END\n", vect->x, vect->y, vect->z);
            mlx_pixel_put(mlx->ptr, mlx->win, x, y, 0xFFFFFF);
            rt_putpixel_ii(mlx, listeobjets, vect);
            y++;
        }
        x++;
    }
    if (vect)
        free(vect);
    return (0);
}