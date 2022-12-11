/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_to_vector.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 10:51:54 by albaud            #+#    #+#             */
/*   Updated: 2022/07/10 22:53:29 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources.h"

t_vector	ft_add_to_vector(t_vector vect, double x, double y, double z)
{
	vect.x += x;
	vect.y += y;
	vect.z += z;
	return (vect);
}
