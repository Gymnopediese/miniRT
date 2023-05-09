/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_keyval.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:52:40 by albaud            #+#    #+#             */
/*   Updated: 2022/07/18 18:01:21 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources.h"

t_keyval	ft_set_keyval(char *key, void *uno, void *dos, void *tres)
{
	t_keyval	res;

	res.key = key;
	res.uno = uno;
	res.dos = dos;
	res.tres = tres;
	return (res);
}
