/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoureau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 17:45:08 by pcoureau          #+#    #+#             */
/*   Updated: 2019/10/21 13:33:08 by pcoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*pdest;
	unsigned char	*psrc;
	size_t			i;

	i = 0;
	pdest = (unsigned char *)dest;
	psrc = (unsigned char *)src;
	if (pdest > psrc)
	{
		while (len > 0)
		{
			len--;
			pdest[len] = psrc[len];
		}
	}
	else if (pdest < psrc)
	{
		while (i < len)
		{
			pdest[i] = psrc[i];
			i++;
		}
	}
	return (pdest);
}
