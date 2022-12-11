/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 14:33:27 by tate              #+#    #+#             */
/*   Updated: 2022/11/23 14:55:38 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_list
{
	struct s_list	*next;
	void			*data;
}	t_list;

typedef struct s_inta
{
	int	*arr;
	int	size;
}	t_inta;

typedef struct s_strpp
{
	char	**data;
}	t_strpp;

typedef struct s_canvas
{
	void		*img;
	char		*cvs;
	int			x;
	int			y;
	int			pixel_bits;
	int			line_bytes;
	int			endian;
}	t_canvas;

typedef struct s_keyval
{
	char	*key;
	void	*uno;
	void	*dos;
	void	*tres;
}	t_keyval;

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
	double	w;
}	t_vector;

typedef struct s_player
{
	t_vector	position;
	t_vector	sprite;
	int			speed;
	double		rotation;
	int			rotspeed;
}	t_player;

typedef struct s_matrix
{
	int			**map;
	t_vector	size;
}	t_matrix;

typedef struct s_map
{
	t_matrix	lowmap;
	t_matrix	map;
	t_canvas	cvs3d;
	t_canvas	*wall;
	t_canvas	*ground;
	t_canvas	*sprites;
}	t_map;

typedef struct s_window
{
	void		*win;
	void		*mlx;
	t_canvas	cvs;
}	t_window;

typedef struct s_line
{
	t_vector	a;
	t_vector	b;
}	t_line;

#endif