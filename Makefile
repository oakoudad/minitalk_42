NAME = client
NAME_S = server
CC = gcc
RM = rm
CFLAGS=	-Wall -Wextra -Werror
LIBFT= ./libft/libft.a

SRV = ./src/ft_server.c
CLIE = ./src/ft_client.c

all: $(NAME) $(NAME_S)
	

$(NAME_S):
	@make clean -C libft
	@make -C libft
	@$(CC) $(CFLAGS) $(SRV) $(LIBFT) -o $(NAME_S)

$(NAME):
	@make clean -C libft
	@make -C libft
	@$(CC) $(CFLAGS) $(CLIE) $(LIBFT) -o $(NAME)

clean:
	@make clean -C libft

fclean:
	@make fclean -C libft
	@$(RM) server 
	@$(RM) client

re : fclean all

.PHONY: fclean clean all client server