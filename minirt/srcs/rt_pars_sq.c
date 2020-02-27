/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_pars_sq.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoureau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 22:33:19 by pcoureau          #+#    #+#             */
/*   Updated: 2020/02/25 22:33:21 by pcoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "keys.h"

int     rt_get_sqheight(t_rtlist *obj, char *line)
{
    if (!line)
        return (19);
    obj->h = ft_atoi(line);
    return (0);
}
}

int     rt_pars_sq_ii(t_rtlist *obj, char **tab)
{
    int ret;
    if (ret = rt_get_objcoor(obj, tab[1]))
        return (ret);
    if (ret = rt_get_objvector(obj, tab[2]))
        return (ret);
    if (ret = rt_get_sqheight(obj, tab[3]))
        return (ret);
    if (ret = rt_get_objcolor(obj, tab[4]))
        return (ret);
    return (0);
}

int     rt_pars_sq(t_mlx *mlx, char *line)
{
    int         ret;
    char        **tab;
    t_rtlist    *obj;
    t_rtlist    *last;

    last = ft_lstlast(mlx->obj);
    if (!(obj = malloc(sizeof(t_rtlist))))
        return(13);
    obj->next = NULL;
    obj->type = 3;
    last->next = obj;
    if (!(tab = ft_split(line, ' ')))
        return (14);
    ret = rt_pars_sp_ii(obj, tab);
    tab = ft_deltab(tab);
    return (ret);
}