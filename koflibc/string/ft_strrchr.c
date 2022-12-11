/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:47:35 by albaud            #+#    #+#             */
/*   Updated: 2022/10/31 11:41:01 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = 0;
	while (s[len])
		++len;
	while (len >= 0)
	{
		if ((unsigned char)s[len] == (unsigned char)c)
			return ((char *) &s[len]);
		len--;
	}
	return (0);
}
