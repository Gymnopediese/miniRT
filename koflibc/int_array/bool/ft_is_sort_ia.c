/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort_ia.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 22:23:44 by albaud            #+#    #+#             */
/*   Updated: 2022/07/19 14:44:08 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort_ia(int *arr, int length, int mode)
{
	int	loop;
	int	left;
	int	right;

	left = 0;
	right = 0;
	loop = -1;
	while (++loop < length - 1)
	{
		if (arr[loop] - arr[loop + 1] > 0)
			left = 1;
		if (arr[loop + 1] - arr[loop] > 0)
			right = 1;
	}
	if (left && right && mode == 0)
		return (0);
	if (left && mode == 1)
		return (0);
	if (right && mode == -1)
		return (0);
	return (1);
}
