BONUS_NAME = checker

CC      = cc
CFLAGS  = -Wall -Wextra -Werror -I.

BONUS_SRCS = operations_push_bonus.c \
             operations_reverse_bonus.c \
             operations_rotate_bonus.c \
             operations_swap_bonus.c \
             parsing_helpers_bonus.c \
             parsing_main_bonus.c \
             struct_utils_bonus.c \
             libft_helpers_bonus.c \
             libft_helpers2_bonus.c \
             reader_bonus.c \
             reader2_bonus.c \
             checker_bonus.c

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS_NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(BONUS_OBJS)

fclean: clean
	rm -f $(BONUS_NAME)

re: fclean bonus

.PHONY: bonus clean fclean re