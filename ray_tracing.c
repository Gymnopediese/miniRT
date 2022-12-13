/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:22:13 by albaud            #+#    #+#             */
/*   Updated: 2022/12/12 20:50:53 by albaud           ###   ########.fr       */
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
	hit->ray.origin = min;
	hit = sphere_reflection(hit, &r->origin);
	hit->normal = v_rm(&hit->ray.origin, &cobj->pos);
	return (cobj);
}

#define RAYS_AMOUNT 3
#define RAYS_DEPTH 3

int	mergecol(int a, int b)
{
	int	rgb;

	rgb = ((a >> 16) + (b >> 16)) / 2;
	rgb = (rgb << 8) + (((a >> 8) & 0xff) + ((b >> 8) & 0xff)) / 2;
	rgb = (rgb << 8) + ((a & 0xff) + (b & 0xff)) / 2;
	// if (a != b)
	// 	printf("%i %i %i \n", a, b, rgb);
	return (rgb);
}

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
		//color = coloring2(obj_hit, &hit.ray.origin, scene);
		// print_vector(r->direction, "in\t");
		// print_vector(hit.ray.direction, "out\t");
		//return (color);
		color = v_tocol(&obj_hit->color);
		while (++iter < RAYS_AMOUNT)
		{
			r->origin = hit.ray.origin;
			r->direction = disperse(&hit, obj_hit);
			r->direction = v_nmult(&r->direction, -1);
			t = ray_trace(scene, r, depth + 1);

			if (t != -1)
				color = mergecol(color, t);
		}
	}
	return (color);
}
