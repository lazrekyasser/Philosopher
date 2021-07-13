/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylazrek <ylazrek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 17:08:00 by ylazrek           #+#    #+#             */
/*   Updated: 2021/07/12 15:16:17 by ylazrek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	take_fork(t_philo *p)
{
	if (g_someone_died)
	{	
		pthread_mutex_lock(&g_forks[p->left]);
		print_message(p, FORK);
		if (g_someone_died)
		{
			pthread_mutex_lock(&g_forks[p->right]);
			print_message(p, FORK);
			return (1);
		}
	}
	return (0);
}

int	release_fork(t_philo *p)
{
	if (g_someone_died)
	{
		pthread_mutex_unlock(&g_forks[p->left]);
		pthread_mutex_unlock(&g_forks[p->right]);
		pthread_mutex_unlock(&p->mutex_eat);
		return (1);
	}
	return (0);
}
