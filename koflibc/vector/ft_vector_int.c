/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 23:00:21 by albaud            #+#    #+#             */
/*   Updated: 2022/07/10 23:43:41 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources.h"

t_vector	ft_vector_int(t_vector vect)
{
	vect.x = round(vect.x);
	vect.y = round(vect.y);
	vect.z = round(vect.z);
	vect.w = round(vect.w);
	return (vect);
}
