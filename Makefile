NAME        = push_swap

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -I. -Ilibft

SRCS        = main.c \
              operations_push.c \
              operations_reverse.c \
              operations_rotate.c \
              operations_swap.c \
              parsing_helpers.c \
              parsing_main.c \
              simple_algorithm.c \
              strategy.c \
              struct_utils.c

OBJS        = $(SRCS:.c=.o)

LIBFT_DIR   = libft
LIBFT       = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
