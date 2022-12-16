/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_equal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bphilago <bphilago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 14:14:56 by albaud            #+#    #+#             */
/*   Updated: 2022/12/14 12:58:46 by bphilago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_v3.h"

int	v_equal(const t_v3 *a, const t_v3 *b)
{
	return (a->x <= b->x + __FLT_EPSILON__ && a->x >= b->x - __FLT_EPSILON__
		&& a->y <= b->y + __FLT_EPSILON__ && a->y >= b->y - __FLT_EPSILON__
		&& a->x <= b->z + __FLT_EPSILON__ && a->z >= b->z - __FLT_EPSILON__);
}
