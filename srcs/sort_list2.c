/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list2c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcedric <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 11:52:45 by bcedric           #+#    #+#             */
/*   Updated: 2019/01/25 11:52:48 by bcedric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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

t_elem		*check_sort_list_time(t_elem *li)
{
	t_elem		*begin;
	int			size;

	size = list_size(li);
	begin = li;
	while (size > 0)
	{
		li = begin;
		while (li->next != NULL)
		{
			if (li->fileinfo.st_mtime < li->next->fileinfo.st_mtime)
			{
				swap_value(li, li->next);
			}
			li = li->next;
		}
		size--;
	}
	li = begin;
	return (li);
}

t_elem		*check_sort_list_reverse(t_elem *li)
{
	t_elem	*new_ord;
	t_elem	*begin;

	begin = li;
	new_ord = new_list();
	while (li != NULL)
	{
		new_ord = push_front(new_ord, li->name, li->full_path, li->fileinfo);
		li = li->next;
	}
	free_li(begin);
	return (new_ord);
}

t_elem		*check_option_sort(t_elem *li, t_elem *j)
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

void		swap_value(t_elem *li, t_elem *li_next)
{
	char		*temp[2];
	struct stat	file;
	char		*temp_log;
	char		*temp_group;

	temp[0] = li->name;
	temp_log = li->login;
	temp_group = li->group;
	file = li->fileinfo;
	temp[1] = li->full_path;
	li->group = li_next->group;
	li->login = li_next->login;
	li->name = li_next->name;
	li->fileinfo = li_next->fileinfo;
	li->full_path = li_next->full_path;
	li_next->name = temp[0];
	li_next->fileinfo = file;
	li_next->full_path = temp[1];
	li_next->group = temp_group;
	li_next->login = temp_log;
}
