/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intmmin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:33:04 by albaud            #+#    #+#             */
/*   Updated: 2022/11/02 23:28:20 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources.h"

int	ft_intmmin(t_matrix map)
{
	int	i;
	int	j;
	int	min;

	min = 2147483647;
	i = -1;
	while (++i < map.size.x)
	{
		j = -1;
		while (++j < map.size.y)
		{
			if (map.map[j][i] < min)
				min = map.map[j][i];
		}
	}
	return (min);
}
