/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcedric <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 13:44:01 by bcedric           #+#    #+#             */
/*   Updated: 2019/01/17 15:32:36 by bcedric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char g_bit = 0;

List create_child_list(char *path) //On recoit juste le chemin a ouvrir
{
	struct dirent *dent;
	struct stat fileinfo;
	List child = new_list();
	DIR *dir;
	char *full_path;

	dir = opendir(path); //On ouvre le path et non le name
	while((dent = readdir(dir)) != NULL)
	{
		full_path = ft_strjoin(path, "/");
		full_path = ft_strjoin(full_path, dent->d_name);
		//leak
		lstat(full_path, &fileinfo);
		child = push_back(child, dent->d_name, full_path, fileinfo);
	}
	// free(dent);
	//free(fileinfo);
	return(child);
}

void affichage(List li, char *path)
{
	ListElement *begin;
	begin = li;
	if (path != NULL)
		printf("\n%s:\n", path);
	printf("total %s\n", "xx");
	while (li != NULL)
	{
		if (g_bit & OPTION_l)
			main_l(li, begin);
		else
			ft_putendl(li->name);
		li = li->next;
	}
}

void parent_to_childe(List parent, char *path) //ajout du path pour la recursive
{
	DIR *dir;
	List child = new_list();
	char *path_backup; //correspond au path avant d'avoir ajouté le num du dossier qu'on ouvre (il doit y avoir moyen de faire autrement mais bon...)

	path_backup = ft_strdup(path); //On sauve le path dedans

	while(parent != NULL && (g_bit & OPTION_R))
	{
			//On config le path avant de faire quoi que ce soit
		path = ft_strjoin(path, "/"); //On ajoute un / car c'est un dossier
		path = ft_strjoin(path, parent->name); //puis le nom du fichier

		dir = opendir(path); //vérifier qu'il faut pas mettre le path

		if (dir != NULL)
		{
			child = create_child_list(path); //On cree la structure avec tous les enfants du path
			child = check_sort_list_ascci(child);

			affichage(child, path);
			parent_to_childe(child, path); //On recusive sur les enfants et on garde le path complet
			//printf("\n");
		}
		path = path_backup; //On remet le path sans le nom du dossier

		parent = parent->next;
	}
}

// void	display_l(List li)
// {
// 	ListElement *begin;
//
// 	begin = li;
// 	while (li != NULL)
// 	{
// 		main_l(li, begin);
// 		li = li->next;
// 	}
//
// }
//
// void	display(List li, int i)
// {
// 	if (i == 0)
// 	{
// 		if (g_bit & OPTION_l)
// 			display_l(li);
// 		else
// 			print_list(li);
// 	}
// 	else if (i == 1)
// 	{
// 		printf("YOP\n"); //si il y a des dossiers en argument
// 	}
// }

// void list_begin(List li, int i, int argc)
// {
// 	ListElement *child;
// 	int j;
//
// 	j = 0;
// 	if (list_size(li) == 1) //si 1 element dans ta chaine
// 	{
// 		if (i == argc || (i - 1) == argc) //si il a pas d'arguments
// 			j = 0;
// 		else
// 			j = 1;
// 		child = create_child_list(li->name);
// 		child = option_a(child);
// 		child = check_sort_list_ascci(child);
// 		//print_list(child);
// 		//sleep(30);
// 		display(child, j);
// 	}
//
// }

int main (int argc, char **argv)
{
	int i;

	List mylist = new_list();
	i = 1;
	check_arguments_b0(argv, argc);
	i = check_option(argv, argc);
	sort_argv(i, argc, argv);
	mylist = check_directory(i, argc, argv, mylist); //Création de la liste parent avec les arguments (ou non) de la fonction
	if (!is_empty(mylist))  //si la liste est vide
		return (0);
	mylist = check_sort_list_ascci(mylist); //On trie la liste dans l'ordre ASCI
	if (i < argc) //Si on a des arguents
		mylist = print_and_free_only_file(mylist); //on affiche les fichiers et free les fichiers

	affichage(mylist, NULL);
	parent_to_childe(mylist, "."); //On passe la 1ere fois un . (a voir si on passe un nom de dossier en param !)


	return (0);
}
