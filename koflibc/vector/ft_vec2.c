/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 10:51:54 by albaud            #+#    #+#             */
/*   Updated: 2022/08/11 18:25:13 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources.h"

t_vector	ft_vec2(double x, double y)
{
	t_vector	vect;

	vect.x = x;
	vect.y = y;
	vect.z = 0;
	vect.w = 0;
	return (vect);
}
