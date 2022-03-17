/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 16:04:30 by oakoudad          #+#    #+#             */
/*   Updated: 2021/11/12 14:15:21 by oakoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char const	*ft_start(char const *s1, char const *set)
{
	int	i;
	int	status;

	while (*s1)
	{
		i = 0;
		status = 0;
		while (set[i])
		{
			if (set[i] == *s1 && status == 0)
			{
				s1++;
				status = 1;
			}
			i++;
		}
		if (status == 0)
			break ;
	}
	return ((char *)s1);
}

int	ft_end(char *s1, char const *set)
{
	int	i;
	int	status;
	int	l;

	l = ft_strlen (s1) - 1;
	while (l >= 0)
	{
		i = 0;
		status = 0;
		while (set[i])
		{
			if (set[i] == s1[l] && status == 0)
			{
				l--;
				status = 1;
			}
			i++;
		}
		if (status == 0)
			break ;
	}
	return (l + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*p;
	int		i;

	if (!s1 || !set)
		return (NULL);
	s1 = ft_start(s1, set);
	p = (char *) malloc (ft_end ((char *)s1, set) + 1);
	if (!p)
		return (NULL);
	i = 0;
	while (i < ft_end((char *)s1, set))
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = 0;
	return (p);
}
