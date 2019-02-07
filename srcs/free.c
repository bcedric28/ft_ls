/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcedric <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 13:02:20 by bcedric           #+#    #+#             */
/*   Updated: 2019/02/07 16:49:23 by bcedric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**free_li free tout une liste
**
**free_li_one ne free que un seul maillon de la liste
*/

void	free_li(t_element *li)
{
	t_element *begin;

	while (li != NULL)
	{
		begin = li->next;
		free(li->name);
		li->name = NULL;
		if (li->full_path && (li->parent == 0))
			free(li->full_path);
		if (g_bit & OPTION_L)
		{
			if (li->login)
			{
				free(li->login);
				li->login = NULL;
			}
		}
		li->next = NULL;
		free(li);
		li = NULL;
		li = begin;
	}
}

void	free_li_one(t_element *li)
{
	free(li->name);
	li->name = NULL;
	if (li->full_path && (li->parent == 0))
		free(li->full_path);
	if (g_bit & OPTION_L)
	{
		if (li->login)
		{
			free(li->login);
			li->login = NULL;
		}
	}
	li->next = NULL;
	free(li);
	li = NULL;
}
