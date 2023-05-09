/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resize_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 02:07:29 by albaud            #+#    #+#             */
/*   Updated: 2022/07/22 02:09:30 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../sources.h"

void	ft_resize_ligne(t_canvas dest, t_canvas src, t_vector inds,
	t_vector std)
{
	int		i;
	double	j;

	i = -1;
	j = 0;
	while (++i < std.y)
	{
		ft_clone_pixel(&dest, inds.y, i, ft_get_pixel(&src, inds.x, (int) j));
		j += (double) std.x / std.y;
	}
}
