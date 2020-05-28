/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_pars_r.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoureau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 21:53:32 by pcoureau          #+#    #+#             */
/*   Updated: 2020/02/25 21:53:34 by pcoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "keys.h"

int     rt_pars_r_ii(t_mlx *mlx)
{
    if (mlx->x < 0)
        mlx->x = 1;
    if (mlx->y < 0)
        mlx->y = 1;
    if (mlx->x > 1920)
        mlx->x = 1920;
    if (mlx->y > 1080)
        mlx->y = 1080;
    return (0);
}

int     rt_pars_r(t_mlx *mlx, char *line)
{
    int i;

    i = 0;
    if (mlx->x_ok && mlx->y_ok)
        return(20);
    while (line[i] && (line[i] < '0' || line[i] > '9'))
        i++;
    if (line[i])
    {
        mlx->x = ft_atoi(line + i);
        mlx->x_ok = 1;
    }
    else
        return (4);
    while (line[i] >= '0' && line[i] <= '9')
        i++;
    while (line[i] && (line[i] < '0' || line[i] > '9'))
        i++;
    if (line[i])
    {
        mlx->y = ft_atoi(line + i);
        mlx->y_ok = 1;
    }
    else
        return (4);
    return (rt_pars_r_ii(mlx));
}