/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_randint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bphilago <bphilago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:22:42 by albaud            #+#    #+#             */
/*   Updated: 2022/12/12 12:47:10 by bphilago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources.h"

int	ft_randint(int min, int max)
{
	time_t		t;
	static int	innit = 1;
	
	if (innit)
	{
		innit = 0;
		srand((unsigned) time(&t));
	}
	return (rand() % (max - min) + min);
}
