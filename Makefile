CC = g++ -std=c++11

NAME = a.out
SRC = IMPLEMENT/15683.cpp

all : $(NAME)

$(NAME) : $(SRC)
	$(CC) -o $@ $^

clean : 
	rm -f $(NAME)

re : clean all