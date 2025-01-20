# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tboulogn <tboulogn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/03 18:16:41 by tboulogn          #+#    #+#              #
#    Updated: 2025/01/20 13:48:38 by tboulogn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

LIBFT_DIR	= ./libft
PRINTF_DIR	= ./ft_printf

LIBFT	= $(LIBFT_DIR)/libft.a
PRINTF	= $(PRINTF_DIR)/printf.a

RESET 	= \033[0m
VERT 	= \033[1;32m

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

RM 		= rm -f
MAKE	= make

SRCS	= client.c server.c

OBJS	= $(SRCS:%.c=%.o)
					  
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)
	@echo "$(VERT)Program $(NAME) created.$(RESET)"

$(LIBFT):
	$(MAKE) -C ./libft
	@echo "$(VERT)Libft compiled$(RESET)"

$(PRINTF):
	$(MAKE) -C ./ft_printf
	@echo "$(VERT)Printf compiled$(RESET)"

clean:
	$(RM) -r $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean
	@echo "$(VERT)Objects cleaned$(RESET)"

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean
	@echo "$(VERT)All cleaned$(RESET)"

re: fclean all

.PHONY: all clean fclean re