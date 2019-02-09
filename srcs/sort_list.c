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

t_elem		*while_li(t_elem *li, t_elem *begin, int size, t_elem *te_next)
{
	while (--size > 0)
	{
		li = begin;
		while (li->next != NULL)
		{
			if ((li->parent == 0) && is_hide(li) && (!(g_bit & OPTION_A)))
			{
				te_next = li->next;
				begin = back_list(li, begin);
				li = te_next;
			}
			else
			{
				if (ft_strcmp(li->name, li->next->name) > 0)
					swap_value(li, li->next);
				li = li->next;
			}
		}
	}
	if ((li->parent == 0) && is_hide(li) && (!(g_bit & OPTION_A)))
	{
		begin = back_list(li, begin);
		li = begin;
	}
	return (begin);
}

t_elem		*check_sort_list_ascci(t_elem *li)
{
	t_elem		*begin;
	t_elem		*temp_next;
	int			size;

	temp_next = NULL;
	size = (list_size(li) + 1);
	begin = li;
	begin = while_li(li, begin, size, temp_next);
	li = check_option_sort(li, begin);
	return (li);
}
