/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcedric <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 12:03:35 by bcedric           #+#    #+#             */
/*   Updated: 2019/02/07 16:39:20 by bcedric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**simple fonction qui me permet de savoir si c'est un fichier || dossier
**cacher
*/

int		is_hide(t_elem *li)
{
	if (ft_strncmp(li->name, ".", 1) == 0)
	{
		return (1);
	}
	return (0);
}
