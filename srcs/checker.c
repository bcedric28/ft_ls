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
			ft_error(*s1, 3);
			break ;
		}
		s1++;
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
				option(s1[i]);
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
		{
			g_bit |= 32;
			break ;
		}
		if (s1[i][0] == '\0')
			ft_error(s1[i][0], 1);
		i++;
	}
}
