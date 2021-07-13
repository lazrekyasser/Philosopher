/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylazrek <ylazrek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 17:09:03 by ylazrek           #+#    #+#             */
/*   Updated: 2021/07/10 17:20:52 by ylazrek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	go_sleep(t_philo *p)
{
	int	time;

	time = g_sleep * 1000;
	if (g_someone_died)
	{
		print_message(p, SLEEP);
		usleep(time);
		return (1);
	}
	return (0);
}
