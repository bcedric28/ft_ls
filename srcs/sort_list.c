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

void		sort_argv(int i, int argc, char **tab)
{
	char	*temp;
	int		j;

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

t_elem	*check_sort_list_time(t_elem *li)
{
	char		*temp[2];
	struct stat	file;
	t_elem	*j;
	int			size;

	size = list_size(li);
	j = li;
	while (size > 0)
	{
		li = j;
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
			}
			li = li->next;
		}
		size--;
	}
	li = j;
	return (li);
}

t_elem	*check_sort_list_reverse(t_elem *li)
{
	t_elem	*new_ord;

	new_ord = new_list();
	while (li != NULL)
	{
		new_ord = push_front(new_ord, li->name, li->full_path, li->fileinfo);
		li = li->next;
	}
	free_li(li);
	return (new_ord);
}

t_elem	*check_option_sort(t_elem *li, t_elem *j)
{
	int i;
	int k;

	i = 0;
	k = 0;
	if (g_bit & OPTION_T)
	{
		k = 1;
		li = check_sort_list_time(j);
	}
	if (g_bit & OPTION_RR)
	{
		i = 1;
		li = check_sort_list_reverse(j);
	}
	if (k == 0 && i == 0)
		return (j);
	return (li);
}

/*
**t_elem *invert_two_links(t_elem *li, t_elem *previous, t_elem *begin) //a vérifier
**{
**	t_elem *suivant;
**	t_elem *actuel;
**	t_elem *debut;
**
**	if (li->next == begin->next) // 0->1->2->3->4 (li = 0)
**	{
**		suivant = li->next->next; //2
**		debut = begin;
**		actuel = li->next;
**		actuel->next = debut;
**		debut->next = suivant;
**		return (actuel); //1->0->2->3->4
**	}
**	else //inverser 2 maillons quelconque
**	{  // 0->1->2->3->4 (li = 2)
**		suivant = li->next; //On défini le maillon suivant (3)
**		previous->next = suivant; //le précedent pointe sur le suivant (1->3)
**		li->next = suivant->next; //l'actuel pointe sur le suivant du suivant (2->4)
**		suivant->next = li; //le suivant pointe sur l'actuel (3->2)
**		//0->1->3->2->4
**		return (begin);
**	}
**}
*/

t_elem	*check_sort_list_ascci(t_elem *li)
{
	char		*temp[2];
	struct stat	file;
	char		*temp_log;
	char		*temp_group;
	t_elem	*begin;
	int			size;
	t_elem	*temp_next;

	size = list_size(li);
	begin = li;
	while (size > 0)
	{
		li = begin;
		while (li->next != NULL)
		{
			if ((li->parent == 0) && is_hide(li) && (!(g_bit & OPTION_A)))
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
				}
				li = li->next;
			}
		}
		size--;
	}
	if ((li->parent == 0) && is_hide(li) && (!(g_bit & OPTION_A)))
	{
		begin = back_list(li, begin);
		li = begin;
	}
	li = check_option_sort(li, begin);
	return (li);
}
