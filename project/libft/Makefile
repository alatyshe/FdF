SRC = ft_atoi.c ft_lstmap.c ft_putstr.c ft_strmapi.c ft_lstmap.c	ft_putstr_fd.c\
		ft_strncat.c ft_lstnew.c ft_strcat.c ft_strncmp.c ft_bzero.c ft_memalloc.c\
		ft_strchr.c ft_strncpy.c ft_isalnum.c ft_memccpy.c ft_strclr.c ft_strndup.c\
		ft_isalpha.c ft_memchr.c ft_strcmp.c ft_strnequ.c ft_isascii.c ft_memcmp.c\
		ft_strcpy.c ft_strnew.c ft_isblank.c ft_memcpy.c ft_strdel.c ft_strnstr.c\
		ft_isdigit.c ft_memdel.c ft_strdup.c ft_strrchr.c ft_isnumber.c ft_memmove.c\
		ft_strequ.c ft_strsplit.c ft_isprint.c ft_memset.c ft_striter.c ft_strstr.c\
		ft_isupper.c ft_putchar.c ft_striteri.c ft_strsub.c ft_itoa.c ft_putchar_fd.c\
		ft_strjoin.c ft_strtrim.c ft_lstadd.c ft_putendl.c ft_strlcat.c ft_tolower.c\
		ft_lstdel.c ft_putendl_fd.c ft_lst_size.c ft_toupper.c ft_lstdelone.c\
		ft_putnbr.c ft_strlen.c ft_lstiter.c ft_putnbr_fd.c ft_strmap.c\
		get_next_line.c

HEAD = libft.h
NAME = libft.a
FLAGS = -Wall -Wextra -Werror
OBJ = $(SRC:.c=.o)

all: $(NAME)
$(NAME): $(OBJ)

	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	@echo libft.a has been made
%.o: %.c
	gcc $(FLAGS) -c -o $@ $< 
clean:
	rm -f $(OBJ)
	@echo *.o have been cleaned.
fclean: clean
	rm -f $(NAME)
	@echo *.a and *.o have been cleaned.
re: fclean all
