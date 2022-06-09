/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labenall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:51:42 by labenall          #+#    #+#             */
/*   Updated: 2022/05/11 17:54:19 by labenall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_exit(char *s, int n_exit)
{
	ft_printf("%s", s);
	exit(n_exit);
}

static void	invalid_number(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] < '0' || s[i] >= '9')
			ft_exit("Invalid PID", 1);
		i++;
	}
}

static	int	cas(int s)
{
	if (s == 1)
		return (-1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int						s;
	unsigned long long		res;
	unsigned long long		stock;

	s = 1;
	res = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
	{
		s = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	invalid_number(str);
	while (*str >= '0' && *str <= '9')
	{
		stock = res;
		res = res * 10 + *str - '0';
		if (stock > res || res > LONG_MAX)
			return (cas(s));
		str++;
	}
	return (s * res);
}
