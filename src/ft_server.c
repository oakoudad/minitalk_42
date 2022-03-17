/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakoudad <oakoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:31:10 by oakoudad          #+#    #+#             */
/*   Updated: 2022/03/16 20:27:14 by oakoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int	ft_power(int a, int p)
{
	if (p == 0)
		return (1);
	if (p == 1)
		return (a);
	return (a * ft_power(a, p - 1));
}

void	init_bin(int *i, int *cp, char *c)
{
	*i = 0;
	*cp = 0;
	*c = 0;
}

void	ft_serve(int signal, siginfo_t *siginfo, void *uc)
{
	static int	cp;
	static int	i;
	static char	c;
	static int	c_pid;

	(void)uc;
	if (c_pid != siginfo->si_pid)
		init_bin(&i, &cp, &c);
	if (signal == SIGUSR2)
		c += ft_power(2, cp);
	else
		i++;
	cp++;
	if (cp == 8 && i < 8)
	{
		ft_putchar_fd(c, 1);
		init_bin(&i, &cp, &c);
	}
	if (i == 8)
	{
		kill(siginfo->si_pid, SIGUSR1);
		init_bin(&i, &cp, &c);
	}
	c_pid = siginfo->si_pid;
}

int	main(void)
{
	struct sigaction	action;

	ft_putstr_fd("Your PID : ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	action.sa_sigaction = ft_serve;
	action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
		usleep(5000);
}
