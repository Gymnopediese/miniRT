/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 17:11:46 by albaud            #+#    #+#             */
/*   Updated: 2022/10/31 11:35:02 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources.h"

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = -1;
	while (++size != -1 && lst)
		lst = lst->next;
	return (size);
}
