/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 13:45:22 by oakoudad          #+#    #+#             */
/*   Updated: 2021/11/12 13:45:24 by oakoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	l_src;
	size_t	l_dst;
	size_t	i;

	l_src = ft_strlen(src);
	l_dst = ft_strlen (dst);
	i = 0;
	if (dstsize <= l_dst)
		return (l_src + dstsize);
	while (src[i] && (dstsize - l_dst - 1) > 0)
		dst[l_dst++] = src[i++];
	dst[l_dst] = '\0';
	return (l_dst - i + l_src);
}
