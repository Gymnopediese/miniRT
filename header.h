/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bphilago <bphilago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 12:42:18 by albaud            #+#    #+#             */
/*   Updated: 2023/05/09 15:05:06 by bphilago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# define STEPS 3

# include "koflibc/sources.h"
# include "structs.h"
# include "background/background.h"
# include "shapes/shapes.h"
# include "gui/gui.h"

void		print_scene(t_scene *i);
void		parse_rt_file(t_scene *scene, char *file_name);
void		error(char *message);
void		input(int key, t_scene *scene);
// void		iterate_objects(t_scene *scene);
t_v3		v_relative_pos(double height, double width, double x, double y);
void		ray_trace(t_scene *scene, t_ray *r, t_v3 *l_color,
				t_v3 *s_color, float disperssion, int iter);
void		print_vector(t_v3 a, char *name);
int			damier(t_obj *obj, t_v3 *hit, t_scene *scene);
int			uvmapping(t_obj *obj, t_v3 *hit, t_scene *scene);
// Dispersion
t_v3		disperse(t_hit *hit, t_obj *obj);
int			coloring2(t_obj	*obj, t_v3 *hit, t_scene *scene);
// test
void		print_buffer(t_scene *scene, t_v3 **buffer);
void		progressive_iteration(t_scene *scene, t_v3 **buffer, int steps);
#endif
