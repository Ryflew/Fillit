# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vdarmaya <vdarmaya@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/15 15:29:54 by vdarmaya          #+#    #+#              #
#    Updated: 2016/12/08 06:06:40 by vdarmaya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
FLAGS = -Wall -Wextra -Werror
LIBDIR = ./srcs/libft/
SRCDIR = ./srcs/

SRC = main.c \
 		check_validity.c \
 		get_next_line.c \
		chained_lists.c \
		map.c \
		tetri.c \
		solver.c

SRCS = $(addprefix $(SRCDIR), $(SRC))

all: $(NAME)

$(NAME):
	@make -C $(LIBDIR)
	@gcc $(FLAGS) $(SRCS) -o $(NAME) -L $(LIBDIR) -l ft -g
	@echo "Fillit - Compilation Done"

clean:
	@make clean -C $(LIBDIR)
	@echo "Fillit - Clean Done"

fclean: clean
	@make fclean -C $(LIBDIR)
	@rm -rf $(NAME)
	@echo "Fillit - Fclean Done"

re: fclean all

.PHONY: $(NAME) $(clean) $(fclean) $(re)
