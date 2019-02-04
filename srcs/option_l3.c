/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_l3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcedric <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 10:00:06 by bcedric           #+#    #+#             */
/*   Updated: 2019/01/26 10:00:07 by bcedric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**File_date : fonction qui permet de recuperer la date de modifiction et de
**	l'afficher. Mais avant on verifie bien que la date n'est pas anterieur ou
**	posterieur a += 6 mois grace a la fonction file_date_years. Ensuite on
**	affiche le reste de la date avec le bon format.
*/

int 	total_block(List begin)
{
	int block;
	int temp;

	block = 0;
	temp = 0;
	while (begin != NULL)
	{
		temp = block;
		block = begin->fileinfo.st_blocks + temp;
		begin = begin->next;
	}
	return(block);
}

void	affichage_file_years(List li, int i)
{
	i = 19;
	while (i < 24)
	{
		ft_putchar(li->date[i]);
		i++;
	}
	ft_putstr(" ");
}

void	affichage_file_date(List li, int i)
{
	while (i < 16)
	{
		ft_putchar(li->date[i]);
		i++;
	}
	ft_putstr(" ");
}

int		check_6_months(List li, time_t now)
{
	if (now - li->fileinfo.st_mtime >= 15778800)
		return (1);
	if (now - li->fileinfo.st_mtime <= -15778800)
		return (1);
	return (0);
}

void 	file_date(List li)
{
	int 	i;
	time_t	now;

	i = 0;
	now = time(NULL);
	li->date = ctime(&li->fileinfo.st_mtime);
	while (li->date[i])
	{
		if (li->date[i] != '\t' && li->date[i] != ' ')
			i++;
		else
			break;
	}
	while (li->date[i] && i <= 10)
	{
		ft_putchar(li->date[i]);
		i++;
	}
	if (check_6_months(li, now))
		affichage_file_years(li, i);
	else
		affichage_file_date(li, i);
}
