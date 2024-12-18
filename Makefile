##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## ..
##

NAME	=	organized

SRC =   main.c
SRC +=	add.c
SRC +=  sort.c
SRC +=  del.c
SRC +=  disp.c

OBJ = $(SRC:.c=.o)

CFLAGS = -I./include/ -L lib/ -lmy  -L ./ -lshell -Wall -Wextra -g

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./lib/
	gcc $(OBJ) -o $(NAME) $(CFLAGS)

clean :
	make clean -C ./lib/
	rm -f $(OBJ)

fclean: clean
	make fclean -C ./lib/
	rm -f $(NAME)

re: fclean all
