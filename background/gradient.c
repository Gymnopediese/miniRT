/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 19:18:11 by albaud            #+#    #+#             */
/*   Updated: 2022/12/10 22:49:54 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "background.h"

int	gradient_background(t_canvas *cvs, t_v3 *s, t_v3 *e)
{
	int		x;
	int		y;
	t_v3	to_add;

	to_add = (t_v3){(e->x - s->x) / cvs->y,
		(e->y - s->y) / cvs->y, (e->z - s->z) / cvs->y};
	y = -1;
	while (++y < cvs->y)
	{
		x = -1;
		while (++x < cvs->x)
		{
			ft_put_pixel(cvs, x, y, ft_rgb(s->x, s->y, s->z));
		}
		v_cadd(s, &to_add);
	}
	return (0);
}
