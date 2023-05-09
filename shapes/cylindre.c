/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylindre.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 12:50:34 by albaud            #+#    #+#             */
/*   Updated: 2023/03/19 01:38:26 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../header.h"

// t_vector	v_4unit(const t_vector *a)
// {
// 	double	norm;

// 	norm = sqrt(a->x * a->x + a->y * a->y + a->z * a->z + a->w * a->w);
// 	return ((t_vector){
// 		a->x / norm,
// 		a->y / norm,
// 		a->z / norm,
// 		a->w / norm,
// 	});
// }

// void	v_4print(const t_vector *a, char *name)
// {
// 	printf("%s (%f %f %f %f)\n", name, a->x, a->y, a->z, a->w);
// }

// t_vector	m_44mult(const t_vector *p, double m[4][4])
// {
// 	t_vector	r;

// 	// r.x = p->x * m[0][0] + p->y * m[1][0] + p->z * m[2][0] + m[3][0];
// 	// r.y = p->x * m[0][1] + p->y * m[1][1] + p->z * m[2][1] + m[3][1];
// 	// r.z = p->x * m[0][2] + p->y * m[1][2] + p->z * m[2][2] + m[3][2];
// 	// r.w = p->x * m[0][3] + p->y * m[1][3] + p->z * m[2][3] + m[3][3];
// 	r.x = p->x * m[0][0] + p->y * m[0][1] + p->z * m[0][2] + p->w * m[0][3];
// 	r.y = p->x * m[1][0] + p->y * m[1][1] + p->z * m[1][2] + p->w * m[1][3];
// 	r.z = p->x * m[2][0] + p->y * m[2][1] + p->z * m[2][2] + p->w * m[2][3];
// 	r.w = p->x * m[3][0] + p->y * m[3][1] + p->z * m[3][2] + p->w * m[3][3];
// 	return (r);
// }

void	cylindre_equation(t_eqt *e, t_ray *ray, t_obj *obj)
{
	e->a = ray->direction.x * ray->direction.x
		+ ray->direction.y * ray->direction.y;
	e->b = 2 * (ray->direction.x * ray->origin.x
			+ ray->direction.y * ray->origin.y);
	e->c = ray->origin.x * ray->origin.x + ray->origin.y * ray->origin.y
		- obj->diametre / 2 * obj->diametre / 2;
	e->delta = e->b * e->b - 4 * e->a * e->c;
	if (e->delta < 0)
		return ;
	e->x1 = (-e->b + sqrt(e->delta)) / (2 * e->a);
	e->x2 = (-e->b - sqrt(e->delta)) / (2 * e->a);
}

int	cylindre_intersect(t_ray *ray, t_obj *cylindre, t_hit *hit)
{
	t_eqt	e;
	t_ray	r;

	global_to_local(ray, &r, cylindre);
	cylindre_equation(&e, &r, cylindre);
	if (e.delta < 0)
		return (0);
	if (e.x2 < e.x1)
		r.origin = v_ponline(&r.origin, &r.direction, e.x2);
	else
		r.origin = v_ponline(&r.origin, &r.direction, e.x1);
	if (fabs(r.origin.z) > cylindre->hauteur)
		return (0);
	hit->normal = (t_v3){r.origin.x, r.origin.y, 0};
	hit->normal = m_3mult(&hit->normal, cylindre->transform);
	r.origin = m_3mult(&r.origin, cylindre->transform);
	hit->ray.origin = r.origin;
	hit->obj = cylindre;
	return (1);
}
	// r.origin = m_4mult(r->origin, cylindre->inverse_transform);
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
