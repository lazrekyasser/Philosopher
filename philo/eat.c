/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylazrek <ylazrek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 17:07:53 by ylazrek           #+#    #+#             */
/*   Updated: 2021/07/12 16:22:35 by ylazrek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	eat(t_philo *p)
{
	int	time;

	time = g_eat * 1000;
	if (g_someone_died == 1)
	{
		pthread_mutex_lock(&p->mutex_eat);
		p->eat_count++;
		print_message(p, EAT);
		p->last_meal = get_time();
		p->limit = p->last_meal + g_die;
		usleep(time);
		return (1);
	}
	return (0);
}
