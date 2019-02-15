/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcedric <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 13:44:01 by bcedric           #+#    #+#             */
/*   Updated: 2019/02/08 12:14:51 by bcedric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char g_bit = 0;

int			main(int argc, char **argv)
{
	int			i;
	t_elem		*mylist;

	mylist = new_list();
	i = check_option(argv, argc);
	mylist = check_directory(i, argc, argv, mylist);
	if (!is_empty(mylist))
		return (0);
	mylist = check_sort_list_ascci(mylist);
	if (i != argc)
	{
		mylist = print_and_free_only_file(mylist);
		if (argc - i == 1)
			i = 0;
		if (list_size(mylist) != 0)
			parent_to_childe(mylist, NULL, i);
	}
	else
	{
		no_arguments(mylist);
	}
	if (mylist)
		(g_bit & OPTION_RR) ? free_li_parent(mylist) : free_li(mylist);
	return (0);
}
