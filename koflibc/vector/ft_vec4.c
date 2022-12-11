/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 10:51:54 by albaud            #+#    #+#             */
/*   Updated: 2022/08/11 18:24:38 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources.h"

t_vector	ft_vec4(double x, double y, double z, double w)
{
	t_vector	vect;

	vect.x = x;
	vect.y = y;
	vect.z = z;
	vect.w = w;
	return (vect);
}
