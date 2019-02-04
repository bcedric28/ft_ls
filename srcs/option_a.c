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

/*
**option_a : Fonction qui permet de verifier si l'option "-a" est actif,
**	si c'est le cas je fais appel a check_option_a qui me permet de boucler
**	sur ma liste et de verifier sur chaque maillon, grace a is_hide, si
**	le name ne commence pas par "." si c'est le cas je fais appel a ma
**	fonction "back_list" (list3.c)
*/

int 	is_hide(List li)
{
	if(ft_strncmp(li->name, ".", 1) == 0)
	{
		return (1);
	}
	return (0);
}


int is_hide_path(char *path)
{
	int i;

	i = 0;
	while(path[i])
	{
		i++;
	}
	i--;
	//printf("I %d\n", i);
	while(path[i] != '/')
	{
		//printf("PATH[%d] %c\n", i, path[i]);
		if (path[i] == '.' && path[i - 1] == '/')
			return (1);
		i--;
	}
	return (0);
}

