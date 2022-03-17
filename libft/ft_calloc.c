/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:05:30 by oakoudad          #+#    #+#             */
/*   Updated: 2021/11/12 15:05:35 by oakoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void		*p;

	p = malloc(size * count);
	if (!p)
		return (NULL);
	ft_memset(p, '\0', size * count);
	return (p);
}
