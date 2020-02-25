/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoureau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:12:05 by pcoureau          #+#    #+#             */
/*   Updated: 2019/10/20 17:06:04 by pcoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	t;

	t = 0;
	i = 0;
	if (!src || !dest)
		return (t);
	while (src[i] != '\0')
	{
		t++;
		i++;
	}
	i = 0;
	if (size == 0)
		return (t);
	while (src[i] != '\0' && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (t);
}
