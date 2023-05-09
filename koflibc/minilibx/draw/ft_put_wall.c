/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 18:33:41 by albaud            #+#    #+#             */
/*   Updated: 2022/07/22 19:30:05 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../sources.h"

void	ft_put_wall(t_matrix map, t_vector pos, int num, int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			if (i == 0)
				map.map[(int)pos.y + j][(int)pos.x + i] = num;
			if (j == 0)
				map.map[(int)pos.y + j][(int)pos.x + i] = num + 1;
			if (i == size - 1)
				map.map[(int)pos.y + j][(int)pos.x + i] = num + 2;
			if (j == size - 1)
				map.map[(int)pos.y + j][(int)pos.x + i] = num + 3;
			else
				map.map[(int)pos.y + j][(int)pos.x + i] = -1;
		}
	}
}
