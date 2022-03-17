/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 16:09:54 by oakoudad          #+#    #+#             */
/*   Updated: 2021/11/12 14:56:40 by oakoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_word(char const *s, char c)
{
	int	i;
	int	flage;
	int	cp;

	i = 0;
	flage = 0;
	cp = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] != c && flage == 0)
		{
			cp++;
			flage = 1;
		}
		else if (s[i] == c && flage == 1)
			flage = 0;
		i++;
	}
	return (cp);
}

int	ft_count_and_alloc(char *s, char c)
{
	int	i;
	int	cp;

	i = 0;
	cp = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i] != c && s[i])
	{
		i++;
		cp++;
	}
	if (cp == 0)
		return (0);
	return (cp);
}

int	ft_split_2(char const *s, char c, char **str, int i)
{
	int	j;
	int	k;

	j = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			k = 0;
			str[j] = (char *)malloc(ft_count_and_alloc((char *)&s[i], c) + 1);
			if (!str[j])
				return (j);
			while (k < ft_count_and_alloc((char *)&s[i], c))
			{
				str[j][k] = s[i + k];
				k++;
			}
			str[j++][k] = 0;
			i += k;
		}
	}
	str[j] = 0;
	return (-1);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		j;

	if (!s)
		return (NULL);
	str = (char **)malloc(sizeof(char *) * count_word(s, c) + 1);
	if (!str)
		return (NULL);
	j = ft_split_2(s, c, str, 0);
	if (j != -1)
	{
		while (j >= 0)
			free(&str[j--]);
		free(str);
	}
	return (str);
}
