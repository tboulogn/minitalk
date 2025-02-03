# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tboulogn <tboulogn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/03 18:16:41 by tboulogn          #+#    #+#              #
#    Updated: 2025/02/03 10:44:56 by tboulogn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

PRINTF_DIR	= ft_printf

PRINTF	= $(PRINTF_DIR)/printf.a

RESET 	= \033[0m
VERT 	= \033[1;32m

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g

RM 		= rm -f
MAKE	= make

CLIENT = client
SERVER = server
UTILITARIES = utilitaries

CLIENT_SRCS = client.c
SERVER_SRCS = server.c
UTILITARIES_SRCS = utilitaries.c 

CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)
SERVER_OBJS = $(SERVER_SRCS:.c=.o)
UTILITARIES_OBJS = $(UTILITARIES_SRCS:.c=.o)

all: $(CLIENT) $(SERVER)

$(CLIENT): $(CLIENT_OBJS) $(UTILITARIES_OBJS) $(PRINTF)
	@$(CC) $(CFLAGS) $(CLIENT_OBJS) $(UTILITARIES_OBJS) $(PRINTF) -o $(CLIENT)
	@echo "$(VERT)Client created successfully. Start with ./ client <PID> <message>$(RESET)"

$(SERVER): $(SERVER_OBJS) $(UTILITARIES_OBJS) $(PRINTF)
	@$(CC) $(CFLAGS) $(SERVER_OBJS) $(UTILITARIES_OBJS) $(PRINTF) -o $(SERVER)
	@echo "$(VERT)Server created successfully. Start with ./server$(RESET)"

$(PRINTF):
	@$(MAKE) -s -C $(PRINTF_DIR)
	@echo "$(VERT)Printf compiled successfully.$(RESET)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(CLIENT_OBJS) $(UTILITARIES_OBJS) $(SERVER_OBJS)
	@$(MAKE) -s -C $(PRINTF_DIR) clean
	@echo "$(VERT)Intermediate files cleanned.$(RESET)"

fclean: clean
	@$(RM) $(CLIENT) $(UTILITARIES_OBJS) $(SERVER)
	@$(MAKE) -s -C $(PRINTF_DIR) fclean
	@echo "$(VERT)All files cleaned.$(RESET)"

re: fclean all

.PHONY: all clean fclean re