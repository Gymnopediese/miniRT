/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_canvas.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 11:08:57 by albaud            #+#    #+#             */
/*   Updated: 2022/11/02 20:24:13 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../sources.h"

void	ft_fill_canvas(t_canvas cvs, int color)
{
	int	i;
	int	j;

	i = -1;
	while (++i < cvs.x)
	{
		j = -1;
		while (++j < cvs.y)
			ft_put_pixel(&cvs, i, j, color);
	}
}
