/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_indexof_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:59:09 by albaud            #+#    #+#             */
/*   Updated: 2022/11/23 14:56:25 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources.h"

int	ft_indexof_list(t_list *list_ptr, void *data_ref, int (*cmp)())
{
	int	i;

	i = 0;
	while (list_ptr)
	{
		if ((*cmp)(list_ptr->data, data_ref) == 0)
			return (i);
		list_ptr = list_ptr->next;
		i++;
	}
	return (-1);
}
