/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_vector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 10:51:54 by albaud            #+#    #+#             */
/*   Updated: 2022/07/10 17:47:59 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources.h"

t_vector	ft_add_vector(t_vector vect, t_vector toadd)
{
	vect.x += toadd.x;
	vect.y += toadd.y;
	vect.z += toadd.z;
	return (vect);
}
