/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_encrypt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 20:20:18 by albaud            #+#    #+#             */
/*   Updated: 2022/07/14 20:30:55 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_encrypt(char *str, char *key)
{
	int	i;
	int	ind;

	ind = -1;
	i = -1;
	if (!key[0])
		return ;
	while (str[++i])
	{
		if (!key[++ind])
			ind = 0;
		str[i] += key[ind];
		if (str[i] > 126)
			str[i] -= 126;
		if (str[i] < 32)
			str[i] += 32;
	}
}
