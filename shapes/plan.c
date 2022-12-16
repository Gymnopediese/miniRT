/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 12:50:34 by albaud            #+#    #+#             */
/*   Updated: 2022/12/16 10:02:01 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

t_v3	*plan_intersect(t_ray *ray, t_obj *plan, t_v3 *hit)
{
	double	a;
	double	b;
	double	c;
	double	d;
	double	x;

	a = plan->orientation.x;
	b = plan->orientation.y;
	c = plan->orientation.z;
	d = - (a * plan->pos.x + b * plan->pos.y + c * plan->pos.y);
	x = - (a * ray->origin.x + b * ray->origin.y + c * ray->origin.z - d)
		/ (a * ray->direction.x + b * ray->direction.y
			+ c * ray->direction.z - d);
	//printf("%f %f %f %f %f\n", a, b, c, d, x);
	*hit = v_ponline(&ray->origin, &ray->direction, x);
	//print_vector(*hit, "salame: ");
	return (hit);
}

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
