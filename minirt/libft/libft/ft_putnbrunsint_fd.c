/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrunsint_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoureau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 12:30:14 by pcoureau          #+#    #+#             */
/*   Updated: 2020/01/20 12:30:49 by pcoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbrunsint_fd(unsigned int nb, int fd)
{
	unsigned int r;
	unsigned int t;

	if (fd < 0)
		return ;
	t = nb;
	r = t % 10;
	t = t / 10;
	if (t != 0)
	{
		ft_putnbr_fd(t, fd);
	}
	ft_putchar_fd(r + '0', fd);
}
