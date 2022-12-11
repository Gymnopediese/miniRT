/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_square.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 00:03:25 by albaud            #+#    #+#             */
/*   Updated: 2022/07/20 19:42:57 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../sources.h"

void	ft_draw_square(t_canvas *cvs, t_vector pos, int size, int color)
{
	ft_draw_line(cvs, pos, ft_add_to_vector(pos, size, 0, 0), color);
	ft_draw_line(cvs, pos, ft_add_to_vector(pos, 0, size, 0), color);
	ft_draw_line(cvs, ft_add_to_vector(pos, size, size, 0),
		ft_add_to_vector(pos, size, 0, 0), color);
	ft_draw_line(cvs, ft_add_to_vector(pos, size, size, 0),
		ft_add_to_vector(pos, 0, size, 0), color);
}
