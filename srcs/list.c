/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcedric <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 07:45:37 by bcedric           #+#    #+#             */
/*   Updated: 2019/02/07 16:54:05 by bcedric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**new_list: Fonction qui permet de cree une nouvelle liste.
**
**is_empty: Fonction qui permet de savoir si la liste est vide.
**
**list_size: Fonction qui permet de connaitre la taille de la liste
**
**print_list: print toutes la liste(seulement le nom compris dans le maillon)
**
**print_name_list: print le nom du maillon qu'il recoit
*/

List	new_list(void)
{
	return (NULL);
}

int		is_empty(List li)
{
	if (li == NULL)
		return (0);
	return (1);
}

int		list_size(List li)
{
	int size;

	size = 0;
	if (!(is_empty(li)))
		return (size);
	while (li != NULL)
	{
		++size;
		li = li->next;
	}
	return (size);
}

void	print_list(List li)
{
	int i;

	if (!(is_empty(li)))
	{
		ft_putendl("Rien a afficher");
		return ;
	}
	while (li != NULL)
	{
		i = 0;
		while (li->name[i] != '\0')
		{
			ft_putchar(li->name[i]);
			i++;
		}
		li = li->next;
		ft_putendl("");
	}
}

void	print_name_list(List li)
{
	char	buf[NAME_MAX + 1];

	ft_putstr(li->name);
	if (S_ISLNK(li->fileinfo.st_mode))
	{
		ft_putstr(" -> ");
		ft_bzero(buf, NAME_MAX + 1);
		readlink(li->full_path, buf, NAME_MAX);
		ft_putstr(buf);
	}
	ft_putendl("");
}
