/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcedric <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 13:44:01 by bcedric           #+#    #+#             */
/*   Updated: 2019/02/08 12:14:51 by bcedric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		print_total(t_elem *li, int total)
{
	char		*result;

	total = total_block(li);
	ft_putstr("total ");
	result = ft_itoa(total);
	ft_putstr(result);
	free(result);
	ft_putendl("");
}

void		affichage(t_elem *li, char *path, int i)
{
	t_elem		*begin;
	int			total[3];

	if (i != 0)
		printf("%s:\n", path); //printf !!
	if (g_bit & OPTION_L && (is_empty(li) == 1) && li->parent == 0)
		print_total(li, total[0]);
	file_minor_and_major(li, total);
	if (g_bit & OPTION_L && li)
		begin = data_noodle(li);
	while (li != NULL)
	{
		if (g_bit & OPTION_L)
			main_l(li, begin, total);
		else
			ft_putendl(li->name);
		li = li->next;
	}
	ft_putendl("");
}
