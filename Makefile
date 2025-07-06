NAME = ft_printf.a
SRC =	ft_printf.c \
		ft_printf_char.c \
		ft_printf_str.c \
		ft_printf_int.c \
		ft_printf_uint.c \
		ft_printf_percent.c \
		ft_printf_ptr.c \
		ft_printf_hexadecimal.c

OBJ_DIR = obj
OBJ = $(SRC:.c=.o)
OBJ := $(addprefix $(OBJ_DIR)/, $(OBJ))

CC = cc

CFLAGS = -Wall -Wextra -Werror #-I/path/to/headers

.PHONY: all clean fclean re

# Targets
all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(BONUS_OBJ)
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
