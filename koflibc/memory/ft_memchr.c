/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:47:35 by albaud            #+#    #+#             */
/*   Updated: 2022/10/31 11:37:23 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*sc;

	sc = (char *)s;
	i = -1;
	while (++i < n)
	{
		if ((unsigned char)sc[i] == (unsigned char)c)
			return (&sc[i]);
	}
	return (0);
}
