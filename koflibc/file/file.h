/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 16:55:09 by albaud            #+#    #+#             */
/*   Updated: 2022/07/18 15:37:54 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H

char	*ft_read_fd(int fd);
char	**ft_read_lignes_fd(int fd);

char	*ft_read(char *file_name);
char	**ft_read_lignes(char *file_name);

char	**ft_glob(char *dirname, int mode);
int		ft_count_dir(char *dirname, int mode);
#endif 