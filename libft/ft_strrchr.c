/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.C                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 19:19:00 by oakoudad          #+#    #+#             */
/*   Updated: 2021/11/12 13:49:54 by oakoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	int				tmp;

	i = 0;
	tmp = 0;
	while (1)
	{
		if (s[i] == (unsigned char)c)
			tmp = i;
		if (s[i] == '\0')
			break ;
		i++;
	}
	s += tmp;
	if (s[0] == (unsigned char)c)
		return ((char *)s);
	return (0);
}
