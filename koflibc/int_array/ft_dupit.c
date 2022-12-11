/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dupit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 03:16:52 by albaud            #+#    #+#             */
/*   Updated: 2022/07/19 14:44:17 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources.h"

int	*ft_iadup(int *arr, int size)
{
	int	*res;

	res = malloc(sizeof(int) * size);
	while (--size >= 0)
		res[size] = arr[size];
	return (res);
}
