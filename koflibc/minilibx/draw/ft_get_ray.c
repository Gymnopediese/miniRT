/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 18:54:18 by albaud            #+#    #+#             */
/*   Updated: 2022/07/24 01:47:01 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../sources.h"

t_vector	ft_get_ray(t_matrix map, t_vector a, double angle, int res)
{
	t_vector	toadd;

	toadd.y = sin(ft_deg_to_rad(angle));
	toadd.x = cos(ft_deg_to_rad(angle));
	a.z = 0;
	while (map.map[(int)round(a.x)][(int)round(a.y)] == 0)
		a = ft_add_to_vector(a, toadd.x, toadd.y, 1);
	while (map.map[(int)round(a.x)][(int)round(a.y)] != 0)
		a = ft_add_to_vector(a, -toadd.x / res, -toadd.y / res, -1 / res);
	a = ft_add_to_vector(a, toadd.x / res, toadd.y / res, 1 / res);
	a.w = map.map[(int)round(a.x)][(int)round(a.y)];
	return (a);
}
