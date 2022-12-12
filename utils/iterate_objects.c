/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterate_objects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 19:08:13 by albaud            #+#    #+#             */
/*   Updated: 2022/12/12 12:30:58 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	iterate_objects(t_scene *scene)
{
	int		x;
	int		y;
	t_ray	r;
	//t_list	*t;
	int		color;

	y = -1;
	r.origin = scene->camera->pos;
	while (++y < scene->w.cvs.y)
	{
		x = -1;
		while (++x < scene->w.cvs.x)
		{
			r.direction = v_relative_pos(scene->w.cvs.x, scene->w.cvs.y, x, y);
			color = ray_trace(scene, &r, 0);
			if (-1 != color)
			 	ft_put_pixel(&scene->w.cvs, x, y, color);
			// t = scene->objects;
			// while (t)
			// {
			// 	color = ray_trace(scene, t->data, &r);
			// 	if (-1 != color)
			// 		ft_put_pixel(&scene->w.cvs, x, y, color);
			// 	t = t->next;
			// }
		}
	}
}
