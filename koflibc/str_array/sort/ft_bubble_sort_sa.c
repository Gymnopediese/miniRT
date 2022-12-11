/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble_sort_sa.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:52:55 by albaud            #+#    #+#             */
/*   Updated: 2022/11/23 14:56:08 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../sources.h"

void	ft_bubble_sort_sa(char **arr)
{
	int		i;
	int		gate;
	char	*temp;

	gate = 1;
	while (gate)
	{
		gate = 0;
		i = 0;
		while (arr[i + 1])
		{
			if (ft_strcmp(arr[i + 1], arr[i]) < 0)
			{
				temp = arr[i + 1];
				arr[i + 1] = arr[i];
				arr[i] = temp;
				gate = 1;
			}
			i++;
		}
	}
}
