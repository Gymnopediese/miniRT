/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_unit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 17:04:37 by albaud            #+#    #+#             */
/*   Updated: 2022/12/12 09:50:00 by albaud           ###   ########.fr       */
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
	double	max;

	max = v_maxabs(a);
	return ((t_v3){
		a->x / max,
		a->y / max,
		a->z / max,
	});
}

t_v3	*v_cunit(t_v3 *a)
{
	a->x = to_unit(a->x);
	a->y = to_unit(a->y);
	a->z = to_unit(a->z);
	return (a);
}
