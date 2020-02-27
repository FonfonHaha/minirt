/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoureau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 18:00:52 by pcoureau          #+#    #+#             */
/*   Updated: 2020/02/25 18:44:34 by pcoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "keys.h"

/*
** 	codes d'erreur retour rt_pars :
**	1 = erreur open
**	2 = gnl retour -1
**	3 = get funct error
**	4 = erreur dans resolution : resolution missing
**	5 = erreur lumiere ambiante
**	6 = erreur couleur lumiere ambiante
**	7 = erreur de coordonnee camera
**	8 = erreur camera orientation
**	9 = erreur camera fov
*/

t_mlx	*rt_init()
{
	t_mlx	*mlx;
	if (!(mlx = ft_calloc(1, sizeof(t_mlx*))))
		return (NULL);
	mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr, 500, 500, "miniRT");
	return (mlx);
}
