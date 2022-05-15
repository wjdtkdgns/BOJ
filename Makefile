CC = g++

NAME = a.out
SRC = BELLMANFORD/1865.cpp

all : $(NAME)

$(NAME) : $(SRC)
	$(CC) -o $@ $^

clean : 
	rm -f $(NAME)

re : clean all