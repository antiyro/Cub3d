# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbouhada <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/23 15:43:21 by nbouhada          #+#    #+#              #
#    Updated: 2021/01/04 14:46:29 by nbouhada         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

GCC		= gcc -Wall -Wextra -Werror

SRC		= ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
ft_isascii.c ft_isdigit.c ft_isprint.c ft_memccpy.c ft_strchr.c ft_itoa.c\
ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_split.c\
ft_strdup.c ft_putstr_fd.c ft_strrchr.c ft_strjoin.c ft_tablen.c\
ft_strlen.c ft_strcmp.c ft_strnstr.c ft_strtrim.c ft_putnbr_fd.c ft_strmapi.c\
ft_substr.c ft_tolower.c ft_toupper.c ft_putchar_fd.c ft_putendl_fd.c\

BONUS	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstdelone.c\
ft_lstclear.c ft_lstiter.c ft_lstadd_back.c ft_lstmap.c

OBJ 	= $(SRC:.c=.o)

OBJBONUS = $(BONUS:.c=.o)

INC		= -I includes/

$(NAME): $(OBJ)
				ar rc $(NAME) $(OBJ)
				ranlib $(NAME)
%.o: %.c
				$(GCC) $(INC) -o $@ -c $?

bonus: $(NAME) $(OBJBONUS)
				ar rcs ${NAME} ${OBJ} ${OBJBONUS}
all: $(NAME)

clean:
				rm -rf $(OBJ) ${OBJBONUS}
fclean: clean
				rm -rf $(NAME)
re: fclean all

.PHONY: clean
