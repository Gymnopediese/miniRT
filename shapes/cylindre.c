/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylindre.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 12:50:34 by albaud            #+#    #+#             */
/*   Updated: 2022/12/14 22:29:36 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../header.h"

t_vector	v_4unit(const t_vector *a)
{
	double	norm;

	norm = sqrt(a->x * a->x + a->y * a->y + a->z * a->z + a->w * a->w);
	return ((t_vector){
		a->x / norm,
		a->y / norm,
		a->z / norm,
		a->w / norm,
	});
}

t_ray	change_referentielo(t_ray *ray, t_v3 *new_ref)
{
	t_ray	new_dir;

	if (v_equal(new_ref, v_null()))
		return (*ray);
	new_dir.origin = v_mult(&ray->origin, new_ref);
	//new_dir.direction = v_mult(&ray->direction, new_ref);
	return (new_dir);
}

t_ray	change_referentiel3(t_ray *ray, t_v3 *new_ref)
{
	t_ray	new_dir;
	t_v3	normal;

	normal = v_unit(&ray->origin);
	new_dir.origin = v_v3mult(&normal, new_ref);
	normal = v_unit(&ray->direction);
	new_dir.direction = v_v3mult(&normal, new_ref);
	return (new_dir);
}

t_ray	change_referentiel(t_ray *ray, t_v3 *new_ref)
{
	t_ray	new_dir;

	new_dir.origin = v_v3mult(&ray->origin, new_ref);
	new_dir.direction = v_v3mult(&ray->direction, new_ref);
	return (new_dir);
}

t_vector	v_4ponline(const t_vector *a, const t_vector *b, const double x)
{
	return ((t_vector)
		{
			a->x + b->x * x,
			a->y + b->y * x,
			a->z + b->z * x,
			a->w + b->w * x,
		});
}


t_v3	*cylindre_intersect(t_ray *r, t_obj *cylindre, t_v3 *hit)
{
	double	a;
	double	b;
	double	c;
	double	x;
	t_vector	or;
	t_vector	di;

	//v_cnmult(&r->direction, -1);
	or = m_4mult(&r->origin, cylindre->inverse_transform);
	//t = v_unit(&r->direction);
	di = m_4mult(&r->direction, cylindre->inverse_transform);
	di = v_4unit(&di);
	//v_cnmult(&r->direction, -1);
	a = di.x * di.x + di.y * di.y;
	b = 2 * (di.x * or.x + di.y * or.y);
	c = or.x * or.x + or.y * or.y
		- cylindre->diametre / 2 * cylindre->diametre / 2;
	x = b * b - 4 * a * c;
	if (x < 0)
		return (0);
	x = (-b - sqrt(x)) / (2 * a);
	c = (-b + sqrt(x)) / (2 * a);
	if (c < x)
		or = v_4ponline(&or, &di, c);
	else
		or = v_4ponline(&or, &di, x);
	if (fabs(or.z) > 1)
		return (0);
	//  m_print(cylindre->transform);
	//  m_print(cylindre->inverse_transform);
	//print_vector(*(t_v3 *)&or, "before come back:");
	or = m_4mult(hit, cylindre->transform);
	//print_vector(*(t_v3 *)&or, "after come back:");
	hit->x = or.x;
	hit->y = or.y;
	hit->z = or.z;
	//print_vector(*hit, "HIIITIT");
	return (hit);
}
	// or = m_4mult(r->origin, cylindre->inverse_transform);
	// di = m_4mult(r->direction, cylindre->inverse_transform);
	// a = ray.direction.x * ray.direction.x + ray.direction.y * ray.direction.y;
	// b = 2 * (ray.origin.x * ray.direction.x + ray.origin.y * ray.direction.y);
	// c = ray.origin.x * ray.origin.x + ray.origin.y * ray.origin.y
	// 	- cylindre->diametre / 2 * cylindre->diametre / 2;
	// x = b * b - 4 * a * c;
	// if (x < 0)
	// 	return (0);
	// x = (-b - sqrt(x)) / (2 * a);
	// //printf("%f %f %f %f\n", a, b, c, x);
	// *hit = v_ponline(&ray.origin, &ray.direction, x);
	// //*hit = v_v3mult(hit, &ray->direction);
	// //printf("%f\n", hit->z);

	// v_cadd(hit, &cylindre->pos);
	// // print_vector(*hit, "hit sphere");
	// // printf("ranfom %f\n", v_dist(hit, &cylindre->pos));
	// if (v_dist(hit, &cylindre->pos) > 1)
	// 	return (0);
	// return (hit);

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
