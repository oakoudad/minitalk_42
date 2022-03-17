/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:45:39 by oakoudad          #+#    #+#             */
/*   Updated: 2021/11/12 15:45:41 by oakoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	l;
	char	*str;

	i = -1;
	if (!s || !f)
		return (NULL);
	l = ft_strlen(s);
	str = malloc(sizeof(char) * l + 1);
	if (!str)
		return (NULL);
	while (++i < l)
		str[i] = (*f)(i, s[i]);
	str[i] = '\0';
	return (str);
}
