/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_to.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 14:30:45 by tate              #+#    #+#             */
/*   Updated: 2022/07/17 18:57:49 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../sources.h"

int	ft_strlen_to(char *to_count, char target)
{
	int	counter;

	counter = 0;
	while (*to_count != target && *to_count)
	{
		to_count += 1;
		counter ++;
	}
	return (counter);
}
