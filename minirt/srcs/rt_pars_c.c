/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_pars_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoureau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 22:33:19 by pcoureau          #+#    #+#             */
/*   Updated: 2020/02/25 22:33:21 by pcoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "keys.h"

int     rt_get_cfov(t_rtlist *cam, char *line, t_mlx *mlx)
{
    int i;

    i = 0;
    if (!line[i])
        return (1);
    if ((cam->z3 = ft_atoi(line)) < 0 || cam->z3 > 180)
        return (24);
    mlx->cfov_ok = 1;
    return (0);
}

int     rt_get_cori_ii(t_rtlist *cam)
{
    if (cam->x2 < - 1.0 || cam->x2 > 1.0)
        return (26);
    if (cam->y2 < - 1.0 || cam->y2 > 1.0)
        return (26);
    if (cam->z2 < - 1.0 || cam->z2 > 1.0)
        return (26);
    printf("\n\n-------------TEST------------------- %f\n\n", cam->y2);
    return (0);
}

int     rt_get_cori(t_rtlist *cam, char *line, t_mlx *mlx)
{
    int     i;

    i = 0;
    if (!line[i])
        return (1);
    
    cam->x2 = ft_atof(line + i);
    while (line[i] && ((line[i] >= '0' && line[i] <= '9') || line[i] == '-'
            || line[i] == '.'))
        i++;
    while (line[i] && (line[i] < '0' || line [i] > '9') && line[i] != '-')
        i++;
    if (!line[i])
        return (1);
    cam->y2 = ft_atof(line + i);
    while (line[i] && ((line[i] >= '0' && line[i] <= '9') || line[i] == '-'
            || line[i] == '.'))
        i++;
    while (line[i] && (line[i] < '0' || line [i] > '9') &&  line[i] == '-')
        i++;
    if (!line[i])
        return (1);
    cam->z2 = ft_atof(line + i);
    mlx->cori_ok = 1;
    return (rt_get_cori_ii(cam));
}

int     rt_get_ccoor(t_rtlist *cam, char *line, t_mlx *mlx)
{
    int     i;

    i = 0;
    if (!line[i])
        return (1);
    cam->x = ft_atof(line + i);
    while (line[i] && ((line[i] >= '0' && line[i] <= '9') || line[i] == '-'))
        i++;
    while (line[i] && (line[i] < '0' && line [i] > '9' && line[i] != '-'))
        i++;
    if (!line[i])
        return (1);
    cam->y = ft_atof(line + i);
    while (line[i] && ((line[i] >= '0' && line[i] <= '9') || line[i] == '-'))
        i++;
    while (line[i] && (line[i] < '0' && line [i] > '9' && line[i] != '-'))
        i++;
    if (!line[i])
        return (1);
    cam->z = ft_atof(line + i);
    mlx->ccoor_ok = 1;
    return (0);
}

int     rt_pars_c_ii(t_rtlist *cam, char *line, t_mlx *mlx)
{
    int i;

    i = 0;
    while (line[i] && (line[i] < '0' || line [i] > '9') && line[i] != '-')
        i++;
    if (rt_get_ccoor(cam, line + i, mlx))
        return (7);
    while (line[i] && ((line[i] >= '0' && line[i] <= '9') || line[i] == '-'
            || line[i] == ','))
        i++;
    while (line[i] && (line[i] < '0' || line [i] > '9') && line[i] != '-')
        i++;
    if (rt_get_cori(cam, line + i, mlx))
        return (8);
    while (line[i] && ((line[i] >= '0' && line[i] <= '9') || line[i] == '-'
            || line[i] == ',' || line[i] == '.'))
        i++;
    while (line[i] && (line[i] < '0' || line [i] > '9')  && line[i] != '-')
        i++;
    printf("\n\n-------------TEST------------------- caca%s %d\n\n", line + i, i);
    if (rt_get_cfov(cam, line + i, mlx))
        return (9);
    printf("--------------TEST----------\n\nx %f\ny %f\nz %f\nvx %f\nvy %f\nvz %f\nfov %d\n\n\n---------------TEST-------------\n", mlx->cx, mlx->cy, mlx->cz, mlx->corix, mlx->coriy, mlx->coriz, mlx->cfov);
    return (0);
}

int     rt_pars_c(t_mlx *mlx, char *line)
{
    t_rtlist *cam;
    t_rtlist *last;

    last = rt_lstlast(mlx->cam);
    if (!(cam = malloc(sizeof(t_rtlist))))
        return (13);
    cam->next = NULL;
    cam->type = 7;
    if (!last)
        mlx->cam = cam;
    else
        last->next = cam;
    return (rt_pars_c_ii(cam, line, mlx));
}