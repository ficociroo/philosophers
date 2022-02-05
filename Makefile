# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/21 10:42:53 by mde-figu          #+#    #+#              #
#    Updated: 2022/02/04 23:10:19 by cfico-vi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosophers

CFLAGS = -Wall -Wextra -Werror
INCLUDES = ./includes/philosophers.h .libraries/libft/libft.h
LIBFT = libraries/libft

SRC_PATH =	./source \

SRC =		main.c \

OBJ_DIR	=	./builds
OBJ		=	$(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC))

vpath %.c $(SRC_PATH)

all: $(NAME)

$(NAME): $(OBJ)
		make -C $(LIBFT)
		gcc $(CFLAGS) -g3 -o $(NAME) $(OBJ) -L $(LIBFT) -lft -I includes

$(OBJ_DIR)/%.o:	%.c ./includes/philosophers.h
	mkdir -p $(OBJ_DIR)
	gcc -c -o $@ $(CFLAGS) -I includes -g3 $<

git:
	@git add .
	@git commit -m "$m"
	@git push
#make git m="blablabla"

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all --suppressions=readline.supp ./philosophers

clean:
		make clean -C $(LIBFT)
		rm -f $(OBJ)
		rm -rf ./buldis

fclean: clean
		make fclean -C $(LIBFT)
		rm -f $(NAME) $(OBJ)

re: fclean all
