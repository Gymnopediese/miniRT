/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bphilago <bphilago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:22:13 by albaud            #+#    #+#             */
/*   Updated: 2022/12/13 10:43:48 by bphilago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_obj	*hit_obj(t_scene *scene, t_ray *r, t_hit *hit)
{
	t_list	*objects;
	t_obj	*obj;
	t_v3	min;
	t_obj	*cobj;

	min = (t_v3){100000, 100000, 100000};
	objects = scene->objects;
	while (objects)
	{
		obj = objects->data;
		if (sphere_intersect(r, obj, &hit->ray.origin)
			&& v_dist(&r->origin, &hit->ray.origin) < v_dist(&min, &r->origin))
		{
			min = hit->ray.origin;
			cobj = obj;
		}
		objects = objects->next;
	}
	if (v_equal(&min, &(t_v3){100000, 100000, 100000}))
		return (0);
	hit->ray.direction = sphere_reflection(r, cobj, &hit->ray.origin);
	hit->normal = v_rm(&hit->ray.direction, &cobj->pos);
	return (cobj);
}

#define RAYS_AMOUNT 3
#define RAYS_DEPTH 3

int	ray_trace(t_scene *scene, t_ray *r, int depth)
{
	t_hit	hit;
	int		iter;
	long	color;
	int		t;
	t_obj	*obj_hit;

	if (depth >= RAYS_DEPTH)
		return (-1);
	iter = -1;
	color = -1;
	obj_hit = hit_obj(scene, r, &hit);
	if (obj_hit)
	{	
		if (depth == 0)
			color = coloring2(obj_hit, &hit.ray.origin, scene);
		else
			color = RED;
		// printf("salut %ld %d\n", color, depth);
		// print_vector(hit.ray.direction, "ricochet direction");
		// print_vector(r->direction, "r direction");
		// while (++iter < RAYS_AMOUNT)
		// {
			//t = ray_trace(scene, disperse(hit, obj_hit), depth + 1);
			// t = ray_trace(scene, &hit.ray, depth + 1);
			// if (t != -1)
			// 	color = t;
			// if (t != -1)
			// 	color = (color + t) / 2;
		// }
	}
	return (color);
}
