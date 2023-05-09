/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 17:51:40 by albaud            #+#    #+#             */
/*   Updated: 2022/10/31 10:34:07 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../sources.h"

char	*ft_strstr(char *str, char *to_find)
{
	int	loop;

	loop = -1;
	if (to_find[0] == '\0')
		return (str);
	while (str[++loop] != '\0')
	{
		if (ft_strcmpl(&str[loop], to_find) == 0)
			return (&str[loop]);
	}
	return (0);
}
