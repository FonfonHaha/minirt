/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_get_param.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoureau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 22:33:19 by pcoureau          #+#    #+#             */
/*   Updated: 2020/02/25 22:33:21 by pcoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "keys.h"

int     rt_get_objcolor(t_rtlist *obj, char *line)
{
    char **tab;
    
    if (!line)
        return(17);
    if (!(tab = ft_split(line, ',')))
        return (13);
    if (!tab[1] || !tab[2] || !tab[3])
    {
        ft_deltab(tab);
        return (16);
    }
    obj->r = ft_atoi(tab[1]);
    obj->g = ft_atoi(tab[2]);
    obj->b = ft_atoi(tab[3]);
    obj->color = rt_color(obj->r, obj->g, obj->b);
    ft_deltab(tab);
    return (0);
}

int     rt_get_objvector(t_rtlist *obj, char *line)
{
    char **tab;
    
    if (!line)
        return(16);
    if (!(tab = ft_split(line, ',')))
        return (13);
    if (!tab[1] || !tab[2] || !tab[3])
    {
        ft_deltab(tab);
        return (16);
    }
    obj->vx = ft_atof(tab[1]);
    obj->vy = ft_atof(tab[2]);
    obj->vz = ft_atof(tab[3]);
    ft_deltab(tab);
    return (0);
}

int     rt_get_objcoor(t_rtlist *obj, char *line)
{
    char **tab;

    if (!line)
        return(15);
    if (!(tab = ft_split(line, ',')))
        return (13);
    if (!tab[1] || !tab[2] || !tab[3])
    {
        ft_deltab(tab);
        return (15);
    }
    obj->x = ft_atof(tab[1]);
    obj->y = ft_atof(tab[2]);
    obj->z = ft_atof(tab[3]);
    ft_deltab(tab);
    return (0);
}