/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mal_vector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:06:07 by albaud            #+#    #+#             */
/*   Updated: 2022/07/21 19:42:35 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources.h"

t_vector	*ft_mal_vector(double x, double y, double z)
{
	t_vector	*vect;

	vect = malloc(sizeof(*vect));
	vect->x = x;
	vect->y = y;
	vect->z = z;
	return (vect);
}
