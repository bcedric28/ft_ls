/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcedric <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 17:21:42 by bcedric           #+#    #+#             */
/*   Updated: 2018/10/05 17:21:44 by bcedric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	needle_len;

	needle_len = ft_strlen(needle);
	if (needle_len == 0)
		return ((char*)haystack);
	if (*haystack == '\0')
		return (NULL);
	i = 0;
	while (haystack[i] && i < len)
	{
		if ((i + needle_len) > len)
			return (NULL);
		if (ft_strncmp(&haystack[i], needle, needle_len) == 0)
			return ((char*)&haystack[i]);
		i++;
	}
	return (NULL);
}
