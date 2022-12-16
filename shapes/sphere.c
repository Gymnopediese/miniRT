/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 19:51:41 by albaud            #+#    #+#             */
/*   Updated: 2022/12/15 22:44:04 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

t_v3	v_units(const t_v3 *a)
{
	double	norm;

	norm = v_norm(a);
	return ((t_v3){
		a->x / (norm + 1),
		a->y / (norm + 1),
		a->z / (norm + 1),
	});
}

void	new_dir(t_ray *r, t_ray *new, t_obj *obj)
{
	// r->direction.x *= -1;
	// r->direction.y *= -1;
	// r->direction.z *= -1;
	new->origin = m_3mult(&r->origin, obj->inverse_transform);
	new->direction = m_3mults(&r->direction, obj->inverse_transform);
	// r->direction.x *= -1;
	// r->direction.y *= -1;
	// r->direction.z *= -1;
	new->direction = v_units(&new->direction);
}

t_v3	*sphere_intersect(t_ray *r, t_obj *sphere, t_v3 *hit)
{
	double		n[5];
	double		discriminant;
	t_ray		ray;
	t_v3		oc;

	new_dir(r, &ray, sphere);
	oc = v_rm(&ray.origin,&(t_v3){0, 0, 0});
	n[0] = v_dotp(&ray.direction, &ray.direction);
	n[1] = 2 * v_dotp(&oc, &ray.direction);
	n[2] = v_dotp(&oc, &oc) - pow(sphere->diametre / 2, 2);
	discriminant = n[1] * n[1] - 4 * n[0] * n[2];
	if (discriminant < 0)
		return (0);
	// print_vector(r->origin, "global origine");
	// print_vector(r->direction, "global direction");
	// print_vector(ray.origin, "local origine");
	// print_vector(ray.direction, "local direction");
	// print_vector(oc, "oc tagueulr");
	n[3] = (-n[1] + sqrt(discriminant)) / (2.0 * n[0]);
	n[4] = (-n[1] - sqrt(discriminant)) / (2.0 * n[0]);
	//printf("%f %f\n", n[3], n[4]);
	if (n[3] <= n[4])
	{
		if (n[3] >= 0 - __FLT_EPSILON__)
		{
			*hit = v_ponline(&ray.origin, &ray.direction, n[3]);
			*hit = m_3mult(hit, sphere->transform);
			return (hit);
		}
		return (0);
	}
	if (n[4] >= 0 - __FLT_EPSILON__)
	{		
		*hit = v_ponline(&ray.origin, &ray.direction, n[4]);
		*hit = m_3mult(hit, sphere->transform);
		return (hit);
	}
	return (0);
}

// t_v3	*sphere_intersect(t_ray *ray, t_obj *sphere, t_v3 *hit)
// {
// 	double	n[5];
// 	double	discriminant;
// 	t_v3	oc;

// 	oc = v_rm(&ray->origin, &sphere->pos);
// 	n[0] = v_dotp(&ray->direction, &ray->direction);
// 	n[1] = 2 * v_dotp(&oc, &ray->direction);
// 	n[2] = v_dotp(&oc, &oc) - pow(sphere->diametre / 2, 2);
// 	discriminant = n[1] * n[1] - 4 * n[0] * n[2];
// 	if (discriminant < 0)
// 		return (0);
// 	n[3] = (-n[1] + sqrt(discriminant)) / (2.0 * n[0]);
// 	n[4] = (-n[1] - sqrt(discriminant)) / (2.0 * n[0]);
// 	if (n[3] <= n[4])
// 	{
// 		if (n[3] >= 0 - __FLT_EPSILON__)
// 		{
// 			*hit = v_ponline(&ray->origin, &ray->direction, n[3]);
// 			return (hit);
// 		}
// 		return (0);
// 	}
// 	if (n[4] >= 0 - __FLT_EPSILON__)
// 	{		
// 		*hit = v_ponline(&ray->origin, &ray->direction, n[4]);
// 		return (hit);
// 	}
// 	return (0);
// }

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
#include <stdio.h>
t_hit	*sphere_reflection(t_hit *hit, t_v3 *origine)
{
	double	bc;
	t_v3	ba;
	t_v3	c;
	t_v3	res;

	ba = v_rm(origine, &hit->ray.origin);
	bc = cos(v_angle(&ba, &hit->normal)) * v_dist(&hit->ray.origin, origine);
	c = v_unit(&hit->normal);
	c = v_ponline(&hit->ray.origin, &c, bc);
	res = v_rm(&c, origine);
	v_cnmult(&res, 2);
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
