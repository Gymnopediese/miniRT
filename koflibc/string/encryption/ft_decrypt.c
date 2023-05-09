/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decrypt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 20:20:18 by albaud            #+#    #+#             */
/*   Updated: 2022/07/17 18:09:53 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_decrypt(char *str, char *key)
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
		if (str[i] < 0)
			str[i] += 126;
		if (str[i] > 126)
			str[i] -= 32;
	}
}
