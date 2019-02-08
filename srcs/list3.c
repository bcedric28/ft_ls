/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcedric <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 07:26:01 by bcedric           #+#    #+#             */
/*   Updated: 2019/02/07 19:16:13 by bcedric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**back_list: enleve un maillon apres un maillon particulier. De cette facons
**je peux enlever un maillon n'importe ou dans dans ma liste.
**je sauvegarde le next, je free, et refait pointer le maillon d'avant sur
**le prochain. Je retourne un pointeur sur le debut de ma liste.
**printf_and_free_only_file permet comme sont nom l'indic d'afficher
**les fichers et de les supprimer
*/

t_elem	*back_list(t_elem *li, t_elem *begin)
{
	t_elem *temp;
	t_elem *membef;
	t_elem *memaft;

	temp = begin;
	if (begin->name == li->name)
	{
		return (back_front(li));
	}
	while (begin->next->name != li->name)
		begin = begin->next;
	membef = begin;
	memaft = li->next;
	free_li_one(li);
	li = NULL;
	membef->next = memaft;
	return (temp);
}

t_elem	*print_and_free_only_file(t_elem *li)
{
	t_elem *li_next;
	t_elem *begin;

	begin = li;
	while (li != NULL)
	{
		li_next = li->next;
		if (S_ISREG(li->fileinfo.st_mode))
		{
			if (g_bit & OPTION_L)
			{
				li->next = NULL;
				affichage(li, "", 0);
				li->next = li_next;
			}
			else
				ft_putendl(li->name);
			begin = back_list(li, begin);
		}
		li = li_next;
	}
	return (begin);
}
