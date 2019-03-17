#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amartyne <amartyne@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/03 15:38:36 by amartyne          #+#    #+#              #
#    Updated: 2019/03/03 15:38:37 by amartyne         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

COLOR_OFF=\033[0m#			# Text Reset
BLACK	=\033[0;30m#		# Black
RED		=\033[0;31m#		# Red
GREEN	=\033[0;32m#		# Green
YELLOW	=\033[0;33m#		# Yellow
BLUE	=\033[0;34m#		# Blue
PURPLE	=\033[0;35m#		# Purple
CYAN	=\033[0;36m#		# Cyan
WHITE	=\033[0;37m#		# White

CC=		gcc

FLAGS=	-Wall -Wextra -Werror

NAME=	fractol

SRC_NAME =	fractol.c formulas.c action.c mult.c formulas2.c formulas3.c\
formulas4.c action2.c

INCLD=		fractol.h

INCLD_DIR	=./incl/
SRC_DIR		=./src/
OBJ_DIR		=./obj/

OBJ_NAME= $(SRC_NAME:%.c=%.o)
SRC=$(addprefix $(SRC_DIR), $(SRC_NAME))
OBJ=$(addprefix $(OBJ_DIR), $(OBJ_NAME))

LIBFT= ./src/libft/libft.a

OK_STRING    =***	$(NAME) created		***

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) -lmlx -framework OpenGL -framework AppKit -lpthread $(OBJ) -o $(NAME) -I $(INCLD_DIR) $(LIBFT)
	@printf "\n$(GREEN)$(OK_STRING)\n\n"

$(OBJ_DIR)%.o:$(SRC_DIR)%.c $(addprefix $(INCLD_DIR), $(INCLD)) $(LIBFT)
	@$(CC) $(FLAGS) -c $< -I $(INCLD_DIR) -o $@
	@printf "$(CYAN)*$(COLOR_OFF)"

$(LIBFT):
	@$(MAKE) -C ./src/libft
	@printf "\n$(GREEN)libft created $(COLOR_OFF)\n\n"

clean:
	@rm -f $(OBJ)
	@$(MAKE) clean -C ./src/libft
	@printf  "$(YELLOW)remove OBJ\n"

fclean:
	@printf "$(YELLOW)remove OBJ$(COLOR_OFF)\n"
	@$(MAKE) fclean -C ./src/libft
	@rm -f $(OBJ)
	@printf "$(RED)remove $(NAME)$(COLOR_OFF)\n"
	@rm -f $(NAME)
	@printf "$(RED)remove $(NAME2)$(COLOR_OFF)\n"
	@rm -f $(NAME2)

re: fclean all