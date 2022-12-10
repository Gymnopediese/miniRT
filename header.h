/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 12:42:18 by albaud            #+#    #+#             */
/*   Updated: 2022/12/10 19:35:27 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "koflibc/sources.h"
# include "background/background.h"

enum e_id
{
	AMBIANCE,
	CAMERA,
	LUMIERE,
	SPHERE,
	PLAN,
	CYLINDRE,
	CONE,
	HYPERBOILD,
	PARABOLOID,
};

typedef struct s_ray
{
	t_vector	*origin;
	t_vector	direction;
}	t_ray;


typedef struct s_light
{
	double		ratio;
	t_vector	pos;
	t_vector	color;
}	t_light;

typedef struct s_ambiance
{
	double		ratio;
	t_vector	color;
}	t_ambiance;

typedef struct s_camera
{
	double		fov;
	t_vector	orientaion;
	t_vector	pos;
}	t_camera;


typedef struct s_obj
{
	enum e_id	id;
	t_vector	pos;
	t_vector	orientation;
	double		diametre;
	double		hauteur;
	t_vector	color;
}	t_obj;

typedef struct s_scene
{
	t_window	w;
	t_ambiance	*ambiance;
	t_camera	*camera;
	t_light		*light;
	t_list		*objects;
}	t_scene;

void		print_scene(t_scene *i);
void		parse_rt_file(t_scene *scene, char *file_name);
void		error(char *message);
//ptere pas non
t_vector	ft_normal(t_vector a, t_vector b, t_vector c);
t_vector	m4mult(t_vector pos, double m[4][4], int div);

void		rot(t_camera *cam);
double		dotprod(t_vector a, t_vector b);
void		rgb(int *pointer);
void		handle_input(int key, t_camera *cam);


//to remove
void		print_vector(t_vector a, char *name);
#endif
