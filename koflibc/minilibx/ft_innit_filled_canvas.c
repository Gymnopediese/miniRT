/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_innit_filled_canvas.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:02:54 by albaud            #+#    #+#             */
/*   Updated: 2022/07/20 21:22:24 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources.h"

t_canvas	ft_init_filled_canvas(void *mlx, int x, int y, int color)
{
	t_canvas	cvs;
	int			yy;

	ft_putnbrn(color);
	cvs = ft_init_canvas(mlx, x, y);
	while (--x >= 0)
	{
		yy = -1;
		while (++yy < y)
		{
			ft_put_pixel(&cvs, x, yy, color);
		}
	}
	return (cvs);
}
