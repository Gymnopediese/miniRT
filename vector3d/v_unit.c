/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_unit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bphilago <bphilago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 17:04:37 by albaud            #+#    #+#             */
/*   Updated: 2022/12/13 14:23:59 by bphilago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_v3.h"

double	to_unit(const double i)
{
	if (i < 0)
		return (-1);
	if (i > 0)
		return (1);
	return (i);
}

t_v3	v_unit(const t_v3 *a)
{
	double	norm;

	norm = v_norm(a);
	return ((t_v3){
		a->x / norm,
		a->y / norm,
		a->z / norm,
	});
}

t_v3	*v_cunit(t_v3 *a)
{
	double	norm;

	norm = v_norm(a);
	a->x /= norm;
	a->y /= norm;
	a->z /= norm;
	return (a);
}
