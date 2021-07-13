/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylazrek <ylazrek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 17:08:40 by ylazrek           #+#    #+#             */
/*   Updated: 2021/07/12 16:23:21 by ylazrek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philosophers_init(void)
{
	int	i;

	g_ps = malloc(sizeof(t_philo) * g_n);
	i = -1;
	mutexes_init();
	while (++i < g_n)
	{
		g_ps[i].eat_count = 0;
		g_ps[i].id = i;
		g_ps[i].left = i;
		g_ps[i].right = (i + 1) % g_n;
		pthread_mutex_init(&g_ps[i].mutex_eat, NULL);
	}
	g_someone_died = 1;
}

void	philosophers_start(void)
{
	int	i;

	g_start = get_time();
	i = -1;
	while (++i < g_n)
	{
		pthread_create(&g_ps[i].th, NULL, philosophers_routine, &g_ps[i]);
		pthread_detach(g_ps[i].th);
		usleep(100);
	}
}

void	philosophers_clear(void)
{
	int	i;

	i = -1;
	while (++i < g_n)
		pthread_mutex_destroy(&g_ps[i].mutex_eat);
	free(g_ps);
	mutexes_clear();
}
