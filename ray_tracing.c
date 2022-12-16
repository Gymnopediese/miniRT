/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bphilago <bphilago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:22:13 by albaud            #+#    #+#             */
/*   Updated: 2022/12/16 11:50:08 by bphilago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#define MIN_SCOLOR 0.01

// Voir si cos negatif
// void	brightness(t_v3 *a, const t_v3 *origine_pos, const t_hit *hit, const t_scene *scene)
// {
// 	t_list	*objects;
// 	t_ray	r;
// 	t_v3	tmp;
// 	t_obj	*obj;

// 	objects = scene->objects;
// 	r.direction = v_rm(&hit->ray.origin, &scene->light->pos);
// 	r.origin = scene->light->pos;
// 	while (objects)
// 	{
// 		obj = objects->data;
// 		if (sphere_intersect(&r, obj, &tmp)) // Voir pour implementer plusieurs rayon par lumière pour des ombres douces + simplifier pour juste verifier si ca touche
// 		{
// 			if (!v_equal(&tmp, &hit->ray.origin))
// 			{
// 				*a = v_mult(a, &scene->ambiance->color);
// 				return ;
// 			}
// 		}	
// 		objects = objects->next;
// 	}
// 	tmp = v_mult(a, &scene->ambiance->color);
// 	v_cmult(a, &scene->light->color);
// 	t_v3 v1 = v_unit(&r.direction); // Crade
// 	t_v3 v2 = v_unit(&hit->normal);
// 	v_cnmult(a, -v_dotp(&v1, &v2));
// 	v_cadd(a, &tmp);
// }

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
	t_v3 v1 = v_unit(&r.direction); // Crade
	t_v3 v2 = v_unit(&hit->normal);
	obj->dispertion = PI;
	if (v_angle(&v1, &v2) < obj->dispertion) // En test
		v_cnmult(a, cos(v_angle(&v1, &v2) / (obj->dispertion / M_PI_2)) * (M_PI_2 / (obj->dispertion + 0.0001))); // Ajout pour eviter de diviser par 0
		// Penser a adapter la puissance des lumières
	else
		v_cnmult(a, 0.0);
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
			&& v_dist(&r->origin, &hit->ray.origin) < v_dist(&min, &r->origin)
			&& v_dist(&r->origin, &hit->ray.origin) > __FLT_EPSILON__) // Probleme
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

void	ray_trace(t_scene *scene, t_ray *r, t_v3 *l_color, t_v3 *s_color, int iter) // Enlever Iter
{
	t_hit	hit;
	t_v3	tmp_color;
	int		t;
	t_obj	*obj_hit;

	if (v_norm(s_color) < MIN_SCOLOR)
		return ;
	obj_hit = hit_obj(scene, r, &hit);
	if (obj_hit)
	{
		tmp_color = obj_hit->color;
		brightness(&tmp_color, &r->origin, &hit, scene);
		v_cmult(&tmp_color, s_color); //Prendre en compte que la brillance renvoie une partie des rayons dans tous les cas !!!
		v_cmult(s_color, &obj_hit->color);
		v_cadd(l_color, &tmp_color);
		ray_trace(scene, &hit.ray, l_color, s_color, ++iter);
	}
}
