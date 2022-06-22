CC = g++

NAME = a.out
SRC = 2POINTER/2473.cpp

all : $(NAME)

$(NAME) : $(SRC)
	$(CC) -o $@ $^

clean : 
	rm -f $(NAME)

re : clean all