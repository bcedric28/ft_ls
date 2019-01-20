# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bcedric <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/14 11:37:49 by bcedric           #+#    #+#              #
#    Updated: 2019/01/17 15:34:40 by bcedric          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

FLAG = -Wall -Wextra

SOURCE = ft_ls.c error.c checker.c list.c

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
