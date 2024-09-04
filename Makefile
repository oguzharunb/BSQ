NAME = bsq

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = ft_free.c ft_init.c ft_main.c ft_map_data.c ft_put.c ft_read_map.c ft_solve.c ft_print_solution.c util.c

SRCS = $(addprefix $(PRE), $(SRC))

PRE = ./srcs/

INCS = ./includes/

all:	$(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME) -I $(INCS)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
