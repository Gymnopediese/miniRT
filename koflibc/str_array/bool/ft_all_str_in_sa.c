/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all_str_in_sa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 18:57:28 by albaud            #+#    #+#             */
/*   Updated: 2022/07/17 18:58:40 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../sources.h"

int	ft_all_str_in_sa(char **src, char **targets)
{
	int	loop;

	loop = -1;
	while (src[++loop])
	{
		if (!ft_contain_sa(targets, src[loop]) && src[loop][0])
			return (0);
	}
	return (1);
}
