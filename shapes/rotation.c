/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 23:22:36 by albaud            #+#    #+#             */
/*   Updated: 2023/03/19 01:00:21 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shapes.h"

void	_rx(double t[SIZE][SIZE], const double teta)
{
	m_clean(t);
	m_one(t);
	t[1][1] = cos(teta);
	t[2][1] = sin(teta);
	t[1][2] = -sin(teta);
	t[2][2] = cos(teta);

}

void	_ry(double t[SIZE][SIZE], const double teta)
{
	m_clean(t);
	m_one(t);
	t[0][0] = cos(teta);
	t[2][0] = -sin(teta);
	t[0][2] = sin(teta);
	t[2][2] = cos(teta);
}

void	_rz(double t[SIZE][SIZE], const double teta)
{
	m_clean(t);
	m_one(t);
	t[0][0] = cos(teta);
	t[1][0] = sin(teta);
	t[0][1] = -sin(teta);
	t[1][1] = cos(teta);
}

void	rotation(t_obj *obj, double t[SIZE][SIZE])
{
	_rx(t, obj->orientation.x);
	m_mult(obj->transform, t);
	_ry(t, obj->orientation.y);
	m_mult(obj->transform, t);
	_rz(t, obj->orientation.z);
	m_mult(obj->transform, t);
}
