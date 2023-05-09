/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_lignes_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 16:50:12 by albaud            #+#    #+#             */
/*   Updated: 2022/11/07 11:42:30 by albaud           ###   ########.fr       */
/*                                                                            */
/*   Name: ft_read_lignes_fd - read text from an open fd line by line         */
/*                                                                            */
/*   Categorie: file reading                                                  */
/*                                                                            */
/*   Synopsis: #include <unistd.h>,                                           */
/*             #include <stdlib.h>,                                           */
/*                                                                            */
/*             char	**ft_read_lignes_fd(int fd)                               */
/*                                                                            */
/*   Depend on: read(),                                                       */
/*              malloc()                                                      */
/*                                                                            */
/*   Description: ft_read_lignes_fd() attempt to read an open file line by    */
/*                line using its fd and return a table of string.             */
/*                                                                            */
/*   Return value: Return a table of string. If an error occurs, it return    */
/*                 NULL.                                                      */
/*                                                                            */
/*   Errors: Don't run this code on a Gameboy please.                         */
/*                                                                            */
/*   See also: ft_read_lignes(), ft_read(), ft_read_fd()                      */
/*                                                                            */
/*   History: I needed it for the get_next_line() function. My final          */
/*            get_next_line() function is the worst piece of code ever        */
/*            made but it has all the bonuses so...                           */
/*                                                                            */
/* ************************************************************************** */

#include "../sources.h"

char	**ft_read_lignes_fd(int fd)
{
	char	*file;
	char	**final;

	file = ft_read_fd(fd);
	if (!file || !file[0])
		return (0);
	final = ft_split(file, '\n');
	free(file);
	return (final);
}
