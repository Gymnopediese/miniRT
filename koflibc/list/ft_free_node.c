/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:50:10 by albaud            #+#    #+#             */
/*   Updated: 2022/07/18 16:51:40 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources.h"

void	ft_free_node(t_list *node, int pointers)
{
	if (pointers == 1)
		free(node->data);
	if (pointers == 2)
		ft_free_pp(node->data);
	free(node);
}
