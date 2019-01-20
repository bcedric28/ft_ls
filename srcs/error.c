/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcedric <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 07:34:01 by bcedric           #+#    #+#             */
/*   Updated: 2019/01/18 07:34:02 by bcedric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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
	{
		ft_putendl_fd("ls: fts_open: No such file or directory", 2);
		exit(EXIT_FAILURE);
	}
	else
	{
		ft_putstr_fd("ls: illegal option -- ", 2);
		ft_putchar_fd(c, 2);
		ft_putendl_fd("", 2);
		ft_putstr_fd("usage: ls [-alrRt] [file ...]", 2);
		exit(EXIT_FAILURE);
	}
}
