CC = g++

NAME = a.out
SRC = DIJKSTRA/11779.cpp

all : $(NAME)

$(NAME) : $(SRC)
	$(CC) -o $@ $^

clean : 
	rm -f $(NAME)

re : clean all