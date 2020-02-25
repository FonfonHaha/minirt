/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoureau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 20:27:55 by pcoureau          #+#    #+#             */
/*   Updated: 2019/10/20 19:38:00 by pcoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		i;
	size_t	n;
	int		v;

	i = 0;
	n = 0;
	v = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		v = i;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		n = (n * 10) + (str[i] - 48);
		i++;
	}
	if (str[v] == '-')
		return (-n);
	return (n);
}
