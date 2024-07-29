NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
SRCS = push_swap.c push_swap_input.c push_swap_utils.c push_swap_actions.c push_swap_sort.c
OBJS = $(SRCS:.c=.o)
HEADER = push_swap.h

LIBFT_DIR = /home/nick/42Berlin/Libft
LIBFT = $(LIBFT_DIR)/libft.a

INCLUDES = -I$(LIBFT_DIR)

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS) $(HEADER)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR) bonus

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
