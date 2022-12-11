/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_right.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 03:20:28 by albaud            #+#    #+#             */
/*   Updated: 2022/11/23 14:49:07 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources.h"

t_canvas	ft_rotate_right(void *mlx, t_canvas cvs, int angle)
{
	t_canvas	res;
	double		ind;
	int			i;

	res = ft_init_canvas(mlx, (int)(cvs.x
				* cos((double) angle / 180 * PI)), cvs.y);
	ind = 0;
	i = 0;
	while (i < res.x)
	{
		ft_copy_shrinked_col(res, cvs,
			ft_vect((int) ind, i, 0), ft_vect(cvs.y, cvs.y + i - (int) ind, 0));
		ind += (double)cvs.x / (double)res.x;
		i++;
	}
	return (res);
}
