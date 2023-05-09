/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resize_cvs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 01:50:52 by albaud            #+#    #+#             */
/*   Updated: 2022/11/23 14:49:22 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources.h"

t_canvas	ft_resize_cvs(void *mlx, t_canvas cvs, double mult)
{
	t_canvas	res;
	double		i;
	double		j;

	res = ft_init_canvas(mlx, cvs.x * mult, cvs.y * mult);
	i = -1;
	j = 0;
	while (++i < cvs.x * mult)
	{
		ft_resize_ligne (res, cvs, ft_vect(round(j), i, 0),
			ft_vect(cvs.y, cvs.y * mult, 0));
		j += (double) 1 / (double) mult;
	}
	return (res);
}
