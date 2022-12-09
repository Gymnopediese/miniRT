/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:45:50 by albaud            #+#    #+#             */
/*   Updated: 2022/12/09 16:30:29 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	ft_strcmp_word(char *line, char *cmp)
{
	int	i;

	while (*line && *line == ' ')
		*line += 1;
	i = 0;
	while (line[i] == cmp[i] && cmp[i] && line[i] && line[i] != ' ')
		i++;
	return (line[i] - cmp[i]);
}

void	valid_file(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len >= 3 && filename[len - 1] == 't' && filename[len - 2] == 'r'
		&& filename[len - 3] == '.')
		return ;
	error("wrong file type");
}
