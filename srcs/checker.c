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

/*
**Check_arguments : fs_open (Fonction de checker)
**
**Check_directory : Fonction qui permet de verifier en appelant dirtrue si
**	l'arugements rentree existe (dossier ou fichier) (stat == 0 --> existe)
**	(stat == -1 --> n'existe pas). Si dirtrue renvoie "1" allors on fais
**	appelle a la fonction put_in_list qui s'occupe de remplire la liste
**	chainer.
*/

int dirtrue(char *s1, struct stat *file)
{
	if (lstat(s1, file) == 0)
		return (1);
	else
		return (0);
}

List  put_in_list(char *str, List li,  struct stat file)
{
	int i;

	i = 0;
	if (ft_strcmp(str, "..") == 0 || ft_strcmp(str, ".") == 0)
	{
		str = ft_strjoin(str, "/");
		i = 1;
	}
	li = push_back(li, str, str, file, i);
	return (li);
}

List	check_directory(int i, int argc, char **argv, List li)
{
	struct stat file;
	if (i == argc) //si pas d'arguments
	{
		li = create_child_list("."); //on crée la liste avec les dossiers/fichiers
		li = check_sort_list_ascci(li);
		return (li);
	}
	while (i < argc) //Tant qu'il y a des arguments
	{
		if (!(dirtrue(argv[i], &file))) //on recup les infos de chaque argument
		 ft_error2(argv[i], 0);
		else
			li = put_in_list(argv[i], li, file); //On les met dans la liste
		i++; //argument suivant
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
