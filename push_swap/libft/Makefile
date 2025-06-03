# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpaulo-c <rpaulo-c@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/02 19:56:54 by rpaulo-c          #+#    #+#              #
#    Updated: 2025/06/03 15:40:50 by rpaulo-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
OBJ_DIR = obj

SRCS = \
	ft_atol.c ft_isdigit.c ft_isxdigit.c ft_isspace.c ft_tolower.c \
	ft_putstr_fd.c ft_putchar_fd.c ft_putendl_fd.c ft_strtol.c

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "Library $(NAME) created."

$(OBJ_DIR)/%.o: %.c libft.h | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiling: $<"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "Created $(OBJ_DIR) directory."

clean:
	@rm -rf $(OBJ_DIR)
	@echo "Clean complete."

fclean: clean
	@rm -f $(NAME)
	@echo "Fclean complete."

re: fclean all

.PHONY: all clean fclean re
