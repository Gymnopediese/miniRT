/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 10:37:13 by tate              #+#    #+#             */
/*   Updated: 2022/10/31 11:40:42 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources.h"

char	*ft_strdup(char *src)
{
	int		i;
	int		len;
	char	*str;

	len = ft_strlen(src);
	str = (char *)malloc(sizeof(*str) * (len + 1));
	if (str == 0)
		return (str);
	i = -1;
	while (++i < len)
		str[i] = src[i];
	str[i] = 0;
	return (str);
}
