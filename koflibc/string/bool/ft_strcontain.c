/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcontain.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 18:49:56 by tate              #+#    #+#             */
/*   Updated: 2022/07/17 18:57:32 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../sources.h"

int	ft_strcontain(char *to_count, char target)
{
	int	counter;

	counter = 0;
	while (*to_count)
	{
		if (*to_count == target)
			return (1);
		to_count += 1;
	}
	return (0);
}
