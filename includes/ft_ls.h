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

typedef struct	s_el
{
	char		*name;
	struct stat	fileinfo;
	struct s_el	*next;
	char		*login;
	char		*group;
	char		*full_path;
	char		*date;
	int			max_login;
	int			max_group;
	int			size;
	int			size_max;
	int			parent;
}				t_elem;
void			parent_to_childe(t_elem *parent, char *path2, int i);
t_elem			*create_child_list(char *path, int parent);
int				check_perm(char *path);
void			affichage(t_elem *li, char *path, int i);
void			affichage_xattr_acl(t_elem *li, int *total);
int				total_block(t_elem *begin);
void			fill_noodle_data(t_elem *begin, int *tab);
t_elem			*data_noodle(t_elem *begin);
/*
** Fonction pour le -a dans le fichier option_a.c
*/
int				is_hide(t_elem *li);

/*
** Fonction pour le -l dans le fichier option_l(2 & 3).c et file_perm.c
*/

/*
** --------------------file_perm.c-----------------------
*/

void			kernel_of_file_perm(t_elem *li);
void			affichage_type(t_elem *li);
char			affichage_perm(int i, t_elem *li);
char			affichage_perm_usr(int i, t_elem *li);
char			affichage_perm_group(int i, t_elem *li);
char			affichage_perm_other(int i, t_elem *li);
/*
** ---------------------option_l-------------------------
*/

int				number_of_digit(int max);
void			count_file_link(t_elem *li, t_elem *begin, int *total);
void			affichage_file_link(int max, t_elem *li, int *total);
t_elem			*login_name(t_elem *begin);
void			affichage_file_login(t_elem *li);

/*
** ---------------------option2_l-------------------------
*/

void			affichage_file_group(t_elem *li);
void			affichage_file_size(t_elem *li, int *total);
void			file_minor_and_major(t_elem *begin, int *total);
void			affichage_minor(t_elem *li, int min);
void			affichage_major(t_elem *li, int max);
void			main_l(t_elem *li, t_elem *begin, int *total);

/*
** ---------------------option3_l-------------------------
*/

void			file_date(t_elem *li);
int				check_6_months(t_elem *li, time_t now);
void			affichage_file_date(t_elem *li, int i);
void			affichage_file_years(t_elem *li, int i);
int				total_block(t_elem *begin);

/*
** Fonction de gestion d'erreur dans le fichier error.c
*/

void			ft_error(char c, int i);
void			ft_error2(char *s, int j);
void			ft_error3(char *s, int end, int j, t_elem *parent);

/*
**Fonction de check d'arguments dans checker.c et dans checker_option.c
*/

/*
** ---------------------checker.c--------------------------------
*/

t_elem			*check_directory(int i, int argc, char **argv, t_elem *li);
t_elem			*put_in_list(char *str, t_elem *li, struct stat file);
int				dirtrue(char *s1, struct stat *file);

/*
** ---------------------checker_option.c-------------------------
*/

int				check_option(char **s1, int argc);
void			option(char *s1);
int				turn_on_option(char option);

/*
**Trie de argv et la liste selon les option demander dans le fichier sort_list.c
*/


void			sort_argv(int i, int argc, char **tab);
t_elem			*check_sort_list_time(t_elem *li);
t_elem			*check_sort_list_reverse(t_elem *li);
t_elem			*check_option_sort(t_elem *li, t_elem *j);
void			swap_value(t_elem *li, t_elem *li_next);


t_elem			*while_li(t_elem *li, t_elem *begin, int size, t_elem *te_next);
t_elem			*check_sort_list_ascci(t_elem *li);
/*
**Fonction de liste de base dans les fichiers list.c list2.c list3.c
*/

/*
** ---------------------list.c-------------------------
*/

t_elem			*new_list(void);
int				is_empty(t_elem *li);
int				list_size(t_elem *li);
void			print_list(t_elem *li);
void			print_name_list(t_elem *li);

/*
** ---------------------list2.c-------------------------
*/
t_elem			*new_elem(char *name, char *f_path, struct stat f, int parent);
t_elem			*push_back(t_elem *li, t_elem *new_element);
t_elem			*push_front(t_elem *li, char *s, char *f_path, struct stat f);
t_elem			*back_up(t_elem *li);
t_elem			*back_front(t_elem *li);

/*
**---------------------list3.c-------------------------
*/

t_elem			*back_list(t_elem *li, t_elem *begin);
t_elem			*print_and_free_only_file(t_elem *li);

/*
**Fonction pour free dans le fichier free.c
*/

void			free_li(t_elem *li);
void			free_li_one(t_elem *li);




#endif
