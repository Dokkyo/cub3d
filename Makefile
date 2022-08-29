NAME	= cub3d.out

SRCS	= main.c \
				parsing/parse.c \
				parsing/get_identifiers.c \
				parsing/check_identifiers.c \
				parsing/get_map.c \
				parsing/check_map.c \
				utils/array.c \
				utils/cub3d_init.c \
				utils/cub3d_exit.c \
				utils/ft_strcmp.c \
				utils/ft_strcspn.c \
				utils/mlx.c \
				utils/pixel.c

OBJS	= ${SRCS:.c=.o}
OBJS	:= $(addprefix objs/,${OBJS})

FL_MLX	= -ldl -L./mlx_linux -lmlx -Lmlx -lm -lXext -lX11 mlx_linux/libmlx.a

LIBFT = libft/libft.a

all:		${NAME}

$(NAME):	${OBJS}

	@make -C ./mlx_linux
	@make -C ./libft
	@gcc -g -Wall -Wextra -Werror -I includes ${OBJS} -o $(NAME) $(LIBFT) $(FL_MLX)

objs/%.o:	%.c
	@mkdir -p objs
	@gcc -g -Wall -Werror -Wextra -lmlx -lbass -I includes -o $@ -c $<

clean:
	@make -C ./mlx_linux clean
	rm -rf objs
	rm -f libft/*.o

fclean: clean
	@make -C ./mlx_linux clean
	rm -f libft/libft.a
	rm -f ${NAME}

re:		fclean all

.PHONY: all clean fclean re
