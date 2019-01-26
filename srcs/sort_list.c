/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcedric <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 11:52:45 by bcedric           #+#    #+#             */
/*   Updated: 2019/01/25 11:52:48 by bcedric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void sort_argv(int i, int argc, char **tab)
{
	char *temp;
	int j;

	j = i;
	while (i < argc && tab[i + 1] != '\0')
	{
		if (ft_strcmp(tab[i], tab[i + 1]) > 0)
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			i = j;
		}
		else
			i++;
	}
}

List check_sort_list_time(List li)
{
	char *temp;
	struct stat file;
	ListElement *j;
	
	j = li;
	while (li->next != NULL)
	{
		if (li->fileinfo.st_mtime < li->next->fileinfo.st_mtime)
		{
			temp = li->name;
			file = li->fileinfo;
			li->name = li->next->name;
			li->fileinfo = li->next->fileinfo;
			li->next->name = temp;
			li->next->fileinfo = file;
			li = j;
		}
		else
			li = li->next;
	}
	li = j;
	return (li);
}

List check_sort_list_reverse(List li)
{
		List new_ord = new_list();
		while(li != NULL)
		{
			new_ord = push_front(new_ord, li->name, li->fileinfo);
			li = back_front(li);
		}
		return(new_ord);
}

List check_sort_list_ascci(List li)
{
	char *temp;
	struct stat file;
	ListElement *j;

	j = li;
	while (li->next != NULL)
	{
		if (ft_strcmp(li->name, li->next->name) > 0)
		{
			temp = li->name;
			file = li->fileinfo;
			li->name = li->next->name;
			li->fileinfo = li->next->fileinfo;
			li->next->name = temp;
			li->next->fileinfo = file;
			li = j;
		}
		else
			li = li->next;
	}
	li = j;
	if(g_bit & OPTION_t)
		li = check_sort_list_time(li);
	if (g_bit & OPTION_r)
		li = check_sort_list_reverse(li);
	return (li);
}