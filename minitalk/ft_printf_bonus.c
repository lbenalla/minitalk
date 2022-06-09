/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labenall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:51:52 by labenall          #+#    #+#             */
/*   Updated: 2022/05/09 16:55:52 by labenall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	my_ft_print(unsigned int un, int *ret)
{
	char	c;

	if (un >= 10)
	{
		my_ft_print(un / 10, ret);
		my_ft_print(un % 10, ret);
	}
	else
	{
		c = un + '0';
		write(1, &c, 1);
		*ret = *ret +1;
	}
}

static int	ft_printdecimal(int n)
{
	unsigned int	un;
	int				ret;

	ret = 0;
	if (n < 0)
	{
		un = n * (-1);
		write(1, "-", 1);
		ret++;
	}
	else
		un = n;
	my_ft_print(un, &ret);
	return (ret);
}

static int	ft_printchar(int c)
{
	unsigned char	s;

	s = (unsigned char)c;
	write(1, &s, 1);
	return (1);
}

static int	my_print(va_list ap, char c)
{
	int	ret;

	ret = 0;
	if (c == 'c')
		ret += ft_printchar(va_arg(ap, int));
	else if (c == 'd')
		ret += ft_printdecimal(va_arg(ap, int));
	else if (c == 's')
		ret += ft_printstr(va_arg(ap, char *));
	return (ret);
}

int	ft_printf(char *s, ...)
{
	int		ret;
	int		i;
	va_list	ap;

	i = 0;
	va_start(ap, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			if (s[i + 1] == '\0')
				break ;
			ret += my_print(ap, s[i + 1]);
			i++;
		}
		else
			ret += write(1, &s[i], 1);
		i++;
	}
	va_end(ap);
	return (ret);
}
