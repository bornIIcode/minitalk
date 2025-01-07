/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytabia <ytabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:25:54 by ytabia            #+#    #+#             */
/*   Updated: 2025/01/03 13:52:58 by ytabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H
# include "ft_printf/ft_printf.h"
# include <signal.h>
# include <stdio.h>
# include <unistd.h>

int		g_recieved;
void	signal_handler(int signal, siginfo_t *info, void *context);
#endif
