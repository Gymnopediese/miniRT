/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_intm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:51:50 by albaud            #+#    #+#             */
/*   Updated: 2022/07/22 19:12:18 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources.h"

t_matrix	ft_init_intm(int x, int y, int val)
{
	t_matrix	res;
	int			**map;
	int			i;
	int			j;

	res.size = ft_vect(x, y, 0);
	map = malloc(y * sizeof(*map));
	i = -1;
	res.map = map;
	while (++i < y)
	{
		map[i] = malloc(x * sizeof(**map));
		j = -1;
		while (++j < x)
		{
			map[i][j] = val;
		}
	}
	return (res);
}
