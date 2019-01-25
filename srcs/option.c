/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcedric <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 12:03:35 by bcedric           #+#    #+#             */
/*   Updated: 2019/01/25 12:03:48 by bcedric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int 	is_hide(List li)
{
	if(ft_strncmp(li->name, ".", 1) == 0)
	{
		return (1);
	}
	return (0);
}

List 	check_option_a(List li)
{
	ListElement *begin;

	while (li->next != NULL)
	{
		if (is_hide(li))
		{
			begin = li;
			li = back_list(li, begin);
		}
		else
			break ;
	}
	return (li);
}

List option_a(List li)
{
	if (!(g_bit & OPTION_a))
	{
		li = check_option_a(li);
	}
	return (li);
}