/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:55:44 by albaud            #+#    #+#             */
/*   Updated: 2023/03/17 19:41:10 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#define SLIDER_SIZE 30

double	range(double a, double min, double max)
{
	if (a < min)
		return (min);
	if (a > max)
		return (max);
	return (a);
}

void	slider_pressed(t_slid *s)
{
	(void) s;
}

void	slider_released(t_slid *s, t_v3 *pos)
{
	double	new_val;

	new_val = range(pos->x, s->min_x, s->max_x);
	new_val = (s->max_x - s->min_x) / new_val;
	new_val = (s->max - s->min) / new_val;
	*s->to_change = new_val;
	if (pos->x > s->max_x)
		pos->x = s->max_x;
	if (pos->x < s->min_x)
		pos->x = s->min_x;
	s->pos.x = pos->x;
}

void	init_slider(t_slid *slid, double *i, t_v3 pos, t_v3 minmax)
{
	slid->pressed = slider_pressed;
	slid->released = slider_released;
	slid->pos = pos;
	slid->min = minmax.x;
	slid->max = minmax.y;
	slid->min_x = pos.x;
	slid->max_x = minmax.z;
	slid->to_change = i;
	slid->size = (t_v3){SLIDER_SIZE, SLIDER_SIZE, 0};
}

int	clicked(t_v3 *click, t_v3 *pos, t_v3 *size)
{
	return (click->x > pos->x && click->y > pos->y
		&& click->x < pos->x + size->x && click->y < pos->y + size->y);
}

void	*thread_mlx_loop(void *mlx)
{
	mlx_loop(mlx);
	return (0);
}

int	mouse_down(int key, int x, int y, t_gui *gui)
{
	int		i;
	t_v3	pos;
	pos = (t_v3){x, y, 0};
	gui->key[key] = 1;
	i = -1;
	while (++i < 6)
	{
		if (clicked(&pos, &gui->sliders[i].pos, &gui->sliders[i].size))
			gui->focus = &gui->sliders[i];
	}
	return (0);
}

int	mouse_up(int key, int x, int y, char *keys)
{
	(void) x;
	(void) y;
	printf("key %i\n", key);
	keys[key] = 0;
	return (0);
}

int	mouse_move(int x, int y, t_gui *gui)
{
	int		i;
	t_v3	pos;

	i = -1;
	pos = (t_v3){x, y, 0};
	mlx_clear_window(gui->w.mlx, gui->w.win);
	while (++i < 6)
		ft_putimg(gui->w, gui->sliders->sprit.img, *(t_vector *)&gui->sliders[i].pos);
	if (!gui->key[1] || !gui->focus)
		return (0);
	v_print(&pos);
	slider_released(gui->focus, &pos);
	gui->scene->hook(gui->scene);
	return (0);
}

void	init_sliders(t_gui *gui, int i)
{
	t_list	*obj;

	obj = gui->scene->objects;
	while (--i >= 0)
		obj = obj->next;
	init_slider(&gui->sliders[0],
		&((t_obj *)obj->data)->scale.x,
		(t_v3){10, SLIDER_SIZE + 10, 0}, (t_v3){1, 10, 100});
	init_slider(&gui->sliders[1],
		&((t_obj *)obj->data)->scale.y,
		(t_v3){10, (SLIDER_SIZE + 10) * 2, 0}, (t_v3){1, 10, 100});
	init_slider(&gui->sliders[2],
		&((t_obj *)obj->data)->scale.z,
		(t_v3){10, (SLIDER_SIZE + 10) * 3, 0}, (t_v3){1, 10, 100});
	init_slider(&gui->sliders[3],
		&((t_obj *)obj->data)->orientation.x,
		(t_v3){10, (SLIDER_SIZE + 10) * 4, 0}, (t_v3){0, PI, 100});
	init_slider(&gui->sliders[4],
		&((t_obj *)obj->data)->orientation.y,
		(t_v3){10, (SLIDER_SIZE + 10) * 5, 0}, (t_v3){0, PI, 100});
	init_slider(&gui->sliders[5],
		&((t_obj *)obj->data)->orientation.z,
		(t_v3){10, (SLIDER_SIZE + 10) * 6, 0}, (t_v3){0, PI, 100});
}

int	key(int k, t_gui *gui)
{
	if (k == KEYCODE_0 && gui->current_shape > 0)
		gui->current_shape--;
	if (k == KEYCODE_1 && gui->current_shape < 1)
		gui->current_shape++;
	init_sliders(gui, gui->current_shape);
	return (0);
}

void	init_gui(t_gui *gui)
{

	ft_bzero(gui->key, 100);
	gui->current_shape = 0;
	init_sliders(gui, gui->current_shape);
	ft_mlx_init(&gui->w, 300, 300, "TOOL");

	gui->sliders[0].sprit = ft_init_filled_canvas(gui->w.mlx,
			SLIDER_SIZE, SLIDER_SIZE, WHITE);
	gui->sliders[1].sprit = gui->sliders[0].sprit;
	gui->sliders[2].sprit = gui->sliders[0].sprit;
	gui->focus = 0;
	mlx_hook(gui->w.win, 2, 0, key, gui);
	mlx_hook(gui->w.win, 4, 0, mouse_down, gui);
	mlx_hook(gui->w.win, 5, 0, mouse_up, gui->key);
	mlx_hook(gui->w.win, 6, 0, mouse_move, gui);
	pthread_create(&gui->thread, 0, thread_mlx_loop, gui->w.mlx);
}
// int	button_realeased(int key, int x, int y, t_gui *gui)
// {
// 	t_v3	pos;

// 	(void) key;
// 	if (gui->focus == 0)
// 		return (0);
// 	pos = (t_v3){x, y, 0};
// 	gui->focus->released(gui->focus, &pos);
// 	ft_putimg(gui->w, gui->focus->sprit.img, *(t_vector *)&pos);
// 	gui->scene->hook(-1, gui->scene);
// 	ft_put_pixel(gui->w.mlx, x, y, WHITE);
// 	return (0);
// }

