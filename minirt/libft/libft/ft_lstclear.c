/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoureau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 20:49:23 by pcoureau          #+#    #+#             */
/*   Updated: 2019/10/20 18:59:48 by pcoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*p;
	t_list	*next;

	if ((*del) && (lst))
	{
		p = *lst;
		while (p->next != NULL)
		{
			next = p->next;
			ft_lstdelone(p, (*del));
			p = next;
		}
		ft_lstdelone(p, (*del));
		*lst = NULL;
	}
}
