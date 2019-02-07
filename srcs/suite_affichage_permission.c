/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suite_affichage_permission.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcedric <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:20:21 by bcedric           #+#    #+#             */
/*   Updated: 2019/02/07 16:57:21 by bcedric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**Fichier qui est la suite d'affichage_permission
*/

char	affichage_perm_other(int i, t_element *li)
{
	if (i == 6)
		return ((li->fileinfo.st_mode & S_IROTH) ? 'r' : '-');
	if (i == 7)
		return ((li->fileinfo.st_mode & S_IWOTH) ? 'w' : '-');
	if (i == 8)
	{
		if (li->fileinfo.st_mode & S_ISVTX)
			return ((li->fileinfo.st_mode & S_IXUSR) ? 't' : 'T');
		else
			return ((li->fileinfo.st_mode & S_IXOTH) ? 'x' : '-');
	}
	return ('-');
}

char	affichage_perm_group(int i, t_element *li)
{
	if (i == 3)
		return ((li->fileinfo.st_mode & S_IRGRP) ? 'r' : '-');
	if (i == 4)
		return ((li->fileinfo.st_mode & S_IWGRP) ? 'w' : '-');
	if (i == 5)
	{
		if (li->fileinfo.st_mode & S_ISGID)
			return ((li->fileinfo.st_mode & S_IXGRP) ? 's' : 'S');
		else
			return ((li->fileinfo.st_mode & S_IXGRP) ? 'x' : '-');
	}
	return ('-');
}

char	affichage_perm_usr(int i, t_element *li)
{
	if (i == 0)
		return ((li->fileinfo.st_mode & S_IRUSR) ? 'r' : '-');
	if (i == 1)
		return ((li->fileinfo.st_mode & S_IWUSR) ? 'w' : '-');
	if (i == 2)
	{
		if (li->fileinfo.st_mode & S_ISUID)
			return ((li->fileinfo.st_mode & S_IXUSR) ? 's' : 'S');
		else
			return ((li->fileinfo.st_mode & S_IXUSR) ? 'x' : '-');
	}
	return ('-');
}

char	affichage_perm(int i, t_element *li)
{
	if (i == 0 || i == 1 || i == 2)
		return (affichage_perm_usr(i, li));
	else if (i == 3 || i == 4 || i == 5)
		return (affichage_perm_group(i, li));
	else
		return (affichage_perm_other(i, li));
	return ('-');
}
