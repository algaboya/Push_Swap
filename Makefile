# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: algaboya <algaboya@student.42yerevan.am    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/07 17:10:33 by algaboya          #+#    #+#              #
#    Updated: 2024/07/11 17:17:51 by algaboya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CFLAGS = -Wall -Wextra -Werror

SRC = main.c validation.c parsing.c for_array.c utils.c my_stack.c push.c rotate.c rev_rotate.c swap.c lit_sort.c babochka.c utilss.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):$(OBJ) push_swap.h Makefile
	cc $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ) $(BNOBJ)

fclean:clean
	rm -f $(NAME)

re:fclean all

.PHONY: all clean fclean re
