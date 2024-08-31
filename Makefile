NAME = bsq

CC = cc

CFLAGS = #-Wall -Wextra -Werror

SRC = map_data.c main.c ftlib.c ft_verify_map.c ft_string.c

SRCS = $(addprefix $(PRE), $(SRC))

PRE = ./srcs/

INCS = ./includes/

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS) -I $(INCS)
clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all