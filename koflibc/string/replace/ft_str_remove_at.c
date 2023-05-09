/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_remove_at.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 15:56:58 by albaud            #+#    #+#             */
/*   Updated: 2022/10/31 11:44:19 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../sources.h"

char	*ft_str_remove_at(char *str, int index, int len, int free_)
{
	char	*res;

	res = malloc(sizeof(char) * (ft_strlen(str) + 1 - len));
	if (!res)
		return (0);
	if (index > 0)
		res = ft_strncpy(res, str, index);
	res = ft_strcat(res, &str[index + len]);
	if (free_)
		free(str);
	return (res);
}
