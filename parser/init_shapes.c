/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shapes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bphilago <bphilago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:06:36 by albaud            #+#    #+#             */
/*   Updated: 2022/12/16 11:58:56 by bphilago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	init_sphere(char **argv, t_obj *obj)
{
	if (ft_strtablen(argv) != 4)
		error("Wrong arguments number for a sphere");
	obj->id = SPHERE;
	obj->pos = ft_atovedo(argv[1], 0, 0);
	obj->diametre = ft_atodor(argv[2], 0, 0);
	if (obj->diametre < 0)
		error("Wrong diameter for a sphere");
	obj->color = ft_atovei(argv[3], 0, 255);
	v_cndiv(&obj->color, 255.0);
}

void	init_plan(char **argv, t_obj *obj)
{
	if (ft_strtablen(argv) != 4)
		error("Wrong arguments number for a sphere");
	obj->id = PLAN;
	obj->pos = ft_atovedo(argv[1], 0, 0);
	obj->orientation = ft_atovedo(argv[2], -1, 1);
	obj->color = ft_atovei(argv[3], 0, 255);
	v_cndiv(&obj->color, 255.0);
}

void	init_cylindre(char **argv, t_obj *obj)
{
	if (ft_strtablen(argv) != 6)
		error("Wrong arguments number for a cylindre");
	obj->id = CYLINDRE;
	obj->pos = ft_atovedo(argv[1], 0, 0);
	obj->orientation = ft_atovedo(argv[2], -1, 1);
	obj->diametre = ft_atodor(argv[3], 0, 0);
	if (obj->diametre < 0)
		error("Wrong diameter for a cylindre");
	obj->hauteur = ft_atodor(argv[4], 0, 0);
	if (obj->hauteur < 0)
		error("Wrong hight for a cylindre");
	obj->color = ft_atovei(argv[5], 0, 255);
	v_cndiv(&obj->color, 255.0);
}

void	init_cone(char **argv, t_obj *obj)
{
	if (ft_strtablen(argv) != 6)
		error("Wrong arguments number for a cone");
	obj->id = CONE;
	obj->pos = ft_atovedo(argv[1], 0, 0);
	obj->orientation = ft_atovedo(argv[2], -1, 1);
	obj->diametre = ft_atodor(argv[3], 0, 0);
	if (obj->diametre < 0)
		error("Wrong diameter for a cone");
	obj->hauteur = ft_atodor(argv[4], 0, 0);
	if (obj->hauteur < 0)
		error("Wrong hight for a cone");
	obj->color = ft_atovei(argv[5], 0, 255);
}

void	init_hyperboloid(char **argv, t_obj *obj)
{
	if (ft_strtablen(argv) != 6)
		error("Wrong arguments number for a hyperboloid");
	obj->id = HYPERBOILD;
	obj->pos = ft_atovedo(argv[1], 0, 0);
	obj->orientation = ft_atovedo(argv[2], -1, 1);
	obj->diametre = ft_atodor(argv[3], 0, 0);
	if (obj->diametre < 0)
		error("Wrong diameter for a hyperboloid");
	obj->hauteur = ft_atodor(argv[4], 0, 0);
	if (obj->hauteur < 0)
		error("Wrong hight for a hyperboloid");
	obj->color = ft_atovei(argv[5], 0, 255);
}
