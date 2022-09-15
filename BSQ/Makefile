FILES = bsq.c check_file.c get_info.c map.c solve.c tools.c
OBJS = $(FILES:.c=.o)
CC = gcc
CCFLAGS = -Wall -Wextra -Werror
NAME = bsq
HEADER = ./

.PHONY : clean all fclean

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CCFLAGS) -o $@ $^

%.o : %.c
	$(CC) -c $(CCFLAGS) -o $@ $< -I $(HEADER)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all