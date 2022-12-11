/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resize_image.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 12:15:51 by albaud            #+#    #+#             */
/*   Updated: 2022/07/24 11:17:45 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources.h"

t_canvas	ft_resize_image(void *mlx, t_canvas cvs, int x, int y)
{
	t_canvas	res;
	double		ind;
	int			i;

	(void) x;
	(void) y;
	res = ft_init_canvas(mlx, (int)(cvs.x * cos((double) x / 180 * PI)), cvs.y);
	ind = 0;
	i = 0;
	while (i < res.x)
	{
		ft_copy_shrinked_col(res, cvs, ft_vect((int) ind, i, 0),
			ft_vect(cvs.y, cvs.y + i - (int) ind, 0));
		ind += (double)cvs.x / (double)res.x;
		i++;
	}
	return (res);
}
