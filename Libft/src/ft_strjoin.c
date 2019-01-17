/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcedric <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 13:51:30 by bcedric           #+#    #+#             */
/*   Updated: 2018/10/07 13:51:31 by bcedric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		k;
	int		l;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	new = NULL;
	new = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (new == NULL)
		return (NULL);
	k = 0;
	while (s1[k])
	{
		new[k] = s1[k];
		k++;
	}
	l = 0;
	while (s2[l])
	{
		new[k] = s2[l];
		l++;
		k++;
	}
	return (new);
}
