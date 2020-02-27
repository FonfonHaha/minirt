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

int     rt_get_cfov(t_mlx *mlx, char *line)
{
    int i;

    i = 0;
    if (!line[i])
        return (1);
    mlx->cfov = ft_atoi(line);
    mlx->cfov_ok = 1;
    return (0);
}

int     rt_get_cori(t_mlx *mlx, char *line)
{
    int     i;

    i = 0;
    if (!line[i])
        return (1);
    mlx->corix = ft_atof(line + i);
    while (line[i] && ((line[i] >= '0' && line[i] <= '9') || line[i] == '-'))
        i++;
    while (line[i] && (line[i] < '0' && line [i] > '9' && line[i] != '-'))
        i++;
    if (!line[i])
        return (1);
    mlx->coriy = ft_atof(line + i);
    while (line[i] && ((line[i] >= '0' && line[i] <= '9') || line[i] == '-'))
        i++;
    while (line[i] && (line[i] < '0' && line [i] > '9' && line[i] != '-'))
        i++;
    if (!line[i])
        return (1);
    mlx->coriz = ft_atof(line + i);
    mlx->cori_ok = 1;
    return (0);
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
            || line[i] == ','))
        i++;
    while (line[i] && (line[i] < '0' || line [i] > '9'))
        i++;
    if (rt_get_cfov(mlx, line + i))
        return (9);
    //printf("--------------TEST----------\n\nx %f\ny %f\nz %f\nvx %f\nvy %f\nvz %f\nfov %d\n\n\n---------------TEST-------------\n", mlx->cx, mlx->cy, mlx->cz, mlx->corix, mlx->coriy, mlx->coriz, mlx->cfov);
    return (0);
}