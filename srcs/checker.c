/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcedric <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 07:36:45 by bcedric           #+#    #+#             */
/*   Updated: 2019/02/07 21:03:11 by bcedric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**Check_arguments : fs_open (Fonction de checker)
**
**Check_directory : Fonction qui permet de verifier en appelant dirtrue si
**	l'arugements rentree existe (dossier ou fichier) (stat == 0 --> existe)
**	(stat == -1 --> n'existe pas). Si dirtrue renvoie "1" allors on fais
**	appelle a la fonction put_in_list qui s'occupe de remplire la liste
**	chainer.
**Put_in_list permet de remplire ma liste parent avec quelque verification
**si l'argument passer en parametre en un lien symbolic mais que le -l
**est activer ou si ce n'est pas un lien symbolic je ne doit pas suivre le
**lien. Si c'est le cas je cree un maillon avec le lien vers ou il pointe.
*/

int			dirtrue(char *s1, struct stat *file)
{
	if (lstat(s1, file) == 0)
		return (1);
	else
		return (0);
}

t_elem		*put_in_list(char *str, t_elem *li, struct stat file)
{
	char	buf[NAME_MAX];

	if ((S_ISLNK(file.st_mode) &&
				(g_bit & OPTION_L)) || !(S_ISLNK(file.st_mode)))
	{
		if (ft_strcmp(str, "..") == 0 || ft_strcmp(str, ".") == 0)
		{
			str = ft_strjoin_free(str, "/", 4);
			li = push_back(li, new_elem(str, str, file, 2));
			if (str)
				ft_strdel(&str);
			return (li);
		}
		li = push_back(li, new_elem(str, str, file, 1));
	}
	else
	{
		ft_bzero(buf, NAME_MAX + 1);
		readlink(str, buf, NAME_MAX);
		lstat(buf, &file);
		li = push_back(li, new_elem(buf, buf, file, 2));
	}
	return (li);
}

t_elem		*check_directory(int i, int argc, char **argv, t_elem *li)
{
	struct stat file;

	sort_argv(i, argc, argv);
	if (i == argc)
	{
		li = create_child_list(".", 0);
		li = check_sort_list_ascci(li);
		return (li);
	}
	while (i < argc)
	{
		if (!(dirtrue(argv[i], &file)))
			ft_error2(argv[i], 0);
		else
			li = put_in_list(argv[i], li, file);
		i++;
	}
	return (li);
}

int			check_perm(char *path)
{
	struct stat fileinfo;

	lstat(path, &fileinfo);
	if (!S_ISDIR(fileinfo.st_mode))
		return (1);
	return (0);
}
