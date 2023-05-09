/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_rm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 20:25:20 by albaud            #+#    #+#             */
/*   Updated: 2022/12/11 17:25:50 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_v3.h"

t_v3	v_rm(const t_v3 *a, const t_v3 *b)
{
	return ((t_v3){a->x - b->x, a->y - b->y, a->z - b->z});
}

t_v3	v_nrm(const t_v3 *a, const double b)
{
	return ((t_v3){a->x - b, a->y - b, a->z - b});
}

void	v_crm(t_v3 *a, const t_v3 *b)
{
	a->x -= b->x;
	a->y -= b->y;
	a->z -= b->z;
}

void	v_cnrm(t_v3 *a, const double b)
{
	a->x -= b;
	a->y -= b;
	a->z -= b;
}
