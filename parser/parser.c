/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:21:18 by albaud            #+#    #+#             */
/*   Updated: 2022/12/09 16:36:23 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

enum e_id	get_id(char *line)
{
	if (ft_strcmp(line, "A") == 0)
		return (AMBIANCE);
	else if (ft_strcmp(line, "L") == 0)
		return (LUMIERE);
	else if (ft_strcmp(line, "C") == 0)
		return (CAMERA);
	else if (ft_strcmp(line, "sp") == 0)
		return (SPHERE);
	else if (ft_strcmp(line, "pl") == 0)
		return (PLAN);
	else if (ft_strcmp(line, "cy") == 0)
		return (CYLINDRE);
	else if (ft_strcmp(line, "cn") == 0)
		return (CYLINDRE);
	else if (ft_strcmp(line, "hb") == 0)
		return (CYLINDRE);
	else if (ft_strcmp(line, "pb") == 0)
		return (CYLINDRE);
	error("invalid object type in .rt file");
	return (0);
}

void	ligne_to_shape(char **argv, t_scene *scene, enum e_id id)
{
	t_obj	*obj;

	obj = allok(sizeof(*obj), 1, 1);
	if (id == SPHERE)
		init_sphere(argv, obj);
	else if (id == PLAN)
		init_plan(argv, obj);
	else if (id == CYLINDRE)
		init_cylindre(argv, obj);
	else if (id == CONE)
		init_cone(argv, obj);
	else if (id == HYPERBOILD)
		init_hyperboloid(argv, obj);
	ft_lstadd_back(&scene->objects, ft_lstnew(obj)); //todo pimplist
}

void	ligne_to_obj(char *line, t_scene *scene)
{
	enum e_id	id;
	char		**argv;

	argv = ft_split(line, ' ');
	if (argv == 0)
		error("split malloc error");
	ft_putendl(line);
	id = get_id(argv[0]);
	ft_putnbrn(CAMERA);
	if (id == AMBIANCE)
		init_ambiance(argv, scene);
	else if (id == LUMIERE)
		init_light(argv, scene);
	else if (id == CAMERA)
		init_camera(argv, scene);
	else
		ligne_to_shape(argv, scene, id);
	ft_free_pp((void **)argv);
}

void	parse_rt_file(t_scene *scene, char *file_name)
{
	char	**lines;
	int		i;

	valid_file(file_name);
	lines = ft_read_lignes(file_name);
	if (lines == 0)
		error("the file does not exist");
	i = -1;
	scene->ambiance = 0;
	scene->camera = 0;
	scene->light = 0;
	scene->objects = 0;
	while (lines[++i])
		ligne_to_obj(lines[i], scene);
}
