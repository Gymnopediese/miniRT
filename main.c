/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:09:01 by albaud            #+#    #+#             */
/*   Updated: 2022/12/09 16:41:55 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "parser/parser.h"

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
	print_scene(&scene);
	//mlx_loop(scene.w.mlx);
}

