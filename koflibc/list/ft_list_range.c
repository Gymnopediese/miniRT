/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_range.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 17:04:21 by albaud            #+#    #+#             */
/*   Updated: 2022/07/21 20:00:51 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources.h"

t_list	*ft_list_range(int min, int max)
{
	t_list	*res;
	int		*rip;

	res = 0;
	while (min < max)
	{
		rip = malloc(sizeof(int));
		*rip = min;
		ft_add(&res, (void *) rip);
		min++;
	}
	return (res);
}
