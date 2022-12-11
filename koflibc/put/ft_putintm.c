/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putintm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 14:24:54 by albaud            #+#    #+#             */
/*   Updated: 2022/08/01 14:26:47 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources.h"

void	ft_putintm(t_matrix map)
{
	int	i;

	i = -1;
	while (++i < map.size.y)
		ft_putia_clean(map.map[i], map.size.x);
}
