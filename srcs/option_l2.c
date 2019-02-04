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
		affichage_file_login(li);
		affichage_file_group(li);
		if (!(S_ISBLK(li->fileinfo.st_mode)) &&
			(!(S_ISCHR(li->fileinfo.st_mode))))
			affichage_file_size(li);
		else
			file_minor_and_major(li, begin);
		file_date(li);
		print_name_list(li);
}

void	affichage_minor(List li, int min)
{
	int i;
	char *result;

	i = number_of_digit(minor(li->fileinfo.st_rdev));
	ft_putstr(" ");
	while (i < min)
	{
		ft_putstr(" ");
		i++;
	}
	result = ft_itoa(minor(li->fileinfo.st_rdev));
	ft_putstr(result);
	free(result);
}

void	affichage_major(List li, int max)
{
	int i;
	char *result;

	if (!(major(li->fileinfo.st_rdev)))
	{
		i = 0;
		while (i < max + 1)
		{
			ft_putstr(" ");
			i++;
		}
		ft_putstr("0,");
		return ;
	}
	else
	{
		i = number_of_digit(major(li->fileinfo.st_rdev));
		while (i < max + 2)
		{
			ft_putstr(" ");
			i++;
		}
		result = ft_itoa(major(li->fileinfo.st_rdev));
		ft_putstr(result);
		ft_putstr(",");
		free(result);
	}
}

void file_minor_and_major(List li, List begin)
{
	int max;
	int min;
	ListElement *temp;

	min = 0;
	max = 0;
	temp = begin;
	while (begin != NULL)
	{
		if (number_of_digit(major(begin->fileinfo.st_rdev)) > max)
			max = number_of_digit(major(begin->fileinfo.st_rdev));
		begin = begin->next;
	}
	begin = temp;
	while (begin != NULL)
	{
		if (number_of_digit(minor(begin->fileinfo.st_rdev)) > min)
			min = number_of_digit(minor(begin->fileinfo.st_rdev));
		begin = begin->next;
	}
	affichage_major(li, max);
	affichage_minor(li, min);
}

void	affichage_file_size(List li)
{
	int i;
	char *result;

	i = number_of_digit(li->fileinfo.st_size);
	while (i < li->size_max + 2)
	{
		ft_putstr(" ");
		i++;
	}
	result = ft_itoa(li->fileinfo.st_size);
	ft_putstr(result);
	free(result);
}


void	affichage_file_group(List li)
{
	int i;

	i = ft_strlen(li->group);
	ft_putstr(li->group);
	while(i < li->max_group)
	{
		ft_putstr(" ");
		i++;
	}
	//ft_putstr(li->group); //Double group !
}

