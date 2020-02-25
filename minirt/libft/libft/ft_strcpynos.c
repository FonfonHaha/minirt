/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpynos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoureau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 13:51:32 by pcoureau          #+#    #+#             */
/*   Updated: 2019/10/13 13:57:29 by pcoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpynos(char *dest, const char *src)
{
	int i;
    int j;

	i = 0;
    j = 0;
	while (src[i] != '\0')
	{
        if (src[i] != ' ')
        {
    		dest[j] = src[i];
            j++;
        }
		i++;
	}
	dest[j] = '\0';
	return (dest);
}
