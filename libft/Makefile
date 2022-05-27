# -*- Makefile -*-
NAME := libft.a
CFLAGS ?= -Wall -Wextra -Werror

SRCS := \
ft_atoi.c \
ft_bzero.c \
ft_isalnum.c \
ft_isalpha.c \
ft_isascii.c \
ft_isdigit.c \
ft_isprint.c \
ft_memchr.c \
ft_memcmp.c \
ft_memcpy.c \
ft_memmove.c \
ft_memset.c \
ft_strchr.c \
ft_strlcat.c \
ft_strlcpy.c \
ft_strlen.c \
ft_strncmp.c \
ft_strnstr.c \
ft_strrchr.c \
ft_tolower.c \
ft_toupper.c \
ft_strdup.c \
ft_calloc.c \
ft_substr.c \
ft_strjoin.c \
ft_strtrim.c \
ft_split.c \
ft_itoa.c \
ft_putchar_fd.c \
ft_putstr_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \
ft_strmapi.c \
ft_striteri.c \
ft_split_len.c \
ft_strdup_c.c \
ft_check_malloc.c 

SRCS_BONUS := \
ft_lstadd_back.c \
ft_lstadd_front.c \
ft_lstclear.c \
ft_lstdelone.c \
ft_lstiter.c \
ft_lstlast.c \
ft_lstmap.c \
ft_lstnew.c \
ft_lstsize.c

OBJS := ${SRCS:%.c=%.o}

OBJS_BONUS := ${SRCS_BONUS:%.c=%.o}

HEADERFILES := libft.h

RED := "\033[1;31m"
GREEN := "\033[1;32m"
CYAN := "\033[1;36m"

ifdef EXEC_BONUS
ALL_OBJS = $(OBJS) $(OBJS_BONUS)
else
ALL_OBJS = $(OBJS)
endif

all: $(NAME)
	
%.o: %.c $(HEADERFILES)
	@$(CC) -c $(CFLAGS) -o $@ $<

$(NAME): $(ALL_OBJS)
	@ar -ru $(NAME) $^
	@echo $(GREEN) "Object files created for LIBFT [OK]"

bonus:
	@$(MAKE) EXEC_BONUS=1

clean:
	@rm -f $(OBJS) $(OBJS_BONUS)
	@echo $(RED) "Deleting object files from libft [OK]"

fclean: clean
	@rm -f $(NAME) $^
	@echo $(RED) "Deleting library file libft.a [OK]"

re: fclean all

.PHONY: all, clean, fclean, re, bonus
