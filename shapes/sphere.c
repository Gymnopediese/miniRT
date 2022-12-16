/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bphilago <bphilago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 19:51:41 by albaud            #+#    #+#             */
/*   Updated: 2022/12/15 12:17:53 by bphilago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shapes.h"

t_v3	*sphere_intersect(t_ray *ray, t_obj *sphere, t_v3 *hit)
{
	double	n[5];
	double	discriminant;
	t_v3	oc;

	oc = v_rm(&ray->origin, &sphere->pos);
	n[0] = v_dotp(&ray->direction, &ray->direction);
	n[1] = 2 * v_dotp(&oc, &ray->direction);
	n[2] = v_dotp(&oc, &oc) - pow(sphere->diametre / 2, 2);
	discriminant = n[1] * n[1] - 4 * n[0] * n[2];
	if (discriminant < 0)
		return (0);
	n[3] = (-n[1] + sqrt(discriminant)) / (2.0 * n[0]);
	n[4] = (-n[1] - sqrt(discriminant)) / (2.0 * n[0]);
	if (n[3] <= n[4])
	{
		if (n[3] >= 0 - __FLT_EPSILON__)
		{
			*hit = v_ponline(&ray->origin, &ray->direction, n[3]);
			return (hit);
		}
		return (0);
	}
	if (n[4] >= 0 - __FLT_EPSILON__)
	{		
		*hit = v_ponline(&ray->origin, &ray->direction, n[4]);
		return (hit);
	}
	return (0);
}

double	hit_circle(const t_ray *ray, const t_obj *c)
{
	t_v3	opos;
	t_v3	cpos;
	double	lon;

	opos = v_rm(&c->pos, &ray->origin);
	cpos = ray->direction;
	lon = v_norm(&opos) * tanf(v_angle(&cpos, &opos));
	if (c->diametre >= lon)
		return (1 / (lon / c->diametre));
	return (0);
}
t_hit	*sphere_reflection(t_hit *hit, t_v3 *origine) //Peut-être buggué
{
	double	bc;
	t_v3	ba;
	t_v3	ac;
	t_v3	c;
	t_v3	res;

	ba = v_rm(origine, &hit->ray.origin);
	bc = cos(v_angle(&ba, &hit->normal)) * v_dist(&hit->ray.origin, origine);
	c = v_unit(&hit->normal);
	c = v_ponline(&hit->ray.origin, &c, bc);
	ac = v_rm(&c, origine);
	v_cadd(&res, &c);
	hit->ray.direction = v_rm(&res, &hit->ray.origin);
	return (hit);
}

// t_v3	sphere_reflection(t_ray *ray, t_obj *sphere, t_v3 *hit)
// {
// 	t_v3	c_to_h;
// 	float	dot_product;
// 	t_v3	res;
// 	float	projection;

// 	c_to_h = v_rm(hit, &sphere->pos);
// 	dot_product = v_dotp(&ray->direction, &c_to_h);
// 	projection = dot_product / v_norm(&c_to_h);
// 	res.x = 2 * projection * c_to_h.x - ray->direction.x;
// 	res.y = 2 * projection * c_to_h.y - ray->direction.y;
// 	res.z = 2 * projection * c_to_h.z - ray->direction.z;
// 	return (res);
// }
