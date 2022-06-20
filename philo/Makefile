PHILO	=	philo

CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
RM 		=	rm -f

SRC_DIR	=	./srcs/
SRCS	=	argc_handle.c init.c main.c philo_state.c\
			philos.c routine.c time_utils.c utils.c utils2.c
OBJS	=	$(SRCS:.c=.o)
INCS	=	-I include

all: $(PHILO)

$(PHILO): $(OBJS)
	$(CC) $(CFLAGS) -o $(PHILO) $(OBJS) -lpthread

%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(PHILO)

re: fclean all

.PHONY: all clean fclean re