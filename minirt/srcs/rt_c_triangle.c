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

float   c_hplan(t_vect *t, t_vect *tvn, t_mlx *mlx)
{
    t_vect c;
    float g;//si on valide le croisement ou non
    t_vect r;//ce quon utilise dans le calcul
    float al;

    c.x = mlx->vx;
    c.y = mlx->vy;
    c.z = mlx->vz;
    g = c.x * tvn->x + c.y * tvn->y + c.z * tvn->z;
    //printf("-------------------COUCOU TEST PLAN -----------\nxr = %f\nyr = %f\nzr = %f\novx = %f\novy = %f\novz = %f\nRESULAT g = %f\n",t->x, t->y, t->z, tvn->x, tvn->y, tvn->z, g);
    if (g == 0)
        return (-1);
    r.x = mlx->camu->x - t->x;
    r.y = mlx->camu->y - t->y;
    r.z = mlx->camu->z - t->z;
    al = -(r.x * tvn->x + r.y * tvn->y + r.z * tvn->z) / g;// = -((Lo - Po) . n)/g
    //printf("TEST---------------------------ALPHA TRIANGLE\n%f\n\n", al);
    return (al < 0 ? -1 : al);
}

float   trii(t_tr tri, float al, t_vect tv, t_mlx *mlx)
{
    t_vect p;
    t_vect s0;// cote 1, v0 v1
    t_vect s1;// cote 2, v1 v2
    t_vect s2;// cote 3, v2 v0
    t_vect p0;
    t_vect p1;
    t_vect p2;
    t_vect c0;
    t_vect c1;
    t_vect c2;

    getcoorinter(&p, mlx, al);
    getvect(&s0, tri.v0, tri.v1);
    getvect(&p0, tri.v0, p);
    prodv(&c0, s0, p0);
    getvect(&s1, tri.v1, tri.v2);
    getvect(&p1, tri.v1, p);
    prodv(&c1, s1, p1);
    getvect(&s2, tri.v2, tri.v0);
    getvect(&p2, tri.v2, p);
    prodv(&c2, s2, p2);
    if ((prods(tv, c0) < 0 && prods(tv, c1) < 0 && prods(tv, c2) < 0)
        || (prods(tv, c0) > 0 && prods(tv, c1) > 0 && prods(tv, c2) > 0))
        return (al);
    return (-1);
}

float   c_triangle(t_rtlist *obj, t_mlx *mlx)
{
    float al;
    t_vect t;//coordonnes plan triangle
    t_vect tv;//vecteur plan du triangle
    t_vect tvn;//la normale du vecteur plan triangle
    t_tr tri;
    t_vect ab;
    t_vect ac;

    t.x = obj->x;//on choppe les coordonnees du point A qui sont les coordonnes du plan du triangle
    t.y = obj->y;
    t.z = obj->z;
    getcoorp(&tri, obj);//on choppe les coordonnees de tous les points
    getvect(&ab, tri.v0, tri.v1);//on choppe le vecteur v0 v1
    getvect(&ac, tri.v0, tri.v2);//on choppe le vecteur v0 v2
    tv.x = ab.y * ac.z - ab.z * ac.y;//on choppe le vecteur du plan du triangle avec le produit vectoriel
    tv.y = -(ab.x * ac.z - ab.z * ac.x);
    tv.z = ab.x * ac.y - ab.y * ac.x;
    getnormale(&tvn, tv);//on choppe la normale
    //printf("TEST---------------------------ALPHA TRIANGLE\n%f\n%f\n%f\n%d\n", tvn.x, tvn.y, tvn.z, obj->r);
    al = c_hplan(&t, &tvn, mlx);
    return (al < 0 ? -1 : trii(tri, al, tvn, mlx));
    //return (al < 0 ? -1 : al);
}
