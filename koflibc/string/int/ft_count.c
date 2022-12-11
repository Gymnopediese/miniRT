/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 14:25:17 by tate              #+#    #+#             */
/*   Updated: 2022/07/17 18:57:37 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../sources.h"

int	ft_count(char *to_count, char target)
{
	int	counter;

	counter = 0;
	while (*to_count)
	{
		if (*to_count == target)
			counter++;
		to_count += 1;
	}
	return (counter);
}
