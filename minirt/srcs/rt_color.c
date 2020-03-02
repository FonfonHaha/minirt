/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoureau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 22:33:19 by pcoureau          #+#    #+#             */
/*   Updated: 2020/02/25 22:33:21 by pcoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "keys.h"

int     rt_notrange(int c)
{
    if (c < 0 || c > 255)
        return (1);
    return (0);
}

int     rt_color(int r, int g, int b)
{
    int color;

    color = 0;
    if (rt_notrange(r) || rt_notrange(g) || rt_notrange(b))
        return (-1);
    color = color + (r * 65536 + g * 256 + b);
    return (color);
}