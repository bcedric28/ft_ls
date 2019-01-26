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