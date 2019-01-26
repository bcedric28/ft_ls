/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_l2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcedric <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 07:06:47 by bcedric           #+#    #+#             */
/*   Updated: 2019/01/26 07:06:49 by bcedric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**(Seulement si le -l est actif)
**Ce fichier contient plusieur fonctions qui me permets toutes d'afficher
**comme -l. Je procede generalement par sauvegarder la chaine la plus
**longue qui me permettra, quand je ferais appel au fonction affichage
**en questions, de bien tout mettre en colonnes.
**Certaines fonction vont remplir ma liste chainer des elements manquant.
*/

void	main_l(List li, List begin)
{
		affichage_file_perm(li);
		count_file_link(li, begin);
		login_name(li, begin);
		group_name(li, begin);
		file_size(li, begin);
		file_date(li);
		print_name_list(li);
}

void	affichage_file_size(int max, List li)
{
	int i;
	int j;

	j = 2;
	i = number_of_digit(li->fileinfo.st_size);
	while (j > 0)
	{
		ft_putstr(" ");
		j--;
	}
	while (i < max)
	{
		ft_putstr(" ");
		i++;
	}
	ft_putstr(ft_itoa(li->fileinfo.st_size));
}

void 	file_size(List li, List begin)
{
	int max;

	max = 0;
	while(begin != NULL)
	{
		if (begin->fileinfo.st_size > max)
			max = begin->fileinfo.st_size;
		begin = begin->next;
	}
	max = number_of_digit(max);
	affichage_file_size(max, li);
}

void	affichage_file_group(int max, List li)
{
	int i;
	int j;

	j = 2;
	i = ft_strlen(li->group);
	while (j > 0)
	{
		ft_putstr(" ");
		j--;
	}
	while (i < max)
	{
		ft_putstr(" ");
		i++;
	}
	ft_putstr(li->group);
}

void	group_name(List li, List begin)
{
	struct group *gid;
	ListElement *temp;
	int max;
	int i;

	max = 0;
	temp = begin;
	while (begin != NULL)
	{
		gid = getgrgid(li->fileinfo.st_gid);
		li->group = gid->gr_name;
		begin = begin->next;
	}
	begin = temp;
	while (begin != NULL)
	{
		i = ft_strlen(li->group);
		if (i > max)
			max = i;
		begin = begin->next;
	}
	affichage_file_group(max, li);
}
