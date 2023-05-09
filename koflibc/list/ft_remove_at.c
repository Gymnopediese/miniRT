/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_at.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 17:20:44 by albaud            #+#    #+#             */
/*   Updated: 2022/07/21 17:27:04 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources.h"

int	ft_remove_at(t_list **list, int ind, void (*freef)())
{
	t_list	*list_ptr;
	t_list	*temp;

	list_ptr = *list;
	if (ind >= ft_size(*list))
		return (-1);
	if (ind == 0)
	{
		temp = *list;
		*list = (*list)->next;
		(*freef)(temp->data);
		free(temp);
		return (1);
	}
	temp = ft_get(*list, ind)->next;
	(*freef)(ft_get(*list, ind)->data);
	free(ft_get(*list, ind));
	ft_get(*list, ind - 1)->next = temp;
	return (1);
}
