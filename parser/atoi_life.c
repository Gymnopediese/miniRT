/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_life.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:47:37 by albaud            #+#    #+#             */
/*   Updated: 2022/12/16 14:53:32 by albaud           ###   ########.fr       */
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
	if (max != min && (i < min || i > max))
		error("atoi range error, please check your .rt file");
	if (str[i])
		error("atoi char error, please check your .rt file");
	return (num * neg);
}

double	ft_atodor(const char *str, double min, double max)
{
	double		neg;
	int			i;
	double		num;
	int			count;

	i = 0;
	neg = 1;
	num = 0;
	count = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			neg *= -1;
	}
	while (str[i] >= 48 && str[i] <= 57)
		num = num * 10 + (str[i++] - 48);
	if (str[i++] != '.')
		return (num * neg);
	while (str[i] >= 48 && str[i] <= 57 && ++count)
		num = num * 10 + (str[i++] - 48);
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		;
	num = num / ft_pow(10, count) * neg;
	if (max != min && (num < min || num > max))
		error("atodo range error, please check your .rt file");
	if (str[i])
		error("atodo char error, please check your .rt file");
	return (num);
}

t_v3	ft_atovedo(char *str, double min, double max)
{
	t_v3	res;
	char	**args;

	args = ft_split(str, ',');
	if (args == 0)
		error("spliting vector double malloc error");
	if (ft_strtablen(args) != 3)
		error("vector invalid arguments");
	res.x = ft_atodor(args[0], min, max);
	res.y = ft_atodor(args[1], min, max);
	res.z = ft_atodor(args[2], min, max);
	ft_free_pp((void **)args);
	return (res);
}

t_v3	ft_atovei(char *str, int min, int max)
{
	t_v3	res;
	char	**args;

	args = ft_split(str, ',');
	if (args == 0)
		error("spliting vector int malloc error");
	if (ft_strtablen(args) != 3)
		error("vector invalid arguments");
	res.x = ft_atoir(args[0], min, max);
	res.y = ft_atoir(args[1], min, max);
	res.z = ft_atoir(args[2], min, max);
	ft_free_pp((void **)args);
	return (res);
}
