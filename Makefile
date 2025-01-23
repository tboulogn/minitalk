# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tboulogn <tboulogn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/03 18:16:41 by tboulogn          #+#    #+#              #
#    Updated: 2025/01/23 16:04:14 by tboulogn         ###   ########.fr        #
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
	@$(CC) $(CFLAGS) $(CLIENT_OBJS) $(LIBFT) $(PRINTF) -o $(CLIENT)
	@echo "$(VERT)Client created successfully.$(RESET)"

$(SERVER): $(SERVER_OBJS) $(LIBFT) $(PRINTF)
	@$(CC) $(CFLAGS) $(SERVER_OBJS) $(LIBFT) $(PRINTF) -o $(SERVER)
	@echo "$(VERT)Server created successfully.$(RESET)"

$(LIBFT):
	@$(MAKE) -s -C $(LIBFT_DIR)
	@echo "$(VERT)Libft compiled successfully.$(RESET)"

$(PRINTF):
	@$(MAKE) -s -C $(PRINTF_DIR)
	@echo "$(VERT)Printf compiled successfully.$(RESET)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(CLIENT_OBJS) $(SERVER_OBJS)
	@$(MAKE) -s -C $(LIBFT_DIR) clean
	@$(MAKE) -s -C $(PRINTF_DIR) clean
	@echo "$(VERT)Intermediate files cleanned.$(RESET)"

fclean: clean
	@$(RM) $(CLIENT) $(SERVER)
	@$(MAKE) -s -C $(LIBFT_DIR) fclean
	@$(MAKE) -s -C $(PRINTF_DIR) fclean
	@echo "$(VERT)All files cleaned.$(RESET)"

re: fclean all

.PHONY: all clean fclean re