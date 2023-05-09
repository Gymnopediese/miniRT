/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstra_clean.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:21:16 by albaud            #+#    #+#             */
/*   Updated: 2022/07/17 17:37:44 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources.h"

void	ft_putstra_clean(char **arr)
{
	int	loop;

	loop = -1;
	ft_putstr("{");
	while (arr[++loop])
	{
		ft_putstr("\"");
		ft_putstr(arr[loop]);
		ft_putstr("\"");
		if (arr[loop + 1])
		{
			ft_putstr(", ");
		}
	}
	ft_putstr("};\n");
}
