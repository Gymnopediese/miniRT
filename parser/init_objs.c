/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_objs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:06:36 by albaud            #+#    #+#             */
/*   Updated: 2022/12/09 16:34:02 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	init_camera(char **argv, t_scene *scene)
{
	if (scene->camera)
		error("Too many cameras in the file");
	scene->camera = allok(sizeof(*scene->camera), 1, 1);
	if (ft_strtablen(argv) != ARGS_CAMERA)
		error("Wrong arguments number for the camera");
	scene->camera->pos = ft_atovedo(argv[1], 0, 0);
	scene->camera->orientaion = ft_atovedo(argv[2], -1, 1);
	scene->camera->fov = ft_atoir(argv[3], 0, 180);
}

void	init_light(char **argv, t_scene *scene)
{
	if (scene->light)
		error("Too many lights in the file");
	scene->light = allok(sizeof(*scene->light), 1, 1);
	if (ft_strtablen(argv) != ARGS_LIGHT)
		error("Wrong arguments number for the light");
	scene->light->pos = ft_atovedo(argv[1], 0, 0);
	scene->light->ratio = ft_atodor(argv[2], 0, 1);
	scene->light->color = ft_atovei(argv[3], 0, 255);
}

void	init_ambiance(char **argv, t_scene *scene)
{
	if (scene->ambiance)
		error("Too many ambiance in the file");
	scene->ambiance = allok(sizeof(*scene->light), 1, 1);
	if (ft_strtablen(argv) != ARGS_AMBIANCE)
		error("Wrong arguments number for the ambiance");
	scene->ambiance->ratio = ft_atodor(argv[1], 0, 1);
	scene->ambiance->color = ft_atovei(argv[2], 0, 255);
}
