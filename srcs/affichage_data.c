/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcedric <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:21:40 by bcedric           #+#    #+#             */
/*   Updated: 2019/02/07 16:33:32 by bcedric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**Ce fichier contient une partie des differents fonction
**qui permettent d'afficher en colonne les differents data
**fichier par fichier.
*/

void	affichage_file_size(t_elem *li, int *total)
{
	int		i;
	int		digit;
	char	*result;

	digit = (number_of_digit(li->fileinfo.st_size) - 1);
	if (total[1] == -1)
	{
		while (++digit < li->size_max + 2)
			ft_putstr(" ");
		result = ft_itoa(li->fileinfo.st_size);
		ft_putstr(result);
		free(result);
	}
	else
	{
		i = (number_of_digit(major(li->fileinfo.st_rdev))) - 1;
		while (++i < total[0] + 4)
			ft_putstr(" ");
		while (++digit < (li->size_max > total[1] ?
					li->size_max : total[1] + 1))
			ft_putstr(" ");
		result = ft_itoa(li->fileinfo.st_size);
		ft_putstr(result);
		free(result);
	}
}

void	affichage_file_group(t_elem *li)
{
	int	i;

	i = ft_strlen(li->group);
	ft_putstr(li->group);
	while (i < li->max_group)
	{
		ft_putstr(" ");
		i++;
	}
}

void	affichage_file_login(t_elem *li)
{
	int	i;

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

void	affichage_file_link(int max, t_elem *li, int *total)
{
	int		i;
	int		j;
	char	*result;

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

void	count_file_link(t_elem *li, t_elem *begin, int *total)
{
	int	max;

	max = 0;
	while (begin != NULL)
	{
		if (begin->fileinfo.st_nlink > max)
			max = begin->fileinfo.st_nlink;
		begin = begin->next;
	}
	max = number_of_digit(max);
	affichage_file_link(max, li, total);
}
