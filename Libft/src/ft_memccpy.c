/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcedric <bcedric@student.19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 23:06:45 by bcedric           #+#    #+#             */
/*   Updated: 2018/10/08 18:10:26 by bcedric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char			*dest0;
	const unsigned char		*src0;
	size_t					i;
	unsigned char			d;

	d = (unsigned char)c;
	dest0 = (unsigned char*)dest;
	src0 = (const unsigned char*)src;
	i = 0;
	while (i < n)
	{
		dest0[i] = src0[i];
		if (src0[i] == d)
		{
			return (&dest0[i + 1]);
		}
		i++;
	}
	return (NULL);
}
