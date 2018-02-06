#----- Colors -----
BLACK	= "\033[1;30m"
RED		= "\033[1;31m"
GREEN	= "\033[1;32m"
YELLOW	= "\033[1;33m"
BLUE	= "\033[1;34m"
MAGENTA	= "\033[1;35m"
CYAN	= "\033[1;35m"
PURPLE	= "\033[1;36m"
WHITE	= "\033[1;37m"
RESET	= "\x1b[0m"
#==================

LIBRARY = libft/libft.a

NAME	= fdf
HEAD	= header/vm.h header/op.h

# FLAGS	= -Wall -Wextra -Werror


#------ path -------
FILES_PATH		= ./files
OBJECTS_PATH	= ./objects


#------ mlx --------
MLX				= ./miniLibX/
MLX_LIB			= $(addprefix $(MLX),mlx.a)
MLX_INC			= -I ./miniLibX
MLX_LNK			= -L ./miniLibX -l mlx -framework OpenGL -framework AppKit

#------ files ------
FILES_FILES		= ft_atoi_base ft_for_s_window ft_print_map\
	ft_structs ft_valid_map main


#------ other ------
FILES_OBJ 		= $(addprefix $(OBJECTS_PATH)/, $(addsuffix .o, $(FILES_FILES)))


#------ make ------
all: $(MLX_LIB) $(NAME)

$(NAME): $(FILES_OBJ) 
	@echo "\n"
	@make -C ./libft/
	@echo $(CYAN) "\tCompiling $@"$(RESET)
	@gcc $(FLAGS) $(MLX_LNK) -o $@ $^ $(LIBRARY)
	@echo $(GREEN) "\tfdf\t\t- has been made\n"$(RESET)

$(MLX_LIB):
	make -C $(MLX)

$(OBJECTS_PATH)/%.o: $(FILES_PATH)/%.c
	@echo $(PURPLE) "\tCompiling $<"$(RESET)
	@mkdir $(OBJECTS_PATH) 2> /dev/null || true
	@gcc $(FLAGS) $(MLX_INC) -o $@ -c $<



#------ make clean ------
cleanlib:
	make clean -C ./libft
	make clean -C $(MLX)

clean: cleanlib
	@echo $(YELLOW)"\t\t\t\tFDF"$(RESET)
	@rm -f $(FILES_OBJ)
	@echo $(RED) "\t.o files have been cleaned."$(RESET)
	@rm -rf $(OBJECTS_PATH)
	@echo $(RED) "\t./objects path have been cleaned."$(RESET)

#------ make fclean ------
fcleanlib:
	make fclean -C ./libft
	make clean -C $(MLX)

fclean: fcleanlib
	@echo $(YELLOW)"\t\t\t\tFDF"$(RESET)
	@rm -f $(FILES_OBJ)
	@echo $(RED) "\t.o files have been cleaned."$(RESET)
	@rm -rf $(OBJECTS_PATH)
	@echo $(RED) "\t./objects path have been cleaned."$(RESET)
	@rm -f $(NAME)
	@echo $(RED) "\tfdf have been cleaned.\n"$(RESET)

#------ make re ------
re: fclean all

