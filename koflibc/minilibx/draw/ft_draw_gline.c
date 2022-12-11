/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_gline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 23:31:27 by albaud            #+#    #+#             */
/*   Updated: 2022/11/23 14:48:18 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../sources.h"

int	loop_size(t_line l, t_vector *toadd)
{
	int			loop;

	toadd->y = -ft_bound(fabs(l.a.y - l.b.y) / fabs(l.a.x - l.b.x), 0, 1);
	toadd->x = -ft_bound(fabs(l.a.x - l.b.x) / fabs(l.a.y - l.b.y), 0, 1);
	loop = (int)ft_distance(l.a, l.b);
	if (toadd->y < toadd->x)
		loop = (int)fabs(l.a.y - l.b.y) + 2;
	else
		loop = (int)fabs(l.a.x - l.b.x) + 2;
	if (l.a.x - l.b.x < 0)
		toadd->x *= -1;
	if (l.a.y - l.b.y < 0)
		toadd->y *= -1;
	return (loop);
}

void	ft_draw_gline(t_canvas *cvs, t_line l, int	*colors, t_vector color)
{
	t_vector	toadd;
	int			loop;
	t_vector	col;

	if (ft_vector_eql(l.a, l.b))
		return ;
	loop = loop_size(l, &toadd);
	col = color;
	col.z = fabs(color.x - color.y) / loop;
	while (--loop > 0)
	{
		if (l.a.x < cvs->x && l.a.y < cvs->y && l.a.x >= 0 && l.a.y >= 0)
			ft_put_pixel(cvs, round(l.a.x), round(l.a.y),
				colors[(int)(fabs(col.x) / color.z * 24)]);
		l.a = ft_add_to_vector(l.a, toadd.x, toadd.y, 0);
		if (col.x < col.y)
			col.x += col.z;
		else
			col.x -= col.z;
	}
}
