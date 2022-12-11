/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_touches.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 01:44:37 by albaud            #+#    #+#             */
/*   Updated: 2022/07/22 17:01:02 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources.h"

int	ft_touches(t_canvas *tchr, t_canvas *target, int x, int y)
{
	int	i;
	int	j;

	i = -1;
	while (++i < tchr->y)
	{
		j = -1;
		while (++j < tchr->x)
		{
			if (ft_has_pixel(target, x + j, y + i) != 0)
				return (1);
		}
	}
	return (0);
}
