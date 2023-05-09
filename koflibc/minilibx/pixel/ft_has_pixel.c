/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_has_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 17:00:27 by albaud            #+#    #+#             */
/*   Updated: 2022/07/22 17:00:42 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../sources.h"

long int	ft_has_pixel(t_canvas *cvs, int x, int y)
{
	char	*pix;
	int		col;

	pix = ft_get_pixel(cvs, x, y);
	col = pix[0] * 255 * 255 + pix[1] * 255 + pix[2];
	return (col);
}
