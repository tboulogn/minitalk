# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tboulogn <tboulogn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 12:08:02 by tboulogn          #+#    #+#              #
#    Updated: 2025/01/15 13:40:22 by tboulogn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printf.a
SRC = ft_printf.c ft_numbers.c ft_letters.c
		
OBJ = $(SRC:.c=.o)
CC = cc
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME) : $(OBJ) 
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@ 

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 