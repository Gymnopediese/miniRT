/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_pp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 22:58:18 by albaud            #+#    #+#             */
/*   Updated: 2022/10/31 23:16:15 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources.h"

void	ft_free_pp(void **to_free)
{
	int	i;

	i = -1;
	if (to_free == 0)
		return ;
	while (to_free[++i])
	{
		free(to_free[i]);
		to_free[i] = 0;
	}
	free(to_free);
}
