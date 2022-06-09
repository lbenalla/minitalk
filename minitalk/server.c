/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labenall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 18:01:44 by labenall          #+#    #+#             */
/*   Updated: 2022/05/09 16:57:23 by labenall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	hendler_server(int sign)
{
	static char		c;
	static int		j;

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
		j = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("%d\n", getpid());
	sa.sa_handler = &hendler_server;
	sa.sa_flags = SA_SIGINFO;
	while (1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		pause();
	}
	return (0);
}
