/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylazrek <ylazrek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 17:09:13 by ylazrek           #+#    #+#             */
/*   Updated: 2021/07/12 16:32:57 by ylazrek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_isnumeric(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '+')
		i++;
	if (str[0] == '+' && ft_strlen(str) == 1)
		return (0);
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	int		value;
	int		prev;

	i = 0;
	sign = 1;
	value = 0;
	while (((str[i] <= 13 && str[i] >= 9) || str[i] == 32) && str[i] != '\0')
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= 48 && str[i] <= 57 && str[i] != '\0')
	{
		prev = value;
		value = value * 10 + sign * (str[i] - '0');
		if (sign == 1 && prev > value)
			return (-1);
		else if (sign == -1 && prev < value)
			return (0);
		i++;
	}
	return (value);
}

void	ft_putnbr_fd(unsigned long long n, int fd)
{
	char	str[13];
	int		length;

	if (n == 0)
		str[0] = '0';
	length = 0;
	while (n != 0)
	{
		str[length++] = '0' + (n % 10);
		n = (n / 10);
	}
	if (length > 0)
		length--;
	while (length >= 0)
		write(fd, &str[length--], 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}
