/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_pars_pl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoureau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 22:33:19 by pcoureau          #+#    #+#             */
/*   Updated: 2020/02/25 22:33:21 by pcoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "keys.h"

int     rt_pars_pl_ii(t_rtlist *obj, char **tab)
{
    int ret;
    if ((ret = rt_get_objcoor(obj, tab[1])))
        return (ret);
    if ((ret = rt_get_objvector(obj, tab[2])))
        return (ret);
    if ((ret = rt_get_objcolor(obj, tab[3])))
        return (ret);
    return (0);
}

int     rt_pars_pl(t_mlx *mlx, char *line)
{
    int         ret;
    char        **tab;
    t_rtlist    *obj;
    t_rtlist    *last;

    last = rt_lstlast(mlx->obj);
    if (!(obj = malloc(sizeof(t_rtlist))))
        return (13);
    obj->next = NULL;
    obj->type = 2;
    if (!last)
        mlx->obj = obj;
    else
        last->next = obj;
    if (!(tab = ft_split(line, ' ')))
        return (14);
    ret = rt_pars_pl_ii(obj, tab);
    tab = ft_deltab(tab);
    return (ret);
}