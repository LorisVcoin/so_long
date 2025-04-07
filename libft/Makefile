# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lviravon <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/09 17:52:30 by lviravon          #+#    #+#              #
#    Updated: 2025/01/27 17:19:15 by lviravon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#=================================={MY_COLORS}=================================#

DEFAULT = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

NAME = libft.a

CC = cc

PRINTF = printf

BONUS_SOURCES = ft_lstnew_bonus.c		\
				ft_lstadd_front_bonus.c	\
				ft_lstsize_bonus.c		\
				ft_lstlast_bonus.c		\
				ft_lstadd_back_bonus.c	\
				ft_lstdelone_bonus.c	\
				ft_lstclear_bonus.c		\
				ft_lstiter_bonus.c		\
				ft_lstmap_bonus.c		\

SRCS =	ft_isalnum.c	\
				ft_isalpha.c	\
				ft_isascii.c	\
				ft_isdigit.c	\
				ft_isprint.c	\
				ft_strlen.c		\
				ft_strlcpy.c	\
				ft_strlcat.c	\
				ft_strnstr.c	\
				ft_memcpy.c		\
				ft_memcmp.c		\
				ft_atoi.c		\
				ft_strncmp.c	\
				ft_toupper.c	\
				ft_tolower.c	\
				ft_bzero.c		\
				ft_memset.c		\
				ft_strchr.c		\
				ft_strrchr.c	\
				ft_memchr.c		\
				ft_memmove.c	\
				ft_calloc.c		\
				ft_strdup.c		\
				ft_substr.c		\
				ft_strjoin.c	\
				ft_putchar_fd.c	\
				ft_putnbr_fd.c	\
				ft_putstr_fd.c	\
				ft_itoa.c		\
				ft_strtrim.c	\
				ft_strmapi.c	\
				ft_striteri.c	\
				ft_putendl_fd.c	\
				ft_split.c		\
				get_next_line.c	\
				

OBJS = $(SRCS:.c=.o)

#=================================={COUNT T .o}================================#

SRC_COUNT_TOT := $(shell expr $(shell echo -n $(SRCS) | wc -w) - $(shell ls -l | grep ".o" | wc -l) + 1)
ifeq ($(shell test $(SRC_COUNT_TOT) -le 0; echo $$?),0)
	SRC_COUNT_TOT := $(shell echo -n $(SRCS) | wc -w)
endif

#================================={COUNT % .o}================================#

SRC_COUNT := 0
SRC_PCT = $(shell expr 100 \* $(SRC_COUNT) / $(SRC_COUNT_TOT))
SRCB_COUNT_TOT := $(shell expr $(shell echo -n $(SRCB) | wc -w) - $(shell ls -l $(OBJB_DIR) 2>&1 | grep ".o" | wc -l) + 1)
ifeq ($(shell test $(SRCB_COUNT_TOT) -le 0; echo $$?),0)
	SRCB_COUNT_TOT := $(shell echo -n $(SRCB) | wc -w)
endif

#=============================={COUNT 1 by 1 .o}==============================#

SRC_LFT_COUNT := 0
SRC_LFT_PCT = $(shell expr 100 \* $(SRC_LFT_COUNT) / $(SRC_LFT_COUNT_TOT))

#==================================={RULES}===================================#

BONUS_OBJECTS = $(BONUS_SOURCES:.c=.o)

CFLAGS = -g -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS)
	@ar -rcs $@ $^
	@$(PRINTF) "\n$(BLUE)@ $(MAGENTA)=======$(BLUE){$(GREEN)LIBFT update$(BLUE)}$(MAGENTA)======= $(BLUE)@"

.c.o :
	@$(eval SRC_COUNT = $(shell expr $(SRC_COUNT) + 1))
	@$(PRINTF) "\r%100s\r[ %d/%d (%d%%) ] Compiling $(GREEN)LIBFT $(BLUE)$<$(DEFAULT)..." "" $(SRC_COUNT) $(SRC_COUNT_TOT) $(SRC_PCT)
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -f $(OBJS) $(BONUS_OBJECTS)

fclean : clean
	@rm -f $(NAME)
	@$(PRINTF) "$(YELLOW)*==============================*\n   /!\\ 🧹LIBFT IS CLEAN🧹 /!\\ \n*==============================*\n"

bonus : $(BONUS_OBJECTS) $(OBJS)
	@ar -rcs $(NAME) $(OBJS) $(BONUS_OBJECTS)

$(BONUS_OBJECTS) : %.o:%.c
	@$(CC) $(CFLAGS) -c $< -o $@


re : fclean all


.PHONY : all clean fclean bonus re 
