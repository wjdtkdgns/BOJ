CC = g++

NAME = a.out
SRC = DFS/1167.cpp
OBJ = $(SRC:%.c=%.o)

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

clean : 
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all