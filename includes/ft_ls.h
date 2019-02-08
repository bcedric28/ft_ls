/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcedric <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 13:43:03 by bcedric           #+#    #+#             */
/*   Updated: 2019/02/07 21:12:20 by bcedric          ###   ########.fr       */
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

typedef struct			s_element
{
	char				*name;
	struct stat			fileinfo;
	struct s_element	*next;
	char				*login;
	char				*group;
	char				*full_path;
	char				*date;
	int					max_login;
	int					max_group;
	int					size;
	int					size_max;
	int					parent;
}						t_element;

t_element				*create_child_list(char *path, int parent);
int						check_perm(char *path);
void					affichage(t_element *li, char *path, int i);
void					affichage_xattr_acl(t_element *li, int *total);
int						total_block(t_element *begin);
void					fill_noodle_data(t_element *begin, int *tab);
t_element				*data_noodle(t_element *begin);
/*
** Fonction pour le -a dans le fichier option_a.c
*/
int						is_hide(t_element *li);

/*
** Fonction pour le -l dans le fichier option_l(2 & 3).c et file_perm.c
*/

/*
** --------------------file_perm.c-----------------------
*/

void					kernel_of_file_perm(t_element *li);
void					affichage_type(t_element *li);
char					affichage_perm(int i, t_element *li);
char					affichage_perm_usr(int i, t_element *li);
char					affichage_perm_group(int i, t_element *li);
char					affichage_perm_other(int i, t_element *li);

/*
** ---------------------option_l-------------------------
*/

int						number_of_digit(int max);
void					count_file_link(t_element *li, t_element *begin, int *total);
void					affichage_file_link(int max, t_element *li, int *total);
t_element				*login_name(t_element *begin);
void					affichage_file_login(t_element *li);

/*
** ---------------------option2_l-------------------------
*/

void					affichage_file_group(t_element *li);
void					affichage_file_size(t_element *li, int *total);
void					file_minor_and_major(t_element *begin, int *total);
void					affichage_minor(t_element *li, int min);
void					affichage_major(t_element *li, int max);
void					main_l(t_element *li, t_element *begin, int *total);

/*
** ---------------------option3_l-------------------------
*/

void					file_date(t_element *li);
int						check_6_months(t_element *li, time_t now);
void					affichage_file_date(t_element *li, int i);
void					affichage_file_years(t_element *li, int i);
int						total_block(t_element *begin);

/*
** Fonction de gestion d'erreur dans le fichier error.c
*/

void					ft_error(char c, int i);
void					ft_error2(char *s, int j);
void					ft_error3(char *s, int end, int j, t_element *parent);

/*
**Fonction de check d'arguments dans checker.c et dans checker_option.c
*/

/*
** ---------------------checker.c--------------------------------
*/

void					check_arguments_b0(char **s1, int argc);
t_element				*check_directory(int i, int argc, char **argv, t_element *li);
t_element				*put_in_list(char *str, t_element *li, struct stat file);
int						dirtrue(char *s1, struct stat *file);

/*
** ---------------------checker_option.c-------------------------
*/

int						check_option(char **s1, int argc);
void					option(char *s1);
int						turn_on_option(char option);

/*
**Fonction de trie de argv et la liste selon les option demander dans le fichier sort_list.c
*/

t_element				*check_sort_list_ascci(t_element *li);
t_element				*check_sort_list_reverse(t_element *li);
t_element				*check_sort_list_time(t_element *li);
void					sort_argv(int i, int argc, char **tab);

/*
**Fonction de liste de base dans les fichiers list.c list2.c list3.c
*/

/*
** ---------------------list.c-------------------------
*/

t_element				*new_list(void);
int						is_empty(t_element *li);
int						list_size(t_element *li);
void					print_list(t_element *li);
void					print_name_list(t_element *li);

/*
** ---------------------list2.c-------------------------
*/
t_element				*new_elemente(char *name, char *full_path, struct stat file, int parent);
t_element				*push_back(t_element *li, t_element *new_element);
t_element				*push_front(t_element *li, char *s, char *full_path, struct stat file);
t_element				*back_up(t_element *li);
t_element				*back_front(t_element *li);

/*
**---------------------list3.c-------------------------
*/

t_element				*back_list(t_element *li, t_element *begin);
t_element				*print_and_free_only_file(t_element *li);

/*
**Fonction pour free dans le fichier free.c
*/

void					free_li(t_element *li);
void					free_li_one(t_element *li);

#endif
