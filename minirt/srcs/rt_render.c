/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoureau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 18:00:52 by pcoureau          #+#    #+#             */
/*   Updated: 2020/02/25 18:44:34 by pcoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "keys.h"

int     rt_render(t_mlx *mlx)
{
    int i;
    int j;
    t_rtlist *camera;

    i = 0;
    j = 0;
    camera = mlx->cam;
    while (j <= mlx->y)
    {
        i = 0;
        while(i <= mlx->x)
        {
            if (rt_putpix(i, j, mlx, camera))
                return(1);
            i++;
        }
        j++;
    }
    return (0);
}