/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end_with.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 17:45:50 by albaud            #+#    #+#             */
/*   Updated: 2022/07/17 18:57:18 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../sources.h"

int	ft_end_with(char *str, char *end)
{
	if (ft_strcmp(ft_strstr(str, end), end) == 0)
		return (1);
	return (0);
}
