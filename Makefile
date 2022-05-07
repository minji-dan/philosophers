SRC_DIR	=	./srcs/

SRCS	=	argc_handle.c\
			init.c\
			main.c\
			philo_state.c\
			philos.c\
			routine.c\
			time_utils.c\
			utils.c\
			utils2.c\

OBJ_DIR	=	./objs/
OBJS	=	$(SRCS:.c=.o)

SRC_DIRS	=	$(addprefix $(SRC_DIR), $(SRCS))
OBJ_DIRS	=	$(addprefix $(OBJ_DIR), $(OBJS))

PHILO	=	philo
PHILO_BONUS		=	philo_bonus
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
RM 		=	rm -f
MKDIR	=	@mkdir -p
INCLUDE	=	-I ./inc

all: $(PHILO)

clean:
	$(RM) $(OBJ_DIRS)

fclean: clean
	$(RM) $(PHILO)

re: fclean all

$(PHILO): $(OBJ_DIRS)
	$(CC) $(CFLAGS) -o $(PHILO) $(OBJ_DIRS) -lpthread

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(MKDIR) $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

.PHONY: all clean fclean re bonus