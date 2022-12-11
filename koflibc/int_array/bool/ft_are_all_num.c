/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_are_all_num.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:56:29 by albaud            #+#    #+#             */
/*   Updated: 2022/11/07 11:48:27 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../sources.h"

int	ft_are_all_num(char **arr)
{
	int	loop;

	loop = -1;
	while (arr[++loop])
	{
		if (!ft_isnum(arr[loop]))
		{
			return (0);
		}
	}
	return (1);
}
