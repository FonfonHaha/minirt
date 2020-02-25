/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoureau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 21:08:15 by pcoureau          #+#    #+#             */
/*   Updated: 2019/10/13 21:24:34 by pcoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t i;

	i = ft_strlen(s);
	if (c == '\0')
		return ((char *)s + i);
	while (i > 0)
	{
		i--;
		if (s[i] == c)
			return ((char *)s + i);
	}
	return (NULL);
}
