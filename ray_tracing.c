/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bphilago <bphilago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:22:13 by albaud            #+#    #+#             */
/*   Updated: 2022/12/13 15:33:09 by bphilago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// Voir si cos negatif
void	brightness(t_v3 *a, const t_v3 *origine_pos, const t_hit *hit, const t_scene *scene)
{
	t_list	*objects;
	t_ray	r;
	t_v3	tmp;
	t_obj	*obj;

	objects = scene->objects;
	r.direction = v_rm(&scene->light->pos, &hit->ray.origin);
	r.origin = hit->ray.origin;
	while (objects)
	{
		obj = objects->data;
		if (sphere_intersect(&r, obj, &tmp)) // Voir pour implementer plusieurs rayon par lumière pour des ombres douces + simplifier pour juste verifier si ca touche
		{
			*a = v_mult(a, &scene->ambiance->color);
			return ;
		}	
		objects = objects->next;
	}
	tmp = v_mult(a, &scene->ambiance->color);
	v_cmult(a, &scene->light->color);
	t_v3 v1 = v_unit(&r.direction);
	t_v3 v2 = v_unit(&hit->normal);
	v_cnmult(a, v_dotp(&v1, &v2));
	v_cadd(a, &tmp);
}

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

int	mergecol(int a, int b) // A modifier pour faire des additions
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
	t_v3	tmp_color;
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
		tmp_color = obj_hit->color;
		brightness(&tmp_color, &r->origin, &hit, scene);
		color = v_tocol(&tmp_color);
		// while (++iter < RAYS_AMOUNT)
		// {
		// 	r->origin = hit.ray.origin;
		// 	r->direction = hit.ray.direction; //disperse(&hit, obj_hit);
		// 	r->direction = v_nmult(&r->direction, -1);
		// 	t = ray_trace(scene, r, depth + 1);
		// 	if (t != -1)
		// 		color = mergecol(color, t);
		// }
	}
	return (color);
}
