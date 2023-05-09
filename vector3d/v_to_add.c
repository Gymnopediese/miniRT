/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_to_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 12:00:34 by albaud            #+#    #+#             */
/*   Updated: 2023/03/18 12:02:28 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_v3.h"

void	v_apply(t_v3 *v, double (*f)())
{
	v->x = f(v->x);
	v->y = f(v->y);
	v->z = f(v->z);
}

void	v_applied(t_v3 *v, double d, double (*f)())
{
	v->x = f(v->x, d);
	v->y = f(v->y, d);
	v->z = f(v->z, d);
}

t_v3	v_relative_pos(double height, double width, double x, double y)
{
	return ((t_v3){
		(x - width / 2) * 2 / width,
		(y - height / 2) * 2 / height,
		1,
	});
}

void	v_normalize(t_v3 *a)
{
	v_cndiv(a, v_norm(a));
}
