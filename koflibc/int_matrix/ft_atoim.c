/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 15:49:36 by albaud            #+#    #+#             */
/*   Updated: 2022/10/31 23:21:10 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources.h"

t_matrix	ft_atoim(char **str, char split)
{
	t_matrix	res;
	int			k;

	res.map = ft_calloc(ft_strtablen(str), sizeof(int *));
	if (res.map == 0)
		return (res);
	k = -1;
	while (str[++k])
	{
		res.map[k] = ft_atoia(str[k], split, &res.size.x);
		if (res.map[k] == 0)
		{
			ft_free_pp((void **)res.map);
			res.map = 0;
			return (res);
		}
	}
	res.size.y = k;
	return (res);
}
