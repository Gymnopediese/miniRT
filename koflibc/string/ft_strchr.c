/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:47:35 by albaud            #+#    #+#             */
/*   Updated: 2022/10/31 11:40:34 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if ((unsigned char) s[i] == (unsigned char)c)
			return ((char *)&s[i]);
	}
	if ((unsigned char) s[i] == (unsigned char)c)
		return ((char *)&s[i]);
	return (0);
}
