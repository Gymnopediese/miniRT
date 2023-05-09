/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uvmapping.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 08:55:28 by albaud            #+#    #+#             */
/*   Updated: 2022/12/12 10:53:13 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

//il faut que tu fasse ca c nimport quoi la😭😭😭
int	get_pix(t_canvas *cvs, double y, double x)
{
	int	rgb;

	x *= cvs->x;
	y *= cvs->y;
	x = (int) x;
	y = (int) y;
	rgb = 0;
	if ((int)cvs->cvs[(int)((y * cvs->line_bytes) + (x * 4) + 2)] >= 0)
		rgb = (int)cvs->cvs[(int)((y * cvs->line_bytes) + (x * 4) + 2)];
	else
		rgb = (int)cvs->cvs[(int)((y * cvs->line_bytes) + (x * 4) + 2)] + 256;
	if ((int)cvs->cvs[(int)((y * cvs->line_bytes) + (x * 4) + 1)] >= 0)
		rgb = (rgb << 8) + (int)cvs->cvs[(int)((y * cvs->line_bytes) + (x * 4) + 1)];
	else
		rgb = (rgb << 8) + (int)cvs->cvs[(int)((y * cvs->line_bytes) + (x * 4) + 1)] + 256;
	if ((int)cvs->cvs[(int)((y * cvs->line_bytes) + (x * 4) + 0)] >= 0)
		rgb = (rgb << 8) + (int)cvs->cvs[(int)((y * cvs->line_bytes) + (x * 4) + 0)];
	else
		rgb = (rgb << 8) + (int)cvs->cvs[(int)((y * cvs->line_bytes) + (x * 4) + 0)] + 256;
	return (rgb);
}

int	uvmapping(t_obj *obj, t_v3 *hit, t_scene *scene)
{
	t_v3	uv;
	t_v3	pos;
	int		i;

	pos = v_rm(hit, &obj->pos);
	uv.x = 0.5 + (atan2f(pos.z, pos.x) / (2 * PI));
	uv.y = 0.5 + (asinf(pos.y) / (PI));
	uv.y -= (int)uv.y;
	uv.x -= (int)uv.x;
	//print_vector(uv, "uv:	");
	i = 1 - (v_dist(hit, &scene->light->pos)
			/ v_dist(&obj->pos, &scene->light->pos));
	//print_vector(uv, "uvpos");
	return (0);
	//return (get_pix(&scene->texture, uv.x, uv.y));
}