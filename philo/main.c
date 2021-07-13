/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylazrek <ylazrek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 17:08:27 by ylazrek           #+#    #+#             */
/*   Updated: 2021/07/12 16:21:23 by ylazrek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	if (!args_isvalid(argc, argv))
	{
		print_error("Error : arguments are not valid\n");
		return (1);
	}
	g_n = ft_atoi(argv[1]);
	g_die = ft_atoi(argv[2]);
	g_eat = ft_atoi(argv[3]);
	g_sleep = ft_atoi(argv[4]);
	g_count = -1;
	if (argc == 6)
		g_count = ft_atoi(argv[5]);
	philosophers_init();
	philosophers_start();
	pthread_mutex_lock(&g_mutex_main);
	pthread_mutex_lock(&g_mutex_main);
	philosophers_clear();
	return (0);
}
