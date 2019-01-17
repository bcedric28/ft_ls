/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcedric <bcedric@student.19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 13:21:28 by bcedric           #+#    #+#             */
/*   Updated: 2018/10/10 14:16:06 by bcedric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *copy;

	copy = malloc(sizeof(*copy));
	if (copy == NULL)
		return (NULL);
	if (content == NULL || content_size == 0)
	{
		copy->content = NULL;
		copy->content_size = 0;
	}
	else
	{
		copy->content = malloc(content_size);
		if (copy->content == NULL)
		{
			free(copy);
			return (NULL);
		}
		ft_memcpy(copy->content, content, content_size);
		copy->content_size = content_size;
	}
	copy->next = NULL;
	return (copy);
}
