# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-bach <ael-bach@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/26 15:29:49 by ael-bach          #+#    #+#              #
#    Updated: 2022/04/15 23:05:07 by ael-bach         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	./philo_bonus.c\
		./ft_atoi.c\
		./creation_of_process.c\
		./philo_bonus_utils.c\

NAME = philo.a
CFLAGS = -Wall -Werror -Wextra
CC = cc
OBJ = $(SRCS:.c=.o)
all : $(NAME) 

$(NAME): $(OBJ)
	@ar -rc $(NAME) $(OBJ) 
	@$(CC)  $(CFLAGS) $(NAME) -o philo_bonus
	
re: fclean all

fclean : clean
	rm  $(NAME) philo_bonus
clean:
	rm  *.o
	
.PHONY  : all clean fclean re