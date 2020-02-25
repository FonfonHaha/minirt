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

int     ft_puis(int n, int m)
{
    int r;

    r = 1;
    while (m)
    {
        r = r * n;
        m--;
    }
    return (r);
}

int     rt_past_a_ii(t_mlx *mlx, char *line)
{
    int i;
    int n;

    i = 0;
    n = 0;
    if (!line[i])
        return (6);
    mlx->lum_color = ft_atoi(line + i) * ft_puis(2, 16);
    while (line[i] && (line[i] >= '0' || line[i] <= '9'))
        i++;
    while (line[i] && (line[i] < '0' || line[i] > '9'))
        i++;
    if (!line[i])
        return (6);
    mlx->lum_color = mlx->lum_color + ft_atoi(line + i) * ft_puis(2, 8);
    while (line[i] && (line[i] >= '0' || line[i] <= '9'))
        i++;
    while (line[i] && (line[i] < '0' || line[i] > '9'))
        i++;
    if (!line[i])
        return (6);
    mlx->lum_color = mlx->lum_color + ft_atoi(line + i) * ft_puis(2, 0);
    return (0); 
}

int     rt_past_a(t_mlx *mlx, char *line)
{
    int i;

    i = 0;
    while (line[i] && (line[i] < '0' || line[i] > '9'))
        i++;
    if (line[i])
    {
        mlx->lum_a = ft_atof(line + i);
        mlx->lum_a_ok = 1;
    }
    else
        return (5);
    while (line[i] && ((line[i] >= '0' || line[i] <= '9') || line[i] == '.'))
        i++;
    while (line[i] && (line[i] < '0' || line[i] > '9'))
        i++;
    return (rt_past_a_ii(mlx, line + i));
}