/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 12:42:18 by albaud            #+#    #+#             */
/*   Updated: 2022/12/12 13:24:08 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPES_H
# define SHAPES_H

# include "../structs.h"

void	iterate_objects(t_scene *scene);
//spheres
t_v3	*sphere_intersect(t_ray *ray, t_obj *sphere, t_v3 *hit);
t_v3	sphere_reflection(t_ray *ray, t_obj *sphere, t_v3 *hit);
#endif
