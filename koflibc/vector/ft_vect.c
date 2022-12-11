/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 10:51:54 by albaud            #+#    #+#             */
/*   Updated: 2022/08/11 18:24:59 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources.h"

t_vector	ft_vect(double x, double y, double z)
{
	t_vector	vect;

	vect.x = x;
	vect.y = y;
	vect.z = z;
	vect.w = 0;
	return (vect);
}
