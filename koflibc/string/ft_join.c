/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 01:48:59 by albaud            #+#    #+#             */
/*   Updated: 2022/11/23 14:50:46 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources.h"

char	*ft_join(char **arr, char *glue)
{
	char	*res;
	int		i;

	i = -1;
	res = malloc(1);
	while (arr[++i])
	{
		res = ft_strjoin(res, arr[i]);
		if (arr[i + 1])
			res = ft_strjoin(res, glue);
	}
	return (res);
}
