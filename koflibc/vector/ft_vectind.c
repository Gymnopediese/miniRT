/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vectind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 12:36:36 by albaud            #+#    #+#             */
/*   Updated: 2022/08/02 12:44:33 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources.h"

double	ft_vectind(t_vector vect, int ind)
{
	if (ind == 0)
		return (vect.x);
	if (ind == 1)
		return (vect.y);
	if (ind == 2)
		return (vect.z);
	if (ind == 3)
		return (vect.w);
	return (0.00000000000001);
}
