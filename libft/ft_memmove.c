/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 18:32:13 by oakoudad          #+#    #+#             */
/*   Updated: 2021/11/12 14:55:12 by oakoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*c_src;
	char	*c_dst;

	c_dst = (char *)dst;
	c_src = (char *)src;
	if (c_src == NULL && c_dst == NULL)
		return (NULL);
	if (c_dst < c_src)
		return (ft_memcpy(dst, src, len));
	while (len > 0)
	{
		c_dst[len - 1] = c_src[len - 1];
		len--;
	}
	return (c_dst);
}
