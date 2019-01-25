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
	if (stat(s1, file) == 0)
		return (1);
	else
		return (0);
}

List  put_in_list(char *str, List li,  struct stat file)
{
	li = push_back(li, str, file);
	return (li);
}

List	check_directory(int i, int argc, char **argv, List li)
{
	struct stat file;
	if (i == argc)
	{
		dirtrue("./", &file);
		li = put_in_list("./", li, file);
		return (li);
	}
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
