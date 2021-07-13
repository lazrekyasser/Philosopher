/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylazrek <ylazrek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 17:08:57 by ylazrek           #+#    #+#             */
/*   Updated: 2021/07/12 16:21:06 by ylazrek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdio.h>
void	print_error(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		write(1, &str[i], 1);
	}
}

void	print_format(int state)
{
	if (state == EAT)
		ft_putstr(" is eating\n");
	else if (state == SLEEP)
		ft_putstr(" is sleeping\n");
	else if (state == THINK)
		ft_putstr(" is thinking\n");
	else if (state == DIED)
		ft_putstr(" died\n");
	else if (state == FORK)
		ft_putstr(" has taken a fork\n");
}

void	print_message(t_philo *p, int state)
{
	pthread_mutex_lock(&g_io_lock);
	ft_putnbr_fd(get_time() - g_start, 1);
	ft_putstr(" ");
	ft_putnbr_fd(p->id + 1, 1);
	print_format(state);
	if (g_count != -1 && state == EAT && p->eat_count == g_count)
		g_eat_count++;
	if (g_eat_count == g_n)
	{
		pthread_mutex_unlock(&g_mutex_main);
		return ;
	}
	if (state != DIED)
		pthread_mutex_unlock(&g_io_lock);
}
