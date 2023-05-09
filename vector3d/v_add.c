/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_add.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 20:25:20 by albaud            #+#    #+#             */
/*   Updated: 2022/12/10 20:58:17 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_v3.h"

t_v3	v_add(const t_v3 *a, const t_v3 *b)
{
	return ((t_v3){a->x + b->x, a->y + b->y, a->z + b->z});
}

t_v3	v_nadd(const t_v3 *a, const double b)
{
	return ((t_v3){a->x + b, a->y + b, a->z + b});
}

void	v_cadd(t_v3 *a, const t_v3 *b)
{
	a->x += b->x;
	a->y += b->y;
	a->z += b->z;
}

void	v_cnadd(t_v3 *a, const double b)
{
	a->x += b;
	a->y += b;
	a->z += b;
}
