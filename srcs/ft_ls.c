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
	if (g_bit & 1)
		ft_putendl("a");
	if (g_bit & 2)
		printf("l\n");
	if (g_bit & 4)
		printf("r\n");
	if (g_bit & 8)
		printf("R\n");
	if (g_bit & 16)
		printf("t\n");
	if (g_bit & 32)
		printf("--\n");
}*/

void sort_argv(int i, int argc, char **tab)
{
	char *temp;
	int j;

	j = i;
	while (i < argc && tab[i + 1] != '\0')
	{
		if (ft_strcmp(tab[i], tab[i + 1]) > 0)
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			i = j;
		}
		else
			i++;
	}
}

List check_sort_list(List li)
{
	char *temp;
	struct stat file;
	ListElement *j;

	j = li;
	while (li->next != NULL)
	{
		if (ft_strcmp(li->name, li->next->name) > 0)
		{
			temp = li->name;
			file = li->fileinfo;
			li->name = li->next->name;
			li->fileinfo = li->next->fileinfo;
			li->next->name = temp;
			li->next->fileinfo = file;
			li = j;
		}
		else
			li = li->next;
	}
	if(g_bit & 16)
	{
		while (li->next != NULL)
		{
			if (li->fileinfo.st_mtime < li->next->fileinfo.st_mtime)
			{
				temp = li->name;
				file = li->fileinfo;
				li->name = li->next->name;
				li->fileinfo = li->next->fileinfo;
				li->next->name = temp;
				li->next->fileinfo = file;
				li = j;
			}
			else
				li = li->next;
		}
	}
	li = j;
	if (g_bit & 4)
	{
		List new_ord = new_list();
		while(li != NULL)
		{
			new_ord = push_front(new_ord, li->name, li->fileinfo);
			li = back_front(li);
		}
		return(new_ord);
	}
	return (li);
}

List create_child_list(char *path) //On recoit juste le chemin a ouvrir
{
	struct dirent *dent;
	struct stat fileinfo;
	List child = new_list();
	DIR *dir;
	static int j = 0;
	int i;

	i = 2;
	if(j != 0)
	{
		while (path[i])
		{
			ft_putchar(path[i]);
			i++;
		}
		ft_putchar(':');
		ft_putendl("");
	}
	dir = opendir(path); //On ouvre le path et non le name
	while((dent = readdir(dir)) != NULL)
	{
		stat(dent->d_name, &fileinfo);
		child = push_back(child, dent->d_name, fileinfo);
	}
	j = 1;
	// free(dent);
	//free(fileinfo);

	return(child);
}

char	file_perm2(int i, List li)
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
	return (0);
}

void affichage_type_of_f(List li)
{
	if (S_ISREG(li->fileinfo.st_mode))
		ft_putchar('-');
	else if (S_ISDIR(li->fileinfo.st_mode))
		ft_putchar('d');
	else if (S_ISCHR(li->fileinfo.st_mode))
		ft_putchar('c');
	else if (S_ISBLK(li->fileinfo.st_mode))
		ft_putchar('b');
	else if (S_ISFIFO(li->fileinfo.st_mode))
		ft_putchar('p');
	else if (S_ISLNK(li->fileinfo.st_mode))
		ft_putchar('l');
	else if(S_ISSOCK(li->fileinfo.st_mode))
		ft_putchar('s');
}

void	affichage_file_perm(List li)
{
	char *str;
	int i;

	i = 0;
	str = ft_strnew(3);
	affichage_type_of_f(li);
	while (i <= 8)
	{
		str[i] = file_perm2(i, li);
		i++;
	}
	str[9] = '\0';
	i = 0;
	while(str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

/*void	affichage_file_link(List li)
{
	//
}*/

void	affichage_file_l(List li)
{
	affichage_file_perm(li);
	//affichage_file_link(li);
}

void affichage_file(List li)
{
	DIR *dir;
	ListElement *temp;

	while (li != NULL)
	{
		temp = li;
		dir = opendir(li->name);
		if (dir == NULL)
		{
			if (g_bit & 2)
				affichage_file_l(temp);
			ft_putstr(li->name);
			ft_putendl("");	
		}
		else 
			closedir(dir);
		li = li->next;
	}
	ft_putendl("");

}


int 	is_hide(List li)
{
	if(ft_strncmp(li->name, ".", 1) == 0)
	{
		return (1);
	}
	return (0);
}

List 	affichage_a(List li)
{
	ListElement *before;
	ListElement *temp;

	temp = li;
	if (g_bit & 4)
	{
		while (li != NULL)
		{
			before = li;
			li = li->next;
		}
		if (is_hide(before))
			 li = back_up(temp);
		else
			return (li);
		affichage_a(li);
	}
	else
	{
		while (li->next != NULL)
		{
			if (is_hide(li))
			{
				//printf("C'est moi\n");
				li = back_front(li);
			}
			else
				break ;
		}
	}
	return (li);
}

/*void parent(List parent, char *path)
{
	//verifier l'ordre de la liste;
	//verifier si le -a est activer;
	//stocker les informations necessaire;
	//afficher le parent en fonction du -l puis supprimer les fichier de la liste chainer en cour, puis si le R l'enfant et ainsi de suite quand plus d'enfant free;
}*/
void parent_to_childe(List parent, char *path, int j) //ajout du path pour la recursive
{
	DIR *dir;
	List child = new_list();
//	static int i = 0;
	char *path_backup; //correspond au path avant d'avoir ajouté le num du dossier qu'on ouvre (il doit y avoir moyen de faire autrement mais bon...)
	parent = check_sort_list(parent);

	path_backup = ft_strdup(path); //On sauve le path dedans
	/*if (j > 0 && i == 0)
		affichage_file(parent);*/
	/*if (i == 0 && j == 0)
		print_list(parent);
	if (i != 0)*/
	if (!(g_bit & 1))
		parent = affichage_a(parent);
	/*if (j > 1 && i == 0)
	{
		i = 1;
		ft_putstr(parent->name);
		ft_putendl(":");
	}*/
		print_list(parent);
	while(parent != NULL)   //Si on laisse le next on perd le dernier element
	{
		if ((ft_strcmp(parent->name, ".") != 0) && (ft_strcmp(parent->name, "..") != 0))
		{
			//printf("Salut %s\n", parent->name);
			//On config le path avant de faire quoi que ce soit
			path = ft_strjoin(path, "/"); //On ajoute un / car c'est un dossier
			path = ft_strjoin(path, parent->name); //puis le nom du fichier

			dir = opendir(path); //vérifier qu'il faut pas mettre le path

			if (dir == NULL)
			{
				// printf("fichier : %s\n", path);
				//parent = parent->next; //on passait 2x au suivant ici
			}
			else
			{

				// printf("dossier : %s\n", path);

				//leak
				if (g_bit & 8)
				{
					child = create_child_list(path); //On cree la structure avec tous les enfants du path
					parent_to_childe(child, path, j); //On recusive sur les enfants et on garde le path complet
				}
				else
				{
					child = create_child_list(path);
					child = check_sort_list(child);
						if (!(g_bit & 1))
							child = affichage_a(child);
					print_list(child);
				}
				//leak
			}
			path = path_backup; //On remet le path sans le nom du dossier

		}
		parent = parent->next;
	}
}

int main (int argc, char **argv)
{
	int i;
	int j;

	j = 0;
	//ListElement *temp;
	List mylist = new_list();
	i = 1;
	check_arguments_b0(argv, argc);
	i = check_option(argv, argc);
	sort_argv(i, argc, argv);
	mylist = check_directory(i, argc, argv, mylist);
	mylist = check_sort_list(mylist);
	j = argc - i;
	/*print_list(mylist);
	temp = mylist;
	mylist = add_list(mylist, temp, "salut");
	print_list(mylist);
	mylist = add_list(mylist, temp, "Bonjour");
	print_list(mylist);
	mylist = back_list(mylist->next->next, temp);
	print_list(mylist);*/
	parent_to_childe(mylist, ".", j); //On passe la 1ere fois un . (a voir si on passe un nom de dossier en param !)
	/*while (mylist != NULL)
	{
		back_front(mylist);
		mylist = mylist->next;
	}*/
	//g_debug();
	return (0);
}
