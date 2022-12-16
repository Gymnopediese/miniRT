/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_printn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 08:38:17 by albaud            #+#    #+#             */
/*   Updated: 2022/12/16 08:57:32 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_v3.h"

void	v_nrprintn(t_v3 a, const char *name)
{
	printf("%s(%f, %f, %f)\n", name, a.x, a.y, a.z);
}

void	v_nprintn(const t_v3 *a, const char *name)
{
	printf("%s(%f, %f, %f)\n", name, a->x, a->y, a->z);
}

void	v_rprintn(t_v3 a)
{
	printf("(%f, %f, %f)\n", a.x, a.y, a.z);
}

void	v_printn(const t_v3 *a)
{
	printf("(%f, %f, %f)\n", a->x, a->y, a->z);
}
