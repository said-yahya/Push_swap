NAME 	= libftprintf.a
CC 		= cc
CFLAGS 	= -Wall -Werror -Wextra
AR 		= ar rcs
RM		= rm -f

SRCS 	= 

		  
OBJS	= $(SRCS:.c=.o)

$(NAME): $(OBJS)
		$(AR) $(NAME) $(OBJS)

all: $(NAME)

clean: 
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re