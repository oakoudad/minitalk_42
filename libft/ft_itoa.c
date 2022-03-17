/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 16:11:10 by oakoudad          #+#    #+#             */
/*   Updated: 2021/11/12 14:45:31 by oakoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count(long n, int *c)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n / 10 > 0)
	{
		n /= 10;
		i++;
	}
	*c = i;
	return (i);
}

char	*ft_itoa(int n)
{
	int		c;
	long	cp;
	char	*str;

	cp = n;
	str = malloc(sizeof(char) * ft_count(n, &c) + 1);
	if (!str)
		return (NULL);
	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
	}
	if (cp < 0)
	{
		str[0] = '-';
		cp *= -1;
	}
	str[c] = 0;
	while (c - 1 >= 0 && str[c - 1] != '-')
	{
		str[c-- - 1] = '0' + (cp % 10);
		cp /= 10;
	}
	return (str);
}
