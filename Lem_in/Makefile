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
NAME = lem-in

C_FILES = main.c create_rooms_number.c read_output.c  tools.c validation.c find_way.c put_way.c \
		struct_tools.c info.c check_finish_way.c create_rooms_links.c create_rooms_data.c

O_FILES = $(C_FILES:.c=.o)

LIB = libft/libft.a

FLAGS = -Wall -Wextra -Werror

all: lib $(NAME)

$(NAME): $(O_FILES) $(LIB)
	gcc $(FLAGS) -o $(NAME) $(O_FILES) $(LIB)

.c.o:
	gcc $(FLAGS) -c $<

lib:
	make -C libft

clean:
	make clean -C libft
	rm -rf $(O_FILES)

fclean: clean
	make fclean -C libft
	rm -rf $(NAME)

re: fclean all

.PHONY: clean all fclean re libft