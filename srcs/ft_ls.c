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

/*void g_debug()
{
	printf("----OPTION-----\n");
	if (g_bit & OPTION_a)
		ft_putendl("a");
	if (g_bit & OPTION_l)
		printf("l\n");
	if (g_bit & OPTION_r)
		printf("r\n");
	if (g_bit & OPTION_R)
		printf("R\n");
	if (g_bit & OPTION_t)
		printf("t\n");
	if (g_bit & OPTION_STOP)
		printf("--\n");
}*/


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
		stat(full_path, &fileinfo);
		child = push_back(child, dent->d_name, fileinfo);
	}
	// free(dent);
	//free(fileinfo);
	return(child);
}

/*void	affichage_file_l(List li)
{
	affichage_file_perm(li);
	//affichage_file_link(li);
}*/

/*void affichage_file(List li)
{
	DIR *dir;
	ListElement *temp;

	while (li != NULL)
	{
		temp = li;
		dir = opendir(li->name);
		if (dir == NULL)
		{
			if (g_bit & OPTION_l)
				affichage_file_l(temp);
			ft_putstr(li->name);
			ft_putendl("");
		}
		else
			closedir(dir);
		li = li->next;
	}
	ft_putendl("");

}*/

/*void parent(List parent, char *path)
{
	//verifier l'ordre de la liste;
	//verifier si le -a est activer;
	//stocker les informations necessaire;
	//afficher le parent en fonction du -l puis supprimer les fichier de la liste chainer en cour, puis si le R l'enfant et ainsi de suite quand plus d'enfant free;
}*/

void parent_to_childe(List parent, char *path) //ajout du path pour la recursive
{
	DIR *dir;
	List child = new_list();
	char *path_backup; //correspond au path avant d'avoir ajouté le num du dossier qu'on ouvre (il doit y avoir moyen de faire autrement mais bon...)
	parent = check_sort_list_ascci(parent);

	path_backup = ft_strdup(path); //On sauve le path dedans
	print_list(parent);

	while(parent != NULL)   //Si on laisse le next on perd le dernier element
	{
		if ((ft_strcmp(parent->name, ".") != 0) && (ft_strcmp(parent->name, "..") != 0))
		{
			//On config le path avant de faire quoi que ce soit
			path = ft_strjoin(path, "/"); //On ajoute un / car c'est un dossier
			path = ft_strjoin(path, parent->name); //puis le nom du fichier

			dir = opendir(path); //vérifier qu'il faut pas mettre le path

			if (dir != NULL)
			{
				//leak
				child = create_child_list(path); //On cree la structure avec tous les enfants du path
				parent_to_childe(child, path); //On recusive sur les enfants et on garde le path complet
									//leak
				printf("\n");
			}
			path = path_backup; //On remet le path sans le nom du dossier
		}
		parent = parent->next;
	}
}
/*
void parent_without_r(List li, int j)
{
	DIR *dir;
	ListElement *temp;
	List child = new_list();

	temp = li;
	if (j == 0)
	{
		if (!(g_bit & OPTION_a))
			li = affichage_a(li);
		print_list(li);
	}
	else
	{
		while (li != NULL)
		{
			dir = opendir(li->name);
			if (dir == NULL)
			{
				ft_putstr(li->name);
			}
			li = li->next;
		}
		ft_putendl("");
		li = temp;
		while (li != NULL)
		{
			dir = opendir(li->name);
			if (dir != NULL)
			{
				ft_putendl(li->name);
				child = create_child_list(li->name);
				check_sort_list(child);
				if (!(g_bit & OPTION_a))
					child = affichage_a(child);
				print_list(child);
			}
			li = li->next;
		}
	}
}*/

void	display_l(List li)
{
	ListElement *begin;

	begin = li;
	while (li != NULL)
	{
		main_l(li, begin);
		li = li->next;
	}

}

void	display(List li, int i)
{
	if (i == 0)
	{
		if (g_bit & OPTION_l)
			display_l(li);
		else
			print_list(li);
	}
	else if (i == 1)
	{
		printf("YOP\n");
	}
}

void list_begin(List li, int i, int argc)
{
	ListElement *child;
	int j;

	j = 0;
	if (list_size(li) == 1)
	{
		if (i == argc || (i - 1) == argc)
			j = 0;
		else
			j = 1;
		child = create_child_list(li->name);
		child = option_a(child);
		child = check_sort_list_ascci(child);
		display(child, j);
	}

}

int main (int argc, char **argv)
{
	int i;
	//int j;

	//ListElement *temp;
	List mylist = new_list();
	i = 1;
	check_arguments_b0(argv, argc);
	i = check_option(argv, argc);
	sort_argv(i, argc, argv);
	mylist = check_directory(i, argc, argv, mylist);
	mylist = check_sort_list_ascci(mylist);
	// print_list(mylist);

	if (i < argc) //Si on a des arguents
	{
		mylist = print_and_free_only_file(mylist);
	}
	print_list(mylist);
	list_begin(mylist, argc, i);
	//printf("%d\n", list_size(mylist));
	//print_list(mylist);
	//j = argc - i;
	/*print_list(mylist);
	temp = mylist;
	mylist = add_list(mylist, temp, "salut");
	print_list(mylist);
	mylist = add_list(mylist, temp, "Bonjour");
	print_list(mylist);
	mylist = back_list(mylist->next->next, temp);
	print_list(mylist);*/
	if (g_bit & OPTION_R)
		parent_to_childe(mylist, "."); //On passe la 1ere fois un . (a voir si on passe un nom de dossier en param !)
	/*while (mylist != NULL)
	{
		back_front(mylist);
		mylist = mylist->next;
	}*/
	//g_debug();
	return (0);
}
