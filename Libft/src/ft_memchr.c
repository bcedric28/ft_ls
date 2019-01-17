/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcedric <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 14:23:34 by bcedric           #+#    #+#             */
/*   Updated: 2018/10/08 18:11:26 by bcedric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char		*src;
	size_t					i;
	unsigned char			d;

	src = (const unsigned char*)s;
	i = 0;
	d = (unsigned char)c;
	while (i < n)
	{
		if (src[i] == d)
		{
			return ((char*)&src[i]);
		}
		i++;
	}
	return (NULL);
}
