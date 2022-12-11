/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyval.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:57:11 by albaud            #+#    #+#             */
/*   Updated: 2022/07/18 18:12:56 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYVAL_H
# define KEYVAL_H

# include "../sources.h"

t_keyval	ft_set_keyval(char *key, void *uno, void *dos, void *tres);
t_keyval	*ft_mal_keyval(char *key, void *uno, void *dos, void *tres);

#endif
