/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bphilago <bphilago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 12:42:18 by albaud            #+#    #+#             */
/*   Updated: 2023/01/15 13:27:32 by bphilago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef STRUCTS_H
# define STRUCTS_H

# include "vectors/t_v3.h"
# include "koflibc/struct.h"

enum e_id
{
	AMBIANCE,
	CAMERA,
	LUMIERE,
	SPHERE,
	PLAN,
	CYLINDRE,
	HYPERBOILD,
	CONE,
	HYPERBOILD2,
	PARABOLOID,
	PARABOLOID2,
};

typedef struct s_ray
{
	t_v3	origin;
	t_v3	direction;
}	t_ray;

typedef struct s_light
{
	double	ratio;
	t_v3	pos;
	t_v3	color;
}	t_light;

typedef struct s_ambiance
{
	double	ratio;
	t_v3	color;
}	t_ambiance;

typedef struct s_camera
{
	double	fov;
	t_v3	orientaion;
	t_v3	pos;
}	t_camera;

typedef struct s_obj
{
	enum e_id	id;
	t_v3		pos;
	t_v3		orientation;
	double		diametre;
	double		hauteur;
	t_v3		color;
	char		moved;
	double		albedo;
	double		dispertion;
	t_canvas	texture;
	double		transform[4][4];
	double		inverse_transform[4][4];
}	t_obj;

typedef struct s_hit
{
	t_ray	ray;
	t_v3	normal;
	t_obj	*obj;
}	t_hit;

typedef struct s_scene
{
	t_window		w;
	t_ambiance		*ambiance;
	t_camera		*camera;
	t_light			*light;
	t_list			*objects;
	int				input_mode;
	t_v3			*(*intersections[8])();
	int				(*hook)();
}	t_scene;

#endif
