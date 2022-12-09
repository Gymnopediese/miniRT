/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:21:18 by albaud            #+#    #+#             */
/*   Updated: 2022/12/09 14:46:04 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

enum e_id	get_id(char *line)
{
	if (ft_strcmp_word(line, "A"))
		return (AMBIANCE);
	else if (ft_strcmp_word(line, "L"))
		return (LUMIERE);
	else if (ft_strcmp_word(line, "C"))
		return (CAMERA);
	else if (ft_strcmp_word(line, "sp"))
		return (SPHERE);
	else if (ft_strcmp_word(line, "pl"))
		return (PLAN);
	else if (ft_strcmp_word(line, "cy"))
		return (CYLINDRE);
	else if (ft_strcmp_word(line, "cn"))
		return (CYLINDRE);
	else if (ft_strcmp_word(line, "hb"))
		return (CYLINDRE);
	else if (ft_strcmp_word(line, "pb"))
		return (CYLINDRE);
}

void	ligne_to_shape(char *line, t_scene *scene, enum e_id id)
{
	t_obj	*obj;

	obj = allok(sizeof(*obj), 1, 1);
	if (id == SPHERE)
		init_sphere(line, obj);
	else if (id == PLAN)
		init_plan(line, obj);
	else if (id == CYLINDRE)
		init_cylindre(line, obj);
	else if (id == CONE)
		init_code(line, obj);
	else if (id == HYPERBOILD)
		init_hyperboloid(line, obj);
	ft_lstadd_back(&scene->objects, ft_lstnew(obj)); //todo pimplist
}

void	ligne_to_obj(char *line, t_scene *scene)
{
	enum e_id	id;

	id = get_id(line);
	if (id == AMBIANCE)
		init_ambiance(line, &scene->camera);
	else if (id == LUMIERE)
		init_light(line, &scene->camera);
	else if (id == CAMERA)
		init_camera(line, &scene->camera);
	else
		ligne_to_shape(line, scene, id);
}

int	parse_rt_file(t_scene *scene, char *file_name)
{
	char	**lines;
	t_obj	tmp;
	int		i;

	valid_file(file_name);
	lines = ft_read_lignes(file_name);
	if (lines == 0)
		error("the file does not exist");
	i = -1;
	while (lines[++i])
		ligne_to_obj(lines[i], scene);
}
