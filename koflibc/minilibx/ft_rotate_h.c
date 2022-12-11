/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_h.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 01:40:39 by albaud            #+#    #+#             */
/*   Updated: 2022/11/23 14:49:32 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources.h"

t_canvas	ft_rotate_h(void *mlx, t_canvas cvs, int angle)
{
	t_canvas	res;
	double		ind;
	int			i;

	res = ft_init_canvas(mlx,
			(int)fabs((cvs.x * cos(ft_deg_to_rad(angle)))), cvs.y);
	ind = 0;
	i = -1;
	while (++i < res.x)
	{
		if (angle < 0)
			ft_copy_shrinked_col(res, cvs,
				ft_vect((int) cvs.x - ind - 1, res.x - i - 1, 0),
				ft_vect(cvs.y, cvs.y + i - (int) ind, 0));
		else
			ft_copy_shrinked_col(res, cvs,
				ft_vect((int) ind, i, 0),
				ft_vect(cvs.y, cvs.y + i - (int) ind, 0));
		ind += (double)cvs.x / (double)res.x;
	}
	return (res);
}
