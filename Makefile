CC = g++

NAME = a.out
SRC = IMPLEMENT/13460.cpp

all : $(NAME)

$(NAME) : $(SRC)
	$(CC) -o $@ $^

clean : 
	rm -f $(NAME)

re : clean all