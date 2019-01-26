/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_option.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcedric <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 11:56:08 by bcedric           #+#    #+#             */
/*   Updated: 2019/01/25 11:56:10 by bcedric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**Check_option: permet de boucler sur les arguments rentree en paramettre
**	par l'utilisateur. Si le paramettre commence par un "-" je verifie si c'est
**	une option valide. Si c'est le cas j'allume le bit correspondant grace a la
**	fonction "option" si ce n'est pas un arguments valide je retourne une
**	erreur.
**	Dans le cas ou un argument ne commence pas par "-" je le considere comme
**	un dossier j'appelle donc checker.
*/

void	option(char *s1)
{
	s1++;
	if (*s1 == '-')
	{
		g_bit |= OPTION_STOP;
		return ;
	}
	if (*s1 == '\0')
	{
		g_bit |= OPTION_END;
		return ;
	}
	while(*s1)
	{
		if (*s1 == 'a')
			g_bit |= OPTION_a;
		else if (*s1 == 'l')
			g_bit |= OPTION_l;
		else if (*s1 == 'r')
			g_bit |= OPTION_r;
		else if (*s1 == 'R')
			g_bit |= OPTION_R;
		else if(*s1 == 't')
			g_bit |= OPTION_t;
		else
		{
			ft_error(*s1, 3);
			break ;
		}
		s1++;
	}
}

int		check_option(char **s1, int argc)
{
	int i;

	i = 1;
	while (i < argc && !(g_bit & OPTION_STOP) && !(g_bit & OPTION_END))
	{
			if (s1[i][0] == '-')
				option(s1[i]);
			else
				break ;
		i++;
	}
	if (g_bit & OPTION_END)
		return (i - 1);
	else
		return (i);
}
