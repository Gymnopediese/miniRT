/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putimg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 12:44:04 by albaud            #+#    #+#             */
/*   Updated: 2022/08/02 12:44:22 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources.h"

void	ft_putimg(t_window w, void *img, t_vector pos)
{
	mlx_put_image_to_window(w.mlx, w.win, img, pos.x, pos.y);
}
