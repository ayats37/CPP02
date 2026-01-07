NAME = a.out
SRC = Fixed.cpp  main.cpp Point.cpp bsp.cpp
OBJ = $(SRC:.cpp=.o)
CPPC = c++
CPPFLAG = -Wall -Wextra -Werror -std=c++98


all: $(NAME)


$(NAME): $(OBJ)
	$(CPPC) $(CPPFLAG) -o $(NAME) $(OBJ)

%.o: %.cpp Fixed.hpp
	$(CPPC) $(CPPFLAG) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re