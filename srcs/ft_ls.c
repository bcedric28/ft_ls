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
#include <sys/xattr.h>

char g_bit = 0;

List create_child_list(char *path) //On recoit juste le chemin a ouvrir
{
	struct dirent *dent;
	struct stat fileinfo;
	List child = new_list();
	DIR *dir;
	char *full_path;

//	printf("PATH : %s\n", path);
	dir = opendir(path); //On ouvre le path et non le name
	if (dir == NULL)
	{
		printf("FUCK4\n\n");
		// return NULL;
		// exit(EXIT_FAILURE);
	}
	// if (listxattr(path, NULL, 0, XATTR_NOFOLLOW) > -1)//j'essaie de comprendre comment nofollow fonctionne
	// {
	// 	if (lstat(path, &fileinfo) != 0)
	//    		exit(EXIT_FAILURE);
	// 	child = push_back(child, path, path, fileinfo);
	// 	return (child);
	// }

	while((dent = readdir(dir)) != NULL)
	{
		full_path = ft_strjoin(path, "/");
		full_path = ft_strjoin(full_path, dent->d_name);
		//leak
		if (lstat(full_path, &fileinfo) != 0)
	   		exit(EXIT_FAILURE);
		child = push_back(child, dent->d_name, full_path, fileinfo);
		//print_list(child);
	}

	closedir(dir);
	return(child);
}

void affichage(List li, char *path, int i)
{
	ListElement *begin;
	begin = li;
	int k = 0;
	int total;

	if (i != 0 /*|| g_bit & OPTION_R*/)
		printf("\n%s:\n", path);
	if (g_bit & OPTION_l)
	{
		// if (i != 0 /*|| g_bit & OPTION_R*/)
		// 	printf("\n%s:\n", path);
		total = total_block(begin);
		ft_putstr("total ");
		ft_putstr(ft_itoa(total));
		ft_putendl("");
	}
	while (li != NULL)
	{
		if (g_bit & OPTION_l)
		{
			if (k == 0)
			{
				begin = login_name(begin);
				k = 1;
			}
			main_l(li, begin);
		}
		else
		{
			ft_putendl(li->name);
		}
		li = li->next;
	}
}

void parent_to_childe(List parent, char *path, int i) //ajout du path pour la recursive
{
	DIR *dir;
	List child = new_list();
	char *path_backup; //correspond au path avant d'avoir ajouté le num du dossier qu'on ouvre (il doit y avoir moyen de faire autrement mais bon...)

	if(path != NULL)
		path_backup = ft_strdup(path); //On sauve le path dedans
	else
	path_backup = NULL; //On sauve le path dedans
	while(parent != NULL /*&& (g_bit & OPTION_R)*/)
	{
		if(ft_strcmp(parent->name, ".") != 0 && ft_strcmp(parent->name, "..") != 0)
		{	//On config le path avant de faire quoi que ce soit
			if(path != NULL)
			{
				path = ft_strjoin(path, "/"); //On ajoute un / car c'est un dossier
				path = ft_strjoin(path, parent->name); //puis le nom du fichier
			}
			else
				path = parent->name;
			dir = opendir(path);
			//print_list(parent);
			if (dir != NULL)
			{
				child = create_child_list(path); //On cree la structure avec tous les enfants du path
				if(child) //si il a bien été créé
				{
					child = check_sort_list_ascci(child);
					//print_list(child);
					//sleep(5);
					affichage(child, path, i++);
					if (g_bit & OPTION_R)
					{
						/*nouvel fonction qui se rajoute sue la stack
						**donc on ne fri pas apre l'avoir afficher
						**quand la stack casse je suppose que
						**du coup on recupere l'ancienne liste et il la reaffiche
						**j'ai pu le constater donc ../../../ ou on refais le man 4fois
						**au lieu de 2 (ls le fais deux fois seulement).
						**Si le dossier est un lien symbolic il ne faut pas le suivre juste l'afficher
						**donc nous pour l'instant on boucle sur les dossier des lien symbolic.
						*/
						parent_to_childe(child, path, i); //On recusive sur les enfants et on garde le path complet
					}
					closedir(dir);
					//free_li(child);
				}
			}
		}
		path = path_backup; //On remet le path sans le nom du dossier
		parent = parent->next;
	}
}

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
	if (i != argc)
	{
		mylist = print_and_free_only_file(mylist);
		parent_to_childe(mylist, NULL, (list_size(mylist) - 1));
	}
	else
	{
		if (g_bit & OPTION_R)
		{
			affichage(mylist, "", 0);
			parent_to_childe(mylist, ".", 1);
		}
		else
			affichage(mylist, "", 0);
	}
	return (0);
}
