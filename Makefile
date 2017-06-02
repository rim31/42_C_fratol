
GC = gcc

FLAG = -I $(INCL) ./minilibx_macos/libmlx.a -framework OpenGl -framework AppKit

SRCS = main.c \
	ft_ruby.c \
	ft_celt.c \
	ft_heart.c \
	ft_dendrite.c \
	ft_bunny.c \
	ft_ship.c \
	ft_mandel.c \
	ft_julia.c \
	ft_mapping.c \
	ft_menu.c \

LIBFT_PATH = ./libft/

LIBFT_NAME = libft.a

LIBFT = $(LIBFT_PATH)$(LIBFT_NAME)

INCL = fractol.h

NAME = fractol

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	@echo "  _____                      __         .__   "
	@echo "_/ ____\___________    _____/  |_  ____ |  |  "
	@echo "\   __\\_  __ \__  \ _/ ___\   __\/  _ \|  |  "
	@echo " |  |   |  | \// __ \\  \___|  | (  <_> )  |__"
	@echo " |__|   |__|  (____  /\___  >__|  \____/|____/"
	@echo "                   \/     \/         by 😜 seng"

		@echo "\033[92mCompiling"
		@make re -C $(LIBFT_PATH)
		@$(GC) -o $(NAME) -Wall -Wextra -Werror $(SRCS) $(FLAG) $(LIBFT)
		@echo "\033[96m->Done"
		@make fclean -C $(LIBFT_PATH)

clean:
		@echo "\033[92mDeleting"
		@rm -f $(OBJ)
		@make fclean -C $(LIBFT_PATH)
		@echo "\033[96mClean done"


fclean: clean
		@echo "\033[92mDeleting"
		@rm -f $(NAME)
		@make fclean -C $(LIBFT_PATH)
		@echo "\033[96mFclean Done"

re: fclean all

.PHONY: all clean fclean re
