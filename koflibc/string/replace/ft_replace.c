/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 10:57:09 by tate              #+#    #+#             */
/*   Updated: 2022/10/31 11:44:14 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../sources.h"

char	*ft_replace(char *to_ch, char *to_re, char *re)
{
	char	*result;
	int		finalsize;
	int		i;
	int		k;

	finalsize = ft_strlen(to_ch) - ft_strlen(to_re) + ft_strlen(re) + 1;
	result = malloc(sizeof(*result) * (finalsize));
	i = -1;
	k = -1;
	while (to_ch[++i])
	{
		result[k + 1] = 0;
		if (ft_strcmpl(&to_ch[i], to_re) == 0 && finalsize)
		{
			result = ft_strcat(result, re);
			k += ft_strlen(re);
			i += ft_strlen(to_re) - 1;
			finalsize = 0;
		}
		else
			result[++k] = to_ch[i];
	}
	result[++k] = 0;
	free(to_ch);
	return (result);
}
