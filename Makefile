# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpaulo-c <rpaulo-c@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/02 19:56:58 by rpaulo-c          #+#    #+#              #
#    Updated: 2025/06/05 22:36:38 by rpaulo-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Diretórios
OBJ_DIR = obj
LIBFT_DIR = libft

VALGRIND 	= valgrind --leak-check=full --track-origins=yes

# Arquivos fonte (sem o prefixo src/)
SRCS = main.c sort_small.c stack_ops_swap_push.c sort_large.c \
       stack_utils.c stack_ops_rev_rotate.c error.c \
       stack_ops_rotate.c validation.c

# Objetos com prefixo da pasta obj/
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

# Biblioteca
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "✅ $(NAME) created successfully!"

$(LIBFT):
	@echo "🔨 Building libft..."
	@$(MAKE) -C $(LIBFT_DIR)

# Regra para compilar objetos (arquivo.c -> obj/arquivo.o)
$(OBJ_DIR)/%.o: %.c push_swap.h $(LIBFT_DIR)/libft.h Makefile | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "📝 Compiling: $<"

# Cria a pasta obj se não existir
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "📁 Created $(OBJ_DIR) directory"

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "🧹 Clean complete"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "🗑️  Fclean complete"

re: fclean all

norm:
	@echo "🔍 Running norminette..."
	@norminette $(SRCS) push_swap.h
	@$(MAKE) -C $(LIBFT_DIR) norm 2>/dev/null || echo "⚠️  Libft norminette not available"
	@echo "✅ Norminette check complete!"

test2: $(NAME)
	$(eval ARG = $(shell shuf -i 0-100 -n 2))
	$(VALGRIND) ./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "Moves: "
	@./push_swap $(ARG) | wc -l

test3: $(NAME)
	$(eval ARG = $(shell shuf -i 0-100 -n 3))
	$(VALGRIND) ./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "Moves: "
	@./push_swap $(ARG) | wc -l

test5: $(NAME)
	$(eval ARG = $(shell shuf -i 0-5000 -n 5))
	$(VALGRIND) ./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "Moves: "
	@./push_swap $(ARG) | wc -l

test100: $(NAME)
	$(eval ARG = $(shell shuf -i 0-5000 -n 100))
	$(VALGRIND) ./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "Moves: "
	@./push_swap $(ARG) | wc -l

test500: $(NAME)
	$(eval ARG = $(shell shuf -i 0-5000 -n 500))
	$(VALGRIND) ./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "Moves: "
	@./push_swap $(ARG) | wc -l

test1000: $(NAME)
	$(eval ARG = $(shell shuf -i 0-5000 -n 1000))
	$(VALGRIND) ./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "Moves: "
	@./push_swap $(ARG) | wc -l

.PHONY: all clean fclean re test2 test3 test5 test100 test500 test1000
