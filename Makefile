CC = g++

NAME = a.out
SRC = IMPLEMENT/2239.cpp

all : $(NAME)

$(NAME) : $(SRC)
	$(CC) -o $@ $^

clean : 
	rm -f $(NAME)

re : clean all