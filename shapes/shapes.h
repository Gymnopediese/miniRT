/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 12:42:18 by albaud            #+#    #+#             */
/*   Updated: 2023/03/19 01:44:54 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPES_H
# define SHAPES_H
# define SIZE 4
# include "../structs.h"

void		m_clean(double a[SIZE][SIZE]);
void		m_mult(double a[SIZE][SIZE], double b[SIZE][SIZE]);
void		m_copy(double dest[SIZE][SIZE], double src[SIZE][SIZE]);
double		determin(double matrix[4][4], int k);
void		m_one(double t[SIZE][SIZE]);

int			paraboloid_intersect(t_ray *ray, t_obj *cylindre, t_hit *hit);
t_v3		*paraboloid2_intersect(t_ray *ray, t_obj *cylindre, t_v3 *hit);
t_v3		m_3mults(const t_v3 *p, double m[4][4]);
void		global_to_local(t_ray *r, t_ray *new, t_obj *obj);
void		local_to_global(t_v3 *r, t_obj *obj);
t_v3		m_3mult(const t_v3 *p, double m[4][4]);
void		m_print(double t[SIZE][SIZE], char *name);
void		m_transform(t_obj *obj, t_scene *scene);
int			hyperboloid_intersect(t_ray *ray, t_obj *cylindre, t_hit *hit);
t_v3		*cone_intersect(t_ray *ray, t_obj *cone, t_v3 *hit);
int			cylindre_intersect(t_ray *ray, t_obj *cylindre, t_hit *hit);
int			plan_intersect(t_ray *ray, t_obj *plan, t_hit *hit);
void		iterate_objects(t_scene *scene);
t_vector	m_4mult(const t_v3 *p, double m[4][4]);
t_v3		*hyperboloid2_intersect(t_ray *ray, t_obj *cylindre, t_v3 *hit);
int			sphere_intersect(t_ray *r, t_obj *sphere, t_hit *hit);
t_hit		*sphere_reflection(t_hit *hit, t_v3 *origine);
// t_v3		sphere_reflection(t_ray *ray, t_obj *sphere, t_v3 *hit);

void		rotation(t_obj *obj, double t[SIZE][SIZE]);
void		m_inverse(double comatr[4][4], int f);


#endif
