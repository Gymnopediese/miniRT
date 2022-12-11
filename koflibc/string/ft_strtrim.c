/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:38:54 by albaud            #+#    #+#             */
/*   Updated: 2022/10/31 11:42:41 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources.h"

int	isin(char const *set, char target)
{
	int	i;

	i = -1;
	while (set[++i])
	{
		if (set[i] == target)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		loop;
	char	*res;

	start = -1;
	while (isin(set, s1[++start]) && s1[start])
		;
	if (s1[start] == 0 || s1 == 0)
		return (ft_calloc(1, 1));
	end = -1;
	while (s1[++end])
		;
	while (isin(set, s1[--end]))
		;
	res = malloc(end - start + 2);
	if (res == 0)
		return (res);
	loop = -1;
	while (++loop < end - start + 1)
		res[loop] = s1[start + loop];
	res[loop] = 0;
	return (res);
}
