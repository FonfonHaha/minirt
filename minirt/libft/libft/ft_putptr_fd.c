/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoureau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 12:28:32 by pcoureau          #+#    #+#             */
/*   Updated: 2020/01/20 12:29:50 by pcoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putptr_fd(unsigned long nbr, char *base, int fd)
{
	unsigned long	i;
	unsigned long	baselen;
	unsigned long	r;
	unsigned long	oui;

	if (!ft_checkbase(base))
		return ;
	oui = nbr;
	i = 0;
	baselen = 0;
	while (base[i] != '\0')
	{
		baselen++;
		i++;
	}
	r = oui % baselen;
	if (baselen != 0 && oui / baselen)
		ft_putptr_fd(oui / baselen, base, fd);
	ft_putchar_fd(base[r], fd);
}
