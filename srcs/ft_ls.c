/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcedric <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 13:44:01 by bcedric           #+#    #+#             */
/*   Updated: 2019/01/17 15:32:36 by bcedric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <errno.h>

char g_bit = 0;

void g_debug()
{
	if (g_bit & 1)
		ft_putendl("a");
	if (g_bit & 2)
		printf("l\n");
	if (g_bit & 4)
		printf("r\n");
	if (g_bit & 8)
		printf("R\n");
	if (g_bit & 16)
		printf("t\n");
	if (g_bit & 32)
		printf("--\n");
}

int		ft_error(char c, int i)
{
	if (i == 0)
	{
		ft_putendl("ls: -: No such file or directory");
	}
	else
	{
		ft_putstr("ls : illegal option -- ");
		ft_putchar(c);
		ft_putendl("");
		ft_putstr("usage: ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] [file ...]");
	}
	return (0);
}

void	put_in_tab()
{
	printf("AUCUN DES DEUX\n");
}

void	dirtrue(char *s1)
{
	printf("SALUT\n");
	printf("%s\n", s1);
	DIR *dir;

	dir = opendir(s1);
	if (dir != NULL)
	{
		closedir(dir);
		printf("Directory\n");
	}
	else if (errno == ENOTDIR)
	{
		printf("FILE\n");
	}
	else
		put_in_tab();
}

void	option(char *s1)
{
	int blocker;
	int i;

	i = 1;
	blocker = 0;
	if (s1[i] == '\0')
		ft_error(*s1, 0);
	s1++;
	while(*s1)
	{
		if (g_bit & 32)
			break ;
		if (*s1 == 'a')
			g_bit |= 1;
		else if (*s1 == 'l')
			g_bit |= 2;
		else if (*s1 == 'r')
			g_bit |= 4;
		else if (*s1 == 'R')
			g_bit |= 8;
		else if(*s1 == 't')
			g_bit |= 16;
		else if (*s1 == '-')
			g_bit |= 32;
		else
		{
			ft_error(*s1, 1);
			break ;
		}
		s1++;
	}
}

int main (int argc, char **argv)
{
	int i;

	i = 1;
	/*This while it's only for option*/
	while (i < argc)
	{
			if (g_bit & 32)
				break ;
			if (argv[i][0] == '-')
			{
				g_bit |= 64;
				option(argv[i]);
			}
			else
				break ;
		i++;
	}
	/*if (g_bit & 64)
		i++;*/
	/*This while it's for directory or file*/
	while (i < argc)
	{
		dirtrue(argv[i]);
		i++;
	}
	g_debug();
	return (0);
}
