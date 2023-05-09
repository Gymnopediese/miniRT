/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 17:11:46 by albaud            #+#    #+#             */
/*   Updated: 2022/10/31 11:35:09 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources.h"

int	ft_size(t_list *begin_list)
{
	int	size;

	size = -1;
	while (++size != -1 && begin_list)
		begin_list = begin_list->next;
	return (size);
}
