CC = g++

NAME = a.out
SRC = IMPLEMENT/3190.cpp

all : $(NAME)

$(NAME) : $(SRC)
	$(CC) -o $@ $^

clean : 
	rm -f $(NAME)

re : clean all