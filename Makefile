# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: pderksen <pderksen@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/05/19 14:17:02 by pderksen      #+#    #+#                  #
#    Updated: 2022/06/09 14:54:04 by pderksen      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# -*- Makefile -*-
NAME := minishell

CC := gcc

ifndef DEBUG
CFLAGS := -Wall -Wextra -Werror
else
CFLAGS := -Wall -Wextra -Werror -fsanitize=address -g
endif

SRCS := src/main.c \
		src/check_quotes.c \
		src/tokenizer.c \
		src/operators.c \
		src/words.c \
		src/print.c \
		src/utils.c
HEADERFILES := lexer.h

READLINE := -lreadline -I/Users/pderksen/.brew/Cellar/readline
LIBFT := libft/libft.a

all: $(NAME)

$(NAME) : $(SRCS) $(LIBFT)
		$(CC) $(CFLAGS) $(READLINE) -o $@ $^

$(LIBFT) :
	$(MAKE) bonus -C libft

clean :
	$(MAKE) clean -C libft 

fclean :
	$(MAKE) fclean -C libft
	rm -f $(NAME)

re : fclean all

.PHONY : all, clean, fclean, re
