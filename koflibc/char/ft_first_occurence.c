/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_occurence.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 14:15:11 by albaud            #+#    #+#             */
/*   Updated: 2022/07/17 18:21:19 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources.h"

char	ft_first_occurence(char *str, char *target)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (ft_strcontain(target, str[i]))
		{
			return (str[i]);
		}
	}
	return (0);
}
