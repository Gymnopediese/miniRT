/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 17:58:30 by albaud            #+#    #+#             */
/*   Updated: 2023/03/17 21:36:55 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"
#define ADD 0.5

int	inputs(t_scene *scene)
{
	int	f;

	f = 0;
	if (scene->inputs[KEYCODE_A] && ++f)
		scene->camera->pos.x -= ADD;
	if (scene->inputs[KEYCODE_S] && ++f)
		scene->camera->pos.y += ADD;
	if (scene->inputs[KEYCODE_D] && ++f)
		scene->camera->pos.x += ADD;
	if (scene->inputs[KEYCODE_W] && ++f)
		scene->camera->pos.y -= ADD;
	if (scene->inputs[KEYCODE_F] && ++f)
		scene->light->pos.x -= ADD;
	if (scene->inputs[KEYCODE_G] && ++f)
		scene->light->pos.y += ADD;
	if (scene->inputs[KEYCODE_H] && ++f)
		scene->light->pos.x += ADD;
	if (scene->inputs[KEYCODE_T] && ++f)
		scene->light->pos.y -= ADD;
	if (scene->inputs[KEYCODE_4] && ++f)
		scene->light->pos.z += ADD;
	if (scene->inputs[KEYCODE_5] && ++f)
		scene->light->pos.z -= ADD;
	if (scene->inputs[KEYCODE_UP_ARROW] && ++f)
		scene->camera->pos.z += ADD;
	if (scene->inputs[KEYCODE_DOWN_ARROW] && ++f)
		scene->camera->pos.z -= ADD;
	return (f);
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

int	keyup(int key, char *keys)
{
	keys[key] = 0;
	return (0);
}

int	keydown(int key, char *keys)
{
	keys[key] = 1;
	return (0);
}
