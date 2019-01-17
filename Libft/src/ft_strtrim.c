/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcedric <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 14:23:34 by bcedric           #+#    #+#             */
/*   Updated: 2018/10/07 14:23:35 by bcedric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t		i;
	size_t		j;

	if (s == NULL)
		return (NULL);
	i = ft_strlen(s) - 1;
	j = 0;
	while (s[i] || s[j])
	{
		if (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
			j++;
		if (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i--;
		if (s[j] == '\0' && s[j] >= s[i])
			return (ft_strnew(0));
		else if ((s[i] != ' ' && s[i] != '\n' && s[i] != '\t') &&
			(s[j] != ' ' && s[j] != '\n' && s[j] != '\t'))
			break ;
	}
	return (ft_strsub(s, j, ((i + 1) - j)));
}
