/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcedric <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 07:36:45 by bcedric           #+#    #+#             */
/*   Updated: 2019/01/18 07:36:47 by bcedric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int dirtrue(char *s1, struct stat *file)
{
	//the file or directory exits ?
	//yes = 1;
	//no = 0;
	
	//struct stat file;
	if (stat(s1, file) == 0)
	{
		//printf("File Link:    %d\n", file->st_nlink);
		return (1);
	}
	else
		return (0);
}

void	option(char *s1)
{
	s1++;
	if (*s1 == '-')
	{
		g_bit |= 32;
		return ;
	}
	if (*s1 == '\0')
	{
		g_bit |= 64;
		return ;
	}
	while(*s1)
	{
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
		else
		{
			ft_error(*s1, 3);
			break ;
		}
		s1++;
	}
}

List  put_in_list(char *str, List li,  struct stat file)
{
	li = push_back(li, str, file);

	return (li);
}

List	check_directory(int i, int argc, char **argv, List li)
{
	struct stat file;

	while (i < argc)
	{
		if (!(dirtrue(argv[i], &file)))
		 ft_error2(argv[i]);
		else
			li = put_in_list(argv[i], li, file);
		i++;
	}
	return (li);
}

int		check_option(char **s1, int argc)
{
	int i;

	i = 1;
	while (i < argc && !(g_bit & 32) && !(g_bit & 64))
	{
			if (s1[i][0] == '-')
				option(s1[i]);
			else
				break ;
		i++;
	}
	if (g_bit & 64)
		return (i - 1);
	else
		return (i);
}

void	check_arguments_b0(char **s1, int argc)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (s1[i][0] == '\0')
			ft_error(s1[i][0], 1);
		i++;
	}
}
