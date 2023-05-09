/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_by_key.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 17:40:19 by albaud            #+#    #+#             */
/*   Updated: 2022/07/18 18:49:36 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources.h"

t_list	*ft_get_by_key(t_list *begin_list, char *key)
{
	t_keyval	*str;

	while (begin_list)
	{
		str = (t_keyval *) begin_list->data;
		if (ft_strcmp(str->key, key) == 0)
			return (begin_list);
		begin_list = begin_list->next;
	}
	return (0);
}
