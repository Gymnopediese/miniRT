/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bphilago <bphilago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:22:13 by albaud            #+#    #+#             */
/*   Updated: 2023/05/09 15:14:26 by bphilago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#define MIN_SCOLOR 0.01

void	brightness(t_v3 *tmp_color, const t_v3 *origine_pos, const t_hit *hit, const t_scene *scene)
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
		if (sphere_intersect(&r, obj, &tmp))
		{
			v_cnmult(tmp_color, 0.0);
			return ;
		}
		objects = objects->next;
	}
	v_cmult(tmp_color, &scene->light->color);
	t_v3 v1 = v_unit(&r.direction);
	t_v3 v2 = v_unit(&hit->normal);
	obj->dispertion = PI;
	v_cnmult(tmp_color, cos(v_angle(&v1, &v2)));
}

t_obj	*hit_obj(t_scene *scene, t_ray *r, t_hit *hit)
{
	t_list	*objects;
	t_obj	*obj;
	t_v3	min;
	t_obj	*colid_obj;

	min = (t_v3){100000, 100000, 100000};
	objects = scene->objects;
	while (objects)
	{
		obj = objects->data;
		if (scene->intersections[obj->id - 3](r, obj, &hit->ray.origin)
			&& v_dist(&r->origin, &hit->ray.origin) < v_dist(&min, &r->origin)
			&& v_dist(&r->origin, &hit->ray.origin) > 0.01)
		{
			min = hit->ray.origin;
			colid_obj = obj;
		}
		objects = objects->next;
	}
	if (v_equal(&min, &(t_v3){100000, 100000, 100000}))
		return (0);
	hit->ray.origin = min;
	hit = sphere_reflection(hit, &r->origin); // TODO enlever car plus de reflexion
	hit->normal = v_rm(&hit->ray.origin, &colid_obj->pos);
	return (colid_obj);
}

void	ray_trace(t_scene *scene, t_ray *r, t_v3 *l_color, t_v3 *s_color,
			float disperssion, int iter) // Enlever Iter
{
	t_hit	hit;
	t_v3	tmp_color;
	int		t;
	t_obj	*obj_hit;

	if (v_norm(s_color) < MIN_SCOLOR || disperssion < 0.01 || iter > 1)
		return ;
	obj_hit = hit_obj(scene, r, &hit);
	if (obj_hit)
	{
		tmp_color = obj_hit->color;
		brightness(&tmp_color, &r->origin, &hit, scene);
		v_cmult(&tmp_color, s_color); //Prendre en compte que la brillance renvoie une partie des rayons dans tous les cas !!!
		//v_cnmult(&tmp_color, disperssion); // Quantite de rayon qui attendra la camera
		v_cnmult(&r->direction, -1);
		// disperssion *= A faire;
		v_cmult(s_color, &obj_hit->color);
		v_cadd(l_color, &tmp_color);
		tmp_color = v_mult(&scene->ambiance->color, &obj_hit->color);
		v_cadd(l_color, &tmp_color);
		//ray_trace(scene, &hit.ray, l_color, s_color, disperssion, ++iter);
	}
}
