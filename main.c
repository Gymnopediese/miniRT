/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:09:01 by albaud            #+#    #+#             */
/*   Updated: 2022/12/11 10:40:28 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "parser/parser.h"
#define ADD 5
//θ = cos-1 [ (a · b) / (|a| |b|) ]

__global__	int	hit_circle(const t_ray *ray, const t_obj *c)
{
	t_v3	opos;
	t_v3	cpos;

	opos = v_rm(&c->pos, &ray->origin);
	cpos = ray->direction;
	return (c->diametre >= v_norm(&opos)
		* tanf(v_angle(&cpos, &opos)));
}

t_v3	v_relative_pos(double height, double width, double x, double y)
{
	return ((t_v3){
		(x - width / 2) * 2 / width,
		(y - height / 2) * 2 / height,
		1,
	});
}

void	ray_trace(t_scene *scene)
{
	int		x;
	int		y;
	t_ray	r;
	t_list	*t;

	y = -1;
	r.origin = scene->camera->pos;
	while (++y < scene->w.cvs.y)
	{
		x = -1;
		while (++x < scene->w.cvs.x)
		{
			r.direction = v_relative_pos(scene->w.cvs.x, scene->w.cvs.y, x, y);
			t = scene->objects;
			while (t)
			{
				if (hit_circle(&r, t->data))
				{
					ft_put_pixel < < < 1, 2 > > > (&scene->w.cvs,
						x, y, v_tocol(&((t_obj *)t->data)->color));
				}
				t = t->next;
			}
		}
	}
}

int	hook(int key, t_scene *scene)
{
	ft_putnbrn(key);
	if (key == KEYCODE_A)
		scene->camera->pos.x -= ADD;
	if (key == KEYCODE_S)
		scene->camera->pos.y += ADD;
	if (key == KEYCODE_D)
		scene->camera->pos.x += ADD;
	if (key == KEYCODE_W)
		scene->camera->pos.y -= ADD;
	gradient_background(&scene->w.cvs, &(t_v3){100, 228, 228},
		&(t_v3){228, 119, 119});
	ray_trace(scene);
	ft_putimg(scene->w, scene->w.cvs.img, (t_vector){0, 0, 0, 0});
	return (0);
}

int	main(int argc, char **argv)
{
	t_scene		scene;

	if (argc != 2)
	{
		ft_putendl("miniRT: usage: ./miniRT <file.rt>");
		return (0);
	}
	parse_rt_file(&scene, argv[1]);
	ft_mlx_init(&scene.w, 800, 800, "miniRT");
	scene.w.cvs = ft_init_canvas(scene.w.mlx, 800, 800);
	gradient_background(&scene.w.cvs, &(t_v3){100, 228, 228},
		&(t_v3){228, 119, 119});
	ray_trace(&scene);
	ft_putimg(scene.w, scene.w.cvs.img, (t_vector){0, 0, 0, 0});
	print_scene(&scene);
	mlx_hook(scene.w.win, 2, 0, hook, &scene);
	mlx_loop(scene.w.mlx);
}
