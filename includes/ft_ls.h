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

# define  OPTION_a 1
# define  OPTION_l 2
# define  OPTION_r 4
# define  OPTION_R 8
# define  OPTION_t 16
# define  OPTION_STOP 32
# define  OPTION_END 64

#include "../Libft/includes/libft.h"
#include <stdio.h>
#include <dirent.h>
#include <time.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <stdlib.h>
#include <grp.h>

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
	gid_t group_u;
	char *date;
	uid_t login_u;
	char *full_path;
}ListElement, *List;

List create_child_list(char *path); //On recoit juste le chemin a ouvrir

/*
**Fonction pour le -a dans le fichier option_a.c
*/

List 	option_a(List li);
List 	check_option_a(List li);
int 	is_hide(List li);

/*
**Fonction pour le -l dans le fichier option_l(2 & 3).c et file_perm.c
*/

	/*
	**--------------------file_perm.c-----------------------
	*/

void	affichage_file_perm(List li);
void 	affichage_type_of_f(List li);
char	file_perm2(int i, List li);

	/*
	**---------------------option_l-------------------------
	*/

int		number_of_digit(int max);
void 	count_file_link(List li, List begin);
void	affichage_file_link(int max, List li);
void	login_name(List li, List begin);
void	affichage_file_login(int max, List li);

	/*
	**---------------------option2_l-------------------------
	*/

void	group_name(List li, List begin);
void	affichage_file_group(int max, List li);
void 	file_size(List li, List begin);
void	affichage_file_size(int max, List li);
void 	file_minor_and_major(List li, List begin);
void	main_l(List li, List begin);

	/*
	**---------------------option3_l-------------------------
	*/

void 	file_date(List li);
int		check_6_months(List li, time_t now);
void	affichage_file_date(List li, int i);
void	affichage_file_years(List li, int i);

/*
**Fonction de gestion d'erreur dans le fichier error.c
*/

void	ft_error(char c, int i);
void 	ft_error2(char *s);

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

List 	push_back(List li, char *full_path, char *s, struct stat file);
List 	push_front(List li, char *s, char *full_path, struct stat file);
List 	back_up(List li);
List 	back_front(List li);

	/*
	**---------------------list3.c-------------------------
	*/

List 	back_list(List li, List begin);
List 	add_list(List li, List begin, char *s);
List	print_and_free_only_file(List li);

#endif
