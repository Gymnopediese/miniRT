/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putvector.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:25:53 by albaud            #+#    #+#             */
/*   Updated: 2022/07/21 13:30:05 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources.h"

void	ft_putvector(t_vector a)
{
	ft_putstr("(");
	ft_putnbr(a.x);
	ft_putstr(", ");
	ft_putnbr(a.y);
	ft_putstr(", ");
	ft_putnbr(a.z);
	ft_putstr(", ");
	ft_putnbr(a.w);
	ft_putstr(")\n");
}
