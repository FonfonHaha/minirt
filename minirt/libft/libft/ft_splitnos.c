/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitnos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoureau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 17:52:42 by pcoureau          #+#    #+#             */
/*   Updated: 2020/01/20 12:27:20 by pcoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*free_tabnos(char **tab)
{
	int n;

	n = 0;
	while (tab[n])
		free(tab[n++]);
	free(tab);
	return (NULL);
}

static char	**new_tabnos(char **tab, char *str)
{
	char	**new_tab;
	int		n;

	n = 0;
	while (tab[n])
		n++;
	if (!(new_tab = ft_calloc(sizeof(char **), n + 2)))
		return (NULL);
	n = 0;
	while (tab[n])
	{
		new_tab[n] = tab[n];
		n++;
	}
	free(tab);
	new_tab[n] = str;
	new_tab[n + 1] = NULL;
	return (new_tab);
}

static char	*get_strnos(const char *s, size_t *i, char c)
{
	char	*str;
	size_t	n;
	size_t	j;

	n = 0;
	j = 0;
	while (s[*i + n] && s[*i + n] != c)
		n++;
	if (!(str = ft_calloc(sizeof(char), n + 1)))
		return (NULL);
	n = 0;
	while (s[*i + n] && s[*i + n] != c)
	{
		if (s[*i + n] != ' ')
		{
			str[j] = s[*i + n];
			j++;
		}
		n++;
	}
	str[n] = '\0';
	*i = *i + n;
	return (str);
}

char		**ft_splitnos(char const *s, char c)
{
	char		**tab;
	char		*str;
	size_t		i;

	if (!s || !(tab = ft_calloc(sizeof(char **), 1)))
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			if (!(str = get_strnos(s, &i, c)))
				return (free_tabnos(tab));
			tab = new_tabnos(tab, str);
		}
	}
	return (tab);
}
