/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_imtoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 18:52:15 by albaud            #+#    #+#             */
/*   Updated: 2022/07/21 20:22:40 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources.h"

char	**ft_imtoa(t_matrix map)
{
	char	**res;
	int		k;

	res = malloc((map.size.y + 1) * sizeof(*res));
	k = -1;
	while (++k < map.size.y)
		res[k] = ft_iatoa(map.map[k], map.size.x);
	res[k] = 0;
	return (res);
}
