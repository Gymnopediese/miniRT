/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clone_pixel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 02:45:03 by albaud            #+#    #+#             */
/*   Updated: 2022/07/20 19:42:07 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../sources.h"

void	ft_clone_pixel(t_canvas *cvs, int x, int y, char *pixel)
{
	cvs->cvs[(y * cvs->line_bytes) + (x * 4)] = pixel[0];
	cvs->cvs[(y * cvs->line_bytes) + (x * 4) + 1] = pixel[1];
	cvs->cvs[(y * cvs->line_bytes) + (x * 4) + 2] = pixel[2];
	cvs->cvs[(y * cvs->line_bytes) + (x * 4) + 3] = pixel[3];
}
