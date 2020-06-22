/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_maths.c                                         :+:      :+:    :+:   */
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

void    getvect(t_vect *v, t_vect a, t_vect b)
{
    v->x = b.x - a.x;
    v->y = b.y - a.y;
    v->z = b.z - a.z;
}

void    getcoorp(t_tr *tri, t_rtlist *obj)
{
    tri->v0.x = obj->x;
    tri->v0.y = obj->y;
    tri->v0.z = obj->z;
    tri->v1.x = obj->x2;
    tri->v1.y = obj->y2;
    tri->v1.z = obj->z2;
    tri->v2.x = obj->x3;
    tri->v2.y = obj->y3;
    tri->v2.z = obj->z3;
}

void    getnormale(t_vect *tvn, t_vect t)
{
    float n;
    float x;
    float y;
    float z;

    x = t.x < 0 ? t.x * -1 : t.x;
    y = t.y < 0 ? t.y * -1 : t.y;
    z = t.z < 0 ? t.z * -1 : t.z;
    n = t.z;
    if (x > y && x > z)
        n = t.x;
    else if (y > z)
        n = t.y;
    tvn->x = t.x / n;
    tvn->y = t.y / n;
    tvn->z = t.z / n;
}

void    prodv(t_vect *c, t_vect s, t_vect p)
{
    c->x = s.y * p.z - s.z * p.y;
    c->y = - (s.x * p.z - s.z * p.x);
    c->z = s.x * p.y - s.y * p.x;
}

float   prods(t_vect tvn, t_vect c)
{
    return (c.x * tvn.x + c.y * tvn.y + c.z * tvn.z);
}