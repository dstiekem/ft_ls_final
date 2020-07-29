NAME = ft_ls
FLAGS = -Wall -Werror -Wextra
HEADER = ft_ls.h
LIB = libft/libft.a
SRC = printspecial.c addnode.c makenode.c sort.c main.c scream.c ft_ls.c recurse4.c savelong2.c
# savelong2.c

all: $(NAME)

$(NAME):
	@echo "Making libft"
	@make -C libft/
	@echo "Making ft_ls"
	@gcc $(LIB) $(SRC) -I $(FLAGS) -o $(NAME) -g

	#NB PUT FLAGS BACK BEFROE SUBMISSION
	#    
	#$(HEADER)
clean:
	@echo "Cleaning objects in Libft and any Junk here"
	@make -C libft/ clean

fclean: clean
	@echo "Cleaning Libft Archive"
	@make -C libft/ fclean
	@echo "Removing Executable"
	@rm -rf $(NAME)

re: fclean all
	@make -C libft/ re


