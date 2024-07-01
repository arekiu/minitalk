CC = cc

CFLAGS = -Wall -Wextra -Werror

LIBFT_PATH = libft/

LIBFT_NAME = libft.a

LIBFT = $(LIBFT_PATH)$(LIBFT_NAME)

all: $(LIBFT) client server

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)

client: client.o
	$(CC) $(CFLAGS) client.o -o client $(LIBFT)

server: server.o
	$(CC) $(CFLAGS) server.o -o server $(LIBFT)

client.o: client.c
	$(CC) $(CFLAGS) -c client.c

server.o: server.c
	$(CC) $(CFLAGS) -c server.c

clean:
	@$(MAKE) -C $(LIBFT_PATH) clean
	rm -f client.o server.o

fclean: clean
	@$(MAKE) -C $(LIBFT_PATH) fclean
	rm -f client server

re: fclean all

.PHONY: all clean fclean re
