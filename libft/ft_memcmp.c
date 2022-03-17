/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 14:57:17 by oakoudad          #+#    #+#             */
/*   Updated: 2021/11/12 13:54:25 by oakoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*p1;
	char	*p2;

	p1 = (char *)s1;
	p2 = (char *)s2;
	if (n == 0)
		return (0);
	i = 0;
	while (i < n - 1 && p1[i] == p2[i])
		i++;
	return ((unsigned char)p1[i] - (unsigned char)p2[i]);
}
