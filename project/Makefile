NAME = fdf
SRC = func/main.c func/ft_valid_map.c func/ft_structs.c func/ft_for_s_window.c func/ft_atoi_base.c func/ft_print_map.c
OBJ = $(SRC:.c=.o)
HEAD = fdf.h
FLAGS = -Wall -Wextra -Werror
LIB = libft.a

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	gcc -o $(NAME) -lmlx -framework OpenGL -framework AppKit $(OBJ) libft/*.o
	@echo fdf has been made

%.o: %.c
		gcc $(FLAGS) -c -o  $@ $<	

cleanlib:
	make clean -C ./libft

fcleanlib:
	make fclean -C ./libft

clean: cleanlib
	rm -f $(OBJ)
	@echo *.o have been cleaned.

fclean: clean fcleanlib
	rm -f $(NAME)
	@echo *.a and *.o have been cleaned.

re: fclean all
	
