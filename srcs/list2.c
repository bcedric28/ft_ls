/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcedric <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 07:25:57 by bcedric           #+#    #+#             */
/*   Updated: 2019/01/26 07:25:58 by bcedric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

List push_back(List li, char *s, struct stat file)
{
	ListElement *element;
	ListElement	*temp;

	if (!(element = malloc(sizeof(*element))))
	{
		exit(EXIT_FAILURE);
	}
	element->name = s;
	element->fileinfo = file;

	element->next = NULL;
	if(!(is_empty(li)))
		return (element);
	temp = li;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = element;
	return li;
}

/* ------------------------------------- */

List push_front(List li, char *s, struct stat file)
{
	ListElement *element;

	if (!(element = malloc(sizeof(*element))))
	{
		exit(EXIT_FAILURE);
	}
	element->name = s;
	element->fileinfo = file;

	if(!(is_empty(li)))
		element->next = NULL;
	else
		element->next = li;
	return (element);
}

/* ------------------------------------- */

List back_up(List li)
{
	ListElement *temp;
	ListElement *before;

	before = li;
	temp = li;
	if (!(is_empty(li)))
		return (new_list());
	if (li->next ==  NULL)
	{
		free(li);
		li = NULL;
		return (new_list());
	}
	while(temp->next != NULL)
	{
		before = temp;
		temp = temp->next;
	}
	before->next = NULL;
	free(temp);
	temp = NULL;
	return li;
}

/* ------------------------------------- */

List back_front(List li)
{
	ListElement *element;

	if (!(is_empty(li)))
		return (li);

	element = li->next;
	free(li);
	li = NULL;
	return (element);
}