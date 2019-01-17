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

char g_bit = 0;

/*void g_debug()
{
	printf("----OPTION-----\n");
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
}*/

void 	ft_error2(char *s)
{
	int i;

	i = 0;
	ft_putstr_fd("ls: ", 2);
	while(s[i])
	{
		ft_putchar_fd(s[i], 2);
		i++;
	}
	ft_putendl_fd(": No such file or directory", 2);
}

void	ft_error(char c, int i)
{
	if (i == 0)
		ft_putendl_fd("ls: -: No such file or directory", 2);
	else if (i == 1)
		ft_putendl_fd("ls: fts_open: No such file or directory", 2);
	else
	{
		ft_putstr_fd("ls: illegal option -- ", 2);
		ft_putchar_fd(c, 2);
		ft_putendl_fd("", 2);
		ft_putstr_fd("usage: ls [-alrRt] [file ...]", 2);
	}
	exit(EXIT_FAILURE);
}

int dirtrue(char *s1)
{
	//the file or directory exits ?
	//yes = 1;
	//no = 0;
	
	struct stat file;
	if (stat(s1, &file) == 0)
		return (1);
	else
		return (0);
}

void	option(char *s1)
{
	int i;

	i = 1;
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

void sort_argv(int i, int argc, char **tab)
{
	char *temp;
	int j;

	j = i;
	while (i < argc && tab[i + 1] != '\0')
	{
		if (ft_strcmp(tab[i], tab[i + 1]) > 0)
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			i = j;
		}
		else
			i++;
	}
}

void	check_directory(int i, int argc, char **argv)
{
	while (i < argc)
	{
		if(!(dirtrue(argv[i])))
			ft_error2(argv[i]);
		i++;
	}
}

int		check_option(char **s1, int argc)
{
	int i;

	i = 1;
	while (i < argc)
	{
			if (g_bit & 32)
				break ;
			if (s1[i][0] == '-')
			{
				g_bit |= 64;
				option(s1[i]);
			}
			else
				break ;
		i++;
	}
	return (i);
}

void	check_arguments_b0(char **s1, int argc)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (s1[i][0] == '-' && s1[i][1] == '\0')
			ft_error(s1[i][0], 0);
		if (s1[i][0] == '\0')
			ft_error(s1[i][0], 1);
		i++;
	}
}

int main (int argc, char **argv)
{
	int i;

	i = 1;
	check_arguments_b0(argv, argc);
	i = check_option(argv, argc);
	sort_argv(i, argc, argv);
	check_directory(i, argc, argv);
	return (0);
}
