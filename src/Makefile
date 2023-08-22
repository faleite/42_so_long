###############################################################################
#                                 VARIABLES                                   #
###############################################################################

NAME		= so_long
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g #-fsanitize=address
# FILES 		= $(wildcard src/*.c)
FILES 		= main.c
OBJS		= $(FILES:.c=.o)
MLX_L		= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
RM			= rm -f
INCLUDES	= -I/usr/include -Imlx

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

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

#all: $(LIBFT_LIB) $(NAME)
all: $(NAME)

$(NAME): $(OBJS)

#		@make -C mlx_linux
#		clear
#		@make -C $(LIBFT_PATH) # chama Make para libft
#		clear
		@echo "$(GREEN)Compiling of $(RED)$(NAME)...$(CLR_RESET)"
		$(CC) $(CFLAGS) $(OBJS) $(MLX_L) -o $(NAME)
#		$(CC) $(CFLAGS) $(OBJS) $(MLX_L) $(LIBFT_LIB) -o $(NAME) # inclui a libft
		@echo "$(RED)$(NAME) $(GREEN)is ready!$(CLR_RESET)\n"
		@echo "$(PURPLE)====================================$(CLR_RESET)"

clean:
		@$(RM) $(OBJS)
		@echo "$(RED)$(NAME) object $(GREEN)files have been deleted.$(CLR_RESET)\n"

fclean: clean
		@$(RM) $(NAME)
		@echo "$(RED)$(NAME) $(GREEN)has been deleted.$(CLR_RESET)\n"

re: fclean all
	@echo "$(RED)$(NAME) $(GREEN)has been recompiled.$(CLR_RESET)\n"
	@echo "$(PURPLE)====================================$(CLR_RESET)"

.PHONY: all clean fclean re

