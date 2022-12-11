/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mal_keyval.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:52:40 by albaud            #+#    #+#             */
/*   Updated: 2022/07/18 18:12:48 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources.h"

t_keyval	*ft_mal_keyval(char *key, void *uno, void *dos, void *tres)
{
	t_keyval	*res;

	res = malloc(sizeof(t_keyval));
	res->key = key;
	res->uno = uno;
	res->dos = dos;
	res->tres = tres;
	return (res);
}
