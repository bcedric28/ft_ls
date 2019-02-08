/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_l2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcedric <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 07:06:47 by bcedric           #+#    #+#             */
/*   Updated: 2019/02/07 16:36:36 by bcedric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**Ce fichier me permet d'afficher si c'est un "C" ou un "B"
**les majors et les minors. J'enregistre le major le plus grand
**dans chaque maillons de ma liste. Je fais de meme pour le minor
**Je mets mes varibles min et max a -1. De facons a ce que quand
**j'ai un "B" ou "C" dans ma liste je peux facilement le savoir
**par la suite si total[0] || total[1] sont different de -1.
**Je pourrais donc plus tard determiner les espace nessecaire
**pour idententer tout mes fichier en colone.
*/

void	affichage_minor(t_elem *li, int min)
{
	int		i;
	char	*result;

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

void	affichage_major(t_elem *li, int max)
{
	int		i;
	char	*result;

	if (!(major(li->fileinfo.st_rdev)))
	{
		i = -1;
		while (++i < max + 1)
			ft_putstr(" ");
		ft_putstr("0,");
		return ;
	}
	else
	{
		i = (number_of_digit(major(li->fileinfo.st_rdev))) - 1;
		while (++i < max + 2)
			ft_putstr(" ");
		result = ft_itoa(major(li->fileinfo.st_rdev));
		ft_putstr(result);
		ft_putstr(",");
		free(result);
	}
}

void	file_minor_and_major(t_elem *begin, int *total)
{
	int max;
	int min;

	min = -1;
	max = -1;
	while (begin != NULL)
	{
		if ((S_ISBLK(begin->fileinfo.st_mode)) ||
			((S_ISCHR(begin->fileinfo.st_mode))))
		{
			if (number_of_digit(major(begin->fileinfo.st_rdev)) > max)
				max = number_of_digit(major(begin->fileinfo.st_rdev));
			if (number_of_digit(minor(begin->fileinfo.st_rdev)) > min)
				min = number_of_digit(minor(begin->fileinfo.st_rdev));
		}
		begin = begin->next;
	}
	total[0] = max;
	total[1] = min;
}
