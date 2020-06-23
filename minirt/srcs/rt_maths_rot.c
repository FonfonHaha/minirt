/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_maths_rot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoureau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 18:00:52 by pcoureau          #+#    #+#             */
/*   Updated: 2020/02/25 18:44:34 by pcoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "keys.h"
#include <math.h>

void		rx(t_vect *vect, float x)
{
	t_vect	tmp;

	tmp.x = vect->x;
	tmp.y = vect->y * cos(x) - vect->z * sin(x);
	tmp.z = vect->y * sin(x) + vect->z * cos(x);
	*vect = tmp;
}

void		ry(t_vect *vect, float y)
{
	t_vect	tmp;

	tmp.x = vect->x * cos(y) + vect->z * sin(y);
	tmp.y = vect->y;
	tmp.z = vect->x * -sin(y) + vect->z * cos(y);
	*vect = tmp;
}

void		rz(t_vect *vect, float z)
{
	t_vect	tmp;

	tmp.x = vect->x * cos(z) - vect->y * sin(z);
	tmp.y = vect->x * sin(z) + vect->y * cos(z);
	tmp.z = vect->z;
	*vect = tmp;
}

void		rot(t_vect *vect, t_vect *angle)
{
	rx(vect, angle->x2);
	ry(vect, angle->y2);
	rz(vect, angle->z2);
}

void		anti_rot(t_vect *vect, t_vect *angle)
{
	rz(vect, -angle->z);
	ry(vect, -angle->y);
	rx(vect, -angle->x);
}