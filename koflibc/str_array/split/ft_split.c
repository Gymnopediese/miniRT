/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 15:33:57 by albaud     	   #+#    #+#             */
/*   Updated: 2022/07/11 22:37:29 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../sources.h"

int	ft_mega_split(const char *str, int *mots, int flag, char charset)
{
	int	i;
	int	worldcount;

	i = -1;
	worldcount = 0;
	while (str[++i])
	{
		if (flag == 0 && str[i] != charset)
		{
			flag = 1;
			*mots = i;
			mots += 1;
		}
		if (flag == 1 && (str[i] == charset || str[i + 1] == 0))
		{
			flag = 0;
			*mots = i;
			if (str[i + 1] == 0 && str[i] != charset)
				*mots += 1;
			mots += 1;
			worldcount++;
		}
	}
	return (worldcount);
}

int	f(char **fr)
{
	int		loop;

	loop = -1;
	while (fr[++loop])
		free(fr[loop]);
	free(fr);
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		endstart[SPLITLEN];
	int		wordcount;
	char	**final;
	int		loop;

	wordcount = ft_mega_split(s, endstart, 0, c);
	final = malloc((wordcount + 1) * sizeof (*final));
	if (final == 0)
		return (0);
	loop = 0;
	while (loop < wordcount * 2)
	{
		final[loop / 2] = malloc((endstart[loop + 1]
					- endstart[loop] + 1) * sizeof (char));
		if (final[loop / 2] == 0 && f(final))
			return (0);
		ft_strlcpy(final[loop / 2], &s[endstart[loop]],
			endstart[loop + 1] - endstart[loop] + 1);
		loop += 2;
	}
	final[loop / 2] = 0;
	return (final);
}
