/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoureau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 17:59:40 by pcoureau          #+#    #+#             */
/*   Updated: 2020/02/25 18:06:21 by pcoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "keys.h"

int	rt_hook_keydown(int key, t_mlx *mlx)
{
	if (!mlx)
		return (0);
	if (key == K_ESC)
		exit(EXIT_SUCCESS);
	return (0);
}
