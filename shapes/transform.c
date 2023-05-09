/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 23:06:00 by albaud            #+#    #+#             */
/*   Updated: 2023/03/19 00:58:09 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	m_one(double t[SIZE][SIZE])
{
	int	i;

	i = -1;
	while (++i < SIZE)
		t[i][i] = 1;
}

void	_scaling(t_obj *obj, double t[SIZE][SIZE])
{
	m_clean(t);
	m_one(t);
	t[0][0] = obj->scale.x;
	t[1][1] = obj->scale.y;
	t[2][2] = obj->scale.z;
	m_mult(obj->transform, t);
}

void	_tranpose(t_obj *obj, double t[SIZE][SIZE])
{
	m_clean(t);
	m_one(t);
	t[0][3] = obj->pos.x;
	t[1][3] = obj->pos.y;
	t[2][3] = obj->pos.z;
	m_mult(obj->transform, t);
}

void	m_transform(t_obj *obj, t_scene *scene)
{
	double	t[SIZE][SIZE];
	double	tx;


	(void) scene;
	m_clean(obj->transform);
	m_one(obj->transform);

	_tranpose(obj, t);
	rotation(obj, t);
	_scaling(obj, t);
	m_copy(obj->inverse_transform, obj->transform);
	tx = determin(obj->inverse_transform, 4);
	if (tx == 0)
		error("fuck my life");
	else
		m_inverse(obj->inverse_transform, 4);
}
