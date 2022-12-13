/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterate_objects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bphilago <bphilago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 19:08:13 by albaud            #+#    #+#             */
/*   Updated: 2022/12/13 10:58:56 by bphilago         ###   ########.fr       */
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

void	progressive_iteration(t_scene *scene, int **buffer, int steps)
{
	int		x;
	int		y;
	int		line_size;
	t_ray	r;
	int		color;

	y = -1;
	r.origin = scene->camera->pos;
	while (++y < scene->w.cvs.y)
	{
		x = -1;
		while (++x < scene->w.cvs.x)
		{
			if (y % steps != 0)
				buffer[y][x] = -1;
			else if (x % steps != 0)
				buffer[y][x] = -1;
			else
			{
				r.direction = v_relative_pos(scene->w.cvs.x, scene->w.cvs.y, x, y);
				color = ray_trace(scene, &r, 0); // Voir si color == -1
				if (color == -1)
					color = 0;
				buffer[y][x] = color;
			}
		}
	}
}

void	print_buffer(t_scene *scene, int **buffer)
{
	int		x;
	int		y;
	int		skip_x;
	int		skip_y;
	int		tmp_x;
	int		tmp_y;
	int		color;

	y = 0;
	x = 0;
	while (y < scene->w.cvs.y)
	{
		skip_y = 1;
		while (y + skip_y < scene->w.cvs.y && buffer[y + skip_y][x] == -1)
			++skip_y;
		while (x < scene->w.cvs.x)
		{
			skip_x = 1;
			color = buffer[y][x];
			while (x + skip_x < scene->w.cvs.x && buffer[y][x + skip_x] == -1)
				++skip_x;
			x += skip_x;
			tmp_y = skip_y;
			tmp_x = skip_x;
			while (tmp_y > 0)
			{
				tmp_x = skip_x;
				while (tmp_x > 0)
				{
					ft_put_pixel(&scene->w.cvs, x - tmp_x, y - tmp_y, color);
					tmp_x -= 1;
				}
				tmp_y -= 1;
			}
		}
		x = 0;
		y += skip_y;
	}
}
