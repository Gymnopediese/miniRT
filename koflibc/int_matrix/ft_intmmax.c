/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intmmax.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:33:04 by albaud            #+#    #+#             */
/*   Updated: 2022/11/02 19:36:16 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources.h"

int	ft_intmmax(t_matrix map)
{
	int	i;
	int	j;
	int	max;

	max = -2147483648;
	i = -1;
	while (++i < map.size.x)
	{
		j = -1;
		while (++j < map.size.y)
		{
			if (map.map[j][i] > max)
				max = map.map[j][i];
		}
	}
	return (max);
}
