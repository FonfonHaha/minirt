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

int		rt_pars(t_lmx *mlx, const char *str)
{
	int		i;
	int		fd;
	int		ret;
	int		ret_funct;
	char	*line;
	t_funct	*funct;

	i = 0;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (1);
	while ((ret = get_next_line_two(fd, &line)) > 0)
	{
		if(!(funct = rt_get_funct(line[0])))
		{
			free(line);
			return(3);
		}
		if ((ret_funct = funct(mlx, line)))
			return (ret_funct);
		free(line);
	}
	if (ret == -1)
		return (2);
}