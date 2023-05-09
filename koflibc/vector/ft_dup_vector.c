/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup_vector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 19:42:37 by albaud            #+#    #+#             */
/*   Updated: 2022/07/22 12:18:33 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources.h"

t_vector	*ft_dup_vector(t_vector toclone)
{
	t_vector	*vect;

	vect = malloc(sizeof(*vect));
	vect->x = toclone.x;
	vect->y = toclone.y;
	vect->z = toclone.z;
	vect->w = toclone.w;
	return (vect);
}
