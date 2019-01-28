/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcedric <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 07:26:01 by bcedric           #+#    #+#             */
/*   Updated: 2019/01/26 07:26:03 by bcedric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**add_list : prend en parametre un pointeur pointant sur un maillon en
**	particulier. Ainsi cette focntion permet de rajouter un maillon juste
**	apres le maillon passer en arguments. Je procede de la meme facons
**	que les fonction "back_up et back_front". Ensuite je sauvegarde
**	le next et je fait pointer mon nouveau maillon sur le maillon suivant
**	Je retourne un poiteur sur le debut de la liste.
**
**back_list: enleve un maillon apres un maillon particulier. De cette facons
**	je peux enlever un maillon n'importe ou dans dans ma liste.
**	je sauvegarde le next, je free, et refait pointer le maillon d'avant sur
**	le prochain. Je retourne un pointeur sur le debut de ma liste.
*/

List 	add_list(List li, List begin, char *s)
{
	ListElement *element;
	ListElement *temp;
	struct stat fileinfo;

	lstat(s, &fileinfo);
	temp = li;
	if (!(element = malloc(sizeof(*element))))
	{
		exit(EXIT_FAILURE);
	}
	element->name = s;
	element->fileinfo = fileinfo;
	element->next = li->next;
	li->next = element;
	return (begin);
}


List 	back_list(List li, List begin)
{
	ListElement *temp;
	ListElement *membef;
	ListElement *memaft;

	temp = begin;
	if (begin->name == li->name)
	{
		return (back_front(li));
	}
	while (begin->next->name != li->name)
		begin = begin->next;
	membef = begin;
	memaft = li->next;
	free(li);
	li = NULL;
	membef->next = memaft;
	return (temp);
}

List	print_and_free_only_file(List li)
{
	ListElement *li_next;
	ListElement *begin;

	begin = li;
	while (li != NULL)
	{
		li_next = li->next;
		if(S_ISREG(li->fileinfo.st_mode))
		{
			if (g_bit & OPTION_l)
				main_l(li, begin);
			else
				ft_putendl(li->name);
			begin = back_list(li, begin);
		}
		li = li_next;
	}
	return begin;
}
