/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_pars_tr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoureau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 22:33:19 by pcoureau          #+#    #+#             */
/*   Updated: 2020/02/25 22:33:21 by pcoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "keys.h"

int     rt_get_objcoor2(t_rtlist *obj, char *line)
{
    char **tab;

    if (!line)
        return(15);
    if (!(tab = ft_split(line, ',')))
        return (13);
    if (!tab[0] || !tab[1] || !tab[2])
    {
        ft_deltab(tab);
        return (15);
    }
    obj->x2 = ft_atof(tab[0]);
    obj->y2 = ft_atof(tab[1])* -1;
    obj->z2 = ft_atof(tab[2]);
    ft_deltab(tab);
    return (0);
}

int     rt_get_objcoor3(t_rtlist *obj, char *line)
{
    char **tab;

    if (!line)
        return(15);
    if (!(tab = ft_split(line, ',')))
        return (13);
    if (!tab[0] || !tab[1] || !tab[2])
    {
        ft_deltab(tab);
        return (15);
    }
    obj->x3 = ft_atof(tab[0]);
    obj->y3 = ft_atof(tab[1])* -1;
    obj->z3 = ft_atof(tab[2]);
    ft_deltab(tab);
    return (0);
}

int     rt_pars_tr_ii(t_rtlist *obj, char **tab)
{
    int ret;

    if ((ret = rt_get_objcoor(obj, tab[1])))
        return (ret);
    if ((ret = rt_get_objcoor2(obj, tab[2])))
        return (ret);
    if ((ret = rt_get_objcoor3(obj, tab[3])))
        return (ret);
    if ((ret = rt_get_objcolor(obj, tab[4])))
        return (ret);
    return (0);
}

int     rt_pars_tr(t_mlx *mlx, char *line)
{
    int         ret;
    char        **tab;
    t_rtlist    *obj;
    t_rtlist    *last;

    last = rt_lstlast(mlx->obj);
    if (!(obj = malloc(sizeof(t_rtlist))))
        return(13);
    obj->next = NULL;
    obj->type = 5;
    if (!last)
        mlx->obj = obj;
    else
        last->next = obj;
    if (!(tab = ft_split(line, ' ')))
        return (14);
    ret = rt_pars_tr_ii(obj, tab);
    tab = ft_deltab(tab);
    return (ret);
}