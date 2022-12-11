/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_canvas.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 19:41:46 by albaud            #+#    #+#             */
/*   Updated: 2022/07/20 20:15:19 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../sources.h"

void	ft_draw_canvas(t_canvas *dest, t_canvas *src, int x, int y)
{
	int	i;
	int	j;

	i = -1;
	while (++i < src->y)
	{
		j = -1;
		while (++j < src->x)
		{
			ft_clone_pixel(dest, x + j, y + i, ft_get_pixel(src, j, i));
		}
	}
}
