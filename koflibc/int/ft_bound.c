/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bound.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 22:47:16 by albaud            #+#    #+#             */
/*   Updated: 2022/07/10 22:57:36 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	ft_bound(double num, double min, double max)
{
	if (num > max)
		return (max);
	if (num < min)
		return (min);
	return (num);
}
