/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset_intm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 18:44:00 by albaud            #+#    #+#             */
/*   Updated: 2022/08/02 13:58:12 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources.h"

void	ft_reset_intm(t_matrix map, int val)
{
	int			i;
	int			j;

	i = -1;
	while (++i < map.size.y)
	{
		j = -1;
		while (++j < map.size.x)
			map.map[i][j] = val;
	}
}
