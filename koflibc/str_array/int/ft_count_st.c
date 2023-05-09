/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_st.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 18:15:39 by tate              #+#    #+#             */
/*   Updated: 2022/07/17 18:57:07 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../sources.h"

int	ft_count_st(char **to_count, char *target)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (to_count[i])
	{
		if (ft_strcmp(to_count[i], target) == 0)
			count++;
		i++;
	}
	return (count);
}
