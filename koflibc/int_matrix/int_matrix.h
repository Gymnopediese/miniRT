/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_matrix.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 15:49:02 by albaud            #+#    #+#             */
/*   Updated: 2022/11/02 23:25:37 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INT_MATRIX_H
# define INT_MATRIX_H

int			ft_intmmax(t_matrix map);
t_matrix	ft_atoim(char **str, char split);
t_matrix	ft_init_intm(int x, int y, int val);
void		ft_reset_intm(t_matrix map, int val);
int			ft_intmmin(t_matrix map);
#endif
