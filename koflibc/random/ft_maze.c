/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maze.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:44:40 by albaud            #+#    #+#             */
/*   Updated: 2022/11/23 14:57:27 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources.h"

void	ft_init_neighboors(t_vector *neights, t_vector pos)
{
	neights[0] = ft_vect(pos.x - 1, pos.y, 0);
	neights[1] = ft_vect(pos.x + 1, pos.y, 0);
	neights[2] = ft_vect(pos.x, pos.y + 1, 0);
	neights[3] = ft_vect(pos.x, pos.y - 1, 0);
	neights[4] = ft_vect(pos.x - 2, pos.y, 0);
	neights[5] = ft_vect(pos.x + 2, pos.y, 0);
	neights[6] = ft_vect(pos.x, pos.y + 2, 0);
	neights[7] = ft_vect(pos.x, pos.y - 2, 0);
}

int	ft_try_dig(t_matrix map, t_vector *neights, int ind)
{
	if (ft_isin_range(neights[ind + 4].y, 1, map.size.y - 1)
		&& ft_isin_range(neights[ind + 4].x, 1, map.size.x - 1)
		&& map.map[(int)neights[ind].y][(int)neights[ind].x] == 1
		&& map.map[(int)neights[ind + 4].y][(int)neights[ind + 4].x] == 1)
	{
		map.map[(int)neights[ind].y][(int)neights[ind].x] = 0;
		return (1);
	}
	return (0);
}

int	ft_get_valid_neighboor(t_matrix map, t_vector *n)
{
	t_list		*range;
	int			ran;
	int			ind;

	range = ft_list_range(0, 4);
	while (ft_size(range) > 0)
	{
		ran = ft_randint(0, ft_size(range));
		ind = *(int *)ft_get(range, ran)->data;
		if (ft_try_dig(map, n, ind))
		{
			ft_free_list(&range, &free);
			return (ind);
		}
		ft_remove_at(&range, ran, &free);
	}
	return (-1);
}

void	ft_draw_maze(t_matrix *map)
{
	t_list		*stack;
	t_vector	neights[8];
	t_vector	temp;
	int			size;
	int			ind;

	stack = 0;
	ft_add(&stack, (void *) ft_mal_vector(1, 1, 0));
	size = ft_size(stack);
	while (size > 0)
	{
		temp = *(t_vector *) ft_get(stack, size - 1)->data;
		ft_init_neighboors(neights, temp);
		map->map[(int)temp.y][(int)temp.x] = 0;
		ind = ft_get_valid_neighboor(*map, neights);
		if (ind == -1)
		{
			ft_pop(&stack, &free);
			ft_pop(&stack, &free);
		}
		else
		{
			ft_add(&stack, (void *) ft_dup_vector(neights[ind]));
			ft_add(&stack, (void *) ft_dup_vector(neights[ind + 4]));
		}
		size = ft_size(stack);
	}
}

char	**ft_maze(int x, int y)
{
	t_matrix		map;

	map = ft_init_intm(x, y, 1);
	ft_putendl("2");
	ft_draw_maze(&map);
	ft_putendl("3");
	ft_putia_clean(map.map[3], x);
	ft_putstra_join(ft_imtoa(map), "\n", 1);
	ft_putendl("4");
	return (ft_imtoa(map));
}
