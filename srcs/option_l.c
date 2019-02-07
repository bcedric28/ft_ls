/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_l.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcedric <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 07:03:21 by bcedric           #+#    #+#             */
/*   Updated: 2019/01/26 07:03:23 by bcedric          ###   ########.fr       */
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

int	number_of_digit(int max)
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

void	affichage_file_login(List li)
{
	int i;

	i = 0;
	ft_putstr(" ");
	i = ft_strlen(li->login);
	ft_putstr(li->login);
	while (i < li->max_login + 2)
	{
		ft_putstr(" ");
		i++;
	}
}

void 	fill_noodle(List begin, int *tab)
{
	int login;
	int group;
	int size;

	while (begin != NULL)  // Optimiser
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

List	login_name(List begin)
{
	ListElement *temp;
	int tab[3];


	tab[0] = 0;
	tab[1] = 0;
	tab[2] = 0;
	temp = begin;
	fill_noodle(begin, tab);
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

void	affichage_file_link(int max, List li, int *total)
{
	int i;
	int j;
	char *result;

	if (total[2] == 0)
		j = 3;
	else
		j = 2;
	i = (number_of_digit(li->fileinfo.st_nlink)) - 1;
	while (--j > 0)
		ft_putstr(" ");
	while (++i < max)
		ft_putstr(" ");
	result = ft_itoa(li->fileinfo.st_nlink);
	ft_putstr(result);
	free(result);
}

void 	count_file_link(List li, List begin, int *total)
{
	int max;

	max = 0;
	while(begin != NULL)
	{
		if (begin->fileinfo.st_nlink > max)
			max = begin->fileinfo.st_nlink;
		begin = begin->next;
	}
	max = number_of_digit(max);
	affichage_file_link(max, li, total);
}
