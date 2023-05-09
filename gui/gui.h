/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 12:42:18 by albaud            #+#    #+#             */
/*   Updated: 2023/03/17 19:38:41 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GUI_H
# define GUI_H

# include "../header.h"

typedef struct s_slid
{
	double		*to_change;
	double		min;
	double		max;
	t_canvas	sprit;
	t_v3		pos;
	t_v3		size;
	double		min_x;
	double		max_x;
	void		(*pressed)();
	void		(*released)();
}	t_slid;


typedef struct s_gui
{
	t_window	w;
	t_scene		*scene;
	t_slid		sliders[6];
	t_slid		*focus;
	pthread_t	thread;
	char		key[100];
	char		current_shape;
}	t_gui;

void	init_gui(t_gui *gui);
int		button_pressed(int key, int x, int y, t_gui *gui);
int		button_realeased(int key, int x, int y, t_gui *gui);

#endif
