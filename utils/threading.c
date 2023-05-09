/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threading.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:08:11 by albaud            #+#    #+#             */
/*   Updated: 2023/05/09 16:39:48 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	do_my_part(t_process *process)
{
	int		color;
	t_ray	r;
	t_v3	iter;

	iter.x = process->start.x - 1;
	iter.y = process->start.y - 1;
	iter.z = 0;
	while (++iter.y < process->scene->w.cvs.y)
	{
		while (++iter.x < process->scene->w.cvs.x)
		{
			r.origin = process->scene->camera->pos;
			r.direction = v_relative_pos(process->scene->w.cvs.x,
					process->scene->w.cvs.y, iter.x, iter.y);
			color = ray_trace_basic(process->scene, &r);
			if (-1 != color)
				ft_put_pixel(&process->scene->w.cvs, iter.x, iter.y, color);
			if (++iter.z >= process->iteration)
				return ;
		}
		iter.x = -1;
	}
}

void	*iterate_thread(void *p)
{
	t_process	*process;

	process = p;
	while (1)
	{
		pause();
		do_my_part(process);
		pthread_mutex_lock(&process->scene->lock);
		process->scene->process_count++;
		pthread_mutex_unlock(&process->scene->lock);
	}
	return (0);
}

void	init_threads(t_scene *scene, int amount)
{
	int	i;
	int	sum;
	int	add;

	scene->processes = allok(amount, sizeof(t_process), 1);
	i = -1;
	sum = 0;
	add = (scene->w.cvs.x * scene->w.cvs.y) / amount;
	printf("%i\n", (scene->w.cvs.x * scene->w.cvs.y));
	scene->process_count = 0;
	scene->process_amount = amount;
	pthread_mutex_init(&scene->lock, 0);
	while (++i < amount)
	{
		scene->processes[i].iteration = add;
		scene->processes[i].start.x = sum % scene->w.cvs.x;
		scene->processes[i].start.y = sum / scene->w.cvs.y;
		scene->processes[i].scene = scene;
		pthread_create(&scene->processes[i].thread,
			0, iterate_thread, &scene->processes[i]);
		sum += add;
	}
}
