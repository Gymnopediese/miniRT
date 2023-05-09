/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 14:36:24 by tate              #+#    #+#             */
/*   Updated: 2022/10/31 23:18:11 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		i;
	int		k;
	int		size;

	size = ft_strlen((char *) s1) + ft_strlen((char *) s2);
	result = malloc(sizeof(char) * (size + 1));
	if (result == 0)
		return (0);
	i = -1;
	while (s1[++i])
		result[i] = s1[i];
	k = -1;
	while (s2[++k])
		result[i++] = s2[k];
	result[i++] = '\0';
	free((void *)s1);
	return (result);
}
