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

void	affichage_file_login(int max, List li)
{
	int i;

	i = ft_strlen(li->login);
	ft_putstr(" ");
	while (i < max)
	{
		ft_putstr(" ");
		i++;
	}
	ft_putstr(li->login);	
}

void	login_name(List li, List begin)
{
	struct passwd *pw;
	ListElement *temp;
	int max;
	int i;

	max = 0;
	temp = begin;
	while (begin != NULL)
	{
		pw = getpwuid(li->fileinfo.st_uid);
		li->login = pw->pw_name;
		begin = begin->next;
	}
	begin = temp;
	while (begin != NULL)
	{
		i = ft_strlen(li->login);
		if (i > max)
			max = i;
		begin = begin->next;
	}
	affichage_file_login(max, li);	
}


void	affichage_file_link(int max, List li)
{
	int i;
	int j;

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
	ft_putstr(ft_itoa(li->fileinfo.st_nlink));
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