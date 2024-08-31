NAME = bsq

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = map_data.c main.c ftlib.c ft_verify_map.c

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -o $(NAME) $(SRC)
clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all