SRC_FILES = $(wildcard *.c)
OBJ_FILES = $(patsubst %.c,$(BUILD_DIR)/%.o,$(SRC_FILES))
DEP_FILES = $(patsubst %.c,$(BUILD_DIR)/%.d,$(SRC_FILES))

HDR_FLAGS = -I $(LIBFT) -I $(FT_PRINTF)
LIB_FLAGS = -rpath $(LIBFT) -L $(LIBFT) -lft -rpath $(FT_PRINTF) -L $(FT_PRINTF) -lftprintf
BUILD_DIR = build

NAME = push_swap
CFLAGS = -Wall -Wextra -g -MMD $(HDR_FLAGS) $(LIB_FLAGS)

CC = clang
LIBFT = $(CURDIR)/libft
FT_PRINTF = $(CURDIR)/ft_printf

all: $(NAME)

libft:
	make -C $(LIBFT)

ft_printf:
	make -C $(FT_PRINTF)

$(BUILD_DIR)/%.o: %.c Makefile | $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $@ -c $< 

$(BUILD_DIR):
	mkdir -p $@

$(NAME): libft ft_printf $(OBJ_FILES) 
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ_FILES)

clean reclean:
	rm -rf $(BUILD_DIR)

deepclean: clean
	make -C $(LIBFT) clean
	make -C $(FT_PRINTF) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFT) fclean
	make -C $(FT_PRINTF) fclean

re: fclean all reclean

rebonus: fclean bonus reclean

-include $(DEP_FILES)

.PHONY: all clean fclean re libft ft_printf
