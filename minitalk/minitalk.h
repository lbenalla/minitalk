/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labenall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 20:11:53 by labenall          #+#    #+#             */
/*   Updated: 2022/05/11 17:52:51 by labenall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <stdarg.h>
# include <sys/types.h>
# include <limits.h>

int		ft_printf(char *s, ...);
int		ft_atoi(const char *s);
int		ft_printstr(char *s);
void	ft_exit(char *s, int n_exit);

#endif
