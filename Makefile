# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asaenko <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/21 16:53:37 by asaenko           #+#    #+#              #
#    Updated: 2024/06/21 18:27:05 by asaenko          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SERVER_SRC = server.c

CLIENT_SRC = client.c

LIBFT = libft/libft.a

FT_PRINTF = ft_printf/libftprintf.a

SERVER_NAME = server

CLIENT_NAME = client

all: $(SERVER_NAME) $(CLIENT_NAME)

$(SERVER_NAME): $(SERVER_SRC) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(SERVER_SRC) $(LIBFT) $(FT_PRINTF) -o $(SERVER_NAME)

$(CLIENT_NAME): $(CLIENT_SRC) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(CLIENT_SRC) $(LIBFT) $(FT_PRINTF) -o $(CLIENT_NAME)

$(LIBFT):
	make -C libft

$(FT_PRINTF):
	make -C ft_printf

clean:
	make clean -C libft
	make clean -C ft_printf

fclean: clean
	make fclean -C libft
	make fclean -C ft_printf
	rm -f $(SERVER_NAME) $(CLIENT_NAME)

re: fclean all

.PHONY: all clean fclean re


