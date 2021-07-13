CC=gcc
FLAGS=-Wall -Wextra -Werror
SRCS= args.c \
		eat.c \
		fork.c \
		life.c \
		main.c \
		mutexes.c \
		philosophers.c \
		print.c \
		sleep.c \
		time.c \
		utils.c
OBJS= $(SRCS:.c=.o)
NAME=philo
INCLUDES=philosophers.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -lpthread -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

%.o: %.c $(INCLUDES)
	$(CC) $(FLAGS) -c $< -o $@
