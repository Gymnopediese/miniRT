/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shapes_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 10:19:08 by albaud            #+#    #+#             */
/*   Updated: 2022/12/16 10:30:28 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	init_hyperboloid2(char **argv, t_obj *obj)
{
	if (ft_strtablen(argv) != 6)
		error("Wrong arguments number for a hyperboloid2");
	obj->id = HYPERBOILD2;
	obj->pos = ft_atovedo(argv[1], 0, 0);
	obj->orientation = ft_atovedo(argv[2], -1, 1);
	obj->diametre = ft_atodor(argv[3], 0, 0);
	if (obj->diametre < 0)
		error("Wrong diameter for a hyperboloid2");
	obj->hauteur = ft_atodor(argv[4], 0, 0);
	if (obj->hauteur < 0)
		error("Wrong hight for a hyperboloid2");
	obj->color = ft_atovei(argv[5], 0, 255);
}

void	init_paraboloid(char **argv, t_obj *obj)
{
	if (ft_strtablen(argv) != 6)
		error("Wrong arguments number for a paraboloid");
	obj->id = PARABOLOID;
	obj->pos = ft_atovedo(argv[1], 0, 0);
	obj->orientation = ft_atovedo(argv[2], -1, 1);
	obj->diametre = ft_atodor(argv[3], 0, 0);
	if (obj->diametre < 0)
		error("Wrong diameter for a paraboloid");
	obj->hauteur = ft_atodor(argv[4], 0, 0);
	if (obj->hauteur < 0)
		error("Wrong hight for a paraboloid");
	obj->color = ft_atovei(argv[5], 0, 255);
}

void	init_paraboloid2(char **argv, t_obj *obj)
{
	if (ft_strtablen(argv) != 6)
		error("Wrong arguments number for a paraboloid2");
	obj->id = PARABOLOID2;
	obj->pos = ft_atovedo(argv[1], 0, 0);
	obj->orientation = ft_atovedo(argv[2], -1, 1);
	obj->diametre = ft_atodor(argv[3], 0, 0);
	if (obj->diametre < 0)
		error("Wrong diameter for a paraboloid2");
	obj->hauteur = ft_atodor(argv[4], 0, 0);
	if (obj->hauteur < 0)
		error("Wrong hight for a paraboloid2");
	obj->color = ft_atovei(argv[5], 0, 255);
}