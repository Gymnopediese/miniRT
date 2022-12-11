/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 14:50:32 by albaud            #+#    #+#             */
/*   Updated: 2022/10/31 22:50:21 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources.h"

int	*ft_atoia(char *str, char split, double *size)
{
	char	**buffer;
	int		*res;
	int		k;

	buffer = ft_split(str, split);
	res = ft_calloc(ft_strtablen(buffer), sizeof(int));
	if (res == 0)
	{
		ft_free_pp((void *)buffer);
		return (0);
	}
	k = -1;
	while (buffer[++k])
		res[k] = ft_atoli(buffer[k]);
	*size = k;
	ft_free_pp((void *)buffer);
	return (res);
}
