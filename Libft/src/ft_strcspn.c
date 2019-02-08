/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcedric <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 18:17:37 by bcedric           #+#    #+#             */
/*   Updated: 2018/11/03 18:17:40 by bcedric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_comp(const char *s1, const char *s2)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (s2[i])
	{
		if (s1[j] == s2[i])
			return (0);
		i++;
	}
	return (1);
}

size_t			ft_strcspn(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		if (!(ft_comp(&s1[i], s2)))
			return (0);
		j++;
		i++;
	}
	return (j);
}
