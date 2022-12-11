/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atodo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 12:00:12 by albaud            #+#    #+#             */
/*   Updated: 2022/11/08 23:49:10 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources.h"

double	ft_atodo(const char *str)
{
	double		neg;
	int			i;
	double		num;
	int			count;

	i = 0;
	neg = 1;
	num = 0;
	count = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
		num = num * 10 + (str[i++] - 48);
	if (str[i++] != '.')
		return (num * neg);
	while (str[i] >= 48 && str[i] <= 57 && ++count)
		num = num * 10 + (str[i++] - 48);
	return (num / ft_pow(10, count) * neg);
}
