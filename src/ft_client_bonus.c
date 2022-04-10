/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakoudad <oakoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:02:27 by oakoudad          #+#    #+#             */
/*   Updated: 2022/03/19 21:18:26 by oakoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int	g_send;

int	ft_isvalid(int c, char *pid)
{
	int	i;

	i = 0;
	if (c != 3)
	{
		ft_putstr_fd("\x1B[31mWrong Args!\n\x1B[0m", 1);
		return (0);
	}
	while (pid[i])
	{
		if (ft_isdigit(pid[i]) == 0)
		{
			ft_putstr_fd("\x1B[31mBad PID!\n\x1B[0m", 1);
			return (0);
		}
		i++;
	}
	if (kill(ft_atoi(pid), 0) == -1)
	{
		ft_putstr_fd("\x1B[31mPID is not worked!\n\x1B[0m", 1);
		return (0);
	}
	return (1);
}

void	ft_send_char(int pid, unsigned char c)
{
	int	i;
	int	a;

	i = 0;
	while (i < 8)
	{
		while (g_send)
			usleep(10);
		g_send = 1;
		if (c & 1)
			a = kill(pid, SIGUSR2);
		else
			a = kill(pid, SIGUSR1);
		c = c >> 1;
		i++;
		if (a == -1)
			exit(0);
	}
}

void	handler(int sing)
{
	(void)sing;
	ft_putstr_fd("\x1B[32mMessage received! \x1B[0m\n", 1);
	exit(1);
}

void	next(int sing)
{
	(void)sing;
	g_send = 0;
}

int	main(int c, char **v)
{
	int		pid;
	size_t	i;
	char	*arg;

	i = 0;
	if (ft_isvalid(c, v[1]))
	{
		pid = ft_atoi(v[1]);
		arg = v[2];
		i = 0;
		signal(SIGUSR1, handler);
		signal(SIGUSR2, next);
		g_send = 0;
		while (i <= ft_strlen(arg))
		{
			ft_send_char(pid, arg[i]);
			if (arg[i] == 0)
				break ;
			i++;
		}
		while (1)
			usleep(10);
	}
	return (0);
}
