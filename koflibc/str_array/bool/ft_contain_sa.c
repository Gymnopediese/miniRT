/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_contain_sa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 19:02:08 by albaud            #+#    #+#             */
/*   Updated: 2022/11/07 11:28:47 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../sources.h"

int	ft_contain_sa(char **to_count, char *target)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (to_count[i])
	{
		if (ft_strcmp(to_count[i], target) == 0)
			return (1);
		i++;
	}
	return (0);
}
