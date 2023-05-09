/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bphilago <bphilago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 12:42:18 by albaud            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/03/19 01:28:30 by albaud           ###   ########.fr       */
=======
/*   Updated: 2023/01/15 13:27:32 by bphilago         ###   ########.fr       */
>>>>>>> 1f52c712e9df5d4d33ce49ab8155b5564be9c2c8
/*                                                                            */
/* ************************************************************************** */


#ifndef STRUCTS_H
# define STRUCTS_H

# include "vector3d/t_v3.h"
# include "koflibc/struct.h"
# include <pthread.h>

typedef struct s_eqt
{
	double	a;
	double	b;
	double	c;
	double	delta;
	double	x1;
	double	x2;
}	t_eqt;

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
	t_v3		scale;
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

typedef struct s_scene	t_scene;

typedef struct s_process
{
	pthread_t	thread;
	t_v3		start;
	int			iteration;
	t_scene		*scene;
}	t_process;

typedef struct s_scene
{
	t_window		w;
	t_ambiance		*ambiance;
	t_camera		*camera;
	t_light			*light;
	t_list			*objects;
	int				input_mode;
	int				(*intersections[8])();
	int				(*hook)();

	char			inputs[128];
	//create a struc for those
	t_process		*processes;
	int				process_count;
	int				process_amount;
	pthread_mutex_t	lock;
}	t_scene;


#endif
