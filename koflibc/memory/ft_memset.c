/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 14:17:34 by albaud            #+#    #+#             */
/*   Updated: 2022/10/31 11:37:40 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	loop;
	char	*res;

	res = b;
	loop = -1;
	while (++loop < len)
		res[loop] = (unsigned char) c;
	return (b);
}
