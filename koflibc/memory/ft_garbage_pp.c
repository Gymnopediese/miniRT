/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_garbage_pp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 19:23:05 by albaud            #+#    #+#             */
/*   Updated: 2022/10/31 22:54:48 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources.h"

int	ft_garbage_pp(void **ptr, int len)
{
	int	i;

	i = -1;
	while (++i < len || (len == -1 && ptr[i]))
		ft_garbage_colector(ptr[i], 0, 1);
	ft_garbage_colector(ptr, 0, 1);
	return (1);
}
