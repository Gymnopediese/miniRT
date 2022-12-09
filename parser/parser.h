/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 12:42:18 by albaud            #+#    #+#             */
/*   Updated: 2022/12/09 14:57:26 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# define ARGS_CAMERA 4
# define ARGS_LIGHT 4
# define ARGS_AMBIANCE 3

# include "../header.h"


void		init_camera(char *line, t_scene *scene);
void		init_light(char *line, t_scene *scene);
void		init_ambiance(char *line, t_scene *scene);
void		init_sphere(char *line, t_obj *cam);
void		init_plan(char *line, t_obj *cam);
void		init_cylindre(char *line, t_obj *cam);
void		init_cone(char *line, t_obj *cam);
void		init_hyperboloid(char *line, t_obj *cam);

int			ft_strcmp_word(char *line, char *cmp);
void		valid_file(char *filename);
t_vector	ft_atovedo(char *str, double min, double max);
t_vector	ft_atovei(char *str, int min, int max);
#endif
