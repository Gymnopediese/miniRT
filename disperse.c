/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disperse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bphilago <bphilago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:29:26 by bphilago          #+#    #+#             */
/*   Updated: 2022/12/12 15:09:22 by bphilago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

double	rand01(void)
{

	return ((double)((rand() % (100000000)) / 1000000000.0));
}

t_v3	std_normal(t_v3 *vec)
{
	if (vec->x != 0)
	{
		if (vec->y != 0)
			return ((t_v3){vec->y, -vec->x, 0.0});
		if (vec->z != 0)
			return ((t_v3){vec->z, 0.0, -vec->x});
		return ((t_v3){0.0, 1.0, 0.0});
	}
	if (vec->y != 0)
	{
		if (vec->z != 0)
			return ((t_v3){0.0, vec->z, -vec->y});
		return ((t_v3){1.0, 0.0, 0.0});
	}
	if (vec->z != 0)
		return ((t_v3){1.0, 0.0, 0.0});
	error("Impossible de calculer la normal d'un vecteur null");
	return ((t_v3){0.0, 0.0, 0.0});
}

// Mettre des pointeurs pour pouvoir les recevoir et les recycler
t_v3	disperse(t_hit *hit, t_obj *obj)
{
	t_v3	i;
	t_v3	j;
	t_v3	target;
	double	theta;
	double	r;

	i = std_normal(&hit->ray.direction);
	j = v_v3mult(&i, &hit->ray.direction);
	i = v_unit(&i);
	j = v_unit(&j);
	r = sqrt(rand01());
	theta = rand01() * 2 * PI;
	i = v_nmult(&i, r * cos(theta));
	j = v_nmult(&j, r * sin(theta));
	target = v_unit(&hit->ray.direction);
	target = v_add(&target, &i);
	target = v_add(&target, &j);
	return (target);
}
