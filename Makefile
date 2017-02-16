NAME = gnl
SRC = get_next_line.c test_main.c
OBJ = $(SRC:.c=.o)
LIBF = -lft -Llibft
INC = -I./libft/includes
LIB = ./libft
CFLAGS = -Wall -Werror -Wextra -g

all: $(NAME)

$(NAME): $(LIB)/libft.a
	gcc -c $(CFLAGS) $(INC) $(SRC)
	gcc $(OBJ) $(LIBF) -o $(NAME)

$(LIB)/libft.a: $(LIB)
	@make -C $(LIB)

clean:
	@make -C $(LIB) clean
	rm -rf $(OBJ)

fclean: clean
	@make -C $(LIB) fclean
	rm -f $(NAME)

re: fclean all
