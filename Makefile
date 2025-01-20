# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tboulogn <tboulogn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/03 18:16:41 by tboulogn          #+#    #+#              #
#    Updated: 2025/01/20 16:24:05 by tboulogn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

LIBFT_DIR	= libft
PRINTF_DIR	= ft_printf

LIBFT	= $(LIBFT_DIR)/libft.a
PRINTF	= $(PRINTF_DIR)/printf.a

RESET 	= \033[0m
VERT 	= \033[1;32m

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

RM 		= rm -f
MAKE	= make

CLIENT = client
SERVER = server

CLIENT_SRCS = client.c
SERVER_SRCS = server.c

CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)
SERVER_OBJS = $(SERVER_SRCS:.c=.o)

all: $(CLIENT) $(SERVER)

$(CLIENT): $(CLIENT_OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) $(LIBFT) $(PRINTF) -o $(CLIENT)
	@echo "$(VERT)Client created.$(RESET)"

$(SERVER): $(SERVER_OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(SERVER_OBJS) $(LIBFT) $(PRINTF) -o $(SERVER)
	@echo "$(VERT)Server created.$(RESET)"

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)
	@echo "$(VERT)Libft compiled$(RESET)"

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)
	@echo "$(VERT)Printf compiled$(RESET)"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(CLIENT_OBJS) $(SERVER_OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean
	@echo "$(VERT)Objects cleaned$(RESET)"

fclean: clean
	$(RM) $(CLIENT) $(SERVER)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean
	@echo "$(VERT)All cleaned$(RESET)"

re: fclean all

.PHONY: all clean fclean re