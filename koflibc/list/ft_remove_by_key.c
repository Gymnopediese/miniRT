/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_by_key.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:47:38 by albaud            #+#    #+#             */
/*   Updated: 2022/07/18 18:58:22 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources.h"

void	ft_remove_by_key(t_list **list, char *key)
{
	ft_remove(list, ft_get_by_key(*list, key)->data,
		&ft_stracmp, &ft_free_pp);
}
