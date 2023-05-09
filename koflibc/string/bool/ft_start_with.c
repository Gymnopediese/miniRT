/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_with.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 18:00:45 by albaud            #+#    #+#             */
/*   Updated: 2022/07/17 18:57:25 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../sources.h"

int	ft_start_with(char *str, char *end)
{
	if (ft_strcmp(ft_strstr(str, end), str) == 0)
		return (1);
	return (0);
}
