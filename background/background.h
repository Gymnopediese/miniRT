/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 12:42:18 by albaud            #+#    #+#             */
/*   Updated: 2023/03/19 01:28:36 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BACKGROUND_H
# define BACKGROUND_H

/*
	objectif mettre des foules image en backround
*/

# include "../header.h"
# include "../vector3d/t_v3.h"

int	gradient_background(t_canvas *cvs, t_v3 *s, t_v3 *e);

#endif
