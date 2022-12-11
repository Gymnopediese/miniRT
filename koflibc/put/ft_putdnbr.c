/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 10:35:41 by albaud            #+#    #+#             */
/*   Updated: 2022/07/23 10:36:31 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources.h"

void	ft_putdnbr(char *name, long int num)
{
	ft_putstr(name);
	ft_putstr(" : ");
	ft_putnbrn(num);
}
