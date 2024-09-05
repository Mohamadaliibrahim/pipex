CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

SRC = pipex.c utils.c utils2.c utils3.c

OBJ = $(SRC:.c=.o)
NAME = pipex

# Directories for libraries
FT_PRINTF_DIR = ft_printf
LIBFT_DIR = lib_ft

# Libraries
FT_PRINTF_LIB = $(FT_PRINTF_DIR)/libftprintf.a
LIBFT_LIB = $(LIBFT_DIR)/libft.a
LIBS = $(FT_PRINTF_LIB) $(LIBFT_LIB)

all: $(NAME)

$(NAME): $(OBJ) $(FT_PRINTF_LIB) $(LIBFT_LIB)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBS)

$(FT_PRINTF_LIB):
	$(MAKE) -C $(FT_PRINTF_DIR)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(FT_PRINTF_DIR) clean
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(FT_PRINTF_DIR) fclean
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
