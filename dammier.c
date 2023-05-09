/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dammier.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 08:55:28 by albaud            #+#    #+#             */
/*   Updated: 2022/12/12 10:52:54 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#define DAMIERY 80
#define DAMIERX 20

int	damier(t_obj *obj, t_v3 *hit, t_scene *scene)
{
	t_v3	uv;
	t_v3	pos;
	int		i;

	pos = v_rm(hit, &obj->pos);
	uv.x = 0.5 + (atan2f(pos.z, pos.x) / (2 * PI));
	uv.y = 0.5 + (asinf(pos.y) / (PI));
	uv.y -= (int)uv.y;
	uv.x -= (int)uv.x;
	i = 1 - (v_dist(hit, &scene->light->pos)
			/ v_dist(&obj->pos, &scene->light->pos));
	if ((int)(uv.x * DAMIERX) % 2 && (int)(uv.y * DAMIERY) % 2)
		return (0);
	if ((int)(uv.x * DAMIERX) % 2 && (int)(uv.y * DAMIERY) % 2 == 0)
		return (WHITE);
	if ((int)(uv.x * DAMIERX) % 2 == 0 && (int)(uv.y * DAMIERY) % 2)
		return (WHITE);
	return (0);
}
