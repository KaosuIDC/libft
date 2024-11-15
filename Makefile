# Variables
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
NAME = libft.a
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
HEADER = libft.h

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re