/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 19:56:43 by albaud            #+#    #+#             */
/*   Updated: 2022/12/15 20:04:41 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

t_v3	v_relative_pos(double height, double width, double x, double y)
{
	return ((t_v3){
		(x - width / 2) * 2 / width,
		(y - height / 2) * 2 / height,
		1,
	});
}
