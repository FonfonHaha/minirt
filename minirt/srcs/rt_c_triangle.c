/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_c_triangle.c                                    :+:      :+:    :+:   */
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

float   c_triangle(t_rtlist *obj, t_mlx *mlx)
{
    float xr;//le vecteur camera
    float yr;
    float zr;
    float ovx;//le vecteur du plan
    float ovy;
    float ovz;
    float g;//si on valide le croisement ou non
    float rx;//ce quon utilise dans le calcul
    float ry;
    float rz;
    float al;
    float px;//coordonnees de l'intersection
    float py;
    float pz;

    xr = mlx->vx;
    yr = mlx->vy;
    zr = mlx->vz;
    
    ovx = obj->vx;
    ovy = obj->vy;
    ovz = obj->vz;
    g = xr * ovx + yr * ovy + zr * ovz;
    //printf("-------------------COUCOU TEST PLAN -----------\nxr = %f\nyr = %f\nzr = %f\novx = %f\novy = %f\novz = %f\nRESULAT g = %f\n",xr, yr, zr, ovx, ovy, ovz, g);
    if (g == 0)
        return (-1);
    rx = mlx->camu->x - obj->x;
    ry = mlx->camu->y - obj->y;
    rz = mlx->camu->z - obj->z;
    al = -(rx * obj->vx + ry * obj->vy + rz * obj->vz) / g;// = -((Lo - Po) . n)/g
    if (al < 0)
        return (-1);
    //camera + vecteur camera * al
    px = mlx->camu->x + mlx->vx * al;
    py = mlx->camu->y + mlx->vy * al;
    pz = mlx->camu->z + mlx->vx * al;
    //on a les coordonnees de p, maintenant on doit calculer l'air du triangle, si abc = abp + pbc + apc alors le triangle est croisé
    return (al);
}
