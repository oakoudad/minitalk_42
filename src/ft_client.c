/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakoudad <oakoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:27:16 by oakoudad          #+#    #+#             */
/*   Updated: 2022/03/17 16:21:57 by oakoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int	ft_isvalid(int c, char *pid)
{
	int	i;

	i = 0;
	if (c != 3)
	{
		ft_putstr_fd("Wrong Args!\n", 1);
		return (0);
	}
	while (pid[i])
	{
		if (ft_isdigit(pid[i]) == 0)
		{
			ft_putstr_fd("Bad PID!\n", 1);
			return (0);
		}
		i++;
	}
	if (kill(ft_atoi(pid), 0) == -1)
	{
		ft_putstr_fd("PID is not worked!\n", 1);
		return (0);
	}
	return (1);
}

void	ft_send_char(int pid, unsigned char c)
{
	int	i;

	i = -1;
	while (++i < 8)
	{
		if (c & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		c = c >> 1;
		usleep(120);
	}
}

void	handler(int sing)
{
	if (sing == SIGUSR1)
		ft_putstr_fd("Message received!\n", 1);
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
		while (i <= ft_strlen(arg))
		{
			ft_send_char(pid, arg[i]);
			if (arg[i] == 0)
				break ;
			usleep(100);
			i++;
		}
	}
	return (0);
}
