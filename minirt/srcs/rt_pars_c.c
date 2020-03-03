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
/*
int     rt_get_cfov(t_mlx *mlx, char *line)
{
    int i;

    i = 0;
    if (!line[i])
        return (1);
    if ((mlx->cfov = ft_atoi(line)) < 0 || mlx->cfov > 180)
        return (24);
    mlx->cfov_ok = 1;
    return (0);
}

int     rt_get_cori_ii(t_mlx *mlx)
{
    if (mlx->corix < - 1.0 || mlx->corix > 1.0)
        return (26);
    if (mlx->coriy < - 1.0 || mlx->coriy > 1.0)
        return (26);
    if (mlx->coriz < - 1.0 || mlx->coriz > 1.0)
        return (26);
    printf("\n\n-------------TEST------------------- %f\n\n", mlx->coriy);
    return (0);
}

int     rt_get_cori(t_mlx *mlx, char *line)
{
    int     i;

    i = 0;
    if (!line[i])
        return (1);
    
    mlx->corix = ft_atof(line + i);
    while (line[i] && ((line[i] >= '0' && line[i] <= '9') || line[i] == '-'
            || line[i] == '.'))
        i++;
    while (line[i] && (line[i] < '0' || line [i] > '9') && line[i] != '-')
        i++;
    if (!line[i])
        return (1);
    mlx->coriy = ft_atof(line + i);
    while (line[i] && ((line[i] >= '0' && line[i] <= '9') || line[i] == '-'
            || line[i] == '.'))
        i++;
    while (line[i] && (line[i] < '0' || line [i] > '9') &&  line[i] == '-')
        i++;
    if (!line[i])
        return (1);
    mlx->coriz = ft_atof(line + i);
    if (mlx->corix == 0 && mlx->coriy == 0 && mlx->coriz == 0)
        return (1);
    mlx->cori_ok = 1;
    return (rt_get_cori_ii(mlx));
}

int     rt_get_ccoor(t_mlx *mlx, char *line)
{
    int     i;

    i = 0;
    if (!line[i])
        return (1);
    mlx->cx = ft_atof(line + i);
    while (line[i] && ((line[i] >= '0' && line[i] <= '9') || line[i] == '-'))
        i++;
    while (line[i] && (line[i] < '0' && line [i] > '9' && line[i] != '-'))
        i++;
    if (!line[i])
        return (1);
    mlx->cy = ft_atof(line + i);
    while (line[i] && ((line[i] >= '0' && line[i] <= '9') || line[i] == '-'))
        i++;
    while (line[i] && (line[i] < '0' && line [i] > '9' && line[i] != '-'))
        i++;
    if (!line[i])
        return (1);
    mlx->cz = ft_atof(line + i);
    mlx->ccoor_ok = 1;
    return (0);
}

int     rt_pars_c(t_mlx *mlx, char *line)
{
    int i;

    i = 0;
    while (line[i] && (line[i] < '0' || line [i] > '9') && line[i] != '-')
        i++;
    if (rt_get_ccoor(mlx, line + i))
        return (7);
    while (line[i] && ((line[i] >= '0' && line[i] <= '9') || line[i] == '-'
            || line[i] == ','))
        i++;
    while (line[i] && (line[i] < '0' || line [i] > '9') && line[i] != '-')
        i++;
    if (rt_get_cori(mlx, line + i))
        return (8);
    while (line[i] && ((line[i] >= '0' && line[i] <= '9') || line[i] == '-'
            || line[i] == ',' || line[i] == '.'))
        i++;
    while (line[i] && (line[i] < '0' || line [i] > '9')  && line[i] != '-')
        i++;
    printf("\n\n-------------TEST------------------- caca%s %d\n\n", line + i, i);
    if (rt_get_cfov(mlx, line + i))
        return (9);
    printf("--------------TEST----------\n\nx %f\ny %f\nz %f\nvx %f\nvy %f\nvz %f\nfov %d\n\n\n---------------TEST-------------\n", mlx->cx, mlx->cy, mlx->cz, mlx->corix, mlx->coriy, mlx->coriz, mlx->cfov);
    return (0);
}

*/

int     rt_pars_c_ii(t_rtlist *cam, char **tab)
{
    (void)tab;
    (void)cam;
    return (0);
}

int     rt_pars_c(t_mlx *mlx, char *line)
{
    int         ret;
    char        **tab;
    t_rtlist    *cam;
    t_rtlist    *last;

    last = rt_lstlast(mlx->cam);
    if (!(cam = malloc(sizeof(t_rtlist))))
        return(13);
    cam->next = NULL;
    cam->type = 7;
    if (!last)
        mlx->cam = cam;
    else
        last->next = cam;
    if (!(tab = ft_split(line, ' ')))
        return (14);
    ret = rt_pars_c_ii(cam, tab);
    tab = ft_deltab(tab);
    mlx->cfov_ok = 1;
    return (ret);
}