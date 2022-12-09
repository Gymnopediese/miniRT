/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_life.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:47:37 by albaud            #+#    #+#             */
/*   Updated: 2022/12/09 15:19:23 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	ft_atoir(const char *str, int min, int max)
{
	int	neg;
	int	i;
	int	num;

	i = 0;
	neg = 1;
	num = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
		num = num * 10 + (str[i++] - 48);
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] || (max != min && (i < min || i > max)))
		error("atoi error, please check your .rt file");
	return (num * neg);
}

t_vector	ft_atovedo(char *str, double min, double max)
{
	t_vector	res;
	char		**args;

	args = ft_split(str, ",");
	if (args == 0)
		error("spliting vector double malloc error");
	if (ft_strtablen(args) != 3)
		error("vector invalid arguments");
	res.x = ft_atodo(args[0]);
	res.y = ft_atodo(args[1]);
	res.z = ft_atodo(args[2]);
	ft_free_pp(args);
	return (res);
}

t_vector	ft_atovei(char *str, int min, int max)
{
	t_vector	res;
	char		**args;

	args = ft_split(str, ",");
	if (args == 0)
		error("spliting vector int malloc error");
	if (ft_strtablen(args) != 3)
		error("vector invalid arguments");
	res.x = ft_atoi(args[0]);
	res.y = ft_atoi(args[1]);
	res.z = ft_atoi(args[2]);
	if (min != max && (res.x < min || res.x > max || res.y < min
			|| res.y > max || res.z < min || res.z > max))
		error("invalid range for vector");
	ft_free_pp(args);
	return (res);
}
