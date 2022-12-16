/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bphilago <bphilago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:43:32 by albaud            #+#    #+#             */
/*   Updated: 2022/12/16 11:58:31 by bphilago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "parser/parser.h"

void	 apply_matrices(t_list *o, t_scene *scene)
{
	while (o)
	{
		m_transform(o->data, scene);
		o = o->next;
	}
}

int	hook(int key, t_scene *scene)
{
	t_v3	**buffer;

	buffer = malloc(scene->w.cvs.y * sizeof(*buffer)); // Pour les tests
	for (int i = 0; i < scene->w.cvs.y; ++i)
	{
		buffer[i] = malloc(scene->w.cvs.x * sizeof(**buffer)); // Pour les tests
	}
	input(key, scene);
	gradient_background(&scene->w.cvs, &(t_v3){100, 228, 228},
		&(t_v3){228, 119, 119});
	buffer = malloc(scene->w.cvs.y * sizeof(*buffer)); // Pour les tests
	for (int i = 0; i < scene->w.cvs.y; ++i)
	{
		buffer[i] = malloc(scene->w.cvs.x * sizeof(**buffer)); // Pour les tests
	}
	progressive_iteration(scene, buffer, STEPS);
	print_buffer(scene, buffer);
	ft_putimg(scene->w, scene->w.cvs.img, (t_vector){0, 0, 0, 0});
	return (0);
}

//recopie speed test
//1000000
//recopie
//make run  0,67s user 0,61s system 15% cpu 8,068 total
//make run  0,66s user 0,61s system 15% cpu 8,415 total
//make run  0,55s user 0,58s system 14% cpu 7,805 total
//non recopie
//make run  0,65s user 0,60s system 14% cpu 8,587 total
//make run  0,66s user 0,60s system 15% cpu 8,196 total
//make run  0,65s user 0,60s system 13% cpu 9,044 total
//100000000 add
//make run  0,95s user 0,03s system 85% cpu 1,147 total
//make run  0,96s user 0,04s system 84% cpu 1,168 total
//make run  0,97s user 0,04s system 85% cpu 1,187 total
//Sans reco
//make run  0,49s user 0,04s system 77% cpu 0,686 total
//make run  0,48s user 0,04s system 73% cpu 0,703 total
//make run  0,48s user 0,04s system 74% cpu 0,694 total
// int	main(void)
// {
// 	int			i = 0;
// 	t_v3	salam;
// 	t_v3	salam2;
// 	salam = (t_v3){1,2,3};
// 	salam2 = (t_v3){0,0,0};
// 	while (++i < 100000000)
// 	{
// 		v_cadd(&salam, &salam2);
// 	}
// }

void	init_intersects(t_scene *scene)
{
	scene->intersections[0] = &sphere_intersect;
	scene->intersections[1] = &plan_intersect;
	scene->intersections[2] = &cylindre_intersect;
	scene->intersections[3] = &hyperboloid_intersect;
	scene->intersections[4] = &cone_intersect;
	scene->intersections[5] = &hyperboloid2_intersect;
	scene->intersections[6] = &paraboloid_intersect;
	scene->intersections[7] = &paraboloid2_intersect;
}

void	init_scene(t_scene *scene)
{
	t_v3		**buffer;

	scene->hook = &hook;
	ft_mlx_init(&scene->w, 800, 800, "miniRT");
	scene->w.cvs = ft_init_canvas(scene->w.mlx, 800, 800);
	scene->input_mode = -1;
	gradient_background(&scene->w.cvs, &(t_v3){100, 228, 228},
		&(t_v3){228, 119, 119});
	apply_matrices(scene->objects, scene);
	init_intersects(scene);
	progressive_iteration(&scene, buffer, STEPS);
	print_buffer(&scene, buffer);
	ft_putimg(scene->w, scene->w.cvs.img, (t_vector){0, 0, 0, 0});
	print_scene(scene);
}

int	ghook(int key, t_gui *gui)
{
	gui->scene->hook(key, gui->scene);
	return (0);
}

int	mousetest(int key, int x, int y, t_scene *scene)
{
	(void) x;
	(void) y;
	(void) scene;
	ft_putnbrn(key);
	printf("jojo/n");
	return (0);
}

//asdw pour bouger et f pour passer en mode bouger la lumiere
int	main(int argc, char **argv)
{
	t_scene		scene;
	t_gui		gui;
	int 		pid;

	if (argc != 2)
	{
		ft_putendl("miniRT: usage: ./miniRT <file.rt>");
		return (0);
	}
	gui.scene = &scene;
	ft_mlx_init(&gui.w, 800, 800, "miniRT_gui");
	parse_rt_file(&scene, argv[1]);
	init_scene(&scene);
	mlx_hook(gui.w.win, 2, 0, hook, &scene);
	mlx_hook(scene.w.win, 4, 0, mousetest, &scene);
	mlx_hook(scene.w.win, 5, 0, mousetest, &scene);
	mlx_hook(scene.w.win, 2, 0, hook, &scene);
	mlx_loop(scene.w.mlx);
	// pid = fork();
	// if (pid == 0)
	// 	mlx_loop(gui.w.mlx);
	// else
	// 	mlx_loop(scene.w.mlx);
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
