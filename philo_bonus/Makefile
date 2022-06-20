# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkim2 <mkim2@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/20 16:24:03 by mkim2             #+#    #+#              #
#    Updated: 2022/06/20 16:24:05 by mkim2            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PHILO	=	philo
PHILO_BONUS		=	philo_bonus

CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
RM 		=	rm -f

SRC_DIR	=	./srcs/
SRCS	=	argc_handle.c init.c main.c philo_state.c\
 			philos.c print_utils.c routine.c time_utils.c utils.c

OBJS	=	$(SRCS:.c=.o)
INCS	=	-I include

all: $(PHILO_BONUS)

$(PHILO_BONUS): $(OBJS)
	$(CC) $(CFLAGS) -o $(PHILO_BONUS) $(OBJS) -lpthread

%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(PHILO_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus
