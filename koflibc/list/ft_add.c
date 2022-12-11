/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 16:23:11 by albaud            #+#    #+#             */
/*   Updated: 2022/07/22 12:18:36 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources.h"

void	ft_add(t_list **begin_list, void *data)
{
	t_list	*node;
	t_list	*end;

	node = ft_create_elem(data);
	end = *begin_list;
	if (end == 0)
	{
		*begin_list = node;
		return ;
	}
	while (end->next)
	{
		end = end->next;
	}
	end->next = node;
}
