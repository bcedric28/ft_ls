# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bcedric <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/14 11:37:49 by bcedric           #+#    #+#              #
#    Updated: 2019/02/09 15:36:15 by sstinglh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

FLAG = -Wall -Wextra -Werror

SOURCE = ft_ls.c affichage_data.c affichage_date.c affichage_maj_min.c \
		affichage_permission.c kernel_option_l.c suite_affichage_permission.c \
		check_hide.c checker.c checker_option.c error.c free.c list.c \
		list2.c list3.c sort_list.c sort_list2.c print.c recursive.c
LIBFT_DIR = Libft/

COMP_OBJ = ./obj/*.o

OBJ_DIR = ./obj
SRC_DIR = ./srcs
INCLUDE = ./includes

GGCOLORCYAN = \033[96m
GGCOLORGREEN = \033[32m
GGCOLORRED = \033[31m
GGMAG = \033[1;35m
GGRESET = \033[39m

SRC = $(addprefix $(SRC_DIR)/, $(SOURCE))
OBJ = $(addprefix $(OBJ_DIR)/, $(subst .c,.o, $(SOURCE)))

all: comp
	@mkdir -p $(OBJ_DIR)
	@make $(NAME)

comp:
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJ)
	@gcc $(FLAG) $(COMP_OBJ) -I $(INCLUDE) -L $(LIBFT_DIR) -lft  -o $(NAME)
	@echo "$(GGCOLORCYAN)Creation$(GGRESET) du binaire $(GGMAG)./ft_ls$(GGRESET)..."
	@echo "$(GGCOLORGREEN)Success!$(GGRESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "[$(GGCOLORGREEN)✔$(GGRESET)] "$(subst .c,,$<)
	@mkdir -p $(dir $@) && gcc $(FLAG) -I $(INCLUDE) -o $@ -c $<

clean:
	@make -C $(LIBFT_DIR) clean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@rm -rf $(NAME)
	@echo "$(GGCOLORRED)Suppresion$(GGRESET) de ft_ls..."

re: fclean all

.PHONY: clean fclean re all
