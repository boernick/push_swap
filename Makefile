NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror 
SRCS = push_swap.c push_swap_actions.c push_swap_utils.c push_swap_input.c
OBJS = $(SRCS:.c=.o)
HEADER = push_swap.h

LIBFT_DIR = /home/nboer/git/Libft
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
