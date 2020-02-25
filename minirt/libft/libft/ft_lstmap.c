/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoureau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 21:13:03 by pcoureau          #+#    #+#             */
/*   Updated: 2019/10/20 19:40:02 by pcoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst2;
	t_list	*p;

	if (!lst || !f || !del)
		return (NULL);
	if (!(lst2 = ft_lstnew((*f)(lst->content))))
		return (NULL);
	p = lst2;
	while (lst->next)
	{
		lst = lst->next;
		if (!(lst2->next = ft_lstnew((*f)(lst->content))))
		{
			ft_lstclear(&p, del);
			return (NULL);
		}
		lst2 = lst2->next;
	}
	return (p);
}
