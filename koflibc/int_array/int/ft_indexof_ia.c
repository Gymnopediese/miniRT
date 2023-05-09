/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_indexof_ia.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 21:41:05 by albaud            #+#    #+#             */
/*   Updated: 2022/07/19 14:44:11 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_indexof_ia(int *arr, int size, int target)
{
	int	x;

	x = -1;
	while (++x < size)
	{
		if (arr[x] == target)
			return (x);
	}
	return (-1);
}
