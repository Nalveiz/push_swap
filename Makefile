NAME = push_swap
SRCS = error_utils.c init_a_to_b.c init_b_to_a.c push_swap.c \
 		push.c r_rotate.c  rotate.c sort_three.c sort_stacks.c stack_init.c\
		stack_utils.c swap.c split.c

OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT = inc/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(SRCS)
	@make -C ./inc -s
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "\033[35m                 _                                 "
	@echo "\033[35m _ __  _   _ ___| |__      _____      ____ _ _ __  "
	@echo "\033[35m| '_ \| | | / __| '_ \    / __\ \ /\ / / _\` | '_ \ "
	@echo "\033[37m| |_) | |_| \__ \ | | |   \__ \\ V  V / (_| | |_) |"
	@echo "\033[37m| .__/ \__,_|___/_| |_|___|___/ \_/\_/ \__,_| .__/ "
	@echo "\033[37m|_|                  |_____|                |_|    "
	@echo "Program is ready!"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make -C ./inc clean -s
	@rm -rf $(OBJS)
	@echo "Object files removed!"

fclean: clean
	@make -C ./inc fclean -s
	@rm -rf $(NAME)
	@echo "Program is removed!"

re: fclean all

.PHONY: all clean fclean re
