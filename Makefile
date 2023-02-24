NAME = webserv
CC = clang++
FLAGS = -Wall -Werror -Wextra -std=c++98 #-fsanitize=address -g3
SRC = Webserv.cpp Configuration/Server.cpp Configuration/Configuration.cpp
all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) $(SRC) -o $(NAME)
fclean: 
	rm -f $(NAME)
re: fclean all