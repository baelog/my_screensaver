NAME	= my_screensaver

CC	= gcc

RM	= rm -f

SRCS	=	./main.c		\
		./bonus/tree.c		\
		./bonus/clock.c		\
		./test.c
OBJS	= $(SRCS:.c=.o)

CFLAGS = -I
CFLAGS += -Wall -Wextra -g3

all: $(NAME)

$(NAME): $(OBJS)
	 cd lib/my/; make re
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS) -lc_graph_prog -L./lib -lmy -lm

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	cd lib/my/; make fclean
re: fclean all

.PHONY: all clean fclean re
