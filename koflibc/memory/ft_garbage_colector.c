/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_garbage_colector.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 19:23:05 by albaud            #+#    #+#             */
/*   Updated: 2022/11/08 22:18:56 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources.h"

void	ft_garbage_colector(void *ptr, int mode, int _exit)
{
	static t_list	*garbage;
	t_list			*elem;

	if (mode == 0)
	{
		if (ptr == 0 && _exit)
			ft_garbage_colector(0, 1, _exit);
		elem = ft_lstnew(ptr);
		if (elem == 0 && _exit)
			ft_garbage_colector(0, 1, _exit);
		if (elem == 0)
			return ;
		ft_lstadd_back(&garbage, elem);
	}
	else
	{
		ft_lstclear(&garbage, free);
		if (_exit)
			exit(0);
	}
}
