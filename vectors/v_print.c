/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_print.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 08:38:17 by albaud            #+#    #+#             */
/*   Updated: 2022/12/16 08:57:21 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_v3.h"

void	v_nrprint(t_v3 a, const char *name)
{
	printf("%s(%f, %f, %f)\n", name, a.x, a.y, a.z);
}

void	v_nprint(const t_v3 *a, const char *name)
{
	printf("%s(%f, %f, %f)\n", name, a->x, a->y, a->z);
}

void	v_rprint(t_v3 a)
{
	printf("(%f, %f, %f)\n", a.x, a.y, a.z);
}

void	v_print(const t_v3 *a)
{
	printf("(%f, %f, %f)\n", a->x, a->y, a->z);
}
