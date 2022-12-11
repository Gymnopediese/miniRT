/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_shrinked_col.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 01:51:09 by albaud            #+#    #+#             */
/*   Updated: 2022/07/22 02:06:00 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../sources.h"

void	ft_copy_shrinked_col(t_canvas dest, t_canvas src, t_vector inds,
	t_vector std)
{
	int		i;
	double	j;

	i = (std.x - std.y) / 2;
	j = 0;
	while (++i - (std.x - std.y) / 2 < std.y)
	{
		ft_clone_pixel(&dest, inds.y, i, ft_get_pixel(&src, inds.x, (int) j));
		j += (double) std.x / std.y;
	}
}
