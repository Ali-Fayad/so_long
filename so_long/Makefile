CC      = gcc
CFLAGS  = -Wall -Wextra -Werror -I Include
LDFLAGS = -Lmlx -lmlx -lXext -lX11 -lm

SRCDIR  = Srcs
OBJDIR  = Obj
INCDIR  = Include

NAME    = so_long

SRCS    = \
	Srcs/main.c \
	Srcs/Game/game_keys.c \
	Srcs/Game/game_utils.c \
	Srcs/Game/game_utils2.c \
	Srcs/Valid/clean.c \
	Srcs/Valid/map2matrix.c \
	Srcs/Valid/valid.c \
	Srcs/Valid/valid_solution.c \
	Srcs/Valid/valid_utils.c \
	Srcs/Valid/valid_utils2.c \
	Srcs/Utils/ft_printf.c \
	Srcs/Utils/ft_put.c \
	Srcs/Utils/ft_split.c

OBJS    = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

GREEN   = \033[0;32m
RED     = \033[0;31m
RESET   = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LDFLAGS)
	@echo "$(RED)✔ so_long Compiled!$(RESET)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(RED)Compiled:$(RESET) $(GREEN)$@ ✔$(RESET)"

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	@rm -rf $(OBJDIR)
	@echo "$(RED)🗑️ Object files removed!$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)🗑️ Executable removed!$(RESET)"

re: fclean all

.PHONY: all clean fclean re
