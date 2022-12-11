/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:38:54 by albaud            #+#    #+#             */
/*   Updated: 2022/10/31 11:41:11 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*res;

	i = 0;
	j = 0;
	if (len > ft_strlen(s) - start - 1)
		len = ft_strlen(s) - start;
	if ((unsigned int) ft_strlen(s) <= start)
		len = 0;
	if (len < 0)
		len = 0;
	if (s[0] == 0)
		len = 0;
	res = malloc(len + 1);
	if (res == 0)
		return (res);
	while (s[i])
	{
		if (i >= start && j < len)
			res[j++] = s[i];
		i++;
	}
	res[j] = 0;
	return (res);
}
