/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcedric <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 14:18:06 by bcedric           #+#    #+#             */
/*   Updated: 2018/10/05 14:18:08 by bcedric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	chaine1;
	size_t	chaine2;

	chaine1 = ft_strlen(dst);
	chaine2 = ft_strlen(src);
	i = 0;
	if (size <= chaine1)
		return (chaine2 + size);
	while (chaine1 + i < size - 1)
	{
		dst[chaine1 + i] = src[i];
		i++;
	}
	dst[chaine1 + i] = '\0';
	return (chaine1 + chaine2);
}
