/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoureau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 15:48:27 by pcoureau          #+#    #+#             */
/*   Updated: 2020/01/20 12:27:47 by pcoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base_fd(int nbr, char *base, int fd)
{
	int		i;
	int		baselen;
	int		r;
	long	oui;

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
	if (nbr < 0)
	{
		oui = -oui;
		write(1, "-", fd);
	}
	i = 0;
	r = oui % baselen;
	if (baselen != 0 && oui / baselen)
		ft_putnbr_base_fd(oui / baselen, base, fd);
	ft_putchar_fd(base[r], fd);
}
