# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: labenall <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/27 18:02:17 by labenall          #+#    #+#              #
#    Updated: 2022/05/09 18:32:53 by labenall         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_C = client.c ft_printf.c ft_printf_utlus.c ft_atoi.c

SRC_S = server.c ft_printf.c ft_printf_utlus.c ft_atoi.c

SRC_BONUSC = client_bonus.c ft_printf_bonus.c ft_printf_utlus_bonus.c ft_atoi_bonus.c

SRC_BONUSS = server_bonus.c ft_printf_bonus.c ft_printf_utlus_bonus.c ft_atoi_bonus.c

OBJ_C = ${SRC_C:.c=.o}

OBJ_S = ${SRC_S:.c=.o}

OBJ_BONUSC = ${SRC_BONUSC:.c=.o}

OBJ_BONUSS = ${SRC_BONUSS:.c=.o}

HEADER = minitalk.h

HEADER_BONUS = minitalk_bonus.h

CC = cc

FLAGS = -Wall -Wextra -Werror

CLIENT = client

SERVER = server

CLIENT_BONUS = client_bonus

SERVER_BONUS = server_bonus

all: $(CLIENT) $(SERVER)

bonus: $(CLIENT_BONUS) $(SERVER_BONUS)

$(CLIENT_BONUS): $(OBJ_BONUSC)
	$(CC) $(FLAGS)  $(OBJ_BONUSC) -o $(CLIENT_BONUS) -I $(HEADER_BONUS)

$(SERVER_BONUS): $(OBJ_BONUSS)
	$(CC) $(FALGS)  $(OBJ_BONUSS) -o $(SERVER_BONUS) -I $(HEADER_BONUS)

$(CLIENT): $(OBJ_C)
	$(CC) $(FLAGS)  $(OBJ_C) -o $(CLIENT) -I $(HEADER)

$(SERVER): $(OBJ_S)
	$(CC) $(FALGS)  $(OBJ_S) -o $(SERVER) -I $(HEADER)

clean:
	rm -rf $(OBJ_C) $(OBJ_S) $(OBJ_BONUSC) $(OBJ_BONUSS)
fclean: clean
	rm -rf  $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)

re: fclean all

.PHONY: all clean fclean re
