/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labenall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 18:02:00 by labenall          #+#    #+#             */
/*   Updated: 2022/05/12 11:57:28 by labenall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(char c, int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & 1 << i)
		{
			if (kill(pid, SIGUSR1) == -1)
				ft_exit("Incorrect PID\n", 1);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				ft_exit("Incorrect PID\n", 1);
		}
		usleep(200);
		i++;
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	i = 0;
	if (ac == 3)
	{	
		pid = ft_atoi(av[1]);
		if (pid <= 0)
			ft_exit("PID invalid\n", 1);
		while (av[2][i])
		{
			send_char(av[2][i], pid);
			i++;
		}
		send_char(av[2][i], pid);
	}
	else
		ft_exit("./client [PID] [Message]\n", 1);
	return (0);
}
