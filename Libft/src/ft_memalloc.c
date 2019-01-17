/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcedric <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 13:00:45 by bcedric           #+#    #+#             */
/*   Updated: 2018/10/08 18:06:57 by bcedric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*copy;

	copy = NULL;
	copy = malloc(size);
	if (copy == NULL)
		return (NULL);
	return (ft_memset(copy, 0, size));
}
