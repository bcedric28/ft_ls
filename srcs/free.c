/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcedric <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 13:02:20 by bcedric           #+#    #+#             */
/*   Updated: 2019/01/30 13:02:22 by bcedric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	free_li(List li)
{
	ListElement *begin;
	while (li != NULL)
	{
		begin = li->next;
		free(li->name);
		li->name = NULL;
		free(li->full_path);
		li->full_path = NULL;
		if (g_bit & OPTION_l)
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


void	free_li_one(List li)
{
	free(li->name);
	li->name = NULL;
	// 	free(li->full_path);
	li->full_path = NULL;
	if (g_bit & OPTION_l)
	{
		if (li->login)
		{
		 	free(li->login);
			li->login = NULL;
		}
	}
	li->next = NULL;
	// free(li);
	li = NULL;
}
