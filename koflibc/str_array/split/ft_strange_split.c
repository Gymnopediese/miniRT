/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strange_split.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 04:41:33 by albaud            #+#    #+#             */
/*   Updated: 2022/10/31 10:28:56 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../sources.h"

void	ft_findword(int *flag, int i, int **mots)
{
	*flag = 1;
	**mots = i;
	*mots += 1;
}

void	ft_strange(int *flag, int *i, int **mots, const char *str)
{
	char	cible;

	cible = str[*i];
	if (*flag == 0)
	{
		**mots = *i;
		*mots += 1;
		*flag = 1;
	}
	while (str[*i + 1] && str[*i + 1] != cible)
		*i += 1;
}

int	ft_mega_splits(const char *str, int *mots, char charset, char *join)
{
	int		i;
	int		worldcount;
	int		flag;

	flag = 0;
	i = -1;
	worldcount = 0;
	while (str[++i])
	{
		if (ft_strcontain(join, str[i]))
			ft_strange(&flag, &i, &mots, str);
		if (flag == 0 && str[i] != charset)
			ft_findword(&flag, i, &mots);
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

char	**ft_strange_split(char const *s, char c, char *join)
{
	int		endstart[3000];
	int		wordcount;
	char	**final;
	int		loop;
	int		loop2;

	wordcount = ft_mega_splits(s, endstart, c, join);
	final = malloc((wordcount + 1) * sizeof (*final));
	loop = 0;
	while (loop < wordcount * 2)
	{
		final[loop / 2] = malloc((endstart[loop + 1]
					- endstart[loop] + 1) * sizeof (char));
		loop2 = 0;
		while (endstart[loop] < endstart[loop + 1])
		{
			final[loop / 2][loop2] = s[endstart[loop]];
			endstart[loop] += 1;
			loop2++;
		}
		final[loop / 2][loop2] = 0;
		loop += 2;
	}
	final[loop / 2] = 0;
	return (ft_clean_enclosures_sa(final, join));
}

/*
char	**ft_strange_split(char const *s, char *split, char *join)
{
	char	**splited;
	char	**joined;
	int		i;
	int		j;

	splited = ft_strsplit(s, *split);
	joined = ft_strsplit(s, *split);
	i = -1;
	j = 0;
	while (splited[++i])
	{
		if (ft_contain_subs(splited[++i], join))
		{
			joined[j] = ft_replacen(splited[i], join, "", -1);
			if (ft_count(splited[i], *join) == 1)
			{
				while (!ft_contain_subs(splited[++i], join))
					joined[j] = ft_strjoin(joined[j], splited[i]);
			}
			joined[j] = ft_strjoin(joined[j],
					ft_replacen(splited[i], join, "", -1));
		}
		else
			joined[j] = splited[i];
		j++;
	}
	return (joined);
}
*/