/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_randint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:22:42 by albaud            #+#    #+#             */
/*   Updated: 2022/07/21 15:44:09 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources.h"

int	ft_randint(int min, int max)
{
	time_t		t;
	static int	innit = 1;

	if (min >= max)
	{
		ft_putendl_fd("invalid parameter for function\
 ft_randint() : min should be less than max", 2);
		exit(0);
	}
	if (innit)
	{
		innit = 0;
		srand((unsigned) time(&t));
	}
	return (rand() % (max - min) + min);
}
