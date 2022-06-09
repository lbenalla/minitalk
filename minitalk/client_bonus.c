/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labenall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:51:30 by labenall          #+#    #+#             */
/*   Updated: 2022/05/11 15:40:54 by labenall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	handler_client(int sign)
{
	if (sign == SIGUSR2)
		ft_exit("Message bien recu\n", 0);
}

static void	send_char(char c, int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & 1 << i)
		{
			if (kill(pid, SIGUSR1) != 0)
				ft_exit("Incorrect PID\n", 1);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				ft_exit("Incorrect PID\n", 1);
		}
		usleep(500);
		i++;
	}
}

void	send_message(char **av)
{
	int	i;
	int	pid;

	i = 0;
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

int	main(int ac, char **av)
{
	struct sigaction	sa_client;

	sa_client.sa_handler = &handler_client;
	sa_client.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa_client, NULL) == -1
		|| sigaction(SIGUSR2, &sa_client, NULL) == -1)
		ft_exit("Erreur Sigaction\n", 1);
	if (ac == 3)
		send_message(av);
	else
		ft_exit("./client [PID] [Message]\n", 1);
	while (1)
		pause();
	return (0);
}
