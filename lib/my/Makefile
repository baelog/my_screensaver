##
## EPITECH PROJECT, 2019
## make
## File description:
## make
##

NAME	= libmy.a

CC	= gcc

RM	= rm -f

SRCS	= ./my_compute_power_rec.c	\
	  ./my_compute_square_root.c	\
	  ./my_evil_str.c		\
	  ./my_isneg.c			\
	  ./my_print.c			\
	  ./my_revstr.c 		\
	  ./my_srtlen.c 		\
	  ./my_strcat.c 		\
	  ./my_strcmp.c 		\
	  ./my_strcpy.c			\
	  ./my_strncat.c		\
	  ./my_strncpy.c		\
	  ./my_swap.c			\
	  ./int_to_str.c		\
	  ./my_getnbr.c
OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	cp my.h ../../include
	ar rc $(NAME) $(OBJS)
	cp $(NAME) ..
clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
re: fclean all

.PHONY: all clean fclean re
