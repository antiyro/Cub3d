NAME =		cub3d

SRCS =		srcs/cub3d.c srcs/ft_error.c srcs/ft_error2.c srcs/ft_parsing.c \
	 		srcs/ft_tools.c srcs/ft_tools2.c srcs/ft_verify_map.c \
			srcs/ft_verify_params.c srcs/ft_vrify_params2.c srcs/get_next_line.c \

OBJS =		${_SRCS:.c=.o}

FLAGS =		-Wall -Wextra -Werror

LIBFT =		srcs/libft

MLX_DIR = mlx
MLX = libmlx.a

.c.o:
			@clang ${FLAGS} -I${./} -c $< -o ${<:.c=.o}

all :
		${NAME}

$(NAME): $(OBJS)
		${CC} $(CFLAGS) -o $(NAME) $(OBJ) -L $(MLX_DIR) -lmlx -lm -lbsd -lX11 -lXext

fclean:		clean
				@rm -rf ${NAME} ${MYLIB} ${MLX}

re:			fclean all

.PHONY:		all clean fclean re
