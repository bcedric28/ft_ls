/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcedric <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 07:34:01 by bcedric           #+#    #+#             */
/*   Updated: 2019/02/07 16:46:53 by bcedric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**ft_error: Fonction qui prend en paramettre un char c et un int
**	qui selon les situation dans mon code me permet de savoir
**	quel erreur je dois afficher.
**
**ft_error2: Fonction qui permet d'afficher une erreur quand le dossier
**	ou fichier n'existe pas.
**
**ft_error3: Fonction qui gere les Permission denied.
*/

void	ft_error3(char *s, t_elem *parent)
{
	int			i;
	static int	j = 0;

	i = -1;
	if (j++ != 0)
		ft_putendl("");
	if (parent->parent == 0)
	{
		while (s[++i])
			ft_putchar_fd(s[i], 0);
		ft_putendl_fd(":", 0);
		ft_putstr_fd("ft_ls: ", 2);
		while (s[i] != '/' && i >= 0)
			i--;
		while (s[++i])
			ft_putchar_fd(s[i], 2);
		ft_putendl_fd(": Permission denied", 2);
	}
	else
	{
		ft_putstr_fd("ft_ls: ", 2);
		ft_putstr_fd(parent->name, 2);
		ft_putendl_fd(": Permission denied", 2);
	}
}

void	ft_error2(char *s, int j)
{
	int i;

	i = 0;
	if (j == 0)
	{
		ft_putstr_fd("ft_ls: ", 2);
		while (s[i])
		{
			ft_putchar_fd(s[i], 2);
			i++;
		}
		ft_putendl_fd(": No such file or directory", 2);
	}
}

void	ft_error(char c, int i)
{
	if (i == 0)
		ft_putendl_fd("ft_ls: -: No such file or directory", 2);
	else if (i == 1)
	{
		ft_putendl_fd("ft_ls: fts_open: No such file or directory", 2);
		exit(EXIT_FAILURE);
	}
	else
	{
		ft_putstr_fd("ft_ls: illegal option -- ", 2);
		ft_putchar_fd(c, 2);
		ft_putendl_fd("", 2);
		ft_putstr_fd("usage: ls [-alrRt] [file ...]\n", 2);
		exit(EXIT_FAILURE);
	}
}
