/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_cs_first.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 14:10:54 by albaud            #+#    #+#             */
/*   Updated: 2022/07/17 14:29:49 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources.h"

char	**ft_clean_cs_first(char **array, char *charset, int num)
{
	int		io;
	char	to_clean[2];

	io = -1;
	to_clean[1] = 0;
	while (array[++io])
	{
		to_clean[0] = ft_first_occurence(array[io], charset);
		if (to_clean[0])
			array[io] = ft_replacen(array[io], to_clean, "", num);
	}
	return (array);
}
