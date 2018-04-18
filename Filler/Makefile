# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgnylyan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/21 17:18:23 by vgnylyan          #+#    #+#              #
#    Updated: 2017/12/21 17:18:29 by vgnylyan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = vgnylyan.filler
C_FILES = main.c check_position.c tools.c creat_map.c data.c creat_token.c \
check_connection.c
O_FILES =  main.o check_position.o tools.o creat_map.o data.o creat_token.o \
check_connection.o
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(O_FILES)
	make -C libft
	gcc $(FLAGS) $(O_FILES) libft/libft.a -I libft/includes -o $(NAME)

$(O_FILES): %.o: %.c
	gcc -c $(FLAGS) $< -I libft/includes -o $@

clean:
	make clean -C libft
	rm -rf $(O_FILES)

fclean: clean
	make fclean -C libft
	rm -rf $(NAME)

re: fclean all

.PHONY: clean all fclean re libft
