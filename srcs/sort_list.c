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

/*
**sort_argv : Fonction qui trie le tableau de paramettre rentre par le users
**	-Trie ascci.
**
**check_sort_list_ascci : Fonction qui trie la liste chainer
**	-Trie ascii.
**	Apres le tri je verifie si l' option -t est activer si oui je fais
**	appel la fonction check_sort_list_time puis je verifie si l'option
**	-r est actver si oui j'appelle check_sort_list_reverse
**
**check_sort_list_reverse : Fonction qui trie la liste chainer
**	-Trie inverse de l'ordre ascii
**	Puisque ma liste chainer est deja trier soite de facons ascii soit
**	par date. Je m'occuper juste de reverse la liste. Pour cela
**	je procede en creant une nouvelle liste. Je vais me mettre a la fin
**	de ma liste de base puis faire appelle a ma fonction push_front(list2.c)
**	je free en fesant appelle a back_front(list2.c)
**
**check_sort_list_time : Fonction qui tri la liste chainer
**	-Trie par date de modification
**	Je compare les date des deux maillons, je swap si necessaire.
**	Je procede par bubble sort.
**
**Chaque fonction de list renvoie un pointeur sur le debut de ma liste
**ou de ma nouvelle liste.
*/

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
	char *temp[2];
	struct stat file;
	ListElement *j;

	j = li;
	while (li->next != NULL)
	{
		if (li->fileinfo.st_mtime < li->next->fileinfo.st_mtime)
		{
			temp[0] = li->name;
			file = li->fileinfo;
			temp[1] = li->full_path;
			li->name = li->next->name;
			li->fileinfo = li->next->fileinfo;
			li->full_path = li->next->full_path;
			li->next->name = temp[0];
			li->next->fileinfo = file;
			li->next->full_path = temp[1];
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
			new_ord = push_front(new_ord, li->name, li->full_path, li->fileinfo);
			li = back_front(li);
		}
		return(new_ord);
}

List check_option_sort(List li, List j)
{
	int i;
	int k;

	i = 0;
	k = 0;
	if(g_bit & OPTION_t)
	{
		k = 1;
		li = check_sort_list_time(j);
	}
	if (g_bit & OPTION_r)
	{
		i = 1;
		li = check_sort_list_reverse(j);
	}
	if (k == 0 && i == 0)
		return (j);
	return (li);
}

List check_sort_list_ascci(List li)
{
	char *temp[2];
	struct stat file;
	char *temp_log;
	char *temp_group;
	ListElement *begin;
	ListElement *temp_next;

	begin = li;
	while (li->next != NULL)
	{
		if (is_hide(li) && (!(g_bit & OPTION_a))) //si le nom du fichier/dossier commence par un "." ET aue -a est pas activé
		{
			temp_next = li->next;
			begin = back_list(li, begin);
			li = temp_next;
		}
		else
		{
			if (ft_strcmp(li->name, li->next->name) > 0)
			{
				temp[0] = li->name;
				temp_log = li->login;
				temp_group = li->group;
				file = li->fileinfo;
				temp[1] = li->full_path;
				li->group = li->next->group;
				li->login = li->next->login;
				li->name = li->next->name;
				li->fileinfo = li->next->fileinfo;
				li->full_path = li->next->full_path;
				li->next->name = temp[0];
				li->next->fileinfo = file;
				li->next->full_path = temp[1];
				li->next->group = temp_group;
				li->next->login = temp_log;
				li = begin;
			}
			else
				li = li->next;
		}
	}
	li = check_option_sort(li, begin);
	return (li);
}
