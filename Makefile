CC = g++

NAME = a.out
SRC = 2467.cpp

all : $(NAME)

$(NAME) : $(SRC)
	$(CC) -o $@ $^

clean : 
	rm -f $(NAME)

re : clean all