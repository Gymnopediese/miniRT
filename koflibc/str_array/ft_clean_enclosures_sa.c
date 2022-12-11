/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_enclosures_sa.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 14:10:54 by albaud            #+#    #+#             */
/*   Updated: 2022/07/21 19:21:16 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources.h"

char	**ft_clean_enclosures_sa(char **array, char *charset)
{
	int		io;

	io = -1;
	while (array[++io])
	{
		ft_clean_enclosures(array[io], charset);
	}
	return (array);
}
