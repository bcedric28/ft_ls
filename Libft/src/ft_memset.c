/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcedric <bcedric@student.19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 18:46:11 by bcedric           #+#    #+#             */
/*   Updated: 2018/10/03 23:33:52 by bcedric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	char			*str;
	unsigned char	d;

	d = (unsigned char)c;
	str = (char*)s;
	i = 0;
	while (i < n)
	{
		str[i] = d;
		i++;
	}
	return (str);
}
