/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlist_join.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:42:37 by albaud            #+#    #+#             */
/*   Updated: 2022/07/18 18:34:51 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources.h"

void	ft_putlist_join(t_list *list, void (*put)(), t_keyval join, int endl)
{
	while (list)
	{
		if (join.dos && join.tres)
			(*put)(list->data, join.dos, ((char *) join.tres)[0] - 48);
		else if (join.dos)
			(*put)(list->data, join.dos);
		else
			(*put)(list->data);
		ft_putstr(join.uno);
		list = list->next;
	}
	if (endl)
		ft_putendl("");
}
