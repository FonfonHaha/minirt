/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_pars_a.c                                        :+:      :+:    :+:   */
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
int     rt_past_a_ii(t_mlx *mlx, char *line)
{
    int i;
    int n;

    i = 0;
    n = 0;
    if (!line[i])
        return (6);
    mlx->lum_color = ft_atoi(line + i) * ft_puis(2, 16);
    while (line[i] && (line[i] >= '0' && line[i] <= '9'))
        i++;
    while (line[i] && (line[i] < '0' || line[i] > '9'))
        i++;
    if (!line[i])
        return (6);
    mlx->lum_color = mlx->lum_color + ft_atoi(line + i) * ft_puis(2, 8);
    while (line[i] && (line[i] >= '0' && line[i] <= '9'))
        i++;
    while (line[i] && (line[i] < '0' || line[i] > '9'))
        i++;
    if (!line[i])
        return (6);
    mlx->lum_color = mlx->lum_color + ft_atoi(line + i) * ft_puis(2, 0);
    mlx->lum_a_ok = 1;
    return (0); 
}
*/

int     rt_pars_a_ii(t_mlx *mlx, char *line)
{
    int i;
    char **tab;

    i = 0;
    if (!line[i])
        return (6);
    if (!(tab = ft_split(line, ',')))
        return (23);
    if (!tab[0] || !tab[1] || !tab[2])
        return (11);
    mlx->lumr = ft_atoi(tab[0]) * mlx->lum_a;
    mlx->lumg = ft_atoi(tab[1]) * mlx->lum_a;
    mlx->lumb = ft_atoi(tab[2]) * mlx->lum_a;
    ft_deltab(tab);
    if ((mlx->lum_color = rt_color(mlx->lumr, mlx->lumg, mlx->lumb)) < 0)
        return (22);
    mlx->lum_a_ok = 1;
    return (0);
}

int     rt_pars_a(t_mlx *mlx, char *line)
{
    int i;

    i = 0;
    if (mlx->lum_a_ok)
        return (21);
    while (line[i] && (line[i] < '0' || line[i] > '9'))
        i++;
    if (line[i])
    {
        mlx->lum_a = ft_atof(line + i);
        if (mlx->lum_a < 0.0 || mlx->lum_a > 1.0)
            return (25);
        mlx->lum_a_ok = 1;
    }
    else
        return (5);
    while (line[i] && ((line[i] >= '0' && line[i] <= '9') || line[i] == '.'))
        i++;
    while (line[i] && (line[i] < '0' || line[i] > '9') && line[i] != '-')
        i++;
    return (rt_pars_a_ii(mlx, line + i));
}
