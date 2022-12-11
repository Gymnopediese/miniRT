/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_array.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 16:56:01 by albaud            #+#    #+#             */
/*   Updated: 2022/11/07 11:48:23 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INT_ARRAY_H
# define INT_ARRAY_H

int		ft_are_all_num(char **arr);
int		ft_doublons_ia(int *arr, int size);
int		ft_is_sort_ia(int *arr, int length, int mode);

int		ft_indexof_ia(int *arr, int size, int target);
int		ft_elem_at_sia(int *arr, int size, int target);
int		ft_max(int *arr, int size);
int		ft_max_less(int *arr, int size, int less);
int		ft_min(int *arr, int size);

int		*ft_atoia(char *str, char split, double *size);
void	ft_bubble_sort(int *arr, int size);
int		*ft_iadup(int *arr, int size);
void	ft_swap(int *a, int *b);

#endif 