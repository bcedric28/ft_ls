/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcedric <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 07:25:57 by bcedric           #+#    #+#             */
/*   Updated: 2019/02/07 16:54:35 by bcedric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**push_front : Permet de rajouter un maillon tout devant la liste.
**	je cree d'abord un maillon en lui allouant le taille necessaire
**	puis je le remplis et l'incorpore dans ma liste.
**
**push_back : Pareil que push_front sauf que je le mets le maillon a
**	l'arriere de ma liste.
**
**back_up : Permet de supprimer un maillon en fin de la liste
**
**back_front : Permet de supprimer un maillon en tete de la liste
*/

t_elem	*new_elem(char *name, char *f_path, struct stat f, int parent)
{
	t_elem	*element;

	if (!(element = malloc(sizeof(*element))))
		exit(EXIT_FAILURE);
	element->name = ft_strdup(name);
	element->fileinfo = f;
	element->full_path = f_path;
	element->parent = parent;
	element->size = f.st_size;
	return (element);
}

t_elem	*push_back(t_elem *li, t_elem *new_element)
{
	t_elem			*begin;
	struct passwd	*pw;
	struct group	*gid;

	if (g_bit & OPTION_L)
	{
		gid = getgrgid(new_element->fileinfo.st_gid);
		new_element->group = gid->gr_name;
		if (!(pw = getpwuid(new_element->fileinfo.st_uid)))
			new_element->login = ft_itoa(new_element->fileinfo.st_uid);
		else
			new_element->login = ft_strdup(pw->pw_name);
	}
	new_element->next = NULL;
	if (!(is_empty(li)))
		return (new_element);
	begin = li;
	while (li->next != NULL)
		li = li->next;
	li->next = new_element;
	return (begin);
}

t_elem	*push_front(t_elem *li, char *name, char *f_path, struct stat f)
{
	t_elem			*element;
	struct passwd	*pw;
	struct group	*gid;

	if (!(element = malloc(sizeof(*element))))
		exit(EXIT_FAILURE);
	element->name = name;
	element->fileinfo = f;
	element->full_path = f_path;
	element->size = f.st_size;
	if (g_bit & OPTION_L)
	{
		gid = getgrgid(element->fileinfo.st_gid);
		element->group = gid->gr_name;
		if (!(pw = getpwuid(element->fileinfo.st_uid)))
			element->login = ft_itoa(element->fileinfo.st_uid);
		else
			element->login = ft_strdup(pw->pw_name);
	}
	if (!(is_empty(li)))
		element->next = NULL;
	else
		element->next = li;
	return (element);
}

t_elem	*back_up(t_elem *li)
{
	t_elem *temp;
	t_elem *before;

	before = li;
	temp = li;
	if (!(is_empty(li)))
		return (new_list());
	if (li->next == NULL)
	{
		free(li);
		li = NULL;
		return (new_list());
	}
	while (temp->next != NULL)
	{
		before = temp;
		temp = temp->next;
	}
	before->next = NULL;
	free(temp);
	temp = NULL;
	return (li);
}

t_elem	*back_front(t_elem *li)
{
	t_elem *element;

	if (!(is_empty(li)))
		return (li);
	element = li->next;
	free_li_one(li);
	li = NULL;
	return (element);
}
