/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcedric <bcedric@student.19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 13:26:38 by bcedric           #+#    #+#             */
/*   Updated: 2018/10/12 22:16:44 by bcedric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countletter(char const *s, char c)
{
	size_t	i;
	size_t	countletter;

	i = 0;
	countletter = 0;
	while (s[i])
	{
		if (s[i] != c && s[i + 1] != c && s[i + 1] != '\0')
			countletter++;
		else if (s[i] == c && s[i - 1] != c)
			break ;
		i++;
	}
	countletter++;
	return (countletter);
}

static size_t	ft_countwords(char const *s, char c)
{
	size_t	i;
	size_t	countwords;

	countwords = 0;
	i = 0;
	if (s[0] != c)
	{
		countwords++;
		i++;
	}
	while (s[i])
	{
		if (s[i] != c && s[i - 1] == c)
			countwords++;
		i++;
	}
	return (countwords);
}

static char		*ft_word(char const *s, char c)
{
	char	*str;
	size_t	i;
	size_t	letter;

	letter = ft_countletter(s, c);
	str = ft_strnew(letter);
	i = 0;
	while (i < letter)
	{
		str[i] = s[i];
		i++;
	}
	return (str);
}

static void		*ft_remove(char **str, int index)
{
	while (index >= 0)
	{
		free(str[index]);
		index--;
	}
	free(str);
	return (NULL);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	k;
	char	**str;

	if (s == NULL)
		return (NULL);
	i = 0;
	k = 0;
	str = (char**)malloc(sizeof(char*) * (ft_countwords(s, c)) + 1);
	if (str == NULL)
		return (NULL);
	while (s[k])
	{
		if ((s[k] == c && s[k + 1] != c && s[k + 1] != '\0') ||
			(k == 0 && s[k] != c))
		{
			str[i] = ft_word((k == 0 && s[k] != c) ? &s[k] : &s[k + 1], c);
			if (str[i] == NULL)
				return (ft_remove(str, i));
			i++;
		}
		k++;
	}
	str[i] = 0;
	return (str);
}
