/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labenall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:52:14 by labenall          #+#    #+#             */
/*   Updated: 2022/05/11 17:55:52 by labenall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	hendler_server(int sign, siginfo_t *info, void *context)
{
	static char		c;
	static int		j;
	static int		id_client;

	id_client = info->si_pid;
	if (sign == SIGUSR1)
	{
		c = c | 1 << j;
		j++;
	}
	else
	{	
		j++;
	}
	if (j == 8)
	{
		ft_printf("%c", c);
		if (c == 0)
		{
			if (kill(id_client, SIGUSR2) == -1)
				ft_exit("Error of sending signal\n", 1);
		}
		j = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("%d\n", getpid());
	sa.sa_sigaction = hendler_server;
	sa.sa_flags = SA_SIGINFO;
	while (1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		pause();
	}
	return (0);
}
