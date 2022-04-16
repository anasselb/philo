# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-bach <ael-bach@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/26 15:29:49 by ael-bach          #+#    #+#              #
#    Updated: 2022/04/15 22:46:01 by ael-bach         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	./philo.c\
		./philo_utils.c\
		./ft_atoi.c\
		./helper.c\

NAME = philo.a
CFLAGS = -Wall -Wextra -Werror 
CC = cc
OBJ = $(SRCS:.c=.o)

all : $(NAME) 

$(NAME): $(OBJ) 
	@ar -rc $(NAME) $(OBJ) 
	@$(CC) $(CFLAGS) $(NAME) -o philo
	
re: fclean all

fclean : clean
	rm  $(NAME) philo
clean:
	rm  *.o
	
.PHONY  : all clean fclean re