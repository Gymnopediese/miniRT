/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 17:27:39 by albaud            #+#    #+#             */
/*   Updated: 2022/10/31 23:03:44 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_H
# define MEMORY_H

void	ft_bzero(void *s, size_t n);
void	ft_free_pp(void **to_free);
void	*ft_memccpy(void *restrict dst,
			const void *restrict src, int c, size_t n);
void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n);
void	*ft_memset(void *b, int c, size_t len);
int		ft_f(void *p);
void	*ft_calloc(size_t count, size_t size);
void	ft_garbage_colector(void *ptr, int mode, int _exit);
void	*allok(int num, int size, int exit_on_null);
int		ft_garbage_pp(void **ptr, int len);
#endif