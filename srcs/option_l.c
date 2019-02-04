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

List	login_name(List begin)
{
	ListElement *temp;
	int max_login;
	int max_group;
	int size_max;
	int i;
	int j;
	int k;


	max_login = 0;
	max_group = 0;
	size_max = 0;
	temp = begin;
	while (begin != NULL)  // Optimiser
	{
		j = ft_strlen(begin->group);
		i = ft_strlen(begin->login);
		k = number_of_digit(begin->size);
		if (i > max_login)
			max_login = i;
		if (j > max_group)
			max_group = j;
		if (k > size_max)
			size_max = k;
		begin = begin->next;
	}
	begin = temp;
	while (begin != NULL)
	{
		begin->max_login = max_login;
		begin->max_group = max_group;
		begin->size_max = size_max;
		begin = begin->next;
	}
	begin = temp;
	return (begin);
}

void	affichage_file_link(int max, List li)
{
	int i;
	int j;
	char *result;

	j = 2;
	i = number_of_digit(li->fileinfo.st_nlink);
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
	result = ft_itoa(li->fileinfo.st_nlink);
	ft_putstr(result);
	free(result);
}

void 	count_file_link(List li, List begin)
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
	affichage_file_link(max, li);
}
