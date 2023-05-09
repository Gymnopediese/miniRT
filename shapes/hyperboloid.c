/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hyperboloid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 12:50:34 by albaud            #+#    #+#             */
/*   Updated: 2023/03/19 01:50:04 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../header.h"
#define A 1
#define B 1
#define C 1

int	hyperboloid_intersect(t_ray *ray, t_obj *cylindre, t_hit *hit)
{
	double	a;
	double	b;
	double	c;
	double	x;
	t_ray	r;

	global_to_local(ray, &r, cylindre);
	a = r.direction.x * r.direction.x + r.direction.y * r.direction.y - r.direction.z * r.direction.z;
	b = 2 * (r.direction.x * r.origin.x + r.direction.y * r.origin.y - r.direction.z * r.origin.z);
	c = r.origin.x * r.origin.x + r.origin.y * r.origin.y - r.origin.z * r.origin.z - 1;
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
	hit->normal = (t_v3){r.origin.x, r.origin.y, 0};
	hit->normal = m_3mult(&hit->normal, cylindre->transform);
	r.origin = m_3mult(&r.origin, cylindre->transform);
	hit->ray.origin = r.origin;
	hit->obj = cylindre;

	return (1);
}

// t_hit	*sphere_reflection(t_hit *hit, t_v3 *origine)
// {
// 	double	bc;
// 	t_v3	ba;
// 	t_v3	c;
// 	t_v3	res;

// 	ba = v_rm(origine, &hit->ray.origin);
// 	bc = cos(v_angle(&ba, &hit->normal)) * v_dist(&hit->ray.origin, origine);
// 	c = v_unit(&hit->normal);
// 	c = v_ponline(&hit->ray.origin, &c, bc);
// 	res = v_rm(&c, origine);
// 	v_cnmult(&res, 2);
// 	hit->ray.direction = v_rm(&res, &hit->ray.origin);
// 	return (hit);
// }
