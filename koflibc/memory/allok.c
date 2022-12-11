/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allok.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 19:42:36 by albaud            #+#    #+#             */
/*   Updated: 2022/11/07 12:00:29 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources.h"

void	*allok(int num, int size, int exit_on_null)
{
	void	*res;

	res = ft_calloc(num, size);
	if (res == 0 && exit_on_null)
		ft_garbage_colector(res, 1, 1);
	else
		ft_garbage_colector(res, 0, 0);
	return (res);
}
