CC = g++

NAME = a.out
SRC = IMPLEMENT/14891.cpp

all : $(NAME)

$(NAME) : $(SRC)
	$(CC) -o $@ $^

clean : 
	rm -f $(NAME)

re : clean all