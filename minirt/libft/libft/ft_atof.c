/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoureau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 22:15:00 by pcoureau          #+#    #+#             */
/*   Updated: 2020/02/25 22:15:01 by pcoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

float   ft_atof_ii(const char *str)
{
    int i;
    int puis;
    float n;
    
    i = 0;
    n = 0;
    puis = 10;
    while (str[i] == '.')
	{
        i++;
	}
	while (ft_isdigit(str[i]))
	{
		n = (n * 10) + (str[i] - 48);
		i++;
	}
    i--;
    while (i > 0 && --i)
    {
        puis = puis * 10;
    }
    return (n / puis);
}

float	ft_atof(const char *str)
{
	int		i;
	float	n;
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
    n =  n + ft_atof_ii(str + i);
	if (str[v] == '-')
		return (-n);
	return (n);
}
