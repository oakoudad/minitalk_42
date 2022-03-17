/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 18:23:16 by oakoudad          #+#    #+#             */
/*   Updated: 2021/11/12 13:28:33 by oakoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*c_dst;
	char	*c_src;
	size_t	i;

	i = 0;
	c_dst = (char *)dst;
	c_src = (char *)src;
	if (c_src == NULL && c_dst == NULL)
		return (NULL);
	while (i < n)
	{
		c_dst[i] = c_src[i];
		i++;
	}
	return (dst);
}
