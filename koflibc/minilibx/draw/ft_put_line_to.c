/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_line_to.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 23:31:27 by albaud            #+#    #+#             */
/*   Updated: 2022/07/22 16:58:39 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../sources.h"

#define RET 20

t_vector	ft_put_line_to(t_window *w, t_canvas map, t_vector a, double angle)
{
	t_vector	toadd;

	toadd.y = sin(ft_deg_to_rad(angle));
	toadd.x = cos(ft_deg_to_rad(angle));
	a.z = 0;
	while (ft_get_pixel_color(w->mlx, &map, round(a.x), round(a.y)) == 0)
	{
		mlx_pixel_put(w->mlx, w->win, round(a.x), round(a.y), LIGHT_BLUE);
		a = ft_add_to_vector(a, toadd.x, toadd.y, abs(1));
	}
	while (ft_get_pixel_color(w->mlx, &map, round(a.x), round(a.y)) != 0)
	{
		a = ft_add_to_vector(a, -toadd.x / RET, -toadd.y / RET, 0);
	}
	a = ft_add_to_vector(a, toadd.x / RET, toadd.y / RET, 0);
	a.w = ft_get_pixel_color(w->mlx, &map, round(a.x), round(a.y));
	return (a);
}
