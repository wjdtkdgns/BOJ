CC = g++

NAME = a.out
SRC = DIJKSTRA/1504.cpp

all : $(NAME)

$(NAME) : $(SRC)
	$(CC) -o $@ $^

clean : 
	rm -f $(NAME)

re : clean all