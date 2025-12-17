PURPLE = \033[38;5;93m
BLACK  = \033[0;30m
RESET  = \033[0m

NAME = minideath

CC = cc
CFLAGS = -Wall -Wextra -Werror

MAKEFLAGS += --no-print-directory
INC = -Iincludes -Ilibft
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

READLINE = -lreadline

SRC = src/main.c \
      src/parsing/parse_line.c \
      src/parsing/utils/free.c \
      src/exec/exec_simple.c \
	  src/builtins/builtin_echo.c

OBJ = $(SRC:.c=.o)

# ================= RULES =================

banner:
	@echo "$(PURPLE)"
	@echo "███╗   ███╗██╗███╗   ██╗██╗██████╗ ███████╗ █████╗ ████████╗██╗  ██╗"
	@echo "████╗ ████║██║████╗  ██║██║██╔══██╗██╔════╝██╔══██╗╚══██╔══╝██║  ██║"
	@echo "██╔████╔██║██║██╔██╗ ██║██║██║  ██║█████╗  ███████║   ██║   ███████║"
	@echo "██║╚██╔╝██║██║██║╚██╗██║██║██║  ██║██╔══╝  ██╔══██║   ██║   ██╔══██║"
	@echo "██║ ╚═╝ ██║██║██║ ╚████║██║██████╔╝███████╗██║  ██║   ██║   ██║  ██║"
	@echo "╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝╚═════╝ ╚══════╝╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝"
	@echo "$(BLACK)               ☠  MINIDEATH SHELL LOADING  ☠$(RESET)"
	@echo ""

success:
	@echo "$(PURPLE)✔ Compilation réussie$(RESET)"

all: banner $(LIBFT) $(NAME) success

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(READLINE) -o $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: 
	@$(MAKE) fclean 
	@$(MAKE) all
