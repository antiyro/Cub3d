NAME = cub3D

MAIN = ./srcs/cub3d.c

OBJ_MAIN = ${MAIN:.c=.o}

SRCS =		srcs/cub3d.c srcs/ft_error.c srcs/ft_error2.c srcs/ft_parsing.c \
	 		srcs/ft_tools.c srcs/ft_tools2.c srcs/ft_verify_map.c \
			srcs/ft_verify_params.c srcs/ft_verify_params2.c srcs/get_next_line.c \
			srcs/ft_window.c \

PATH_SRCS = ./

_SRCS = ${addprefix ${PATH_SRCS}, ${SRCS}}

OBJS = ${_SRCS:.c=.o}

LINK = ar rc

CC = clang

FLAGS = -Wall -Werror -Wextra -g3

RM = rm -rf

PATH_HEADER = ./

.c.o:
			${CC} ${FLAGS} -I${PATH_HEADER} -c $< -o ${<:.c=.o}

MYLIB = mylib.a

PATH_MLX_LINUX = ./mlx/

MLX_LINUX = ./mlx/libmlx_Linux.a

all:        ${NAME}

${NAME}:    ${MV} ${OBJ_MAIN} ${OBJS}
			${LINK} ${MYLIB} ${OBJS}
			ranlib ${MYLIB}
			make -C ${PATH_MLX_LINUX}
			${CC} ${FLAGS} -o3 ${OBJ_MAIN} ${MYLIB} ${MLX_LINUX} -lm -lbsd -lX11 -lXext -o ${NAME} srcs/libft/libft.a

clean:
			${RM} ${OBJ_MAIN} ${OBJS}
			make clean -C ${PATH_MLX_LINUX}

fclean:     clean
			${RM} ${NAME} ${MYLIB} ${MLX_LINUX}

re:         fclean all

.PHONY:     all clean fclean re
