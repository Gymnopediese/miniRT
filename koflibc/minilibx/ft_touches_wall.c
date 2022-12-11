/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_touches_wall.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 18:38:23 by albaud            #+#    #+#             */
/*   Updated: 2022/07/23 09:12:15 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources.h"

int	ft_touches_wall(t_matrix map, t_vector pos, int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			if (map.map[(int)pos.x - size / 2 + j][(int)pos.y - size / 2 + i])
				return (1);
		}
	}
	return (0);
}
