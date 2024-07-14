NAME = push_swap.a
CC = cc
CFLAGS = -Wall -Wextra -Werror 
SRCS = main.c
OBJS = $(SRCS:.c=.o)
HEADER = push_swap.h

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	ar rcs $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
