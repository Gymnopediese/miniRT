/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_srta_ind_equal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:30:19 by albaud            #+#    #+#             */
/*   Updated: 2022/07/18 16:37:20 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../sources.h"

int	ft_srta_ind_equal(char **arr, int ind, char *target)
{
	if (ft_strtablen(arr) > ind)
	{
		if (ft_strcmp(arr[ind], target) == 0)
			return (1);
	}
	return (0);
}
