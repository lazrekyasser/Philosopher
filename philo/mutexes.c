/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutexes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylazrek <ylazrek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 17:08:34 by ylazrek           #+#    #+#             */
/*   Updated: 2021/07/12 15:02:04 by ylazrek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	mutexes_init(void)
{
	int	i;

	g_forks = malloc(sizeof(pthread_mutex_t) * g_n);
	pthread_mutex_init(&g_io_lock, NULL);
	pthread_mutex_init(&g_mutex_main, NULL);
	i = -1;
	while (++i < g_n)
		pthread_mutex_init(&g_forks[i], NULL);
}

void	mutexes_clear(void)
{
	int	i;

	i = -1;
	while (++i < g_n)
		pthread_mutex_destroy(&g_forks[i]);
	pthread_mutex_destroy(&g_io_lock);
	pthread_mutex_destroy(&g_mutex_main);
	free(g_forks);
}
