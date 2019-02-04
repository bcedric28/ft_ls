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

	List create_child_list(char *path, int parent) //On recoit juste le chemin a ouvrir
	{
		struct dirent *dent;
		struct stat fileinfo;
		List child = new_list();
		DIR *dir;
		char *full_path;

		dir = opendir(path); //On ouvre le path et non le name
		if (dir == NULL)
		{
			printf("FUCK4\n\n");
			// return NULL;
			// exit(EXIT_FAILURE);
		}
		if (lstat(path, &fileinfo) != 0)
		   		exit(EXIT_FAILURE);
		if (S_ISLNK(fileinfo.st_mode) && parent == 0)
		{
			closedir(dir);
			return (child);
		}
		while((dent = readdir(dir)) != NULL)
		{
			full_path = ft_strjoin_free(path, "/", 4);
			full_path = ft_strjoin_free(full_path, dent->d_name, 0);
			if (lstat(full_path, &fileinfo) != 0)
		   		exit(EXIT_FAILURE);
			child = push_back(child, dent->d_name, full_path, fileinfo, 0);
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
		char *result;

		if (i != 0 /*|| g_bit & OPTION_R*/)
			printf("\n%s:\n", path);
		if (g_bit & OPTION_l && (is_empty(li) == 1))
		{
			// if (i != 0 /*|| g_bit & OPTION_R*/)
			// 	printf("\n%s:\n", path);
			total = total_block(begin);
			ft_putstr("total ");
			result = ft_itoa(total);
			ft_putstr(result);
			free(result);
			ft_putendl("");
		}
		while (li != NULL)
		{
			if (g_bit & OPTION_l)
			{
				if (k == 0)
				{
					begin = login_name(begin);
					k = 1; // ne pas reboucler.
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

		//printf("path %s\n", path);
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
					path = ft_strjoin_free(path, "/", 0); //On ajoute un / car c'est un dossier
					path = ft_strjoin_free(path, parent->name, 0); //puis le nom du fichier
				}
				else
				{
					if (ft_strcmp(parent->name, "./") == 0 && (parent->parent == 1))
						path = ft_strdup(".");
					else if (ft_strcmp(parent->name, "../") == 0 && (parent->parent == 1))
						path = ft_strdup("..");
					else
						path = ft_strdup(parent->name);
				}
				dir = opendir(path);
				if (dir != NULL)
				{
					child = create_child_list(path, 0); //On cree la structure avec tous les enfants du path
					if(child) //si il a bien été créé
					{
						child = check_sort_list_ascci(child);
						affichage(child, path, i++);
						if (g_bit & OPTION_R)
							parent_to_childe(child, path, i); //On recusive sur les enfants et on garde le path complet					
						closedir(dir);
						free_li(child);
					}
					else if(parent->parent == 1)
						affichage(parent, path, i++);
				}
				else if (check_perm(path) == 0 && is_hide_path(path) == 0)
					(parent->next == NULL) ? ft_error2(path, 1, 0) : ft_error2(path, 1, 1);
			}
			if(path_backup)
				path = ft_strdup(path_backup); //On remet le path sans le nom du dossier
			
			parent = parent->next;


		}
		if (path_backup)
			free(path_backup);
		free_li(parent);		
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
		mylist = check_sort_list_ascci(mylist);
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
				parent_to_childe(mylist, ft_strdup("."), 1);
			}
			else
				affichage(mylist, "", 0);
		}
		if (mylist)
			free_li(mylist);
		//while(1);
		return (0);
	}
