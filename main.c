/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:09:01 by albaud            #+#    #+#             */
/*   Updated: 2022/12/12 10:52:35 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "parser/parser.h"

int	coloring(t_obj	*obj, t_v3 *hit, t_scene *scene)
{
	t_v3	rgb;
	double	i;

	i = 1 - (v_dist(hit, &scene->light->pos)
			/ v_dist(&obj->pos, &scene->light->pos));
	(void) rgb;
	if (i < 0)
		i = 0;
	rgb = v_nmult(&scene->light->color, i);
	rgb = v_average(&obj->color, &rgb);
	rgb = v_average(&scene->ambiance->color, &rgb);
	return (v_tocol(&rgb));
}

int	coloring2(t_obj	*obj, t_v3 *hit, t_scene *scene)
{
	t_v3	rgb;
	double	i;
	t_v3	hit_light;
	t_v3	obj_normal;
	//t_v3	colo;

	hit_light = v_rm(&scene->light->pos, hit);
	obj_normal = v_rm(hit, &obj->pos);
	i = 1 - v_angle(&obj_normal, &hit_light) / (PI / 2);
	if (i < 0)
		i = 0;
	//hit->z += 1;
	//colo = v_unit(hit);
	//v_cnadd(&colo, 1);
	//print_vector(colo, "colo");
	//v_cnmult(&colo, 255 * 0.5);
	rgb = v_nmult(&scene->light->color, i);
	rgb = v_average(&obj->color, &rgb);
	//rgb = v_average(&colo, &rgb);
	rgb = v_average(&scene->ambiance->color, &rgb);
	return (v_tocol(&rgb));
}

int	ray_trace(t_scene *scene, t_obj *obj, t_ray *r)
{
	t_v3	hit;

	hit = sphere_intersect(r, obj);
	if (!v_equal(&hit, v_null()))
		return (coloring2(obj, &hit, scene));
	return (-1);
}

int	hook(int key, t_scene *scene)
{
	ft_putnbrn(key);
	input(key, scene);
	gradient_background(&scene->w.cvs, &(t_v3){100, 228, 228},
		&(t_v3){228, 119, 119});
	iterate_objects(scene);
	ft_putimg(scene->w, scene->w.cvs.img, (t_vector){0, 0, 0, 0});
	return (0);
}

// void clone (t_canvas dest, t_canvas src)
// {
// 	for (int i = 0; i < dest.x; i++)
// 	{
// 		for (int j = 0; j < dest.y; j++)
// 		{
// 			ft_put_pixel(&dest, i, j, get_pix(&src, i, j));
// 		}
// 	}
// }
//asdw pour bouger et f pour passer en mode bouger la lumiere
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
	scene.input_mode = -1;
	gradient_background(&scene.w.cvs, &(t_v3){100, 228, 228},
		&(t_v3){228, 119, 119});
	//scene.texture = ft_init_image(scene.w.mlx, "textures/world.xpm");
	iterate_objects(&scene);
	ft_putimg(scene.w, scene.w.cvs.img, (t_vector){0, 0, 0, 0});
	print_scene(&scene);
	mlx_hook(scene.w.win, 2, 0, hook, &scene);
	mlx_loop(scene.w.mlx);
}
