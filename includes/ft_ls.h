/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcedric <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 13:43:03 by bcedric           #+#    #+#             */
/*   Updated: 2019/01/12 13:43:05 by bcedric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# define OPTION_A 1
# define OPTION_L 2
# define OPTION_RR 4
# define OPTION_R 8
# define OPTION_T 16
# define OPTION_STOP 32
# define OPTION_END 64

# include "../Libft/includes/libft.h"
# include <stdio.h>
# include <dirent.h>
# include <time.h>
# include <unistd.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <stdlib.h>
# include <grp.h>
# include <sys/xattr.h>
# include <sys/acl.h>

extern char g_bit;

/*
** Definition de la liste chainee
*/

typedef struct ListElement
{
	char *name;
	struct stat fileinfo;
	struct ListElement *next;
	char *login;
	char *group;
	char *full_path;
	char *date;
	int max_login;
	int max_group;
	int size;
	int size_max;
	int parent;
}ListElement, *List;

List create_child_list(char *path, int parent); //On recoit juste le chemin a ouvrir
int 	check_perm(char *path);
void affichage(List li, char *path, int i);
void affichage_xattr_acl(List li, int *total);
int 	total_block(List begin);
void 	fill_noodle_data(List begin, int *tab);
List	data_noodle(List begin);
/*
**Fonction pour le -a dans le fichier option_a.c
*/
int 	is_hide(List li);

/*
**Fonction pour le -l dans le fichier option_l(2 & 3).c et file_perm.c
*/

	/*
	**--------------------file_perm.c-----------------------
	*/

void	kernel_of_file_perm(List li);
void 	affichage_type(List li);
char	affichage_perm(int i, List li);
char	affichage_perm_usr(int i, List li);
char	affichage_perm_group(int i, List li);
char	affichage_perm_other(int i, List li);

	/*
	**---------------------option_l-------------------------
	*/

int		number_of_digit(int max);
void 	count_file_link(List li, List begin, int *total);
void	affichage_file_link(int max, List li, int *total);
List	login_name(List begin);
void	affichage_file_login(List li);

	/*
	**---------------------option2_l-------------------------
	*/

void	affichage_file_group(List li);
void	affichage_file_size(List li, int *total);
void 	file_minor_and_major(List begin, int *total);
void	affichage_minor(List li, int min);
void	affichage_major(List li, int max);
void	main_l(List li, List begin, int *total);

	/*
	**---------------------option3_l-------------------------
	*/

void 	file_date(List li);
int		check_6_months(List li, time_t now);
void	affichage_file_date(List li, int i);
void	affichage_file_years(List li, int i);
int 	total_block(List begin);

/*
**Fonction de gestion d'erreur dans le fichier error.c
*/

void	ft_error(char c, int i);
void 	ft_error2(char *s, int j);
void 	ft_error3(char *s, int end, int j, List parent);

/*
**Fonction de check d'arguments dans checker.c et dans checker_option.c
*/
	/*
	**---------------------checker.c--------------------------------
	*/

void	check_arguments_b0(char **s1, int argc);
List	check_directory(int i, int argc, char **argv, List li);
List  	put_in_list(char *str, List li,  struct stat file);
int 	dirtrue(char *s1, struct stat *file);

	/*
	**---------------------checker_option.c-------------------------
	*/

int		check_option(char **s1, int argc);
void	option(char *s1);
int		turn_on_option(char option);

/*
**Fonction de trie de argv et la liste selon les option demander dans le fichier sort_list.c
*/

List 	check_sort_list_ascci(List li);
List 	check_sort_list_reverse(List li);
List 	check_sort_list_time(List li);
void 	sort_argv(int i, int argc, char **tab);

/*
**Fonction de liste de base dans les fichiers list.c list2.c list3.c
*/

	/*
	**---------------------list.c-------------------------
	*/

List 	new_list(void);
int 	is_empty(List li);
int 	list_size(List li);
void 	print_list(List li);
void	print_name_list(List li);

	/*
	**---------------------list2.c-------------------------
	*/

List 	push_back(List li, char *full_path, char *name, struct stat file, int parent);
List 	push_front(List li, char *s, char *full_path, struct stat file);
List 	back_up(List li);
List 	back_front(List li);

	/*
	**---------------------list3.c-------------------------
	*/

List 	back_list(List li, List begin);
List 	add_list(List li, List begin, char *s);
List	print_and_free_only_file(List li);

/*
**Fonction pour free dans le fichier free.c
*/

void	free_li(List li);
void	free_li_one(List li);

#endif
