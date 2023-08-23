###############################################################################
#                                 VARIABLES                                   #
###############################################################################

NAME		= so_long
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g -fsanitize=address
FILES 		= $(wildcard src/*.c)
OBJS		= $(FILES:.c=.o)
MLX_L		= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
PRINTF		= ./ft_printf/libftprintf.a
RM			= rm -f
# INCLUDES	= -I/usr/include -Imlx

# .c.o:
#	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

#.c.o:
#	$(CC) -c $< -o $@

################################################################################
#                                 COLORS                                       #
################################################################################

CLR_RESET	= \033[0m
RED		    = \033[1;31m
GREEN		= \033[1;32m
YELLOW		= \033[1;33m
BLUE		= \033[1;34m
CYAN 		= \033[1;36m
PURPLE 		= \033[0;35m

###############################################################################
#                                 SCRIPT                                      #
###############################################################################

all: $(NAME)

$(NAME): $(OBJS)

		make -C mlx_linux
		clear
		@echo "$(GREEN)Compiling of $(RED)$(NAME)...$(CLR_RESET)"
		$(CC) $(CFLAGS) $(OBJS) $(PRINTF) $(MLX_L) -o $(NAME)
		@echo "$(RED)$(NAME) $(GREEN)is ready!$(CLR_RESET)\n"
		@echo "$(PURPLE)====================================$(CLR_RESET)"

clean:
		$(RM) $(OBJS)
		clear
		@echo "$(RED)$(NAME) object $(GREEN)files have been deleted.$(CLR_RESET)\n"

fclean: clean
		$(RM) $(NAME)
		clear
		@echo "$(RED)$(NAME) $(GREEN)has been deleted.$(CLR_RESET)\n"

re: fclean all
	@echo "$(RED)$(NAME) $(GREEN)has been recompiled.$(CLR_RESET)\n"
	@echo "$(PURPLE)====================================$(CLR_RESET)"

.PHONY: all clean fclean re

