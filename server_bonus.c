/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytabia <ytabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:08:50 by ytabia            #+#    #+#             */
/*   Updated: 2025/01/03 13:57:51 by ytabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	signal_handler(int signal, siginfo_t *info, void *context)
{
	static int	count_bit;
	static int	character;

	(void)context;
	if (signal == SIGUSR1)
	{
		character = character << 1 | 1;
		count_bit++;
	}
	else if (signal == SIGUSR2)
	{
		character = character << 1 | 0;
		count_bit++;
	}
	if (count_bit == 8)
	{
		if (character == '\0')
		{
			ft_printf("\n");
		}
		ft_printf("%c", character);
		character = 0;
		count_bit = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(int ac, char **av)
{
	struct sigaction	sa;

	(void)av;
	if (ac == 1)
	{
		ft_printf("PID >> %d\n", getpid());
		sa.sa_sigaction = signal_handler;
		sa.sa_flags = SA_SIGINFO;
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		while (1)
			pause();
	}
	ft_printf("Error: Put one argument\n");
}
