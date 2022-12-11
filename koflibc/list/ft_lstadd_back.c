/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 16:23:11 by albaud            #+#    #+#             */
/*   Updated: 2022/10/31 11:34:41 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*end;

	end = *lst;
	if (end == 0)
	{
		*lst = new;
		return ;
	}
	while (end->next)
	{
		end = end->next;
	}
	end->next = new;
}
