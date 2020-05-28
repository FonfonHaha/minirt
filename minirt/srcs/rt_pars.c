/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_pars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoureau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 18:31:48 by pcoureau          #+#    #+#             */
/*   Updated: 2020/02/25 18:45:01 by pcoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "keys.h"

int		rt_pars(t_mlx *mlx, const char *str)
{
	int		fd;
	int		ret;
	int		ret_funct;
	char	*line;
	t_funct	funct;

	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (1);
	while ((ret = get_next_line_two(fd, &line)) > 0)
	{
		if(!(funct = rt_get_funct(line)))
		{
			free(line);
			close(fd);
			return(3);
		}
		if ((ret_funct = funct(mlx, line)))
		{
			return (ret_funct);
			close(fd);
		}
		free(line);
	}
	if (ret == -1)
	{
		return (2);
		close(fd);
	}
	return (0);
}
