/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_l.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcedric <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 07:03:21 by bcedric           #+#    #+#             */
/*   Updated: 2019/02/07 21:05:03 by bcedric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**Ce fichier est le coeur du -l.
**La fonction main_l va s'occuper de faire les liens et d'appeler
**les differente fonction dans un ordre precis afin d'afficher les donner
**de facon correct.
**data_noodle me permet de remplir tout les maillons de la liste avec
**le max de login de group et de size.
*/

int			total_block(t_elem *begin)
{
	int block;
	int temp;

	block = 0;
	temp = 0;
	while (begin != NULL)
	{
		temp = block;
		block += begin->fileinfo.st_blocks;
		begin = begin->next;
	}
	return (block);
}

int			number_of_digit(int max)
{
	int i;

	i = 0;
	if (max == 0)
		i++;
	while (max > 0)
	{
		max = max / 10;
		i++;
	}
	return (i);
}

void		fill_noodle_data(t_elem *begin, int *tab)
{
	int login;
	int group;
	int size;

	while (begin != NULL)
	{
		group = ft_strlen(begin->group);
		login = ft_strlen(begin->login);
		size = number_of_digit(begin->size);
		if (login > tab[0])
			tab[0] = login;
		if (group > tab[1])
			tab[1] = group;
		if (size > tab[2])
			tab[2] = size;
		begin = begin->next;
	}
}

t_elem		*data_noodle(t_elem *begin)
{
	t_elem		*temp;
	int			tab[3];

	tab[0] = 0;
	tab[1] = 0;
	tab[2] = 0;
	temp = begin;
	fill_noodle_data(begin, tab);
	while (begin != NULL)
	{
		begin->max_login = tab[0];
		begin->max_group = tab[1];
		begin->size_max = tab[2];
		begin = begin->next;
	}
	begin = temp;
	return (begin);
}

void		main_l(t_elem *li, t_elem *begin, int *total)
{
	kernel_of_file_perm(li);
	affichage_xattr_acl(li, total);
	count_file_link(li, begin, total);
	affichage_file_login(li);
	affichage_file_group(li);
	if (!(S_ISBLK(li->fileinfo.st_mode)) &&
			(!(S_ISCHR(li->fileinfo.st_mode))))
		affichage_file_size(li, total);
	else
	{
		affichage_major(li, total[0]);
		affichage_minor(li, total[1]);
	}
	file_date(li);
	print_name_list(li);
}
