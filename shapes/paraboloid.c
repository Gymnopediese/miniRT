/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paraboloid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 12:50:34 by albaud            #+#    #+#             */
/*   Updated: 2023/03/19 01:42:39 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../header.h"
#define A 1
#define B 1
#define C 1

int	paraboloid_intersect(t_ray *ray, t_obj *cylindre, t_hit *hit)
{
	double	a;
	double	b;
	double	c;
	double	x;
	t_ray	r;

	global_to_local(ray, &r, cylindre);
	a = r.direction.x * r.direction.x + r.direction.y * r.direction.y - 2 * r.direction.z;
	b = 2 * (r.direction.x * r.origin.x + r.direction.y * r.origin.y - 2 * r.origin.z);
	c = r.origin.x * r.origin.x + r.origin.y * r.origin.y - 2 * r.origin.z;
	x = b * b - 4 * a * c;
	if (x <= 0)
		return (0);
	c = (-b + sqrt(x)) / (2 * a);
	x = (-b - sqrt(x)) / (2 * a);
	if (c < x)
		r.origin = v_ponline(&r.origin, &r.direction, c);
	else
		r.origin = v_ponline(&r.origin, &r.direction, x);
	if (fabs(r.origin.z) > 10)//c <= 0 || x <= 0 || 
		return (0);
	r.origin = m_3mult(&r.origin, cylindre->transform);
	hit->ray.origin = r.origin;
	return (1);
}
