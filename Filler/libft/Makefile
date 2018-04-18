NAME = libft.a
C_FILES = ft_lstadd.c ft_memcpy.c ft_putstr.c ft_striteri.c ft_strnrev.c \
ft_lstdel.c ft_memdel.c ft_putstr_fd.c	ft_strjoin.c ft_strnstr.c ft_atoi.c \
ft_lstdelone.c ft_memmove.c ft_strcat.c ft_strlcat.c ft_strrchr.c ft_bzero.c \
ft_lstiter.c ft_memset.c	ft_strchr.c	ft_strlen.c ft_strrev.c ft_countwords.c	\
ft_lstlast.c ft_nbrlen.c ft_strclr.c ft_strmap.c ft_strsplit.c ft_isalnum.c \
ft_lstmap.c ft_putchar.c ft_strcmp.c ft_strmapi.c ft_strstr.c ft_isalpha.c \
ft_lstnew.c ft_putchar_fd.c ft_strcpy.c ft_strncat.c ft_strsub.c ft_isascii.c \
ft_memalloc.c ft_putendl.c	ft_strdel.c	ft_strncmp.c ft_strtrim.c ft_isdigit.c \
ft_memccpy.c ft_putendl_fd.c ft_strdup.c ft_strncpy.c ft_tolower.c ft_isprint.c \
ft_memchr.c ft_putnbr.c ft_strequ.c ft_strnequ.c ft_toupper.c ft_itoa.c \
ft_memcmp.c ft_putnbr_fd.c	ft_striter.c ft_strnew.c ft_putstr_len.c \
add_flags.c check_index_flag.c check_size.c formating_string.c ft_printf.c \
ft_wcrtomb.c index_grille.c index_plus.c	index_point.c index_space.c index_width.c \
index_zero.c itoa_base_minus.c itoa_base_plus.c print_number.c print_string.c tools.c \
unicode.c get_next_line.c
O_FILES = ft_lstadd.o ft_memcpy.o ft_putstr.o ft_striteri.o ft_strnrev.o \
ft_lstdel.o ft_memdel.o ft_putstr_fd.o	ft_strjoin.o ft_strnstr.o ft_atoi.o \
ft_lstdelone.o ft_memmove.o ft_strcat.o ft_strlcat.o ft_strrchr.o ft_bzero.o \
ft_lstiter.o ft_memset.o	ft_strchr.o	ft_strlen.o ft_strrev.o ft_countwords.o	\
ft_lstlast.o ft_nbrlen.o ft_strclr.o ft_strmap.o ft_strsplit.o ft_isalnum.o \
ft_lstmap.o ft_putchar.o ft_strcmp.o ft_strmapi.o ft_strstr.o ft_isalpha.o \
ft_lstnew.o ft_putchar_fd.o ft_strcpy.o ft_strncat.o ft_strsub.o ft_isascii.o \
ft_memalloc.o ft_putendl.o	ft_strdel.o	ft_strncmp.o ft_strtrim.o ft_isdigit.o \
ft_memccpy.o ft_putendl_fd.o ft_strdup.o ft_strncpy.o ft_tolower.o ft_isprint.o \
ft_memchr.o ft_putnbr.o ft_strequ.o ft_strnequ.o ft_toupper.o ft_itoa.o \
ft_memcmp.o ft_putnbr_fd.o	ft_striter.o ft_strnew.o ft_putstr_len.o \
add_flags.o check_index_flag.o check_size.o formating_string.o ft_printf.o \
ft_wcrtomb.o index_grille.o index_plus.o	index_point.o index_space.o index_width.o \
index_zero.o itoa_base_minus.o itoa_base_plus.o print_number.o print_string.o tools.o \
unicode.o get_next_line.o
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(O_FILES): %.o: srcs/%.c
	gcc -c $(FLAGS) $< -I includes -o $@

$(NAME): $(O_FILES)
	ar rc $(NAME) $(O_FILES)

clean:
	rm -rf $(O_FILES)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean all fclean re