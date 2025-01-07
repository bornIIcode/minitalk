CLIENT = client
SERVER = server
CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_CLIENT = client.c
SRC_SERVER = server.c
SRC_CLIENT_BONUS = client_bonus.c
SRC_SERVER_BONUS = server_bonus.c

SRC_FTPRINTF = ft_printf/ft_check_spec.c \
               ft_printf/ft_puthex.c \
               ft_printf/ft_putptr.c \
               ft_printf/ft_putunbr.c \
               ft_printf/ft_printf.c \
               ft_printf/ft_putchar.c \
               ft_printf/ft_putnbr.c \
               ft_printf/ft_putstr.c

OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT_BONUS = $(SRC_CLIENT_BONUS:.c=.o)
OBJ_SERVER_BONUS = $(SRC_SERVER_BONUS:.c=.o)
OBJ_FTPRINTF = $(SRC_FTPRINTF:.c=.o)

all: $(CLIENT) $(SERVER)

$(CLIENT): $(OBJ_CLIENT) $(OBJ_FTPRINTF)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) $(OBJ_FTPRINTF) -o $(CLIENT)

$(SERVER): $(OBJ_SERVER) $(OBJ_FTPRINTF)
	$(CC) $(CFLAGS) $(OBJ_SERVER) $(OBJ_FTPRINTF) -o $(SERVER)

bonus: $(CLIENT_BONUS) $(SERVER_BONUS)

$(CLIENT_BONUS): $(OBJ_CLIENT_BONUS) $(OBJ_FTPRINTF)
	$(CC) $(CFLAGS) $(OBJ_CLIENT_BONUS) $(OBJ_FTPRINTF) -o $(CLIENT_BONUS)

$(SERVER_BONUS): $(OBJ_SERVER_BONUS) $(OBJ_FTPRINTF)
	$(CC) $(CFLAGS) $(OBJ_SERVER_BONUS) $(OBJ_FTPRINTF) -o $(SERVER_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_CLIENT) $(OBJ_SERVER) $(OBJ_CLIENT_BONUS) $(OBJ_SERVER_BONUS) $(OBJ_FTPRINTF)

fclean: clean
	rm -f $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus
