NAME        = push_swap

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -I. -Ilibft

SRCS    = main.c \
          operations_push.c \
          operations_reverse.c \
          operations_rotate.c \
          operations_swap.c \
          parsing_helpers.c \
          parsing_main.c \
          algorithm_simple.c \
          strategy.c \
          struct_utils.c \
          algorithm_medium.c\
          algorithm_complex.c\
          algorithm_complex2.c\
          algorithm_complex_radix.c\
          bench_mode.c
          
OBJS        = $(SRCS:.c=.o)

LIBFT_DIR   = Libft
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
