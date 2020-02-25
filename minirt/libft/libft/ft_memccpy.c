/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoureau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:48:34 by pcoureau          #+#    #+#             */
/*   Updated: 2019/10/21 13:36:13 by pcoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*pdest;
	unsigned char	*psrc;
	size_t			i;

	i = 0;
	c = (unsigned char)c;
	pdest = (unsigned char *)dest;
	psrc = (unsigned char *)src;
	while (i < n && psrc[i] != c)
	{
		pdest[i] = psrc[i];
		i++;
	}
	if (psrc[i] == c && i < n)
	{
		pdest[i] = psrc[i];
		return (pdest + (i + 1));
	}
	return (NULL);
}
