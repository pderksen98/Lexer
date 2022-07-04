# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: pderksen <pderksen@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/05/19 14:17:02 by pderksen      #+#    #+#                  #
#    Updated: 2022/07/04 14:54:12 by pderksen      ########   odam.nl          #
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
		src/Lexer/check_quotes.c \
		src/Lexer/tokenizer.c \
		src/Lexer/operators.c \
		src/Lexer/words.c \
		src/Lexer/print.c \
		src/Lexer/token_specifier.c \
		src/Lexer/utils.c \
		src/Expander/paths.c \
		src/Expander/quote_expander.c 
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
