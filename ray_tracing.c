/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:22:13 by albaud            #+#    #+#             */
/*   Updated: 2023/03/22 15:17:19 by albaud           ###   ########.fr       */
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

// void	brightness(t_v3 *a, const t_v3 *origine_pos, const t_hit *hit, const t_scene *scene)
// {
// 	t_list	*objects;
// 	t_ray	r;
// 	t_v3	tmp;
// 	t_obj	*obj;

// 	objects = scene->objects;
// 	r.direction = v_rm(&scene->light->pos, &hit->ray.origin);
// 	r.origin = hit->ray.origin;
// 	while (objects)
// 	{
// 		obj = objects->data;
// 		if (sphere_intersect(&r, obj, &tmp)) // Voir pour implementer plusieurs rayon par lumière pour des ombres douces + simplifier pour juste verifier si ca touche
// 		{
// 			*a = v_mult(a, &scene->ambiance->color);
// 			return ;
// 		}
// 		objects = objects->next;
// 	}
// 	tmp = v_mult(a, &scene->ambiance->color);
// 	v_cmult(a, &scene->light->color);
// 	t_v3 v1 = v_unit(&r.direction); // Crade
// 	t_v3 v2 = v_unit(&hit->normal);
// 	obj->dispertion = PI;
// 	if (v_angle(&v1, &v2) < obj->dispertion) // En test
// 		v_cnmult(a, cos(v_angle(&v1, &v2) / (obj->dispertion / M_PI_2)) * (M_PI_2 / (obj->dispertion + 0.0001))); // Ajout pour eviter de diviser par 0
// 		// Penser a adapter la puissance des lumières
// 	else
// 		v_cnmult(a, 0.0);
// 	v_cadd(a, &tmp);
// }

int	hit_obj(t_scene *scene, t_ray *r, t_hit *hit)
{
	t_list	*objects;
	t_obj	*obj;
	double	min;
	t_obj	*cobj;
	double	t;

	min = 999999;
	objects = scene->objects;
	while (objects)
	{
		obj = objects->data;
		if (scene->intersections[obj->id - 3](r, obj, hit))
		{
			t = v_dist(&r->origin, &hit->ray.origin);
			if (t < min)
			{
				min = t;
				cobj = obj;
			}
		}
		objects = objects->next;
	}
	if (min == 999999)
		return (0);
	scene->intersections[cobj->id - 3](r, cobj, hit);
	return (1);
}

int	ray_trace_basic(t_scene *scene, t_ray *r) // Enlever Iter
{
	t_hit		hit;
	t_v3		col;

	hit.obj = 0;
	if (hit_obj(scene, r, &hit))
	{
		col = v_nmult(&hit.obj->color, 255);
		r->origin = hit.ray.origin;
		r->direction = v_rm(&r->origin, &scene->light->pos);
		v_normalize(&r->origin);
		v_normalize(&r->direction);
		col = v_nmult(&col, fabs(v_dotp(&r->origin, &r->direction) / 3) * scene->light->ratio + 1 - scene->light->ratio);
		if (v_dotp(&r->origin, &r->direction) < 0)
			col = v_nmult(&col, 0);
		return (v_tocol(&col));
	}
	return (-1);
}


void	ray_trace(t_scene *scene, t_ray *r, t_v3 *l_color, t_v3 *s_color, int iter) // Enlever Iter
{
	t_hit	hit;
	t_v3	tmp_color;
	t_obj	*obj_hit;

	obj_hit = 0;
	if (v_norm(s_color) < MIN_SCOLOR)
		return ;
	if (hit_obj(scene, r, &hit))
	{
		*s_color = obj_hit->color;
		tmp_color = obj_hit->color;
		//brightness(&tmp_color, &r->origin, &hit, scene);
		v_cmult(&tmp_color, s_color); //Prendre en compte que la brillance renvoie une partie des rayons dans tous les cas !!!
		v_cmult(s_color, &obj_hit->color);
		v_cadd(l_color, &tmp_color);
		ray_trace(scene, &hit.ray, l_color, s_color, ++iter);
	}
}
