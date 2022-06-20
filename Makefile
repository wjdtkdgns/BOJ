CC = g++

NAME = a.out
SRC = GEOMETRY/2166.cpp

all : $(NAME)

$(NAME) : $(SRC)
	$(CC) -o $@ $^

clean : 
	rm -f $(NAME)

re : clean all