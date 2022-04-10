NAME = client
NAME_S = server
CC = gcc
RM = rm -f
CFLAGS=	-Wall -Wextra -Werror
LIBFT= ./libft/libft.a

HEADER= minitalk.h

NAME_B  = client_bonus
NAME_SB = server_bonus

SRV = ./src/ft_server.c
CLIE = ./src/ft_client.c

SRV_B = ./src/ft_server_bonus.c
CLIE_B = ./src/ft_client_bonus.c

all: $(CLIE) $(SRV) $(HEADER)
	@make fclean -C libft
	@make -C libft
	@$(CC) $(CFLAGS) $(CLIE) $(LIBFT) -o $(NAME)
	@$(CC) $(CFLAGS) $(SRV) $(LIBFT) -o $(NAME_S)

bonus: $(CLIE_B) $(SRV_B) $(HEADER)
	@make fclean -C libft
	@make -C libft
	@$(CC) $(CFLAGS) $(CLIE_B) $(LIBFT) -o $(NAME_B)
	@$(CC) $(CFLAGS) $(SRV_B) $(LIBFT) -o $(NAME_SB)

clean:
	@make clean -C libft

fclean:
	@make fclean -C libft
	@$(RM) server 
	@$(RM) client
	@$(RM) client_bonus
	@$(RM) server_bonus

re : fclean all

.PHONY: fclean clean all bonus