/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcedric <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 20:32:31 by bcedric           #+#    #+#             */
/*   Updated: 2018/11/03 20:43:56 by bcedric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_comp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while(s2[i])
	{
		if (s1[0] == s2[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strpbrk(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while (s1[i])
	{
		if(ft_comp(&s1[i], s2))
			return ((char*)&s1[i]);
		i++;
	}
	return (0);
}
