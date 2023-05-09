/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_contain_subs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 12:29:01 by albaud            #+#    #+#             */
/*   Updated: 2022/07/17 18:17:17 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../sources.h"

int	ft_contain_subs(char *to_count, char *target)
{
	int	counter;

	counter = 0;
	while (*to_count)
	{
		if (ft_strcmpl(to_count, target) == 0)
			return (1);
		to_count += 1;
	}
	return (0);
}
