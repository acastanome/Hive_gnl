#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acastano <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/18 14:58:21 by acastano          #+#    #+#              #
#    Updated: 2022/01/18 16:37:09 by acastano         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = clang

CFLAGS = -Wall -Wextra -Werror

NAME = test_gnl

SRCS = main.c
SRCS2 = get_next_line.c

HEADERS = libft.h get_next_line.h

OBJ = $(SRCS:.c=.o)
OBJ2 = $(SRCS2:.c=.o)

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -c $(SRCS2) -I $(HEADERS)
	$(CC) $(CFLAGS) -c $(SRCS) -I $(HEADERS)
	$(CC) -o $(NAME) $(OBJ) $(OBJ2) -I libft/libft.h -L libft/ -lft

clean:
	/bin/rm -f $(OBJ) *.c~ *.h~

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY = all clean fclean re
