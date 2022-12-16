/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 12:42:18 by albaud            #+#    #+#             */
/*   Updated: 2022/12/16 10:25:13 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPES_H
# define SHAPES_H
#define SIZE 4
# include "../structs.h"

t_v3		*paraboloid_intersect(t_ray *ray, t_obj *cylindre, t_v3 *hit);
t_v3		*paraboloid2_intersect(t_ray *ray, t_obj *cylindre, t_v3 *hit);
t_v3		m_3mults(const t_v3 *p, double m[4][4]);
void		new_dir(t_ray *r, t_ray *new, t_obj *obj);
t_v3		m_3mult(const t_v3 *p, double m[4][4]);
void		m_print(double t[SIZE][SIZE], char *name);
void		m_transform(t_obj *obj, t_scene *scene);
t_v3		*hyperboloid_intersect(t_ray *ray, t_obj *cylindre, t_v3 *hit);
t_v3		*cone_intersect(t_ray *ray, t_obj *cone, t_v3 *hit);
t_v3		*cylindre_intersect(t_ray *ray, t_obj *cylindre, t_v3 *hit);
t_v3		*plan_intersect(t_ray *ray, t_obj *plan, t_v3 *hit);
void		iterate_objects(t_scene *scene);
t_vector	m_4mult(const t_v3 *p, double m[4][4]);
t_v3		*hyperboloid2_intersect(t_ray *ray, t_obj *cylindre, t_v3 *hit);
t_v3		*sphere_intersect(t_ray *ray, t_obj *sphere, t_v3 *hit);
t_hit		*sphere_reflection(t_hit *hit, t_v3 *origine);
// t_v3		sphere_reflection(t_ray *ray, t_obj *sphere, t_v3 *hit);
#endif
