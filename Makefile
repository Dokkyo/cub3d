NAME = cub3d.out
CC = clang
PARAMS = -Wall -Wextra -Werror

INC_PATH = includes/
SRC_PATH = ./
OBJ_PATH = obj/

INC_NAME = cub3d.h
MINILIBX_LIB_PATH = ./mlx_linux/libmlx_Linux.a
LIBFT_LIB_PATH = ./libft/libft.a
SRC_NAME =	main.c \
			parsing/get_identifiers.c \
			parsing/parse.c \
			utils/array.c \
			utils/cub3d_init.c \
			utils/cub3d_exit.c \
			utils/ft_strcmp.c \
			utils/ft_strcspn.c \
			utils/mlx.c \
			utils/pixel.c

LIBX_LINUX_FLAGS = -lm -lbsd -lX11 -lXext

OBJ_NAME= $(SRC_NAME:.c=.o)

INC= -I inc/ -I libft/
SRC= $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ= $(addprefix $(OBJ_PATH), $(OBJ_NAME))

DEF= \033[0m
RED= \033[31;1m
GRN= \033[32;1m
YEL= \033[33;1m

.PHONY: all clean fclean re
all: logo $(NAME)

$(NAME): $(OBJ)
	@echo "$(RED)[cub3d] : $(DEF)Compilation..."
	@make -C libft
	@make -C mlx_linux
	@$(CC) $(PARAMS) $(OBJ) $(LIBFT_LIB_PATH) $(MINILIBX_LIB_PATH) ${LIBX_LINUX_FLAGS} -o $(NAME) $(INC) -L libft/
	@echo "$(RED)[cub3d] : $(DEF)Compilation                 $(GRN)[OK]$(DEF)"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@echo "$(RED)[cub3d] :$(DEF) Compiling $@"
	@$(CC) $(PARAMS) $(INC) -o $@ -c $<

clean:
	@make -C libft clean
	@make -C mlx_linux clean
	@rm -rf $(OBJ_PATH)
	@echo "$(RED)[cub3d] : $(DEF)Cleaning                    $(GRN)[OK]$(DEF)"

fclean: clean
	@make -C libft fclean
	@make -C mlx_linux clean
	@rm -rf $(NAME)
	@echo "$(RED)[cub3d] : $(DEF)Full Cleaning               $(GRN)[OK]$(DEF)"           $(GRN)[OK]$(DEF)"

logo:
	@echo ""
	@echo "\033[38;2;255;126;255m    ::::::: :::    ::: :::::::::  :::::::   ::::::::: "
	@echo "\033[38;2;255;105;255m  +:        :+:    :+: :+:    :+:       :+  :+:     :+ "
	@echo "\033[38;2;255;084;255m +:         +:+    +:+ +:+    +:+       +:+ +:+     +:+ "
	@echo "\033[38;2;255;063;255m :#         +#+    +:+ :#::++::#      +::#  :#:     :#: "
	@echo "\033[38;2;255;042;255m +#         +#+    +#+ +#+    +#+       +#+ +#+     +#+ "
	@echo "\033[38;2;255;021;255m  +#        #+#    #+# #+#    #+#       #+  #+#     #+ "
	@echo "\033[38;2;255;000;255m    #######  ########  #########  #######   ######### "
	@echo "\033[0m"

re: fclean all
