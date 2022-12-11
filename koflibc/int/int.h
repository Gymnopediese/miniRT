/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 16:56:01 by albaud            #+#    #+#             */
/*   Updated: 2022/11/08 18:22:50 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INT_H
# define INT_H

double		ft_bound(double num, double min, double max);

long int	ft_atoli(const char *str);
int			ft_isin_range(int target, int min, int max);
int			ft_atoi(const char *str);
int			ft_atoi(const char *str);
int			ft_intlen(long nb);
int			ft_nlen(long nb, int n);
double		ft_atodo(const char *str);

#endif 