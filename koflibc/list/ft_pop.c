/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pop.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 17:38:10 by albaud            #+#    #+#             */
/*   Updated: 2022/07/21 20:57:23 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources.h"

int	ft_pop(t_list **list, void (*freef)())
{
	if (*list == 0)
		return (-1);
	return (ft_remove_at(list, ft_size(*list) - 1, freef));
}
