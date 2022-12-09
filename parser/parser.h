/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 12:42:18 by albaud            #+#    #+#             */
/*   Updated: 2022/12/09 16:32:15 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# define ARGS_CAMERA 4
# define ARGS_LIGHT 4
# define ARGS_AMBIANCE 3

# include "../header.h"


void		init_camera(char **argv, t_scene *scene);
void		init_light(char **argv, t_scene *scene);
void		init_ambiance(char **argv, t_scene *scene);
void		init_sphere(char **argv, t_obj *cam);
void		init_plan(char **argv, t_obj *cam);
void		init_cylindre(char **argv, t_obj *cam);
void		init_cone(char **argv, t_obj *cam);
void		init_hyperboloid(char **argv, t_obj *cam);

void		valid_file(char *filename);
t_vector	ft_atovedo(char *str, double min, double max);
t_vector	ft_atovei(char *str, int min, int max);
double		ft_atodor(const char *str, double min, double max);
int			ft_atoir(const char *str, int min, int max);
#endif
