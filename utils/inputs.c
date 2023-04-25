/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bphilago <bphilago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 17:58:30 by albaud            #+#    #+#             */
/*   Updated: 2023/04/24 15:09:53 by bphilago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"
#define ADD 1.1

void	input_camera(int key, t_scene *scene)
{
	if (key == KEYCODE_A)
		scene->camera->pos.x -= ADD;
	if (key == KEYCODE_S)
		scene->camera->pos.y += ADD;
	if (key == KEYCODE_D)
		scene->camera->pos.x += ADD;
	if (key == KEYCODE_W)
		scene->camera->pos.y -= ADD;
	if (key == KEYCODE_UP_ARROW)
		scene->camera->pos.z += ADD;
	if (key == KEYCODE_DOWN_ARROW)
		scene->camera->pos.z -= ADD;
}

void	input_light(int key, t_scene *scene)
{
	if (key == KEYCODE_A)
		scene->light->pos.x -= ADD;
	if (key == KEYCODE_S)
		scene->light->pos.y += ADD;
	if (key == KEYCODE_D)
		scene->light->pos.x += ADD;
	if (key == KEYCODE_W)
		scene->light->pos.y -= ADD;
	if (key == KEYCODE_UP_ARROW)
		scene->light->pos.z += ADD;
	if (key == KEYCODE_DOWN_ARROW)
		scene->light->pos.z -= ADD;
}

void	input(int key, t_scene *scene)
{
	// if (key == KEYCODE_LEFT_ARROW)
	// 	scene->move_text.x += ADD / 3;
	// if (key == KEYCODE_RIGHT_ARROW)
	// 	scene->move_text.y += ADD / 3;
	if (scene->input_mode == -1)
		input_camera(key, scene);
	if (scene->input_mode == 1)
		input_light(key, scene);
	if (key == KEYCODE_F)
		scene->input_mode *= -1;
}
