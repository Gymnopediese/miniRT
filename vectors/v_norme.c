/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_norme.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 21:10:39 by albaud            #+#    #+#             */
/*   Updated: 2022/12/10 21:13:56 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_v3.h"

double	v_norm(const t_v3 *a)
{
	return (sqrtf(pow(a->x, 2) + pow(a->y, 2) + pow(a->z, 2)));
}