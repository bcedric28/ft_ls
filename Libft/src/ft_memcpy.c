/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcedric <bcedric@student.19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 22:08:26 by bcedric           #+#    #+#             */
/*   Updated: 2018/10/03 23:33:48 by bcedric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*dest0;
	const char	*src0;

	dest0 = (char*)dest;
	src0 = (const char*)src;
	if (n == 0)
		return (dest0);
	i = 0;
	while (i < n)
	{
		dest0[i] = src0[i];
		i++;
	}
	return (dest0);
}
