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
    if (!tab[0] || !tab[1] || !tab[2])
    {
        ft_deltab(tab);
        return (17);
    }
    obj->r = ft_atoi(tab[0]);
    obj->g = ft_atoi(tab[1]);
    obj->b = ft_atoi(tab[2]);
    obj->color = rt_color(obj->r, obj->g, obj->b);
    ft_deltab(tab);
    if (obj->color < 0)
        return (22);
    return (0);
}

int     rt_vectorverif(float x)
{
    if (x < -1.0 || x > 1.0)
        return (1);
    return (0);
}

int     rt_get_objvector(t_rtlist *obj, char *line)
{
    char **tab;
    
    if (!line)
        return(16);
    if (!(tab = ft_split(line, ',')))
        return (13);
    if (!tab[0] || !tab[1] || !tab[2])
    {
        ft_deltab(tab);
        return (16);
    }
    obj->vx = ft_atof(tab[0]);
    obj->vy = ft_atof(tab[1]);
    obj->vz = ft_atof(tab[2]);
    ft_deltab(tab);
    if (rt_vectorverif(obj->vx) || rt_vectorverif(obj->vy) || rt_vectorverif(obj->vz))
        return (16);
    return (0);
}

int     rt_get_objcoor(t_rtlist *obj, char *line)
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
    obj->x = ft_atof(tab[0]);
    obj->y = ft_atof(tab[1]);
    obj->z = ft_atof(tab[2]);
    ft_deltab(tab);
    return (0);
}