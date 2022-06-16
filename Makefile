# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yel-aoun <yel-aoun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/13 09:55:40 by yel-aoun          #+#    #+#              #
#    Updated: 2022/06/16 12:34:00 by yel-aoun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRC = pipex.c src/exec_pipex.c src/ft_split.c src/ft_strjoin.c \
	src/ft_strncmpr.c src/ft_substr.c src/utiles.c

CC = cc -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

all :$(NAME)

$(NAME) : $(OBJ)
	$(CC) $(SRC) -o $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
