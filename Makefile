CC = g++

NAME = a.out
SRC = IMPLEMENT/14503.cpp

all : $(NAME)

$(NAME) : $(SRC)
	$(CC) -o $@ $^

clean : 
	rm -f $(NAME)

re : clean all