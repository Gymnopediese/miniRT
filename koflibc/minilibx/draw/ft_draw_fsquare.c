/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_fsquare.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 00:03:25 by albaud            #+#    #+#             */
/*   Updated: 2022/07/20 19:43:06 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../sources.h"

void	ft_draw_fsquare(t_canvas *cvs, t_vector pos, int size, int color)
{
	int	x;
	int	y;

	x = 0;
	while (x < size)
	{
		y = 0;
		while (y < size)
		{
			ft_put_pixel(cvs, pos.x + x, pos.y + y, color);
			y++;
		}
		x++;
	}
}
