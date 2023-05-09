/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_enclosures.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 14:10:54 by albaud            #+#    #+#             */
/*   Updated: 2022/11/23 14:55:52 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources.h"

char	*ft_clean_enclosures(char *str, char *charset)
{
	int		ind;
	char	to_clean;

	ind = -1;
	while (str[++ind])
	{
		if (ft_strcontain(charset, str[ind]))
		{
			to_clean = str[ind];
			str = ft_str_remove_at(str, ind, 1, 1);
			while (str[ind] != to_clean && str[ind])
				ind++;
			str = ft_str_remove_at(str, --ind + 1, 1, 1);
		}
	}
	return (str);
}
