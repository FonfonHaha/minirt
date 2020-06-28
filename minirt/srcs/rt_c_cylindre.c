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

void    init_cy(t_rtlist c, t_rtlist *obj)
{
    obj->va.x = c.x - obj->x;
    obj->va.y = c.x - obj->y;
    obj->va.z = c.x - obj->z;
    obj->y2 = prods(obj->va, obj->va);
    obj->z2 = obj->vx * obj->va.x + obj->vy * obj->va.y + obj->vz * obj->va.z;
}

float   c_cylindre(t_rtlist *obj, t_mlx *mlx)
{
    float   cal_b;
    float   d[6];
    float   delta;
    float   ret;

    init_cy(mlx->camu, obj);
}
