/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylazrek <ylazrek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 17:08:51 by ylazrek           #+#    #+#             */
/*   Updated: 2021/07/12 16:23:42 by ylazrek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef enum e_state
{
	EAT,
	SLEEP,
	THINK,
	FORK,
	DIED
}						t_state;
typedef struct s_philo
{
	int					id;
	unsigned long		last_meal;
	unsigned long		limit;
	int					left;
	int					right;
	pthread_t			th;
	pthread_t			th_health;
	pthread_mutex_t		mutex_eat;
	int					eat_count;
}						t_philo;

pthread_mutex_t			*g_forks;
pthread_mutex_t			g_io_lock;
pthread_mutex_t			g_mutex_main;
t_philo					*g_ps;

int						g_n;
int						g_die;
int						g_eat;
int						g_sleep;
int						g_count;

int						g_someone_died;
unsigned long			g_start;
int						g_eat_count;

void					print_message(t_philo *p, int state);
int						ft_isnumeric(char *str);
int						ft_atoi(const char *str);
void					ft_putnbr_fd(unsigned long long n, int fd);
void					ft_putstr(char *str);
int						ft_strlen(char *str);
int						args_isvalid(int argc, char **argv);
void					print_error(char *str);
void					philosophers_init(void);
void					philosophers_clear(void);
void					philosophers_start(void);
unsigned long			get_time(void);
void					mutexes_init(void);
void					mutexes_clear(void);
int						take_fork(t_philo *p);
int						release_fork(t_philo *p);
int						eat(t_philo *p);
int						go_sleep(t_philo *p);
void					*philosophers_routine(void *data);

#endif
