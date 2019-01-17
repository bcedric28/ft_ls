/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcedric <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 13:14:02 by bcedric           #+#    #+#             */
/*   Updated: 2018/10/07 13:14:03 by bcedric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*copy;
	size_t		j;

	if (s == NULL)
		return (NULL);
	copy = ft_strnew(len);
	if (copy == NULL)
		return (NULL);
	j = 0;
	while (j < len)
	{
		copy[j] = s[start];
		j++;
		start++;
	}
	return (copy);
}
