/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcedric <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 07:45:37 by bcedric           #+#    #+#             */
/*   Updated: 2019/01/18 07:45:38 by bcedric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

List new_list(void)
{
	return (NULL);
}

/* ------------------------------------- */

int is_empty(List li)
{
	if (li == NULL)
		return (0);
	return (1);
}

/* ------------------------------------- */

int list_size(List li)
{
	int size;

	size = 0;

	if (!(is_empty(li)))
		return (size);
	while (li != NULL)
	{
		++size;
		li = li->next;
	}
	return (size);
}

/* ------------------------------------- */

void print_list(List li)
{
	int i;

	if (!(is_empty(li)))
	{
		ft_putendl("Rien a afficher");
		return ;
	}
	while (li != NULL)
	{
		i = 0;
		while(li->name[i] != '\0')
		{
			ft_putchar(li->name[i]);
			i++;
		}
		li = li->next;
		ft_putendl("");
	}
}

/* ------------------------------------- */

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

/* ------------------------------------- */

int swap_list(List li, int i, int j)
{
	ListElement *temp;
	ListElement *temp2;
	char *temp3;
	int a;
	int b;

	a = 0;
	b = 0;
	temp = li;
	temp2 = li;
	if (i > list_size(li) || j > list_size(li) || i < 0 ||
		j < 0 || i == j)
		return (0);
	while (a < i - 1)
	{
		if (temp->next == NULL)
			break ;
		temp = temp->next;
		a++;
	}
	while (b < j - 1)
	{
		if (temp->next == NULL)
			break ;
		temp2 = temp2->next;
		b++;
	}
	temp3 = temp->name;
	temp->name = temp2->name;
	temp2->name = temp3;
	return (1);
}

/* --------------------------------------- */
	
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


