/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytabia <ytabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:08:36 by ytabia            #+#    #+#             */
/*   Updated: 2025/01/06 17:13:01 by ytabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	ft_atoi(char *str)
{
	int	i;
	int	signe;
	int	result;

	i = 0;
	signe = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			return (1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	if (str[i])
		return (1);
	return (result * signe);
}

void	send_char(int pid, char c)
{
	int	j;

	j = 7;
	while (j >= 0)
	{
		if (c >> j & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(5000);
		j--;
	}
	while (!g_recieved)
		pause();
	g_recieved = 0;
}

void	send_string(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
		send_char(pid, str[i++]);
	send_char(pid, '\0');
}

void	handler(int signum)
{
	if (signum == SIGUSR1)
		g_recieved = 1;
}

int	main(int argc, char **argv)
{
	int	server_pid;

	signal(SIGUSR1, handler);
	if (argc != 3)
	{
		ft_printf("Error: wrong format\n");
		ft_printf("<./client><server_pid><string>");
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	if (kill(server_pid, 0) == -1)
	{
		ft_printf("Error: Invalid server PID");
		return (1);
	}
	if ((long unsigned int) server_pid == __SIZE_MAX__)
		return (-1);
	send_string(server_pid, argv[2]);
	if (g_recieved == 0)
		ft_printf(">>the msg was sent good<<\n");
}
