/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:01:07 by albaud            #+#    #+#             */
/*   Updated: 2022/10/31 11:37:16 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	loop;
	char	*res;

	res = malloc(count * size);
	if (res == 0)
		return (res);
	loop = -1;
	while (++loop < count * size)
		res[loop] = 0;
	return (res);
}
