/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 21:13:21 by albaud            #+#    #+#             */
/*   Updated: 2022/07/22 18:18:45 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources.h"

void	ft_init_player(t_player *plr, t_vector size, t_vector pos,
			t_vector data)
{
	plr->position = pos;
	plr->speed = data.x;
	plr->rotation = data.y;
	plr->sprite = size;
	plr->rotspeed = data.z;
}
