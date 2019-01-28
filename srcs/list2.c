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

List push_back(List li, char *s, char *full_path, struct stat file)
{
	ListElement *element;
	ListElement	*temp;
	struct passwd *pw;
	struct group *gid;

	//printf("MAILLON %s\n", s);
	//sleep(10);
	if (!(element = malloc(sizeof(*element))))
	{
		exit(EXIT_FAILURE);
	}
	element->name = ft_strjoin("",s);
	element->fileinfo = file;
	element->full_path = full_path;
	gid = getgrgid(element->fileinfo.st_gid);
			element->group = gid->gr_name;
	if(!(pw = getpwuid(element->fileinfo.st_uid)))
		element->login = ft_itoa(element->fileinfo.st_uid);
	else
	{
		element->login = ft_strjoin("",pw->pw_name);
	}
	element->next = NULL;
	if(!(is_empty(li)))
		return (element);
	temp = li;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = element;
	return li;
}


List push_front(List li, char *s, char *full_path, struct stat file)
{
	ListElement *element;

	if (!(element = malloc(sizeof(*element))))
	{
		exit(EXIT_FAILURE);
	}
	element->name = s;
	element->fileinfo = file;
	element->full_path = full_path;

	if(!(is_empty(li)))
		element->next = NULL;
	else
		element->next = li;
	return (element);
}


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