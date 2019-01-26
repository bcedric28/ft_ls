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

List 	add_list(List li, List begin, char *s)
{
	ListElement *element;
	ListElement *temp;

	temp = li;
	if (!(element = malloc(sizeof(*element))))
	{
		exit(EXIT_FAILURE);
	}
	element->name = s;
//	element->fileinfo = file;
	element->next = li->next;
	li->next = element;
	return (begin);
}

/* ------------------------------------- */

List back_list(List li, List begin)
{
	ListElement *temp;
	ListElement *membef;
	ListElement *memaft;

	temp = begin;
	if (begin->name == li->name)
	{
		return (back_front(li));
	}
	while(begin->next->name != li->name)
		begin = begin->next;
	membef = begin;
	memaft = li->next;
	free(li);
	li = NULL;
	membef->next = memaft;
	return (temp);
}