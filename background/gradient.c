/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 19:18:11 by albaud            #+#    #+#             */
/*   Updated: 2022/12/10 19:47:09 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "background.h"

int	gradient_background(t_canvas *cvs, t_vector *s, t_vector *e)
{
	int			x;
	int			y;
	t_vector	to_add;

	to_add = (t_vector){-(s->x - e->x) / cvs->y,
		-(s->y - e->y) / cvs->y, -(s->z - e->z) / cvs->y, 0};
	y = -1;
	while (++y < cvs->y)
	{
		x = -1;
		print_vector(*s, "color");
		while (++x < cvs->x)
		{
			ft_put_pixel(cvs, x, y, ft_rgb(s->x, s->y, s->z));
		}
		*s = ft_add_vector(*s, to_add);
	}
	return (0);
}
