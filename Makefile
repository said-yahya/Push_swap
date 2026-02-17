NAME        = push_swap
BONUS_NAME  = checker
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

BONUS_SRCS = bonus_reader.c bonus_reader2.c bonus_checker.c \
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
BONUS_OBJ   = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(BONUS_OBJ) -o $(BONUS_NAME)

clean:
	rm -f $(OBJS) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
