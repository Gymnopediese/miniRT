/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putinfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:59:16 by albaud            #+#    #+#             */
/*   Updated: 2022/07/17 17:33:37 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources.h"

void	ft_write(char const *s, char *filename)
{
	int	i;
	int	fd;

	i = -1;
	fd = open(filename, O_RDWR | O_CREAT | O_NONBLOCK, 0666);
	while (s[++i])
		write(fd, &s[i], 1);
	close(fd);
}
