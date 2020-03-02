/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_pars_cy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoureau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 22:33:19 by pcoureau          #+#    #+#             */
/*   Updated: 2020/02/25 22:33:21 by pcoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "keys.h"

int     rt_get_cyheight(t_rtlist *obj, char *line)
{
    if (!line || (obj->h = ft_atoi(line)) < 0)
        return (19);
    return (0);
}

int     rt_get_cydiam(t_rtlist *obj, char *line)
{
    if (!line || (obj->diam = ft_atoi(line)) < 0)
        return (18);
    return (0);
}

int     rt_pars_cy_ii(t_rtlist *obj, char **tab)
{
    int ret;
    if ((ret = rt_get_objcoor(obj, tab[1])))
        return (ret);
    if ((ret = rt_get_objvector(obj, tab[2])))
        return (ret);
    if ((ret = rt_get_cydiam(obj, tab[3])))
        return (ret);
    if ((ret = rt_get_cyheight(obj, tab[4])))
        return (ret);
    if ((ret = rt_get_objcolor(obj, tab[5])))
        return (ret);
    return (0);
}

int     rt_pars_cy(t_mlx *mlx, char *line)
{
    int         ret;
    char        **tab;
    t_rtlist    *obj;
    t_rtlist    *last;

    last = rt_lstlast(mlx->obj);
    if (!(obj = malloc(sizeof(t_rtlist))))
        return(13);
    obj->next = NULL;
    obj->type = 4;
    if (!last)
        mlx->obj = obj;
    else
        last->next = obj;
    if (!(tab = ft_split(line, ' ')))
        return (14);
    ret = rt_pars_cy_ii(obj, tab);
    tab = ft_deltab(tab);
    return (ret);
}