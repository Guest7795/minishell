NAME = minishell

CC = cc
CFLAGS = -Wall -Wextra -Werror

INC = -Iincludes -Ilibft
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

READLINE = -lreadline

SRC = src/main.c \
      src/parsing/parse_line.c \
      src/utils/free.c \
      src/exec/exec_simple.c

OBJ = $(SRC:.c=.o)

# ================= RULES =================

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(READLINE) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all
