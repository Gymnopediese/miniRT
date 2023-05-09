/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putia_clean.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:21:16 by albaud            #+#    #+#             */
/*   Updated: 2022/07/19 14:47:21 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources.h"

void	ft_putia_clean(int *arr, int size)
{
	int	loop;

	loop = -1;
	ft_putstr("{");
	while (++loop < size)
	{
		ft_putnbr(arr[loop]);
		if (loop < size - 1)
		{
			ft_putstr(", ");
		}
	}
	ft_putstr("};\n");
}
