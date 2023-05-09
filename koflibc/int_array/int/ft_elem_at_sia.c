/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_elem_at_sia.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 03:26:18 by albaud            #+#    #+#             */
/*   Updated: 2022/07/19 14:44:10 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../sources.h"

int	ft_elem_at_sia(int *arr, int size, int target)
{
	int	*clone;
	int	index;

	clone = ft_iadup(arr, size);
	ft_bubble_sort(clone, size);
	index = clone[target];
	free(clone);
	return (index);
}
