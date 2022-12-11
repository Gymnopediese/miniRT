/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glob.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:31:01 by albaud            #+#    #+#             */
/*   Updated: 2022/07/18 16:01:36 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources.h"

char	**ft_glob(char *dirname, int mode)
{	
	char			**res;
	DIR				*d;
	struct dirent	*dir;
	int				i;

	d = opendir(dirname);
	i = -1;
	if (d)
	{
		res = malloc((ft_count_dir(dirname, mode) + 1) * sizeof(char *));
		dir = readdir(d);
		while (dir != NULL)
		{
			if (mode || dir->d_name[0] != '.')
				res[++i] = ft_strdup(dir->d_name);
			dir = readdir(d);
		}
		closedir(d);
		res[++i] = 0;
		ft_bubble_sort_sa(res);
		return (res);
	}
	return (0);
}
