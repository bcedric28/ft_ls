/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcedric <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 17:13:44 by bcedric           #+#    #+#             */
/*   Updated: 2018/10/05 17:13:46 by bcedric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int j;
	int	verif;

	verif = 0;
	i = -1;
	j = 0;
	if (*s == '\0' && c == '\0')
		return ((char*)s);
	while (s[++i] != '\0')
	{
		if (s[i] == c)
		{
			j = i;
			verif = 1;
		}
		else if (s[i + 1] == c)
		{
			j = i + 1;
			verif = 1;
		}
	}
	if (verif == 1)
		return ((char*)&s[j]);
	return (0);
}
