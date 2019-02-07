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

t_list_element *push_back(t_list_element *li, char *name, char *full_path, struct stat file, int parent)
{
	t_list_element *element;
	t_list_element	*begin;
	struct passwd *pw;
	struct group *gid;

	if (!(element = malloc(sizeof(*element))))
	{
		exit(EXIT_FAILURE);
	}
	element->name = ft_strdup(name);
	element->fileinfo = file;
	element->full_path = full_path;
	element->parent = parent;
	element->size = file.st_size;
	if (g_bit & OPTION_L)
	{
		gid = getgrgid(element->fileinfo.st_gid);
				element->group = gid->gr_name;
		if(!(pw = getpwuid(element->fileinfo.st_uid)))
			element->login = ft_itoa(element->fileinfo.st_uid);
		else
			element->login = ft_strdup(pw->pw_name);
	}
	element->next = NULL;
	if(!(is_empty(li)))
		return (element);

	begin = li;
	while (li->next != NULL)
		li = li->next;
	li->next = element;
	return (begin);
}



t_list_element *push_front(t_list_element *li, char *s, char *full_path, struct stat file)
{
	t_list_element *element;
	struct passwd *pw;
	struct group *gid;

	if (!(element = malloc(sizeof(*element))))
	{
		exit(EXIT_FAILURE);
	}
	element->name = s;
	element->fileinfo = file;
	element->full_path = full_path;
	if (g_bit & OPTION_L)
	{
		gid = getgrgid(element->fileinfo.st_gid);
				element->group = gid->gr_name;
		if(!(pw = getpwuid(element->fileinfo.st_uid)))
			element->login = ft_itoa(element->fileinfo.st_uid);
		else
			element->login = ft_strdup(pw->pw_name);
	}
	if(!(is_empty(li)))
		element->next = NULL;
	else
		element->next = li;
	return (element);
}


t_list_element *back_up(t_list_element *li)
{
	t_list_element *temp;
	t_list_element *before;

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


t_list_element *back_front(t_list_element *li)
{
	t_list_element *element;

	if (!(is_empty(li)))
		return (li);

	element = li->next;
	free_li_one(li);
	li = NULL;
	return (element);
}
