/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_pars_l.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoureau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 22:33:19 by pcoureau          #+#    #+#             */
/*   Updated: 2020/02/25 22:33:21 by pcoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "keys.h"

int     rt_get_lratio(t_rtlist *lum, char *line)
{
    int i;

    i = 0;
    if (!line[i])
        return (1);
    lum->ratio = ft_atof(line);
    if (lum->ratio < 0.0 || lum->ratio > 1.0)
        return (1);
    lum->ratio_ok = 1;
    return (0);
}

int     rt_get_lcolor(t_rtlist *lum, char *line)
{
    int i;
    int r;
    int g;
    int b;
    char **tab;

    i = 0;
    if (!line[i])
        return (6);
    if (!(tab = ft_split(line, ',')))
        return (23);
    if (!tab[0] || !tab[1] || !tab[2])
        return (11);
    r = ft_atoi(tab[0]) * lum->ratio;
    g = ft_atoi(tab[1]) * lum->ratio;
    b = ft_atoi(tab[2]) * lum->ratio;
    ft_deltab(tab);
    if ((lum->color = rt_color(r, g, b)) < 0)
        return (22);
    return (0);
}


/*
int     rt_get_lcolor(t_rtlist *lum, char *line)
{
    int     i;

    i = 0;
    if (!line[i])
        return (1);
    lum->r = ft_atoi(line + i);
    while (line[i] && (line[i] >= '0' && line[i] <= '9'))
        i++;
    while (line[i] && (line[i] < '0' || line [i] > '9'))
        i++;
    if (!line[i])
        return (1);
    lum->g = ft_atoi(line + i);
    while (line[i] && (line[i] >= '0' && line[i] <= '9'))
        i++;
    while (line[i] && (line[i] < '0' || line [i] > '9'))
        i++;
    if (!line[i])
        return (1);
    lum->b = ft_atoi(line + i);
    lum->color = (rt_color(lum->r, lum->g, lum->b));
    return (0);
}
*/


int     rt_get_lcoor(t_rtlist *lum, char *line)
{
    int     i;

    i = 0;
    if (!line[i])
        return (1);
    lum->x = ft_atof(line + i);
    while (line[i] && ((line[i] >= '0' && line[i] <= '9') || line[i] == '-'))
        i++;
    while (line[i] && (line[i] < '0' || line [i] > '9') && line[i] != '-')
        i++;
    if (!line[i])
        return (1);
    lum->y = ft_atof(line + i);
    while (line[i] && ((line[i] >= '0' && line[i] <= '9') || line[i] == '-'))
        i++;
    while (line[i] && (line[i] < '0' || line [i] > '9') && line[i] != '-')
        i++;
    if (!line[i])
        return (1);
    lum->z = ft_atof(line + i);
    lum->coor_ok = 1;
    return (0);
}

int     rt_pars_l_ii(t_rtlist *lum, char *line)
{
    int i;
    int ret;

    i = 0;
    while (line[i] && (line[i] < '0' || line [i] > '9') && line[i] != '-')
        i++;
    if (rt_get_lcoor(lum, line + i))
        return (10);
    while (line[i] && ((line[i] >= '0' && line[i] <= '9') || line[i] == '-'
            || line[i] == ','))
        i++;
    while (line[i] && (line[i] < '0' || line [i] > '9'))
        i++;
    if (rt_get_lratio(lum, line + i))
        return (12);
    printf("---------------LE TEST DE LAMOUR <3<3<3\n|%s|\n----------END", line + i);
    while (line[i] && ((line[i] >= '0' && line[i] <= '9') || line[i] == '.'))
        i++;
    while (line[i] && (line[i] < '0' || line [i] > '9'))
        i++;
    if ((ret = rt_get_lcolor(lum, line + i)))
        return (ret);
    return (0);
}

int     rt_pars_l(t_mlx *mlx, char *line)
{
    t_rtlist *lum;
    t_rtlist *last;

    last = rt_lstlast(mlx->lum);
    if (!(lum = malloc(sizeof(t_rtlist))))
        return(13);
    lum->next = NULL;
    lum->type = 6;
    if (!last)
        mlx->lum = lum;
    else
        last->next = lum;
    return (rt_pars_l_ii(lum, line));
}