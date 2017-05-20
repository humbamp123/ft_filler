/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 10:28:15 by apineda           #+#    #+#             */
/*   Updated: 2016/10/21 17:55:40 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_whitespace(char const *s, char c, int i)
{
	while (s[i] == c && s[i] != '\0')
		i++;
	return (i);
}

static int	ft_c(char const *s, char c, int i)
{
	int		j;

	j = 1;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		j++;
	}
	return (j);
}

static int	ft_words(char const *s, char c, int i)
{
	int		j;

	j = 1;
	while (s[i] != '\0')
	{
		while (s[i] != c && s[i] != '\0')
			i++;
		j++;
		i = ft_whitespace(s, c, i);
	}
	return (j);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		i[3];

	str = NULL;
	ft_bzero((void*)i, sizeof(int) * 3);
	if (s && c)
	{
		i[0] = ft_whitespace(s, c, i[0]);
		if ((str = (char **)ft_memalloc(sizeof(char*) * ft_words(s, c, i[0]))))
		{
			while (s[i[0]] != '\0')
			{
				i[1] = 0;
				str[i[2]] = (char *)ft_strnew(sizeof(char) * ft_c(s, c, i[0]));
				while (s[i[0]] != c && s[i[0]] != '\0')
					str[i[2]][i[1]++] = s[i[0]++];
				str[i[2]][i[1]] = '\0';
				i[2]++;
				i[0] = ft_whitespace(s, c, i[0]);
			}
			str[i[2]] = NULL;
		}
	}
	return (str);
}
