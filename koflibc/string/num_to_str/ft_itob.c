/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itob.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 03:26:21 by tate              #+#    #+#             */
/*   Updated: 2022/10/31 10:32:29 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../sources.h"

char	*ft_itob(int nb, char *base)
{
	char	*str;
	long	n;
	int		i;

	n = nb;
	i = ft_nlen(nb, ft_strlen(base));
	str = (char *)malloc(sizeof(char) * (i + 1));
	str[i--] = 0;
	if (n == 0)
	{
		str[0] = 48;
		return (str);
	}
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
	}
	while (n > 0)
	{
		str[i] = base[n % ft_strlen(base)];
		n = n / ft_strlen(base);
		i--;
	}
	return (str);
}
