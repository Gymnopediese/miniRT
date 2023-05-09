/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 03:19:30 by albaud            #+#    #+#             */
/*   Updated: 2022/07/19 14:44:16 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources.h"

void	ft_bubble_sort(int *arr, int size)
{
	int	flag;
	int	loop;

	flag = 1;
	while (flag)
	{
		loop = -1;
		flag = 0;
		while (++loop < size - 1)
		{
			if (arr[loop] > arr[loop + 1])
			{
				ft_swap(&arr[loop], &arr[loop + 1]);
				flag = 1;
			}
		}
	}
}
