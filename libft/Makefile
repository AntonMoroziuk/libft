# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/28 11:09:27 by amoroziu          #+#    #+#              #
#    Updated: 2018/10/31 13:09:31 by amoroziu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

all: $(NAME)

$(NAME):
	gcc -Wall -Werror -Wextra -c *.c
	ar rc $(NAME) *.o
clean:
	rm -f *.o
fclean: clean
	rm -f $(NAME)
re: fclean all
