/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcedric <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 20:07:48 by bcedric           #+#    #+#             */
/*   Updated: 2018/10/06 20:07:51 by bcedric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*src;

	if (s == NULL || f == NULL)
		return (NULL);
	src = ft_strnew(ft_strlen(s));
	if (src == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		src[i] = f(i, s[i]);
		i++;
	}
	return (src);
}
