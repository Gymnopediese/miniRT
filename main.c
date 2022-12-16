/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bphilago <bphilago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:43:32 by albaud            #+#    #+#             */
/*   Updated: 2022/12/14 11:37:16 by bphilago         ###   ########.fr       */
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
	//rgb = v_average(&colo, &rgb);
	//rgb = v_average(&scene->ambiance->color, &rgb);
	rgb = v_nmult(&scene->ambiance->color, i);
	rgb = v_average(&obj->color, &rgb);
	rgb = v_average(&scene->light->color, &rgb);
	// rgb = v_nmult(&obj->color, i);
	// rgb = v_average(&scene->light->color, &rgb);
	//rgb = v_nmult(&scene->light->color, i);
	//rgb = v_average(&obj->color, &rgb);
	return (v_tocol(&rgb));
}

int	hook(int key, t_scene *scene)
{
	t_v3	**buffer;

	buffer = malloc(scene->w.cvs.y * sizeof(*buffer)); // Pour les tests
	for (int i = 0; i < scene->w.cvs.y; ++i)
	{
		buffer[i] = malloc(scene->w.cvs.x * sizeof(**buffer)); // Pour les tests
	}
	ft_putnbrn(key);
	input(key, scene);
	gradient_background(&scene->w.cvs, &(t_v3){100, 228, 228},
		&(t_v3){228, 119, 119});
	// iterate_objects(scene);
	// test :
	progressive_iteration(scene, buffer, STEPS);
	print_buffer(scene, buffer);
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
	t_v3		**buffer;

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
	buffer = malloc(scene.w.cvs.y * sizeof(*buffer)); // Pour les tests
	for (int i = 0; i < scene.w.cvs.y; ++i)
	{
		buffer[i] = malloc(scene.w.cvs.x * sizeof(**buffer)); // Pour les tests
	}
	progressive_iteration(&scene, buffer, STEPS);
	print_buffer(&scene, buffer);
	ft_putimg(scene.w, scene.w.cvs.img, (t_vector){0, 0, 0, 0});
	print_scene(&scene);
	mlx_hook(scene.w.win, 2, 0, hook, &scene);
	mlx_loop(scene.w.mlx);
}

// t_hit	hit;

	// hit.normal = (t_v3){-1,-1, 0};
	// hit.ray.origin = (t_v3){2,2, 2};
	// print_vector(sphere_reflection(&hit, &(t_v3){0, 0, 0})->ray.direction, "testttt");
	// return (0);
	
// int	main(void)
// {
// 	t_hit	hit_test;
// 	t_obj	obj_test;
// 	t_v3	new_vec;

// 	srand(42);
// 	for (int i = 0; i < 50; ++i)
// 	{
// 		hit_test.normal = (t_v3){0, 0, 0};
// 		hit_test.ray.direction = (t_v3){1, 1, 1};
// 		obj_test.dispertion = PI / 8;
// 		new_vec = disperse(&hit_test, &obj_test);
// 		printf("new vector : %f, %f, %f\n", new_vec.x, new_vec.y, new_vec.z);
// 	}
// }
