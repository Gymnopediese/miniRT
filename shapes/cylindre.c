/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylindre.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 12:50:34 by albaud            #+#    #+#             */
/*   Updated: 2022/12/16 10:34:13 by albaud           ###   ########.fr       */
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

void	v_4print(const t_vector *a, char *name)
{
	printf("%s (%f %f %f %f)\n", name, a->x, a->y, a->z, a->w);
}

t_vector	m_44mult(const t_vector *p, double m[4][4])
{
	t_vector	r;

	// r.x = p->x * m[0][0] + p->y * m[1][0] + p->z * m[2][0] + m[3][0];
	// r.y = p->x * m[0][1] + p->y * m[1][1] + p->z * m[2][1] + m[3][1];
	// r.z = p->x * m[0][2] + p->y * m[1][2] + p->z * m[2][2] + m[3][2];
	// r.w = p->x * m[0][3] + p->y * m[1][3] + p->z * m[2][3] + m[3][3];
	r.x = p->x * m[0][0] + p->y * m[0][1] + p->z * m[0][2] + p->w * m[0][3];
	r.y = p->x * m[1][0] + p->y * m[1][1] + p->z * m[1][2] + p->w * m[1][3];
	r.z = p->x * m[2][0] + p->y * m[2][1] + p->z * m[2][2] + p->w * m[2][3];
	r.w = p->x * m[3][0] + p->y * m[3][1] + p->z * m[3][2] + p->w * m[3][3];
	return (r);
}

t_v3	*cylindre_intersect(t_ray *ray, t_obj *cylindre, t_v3 *hit)
{
	double	a;
	double	b;
	double	c;
	double	x;
	t_ray	r;

	new_dir(ray, &r, cylindre);
	a = r.direction.x * r.direction.x + r.direction.y * r.direction.y;
	b = 2 * (r.direction.x * r.origin.x + r.direction.y * r.origin.y);
	c = r.origin.x * r.origin.x + r.origin.y * r.origin.y
		- cylindre->diametre / 2 * cylindre->diametre / 2;
	x = b * b - 4 * a * c;
	if (x <= 0)
		return (0);
	c = (-b + sqrt(x)) / (2 * a);
	x = (-b - sqrt(x)) / (2 * a);
	if (c < 0 || x < 0)
		return (0);
	if (c < x)
		r.origin = v_ponline(&r.origin, &r.direction, c);
	else
		r.origin = v_ponline(&r.origin, &r.direction, x);
	if (fabs(r.origin.z) > cylindre->hauteur)
		return (0);
	r.origin = m_3mult(&r.origin, cylindre->transform);
	hit->x = r.origin.x;
	hit->y = r.origin.y;
	hit->z = r.origin.z;

	return (hit);
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
