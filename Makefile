NAME        = push_swap

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -I.

SRCS    = main.c \
          operations_push.c \
          operations_reverse.c \
          operations_rotate.c \
          operations_swap.c \
          parsing_helpers.c \
          parsing_main.c \
          strategy.c \
          struct_utils.c \
          algorithm_simple.c \
          algorithm_medium.c \
          algorithm_complex_radix.c \
          bench_mode.c\
          libft_helpers.c\
          libft_helpers2.c
          
OBJS        = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
