/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 16:26:48 by albaud            #+#    #+#             */
/*   Updated: 2022/07/18 19:27:26 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources.h"

t_list	*ft_get(t_list *begin_list, int nbr)
{
	while (--nbr >= 0)
		begin_list = begin_list->next;
	return (begin_list);
}
