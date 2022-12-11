/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 16:32:38 by albaud            #+#    #+#             */
/*   Updated: 2022/11/07 11:41:10 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources.h"

char	*ft_read_fd(int fd)
{
	int		size;
	char	*buffer;
	char	tuffer[3333 + 1];

	buffer = malloc(1);
	size = read(fd, tuffer, 3333);
	while (size)
	{
		tuffer[size] = 0;
		buffer = ft_strjoin(buffer, tuffer);
		size = read(fd, tuffer, 3333);
	}
	return (buffer);
}
