NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -I.

SRCS    = operations_push.c \
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
MAIN    = main.c
COMMON_OBJS = $(SRCS:.c=.o)
MAIN_OBJS   = $(MAIN:.c=.o)

all: $(NAME)

$(NAME): $(MAIN_OBJS) $(COMMON_OBJS)
	$(CC) $(CFLAGS) $(MAIN_OBJS) $(COMMON_OBJS) -o $(NAME)


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJ) $(COMMON_OBJS) $(MAIN_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
