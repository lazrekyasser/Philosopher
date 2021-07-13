/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylazrek <ylazrek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 17:08:18 by ylazrek           #+#    #+#             */
/*   Updated: 2021/07/12 18:28:27 by ylazrek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*check_health(void *data)
{
	t_philo	*p;

	p = (t_philo *)data;
	while (g_someone_died)
	{
		if (get_time() > p->limit)
		{
			pthread_mutex_lock(&p->mutex_eat);
			print_message(p, DIED);
			g_someone_died = 0;
			pthread_mutex_unlock(&g_mutex_main);
			return (NULL);
		}
		usleep(100);
	}
	return (NULL);
}

static void	generate_health_checker(t_philo *p)
{
	pthread_create(&p->th_health, NULL, check_health, p);
	pthread_detach(p->th_health);
}

void	*philosophers_routine(void *data)
{
	t_philo	*p;

	p = (t_philo *)data;
	p->last_meal = get_time();
	p->limit = p->last_meal + g_die;
	generate_health_checker(p);
	while (g_someone_died)
	{
		if (!take_fork(p))
			return (NULL);
		if (!eat(p))
			return (NULL);
		if (!release_fork(p))
			return (NULL);
		if (!go_sleep(p))
			return (NULL);
		print_message(p, THINK);
	}
	return (NULL);
}
