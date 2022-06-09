/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labenall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:52:02 by labenall          #+#    #+#             */
/*   Updated: 2022/05/11 17:53:24 by labenall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

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
