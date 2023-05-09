/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paraboloid2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 12:50:34 by albaud            #+#    #+#             */
/*   Updated: 2023/03/18 00:15:03 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../header.h"
#define A 1
#define B 1
#define C 1

t_v3	*paraboloid2_intersect(t_ray *ray, t_obj *cylindre, t_v3 *hit)
{
	double	a;
	double	b;
	double	c;
	double	x;
	t_ray	r;

	double	xm;
	double	ym;
	double	zm;

	xm = B * B * C * C;
	ym = A * A * C * C;
	zm = B * B * A * A;
	global_to_local(ray, &r, cylindre);
	a = r.direction.x * r.direction.x * xm + r.direction.y * r.direction.y * ym + 2 * r.direction.z * zm;
	b = 2 * (r.direction.x * r.origin.x * xm + r.direction.y * r.origin.y * ym + 2 * r.origin.z * zm);
	c = r.origin.x * r.origin.x * xm + r.origin.y * r.origin.y * ym + 2 * r.origin.z * zm;
	x = b * b - 4 * a * c;
	if (x <= 0)
		return (0);
	c = (-b + sqrt(x)) / (2 * a);
	x = (-b - sqrt(x)) / (2 * a);
	if (c < x)
		r.origin = v_ponline(&r.origin, &r.direction, c);
	else
		r.origin = v_ponline(&r.origin, &r.direction, x);
	if (c <= 0 || x <= 0 || fabs(r.origin.z) > 2)
		return (0);
	r.origin = m_3mult(&r.origin, cylindre->transform);
	hit->x = r.origin.x;
	hit->y = r.origin.y;
	hit->z = r.origin.z;

	return (hit);
}
