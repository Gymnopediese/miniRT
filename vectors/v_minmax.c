/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_minmax.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 09:48:27 by albaud            #+#    #+#             */
/*   Updated: 2022/12/12 09:48:35 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_v3.h"

double	v_max(const t_v3 *v)
{
	if (v->x > v->y && v->x > v->z)
		return (v->x);
	if (v->y > v->z)
		return (v->y);
	return (v->z);
}

double	v_min(const t_v3 *v)
{
	if (v->x < v->y && v->x < v->z)
		return (v->x);
	if (v->y < v->z)
		return (v->y);
	return (v->z);
}

double	v_maxabs(const t_v3 *v)
{
	double	min;
	double	max;

	min = fabs(v_min(v));
	max = fabs(v_max(v));
	if (max > min)
		return (max);
	return (min);
}