/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcedric <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 19:21:59 by bcedric           #+#    #+#             */
/*   Updated: 2018/10/06 19:22:00 by bcedric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*src;

	if (s == NULL || f == NULL)
		return (NULL);
	src = ft_strnew(ft_strlen(s));
	if (src == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		src[i] = f(s[i]);
		i++;
	}
	return (src);
}
