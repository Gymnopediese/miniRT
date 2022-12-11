/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_pixel_color.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 02:03:08 by albaud            #+#    #+#             */
/*   Updated: 2022/07/22 16:57:21 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../sources.h"

long int	ft_get_pixel_color(void *mlx, t_canvas *cvs, int x, int y)
{
	char	*pix;
	int		col;

	pix = ft_get_pixel(cvs, x, y);
	col = pix[0] * 255 * 255 + pix[1] * 255 + pix[2];
	return (mlx_get_color_value(mlx, col));
}
