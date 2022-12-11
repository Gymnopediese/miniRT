/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 23:31:27 by albaud            #+#    #+#             */
/*   Updated: 2022/07/20 21:16:56 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources.h"

void	ft_mlx_init(t_window *w, int x, int y, char *name)
{
	w->mlx = mlx_init();
	w->win = mlx_new_window(w->mlx, x, y, name);
}
