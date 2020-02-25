/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoureau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 20:09:17 by pcoureau          #+#    #+#             */
/*   Updated: 2019/10/20 15:22:01 by pcoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *n, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (n[0] == '\0')
		return ((char *)str);
	while (n[i] != '\0')
		i++;
	while (str[j] != '\0')
		j++;
	if (i > j)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i] != '\0' && i < len)
	{
		j = 0;
		while (str[i + j] == n[j] && i + j < len && n && str[i + j] && n[j])
			j++;
		if (n[j] == '\0')
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}
