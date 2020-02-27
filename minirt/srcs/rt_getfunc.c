/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_getfunc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoureau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 18:58:52 by pcoureau          #+#    #+#             */
/*   Updated: 2020/02/25 18:58:56 by pcoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "keys.h"

static void	create_tab(t_funct *tab)
{
	tab['R'] = rt_pars_r;
	tab['A'] = rt_pars_a;
	tab['c'] = rt_pars_c;
	tab['l'] = rt_pars_l;
	tab['p'] = rt_pars_p;
	tab['s'] = rt_pars_sp;
	tab['S'] = rt_pars_sq;
	tab['c'] = rt_pars_c;
	tab['t'] = rt_pars_t;
	tab['\n'] = rt_pars_bn;
}

t_funct		rt_get_funct(char *s)
{
	static t_funct	*tab = NULL;
	if (!tab)
	{
		if (!(tab = malloc(sizeof(t_funct) * 256)))
			return (NULL);
		ft_bzero(tab, sizeof(*tab) * 256);
		create_tab(tab);
	}
	if (s[0] == 's')
		if (s[1] == 'q')
			return (tab[(int)'S']);
	return (tab[(int)s[0]]);
}
