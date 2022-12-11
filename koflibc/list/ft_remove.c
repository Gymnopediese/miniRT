/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:55:13 by albaud            #+#    #+#             */
/*   Updated: 2022/07/18 18:58:29 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources.h"

int	ft_remove(t_list **list, void *data, int (*cmp)(), void (*freef)())
{
	t_list	*list_ptr;
	t_list	*temp;
	int		ind;

	list_ptr = *list;
	ind = ft_indexof_list(*list, data, cmp);
	if (ind == -1)
		return (0);
	if (ind == 0)
	{
		*list = (*list)->next;
		return (1);
	}
	temp = ft_get(*list, ind)->next;
	(*freef)(ft_get(*list, ind)->data);
	free(ft_get(*list, ind));
	ft_get(*list, ind - 1)->next = temp;
	return (1);
}
