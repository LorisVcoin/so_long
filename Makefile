# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lviravon <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/15 17:16:47 by lviravon          #+#    #+#              #
#    Updated: 2025/02/18 18:03:34 by lviravon         ###   ########.fr        #
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

#==============================={PRINCIPAL UTILS}===============================#

NAME = so_long 

BONUS_NAME = so_long_bonus

PRINTF = printf

SRC =	srcs/main.c	\
		srcs/parsing.c	\
		srcs/parsing_utils.c \
		srcs/so_long_utils.c	\
		srcs/map_settings.c	\
		srcs/init.c			\
		srcs/destroy.c		\
		srcs/verif_textures.c	\
		srcs/settings.c		\
		srcs/player_settings.c	\

SRC_BONUS = srcs_bonus/main.c	\
			srcs_bonus/parsing.c	\
			srcs_bonus/parsing_utils.c	\
			srcs_bonus/so_long_utils.c	\
			srcs_bonus/map_settings.c	\
			srcs_bonus/init.c	\
			srcs_bonus/destroy.c	\
			srcs_bonus/verif_textures.c	\
			srcs_bonus/settings.c	\
			srcs_bonus/player_settings.c	\
			srcs_bonus/map_settings2.c	\
			srcs_bonus/move_settings.c	\
			srcs_bonus/settings_enemies.c	\

OBJS = $(SRC:srcs/%.c=objs/%.o)

OBJS_BONUS = $(SRC_BONUS:srcs_bonus/%.c=bonus_objs/%.o)

CFLAGS = -fPIE -pie -I libft 

#=================================={COUNT T .o}================================#

SRC_COUNT_TOT := $(shell expr $(shell echo -n $(SRC) | wc -w) - $(shell ls -l | grep ".o" | wc -l) + 1)
ifeq ($(shell test $(SRC_COUNT_TOT) -le 0; echo $$?),0)
	SRC_COUNT_TOT := $(shell echo -n $(SRC) | wc -w)
endif

SRC_COUNT_TOT_BONUS := $(shell expr $(shell echo -n $(SRC_BONUS) | wc -w) - $(shell ls -l | grep ".o" | wc -l) + 1)
ifeq ($(shell test $(SRC_COUNT_TOT_BONUS) -le 0; echo $$?),0)
	SRC_COUNT_TOT := $(shell echo -n $(SRC_BONUS) | wc -w)
endif

#================================={COUNT % .o}================================#

SRC_COUNT := 0
SRC_PCT = $(shell expr 100 \* $(SRC_COUNT) / $(SRC_COUNT_TOT))
SRCB_COUNT_TOT := $(shell expr $(shell echo -n $(SRCB) | wc -w) - $(shell ls -l $(OBJB_DIR) 2>&1 | grep ".o" | wc -l) + 1)
ifeq ($(shell test $(SRCB_COUNT_TOT) -le 0; echo $$?),0)
	SRCB_COUNT_TOT := $(shell echo -n $(SRCB) | wc -w)
endif

SRC_COUNT_BONUS := 0
SRC_PCT_BONUS = $(shell expr 100 \* $(SRC_COUNT_BONUS) / $(SRC_COUNT_TOT_BONUS))
SRCB_COUNT_TOT_BONUS := $(shell expr $(shell echo -n $(SRCB_BONUS) | wc -w) - $(shell ls -l $(OBJB_DIR_BONUS) 2>&1 | grep ".o" | wc -l) + 1)
ifeq ($(shell test $(SRCB_COUNT_TOT_BONUS) -le 0; echo $$?),0)
	SRCB_COUNT_TOT := $(shell echo -n $(SRCB_BONUS) | wc -w)
endif

#=============================={COUNT 1 by 1 .o}==============================#

SRC_LFT_COUNT := 0
SRC_LFT_PCT = $(shell expr 100 \* $(SRC_LFT_COUNT) / $(SRC_LFT_COUNT_TOT))

SRC_LFT_COUNT_BONUS := 0
SRC_LFT_PCT_BONUS = $(shell expr 100 \* $(SRC_LFT_COUNT_BONUS) / $(SRC_LFT_COUNT_TOT_BONUS))

#==================================={RULES}===================================#

all : $(NAME)


$(shell mkdir -p objs bonus_objs)
$(shell mkdir -p objs objs)

$(NAME) : $(OBJS)
	@$(PRINTF) "\n$(BLUE)@ $(MAGENTA)=======$(BLUE){$(GREEN)So long update$(BLUE)}$(MAGENTA)======= $(BLUE)@"
	@$(PRINTF) "\n"
	@$(MAKE) -C MacroLibX/ -s -j --silent
	@$(PRINTF) "\n"
	@$(MAKE) -C libft/ --silent
	@cc $(CFLAGS) $(OBJS) libft/libft.a MacroLibX/libmlx.so -lSDL2 -o $(NAME)

$(BONUS_NAME) : $(OBJS_BONUS)
	@$(PRINTF) "\n$(BLUE)@ $(MAGENTA)=======$(BLUE){$(GREEN)So long update$(BLUE)}$(MAGENTA)======= $(BLUE)@"
	@$(PRINTF) "\n"
	@$(MAKE) -C MacroLibX/ -s -j --silent
	@$(PRINTF) "\n"
	@$(MAKE) -C libft/ --silent
	@cc $(CFLAGS) $(OBJS_BONUS) libft/libft.a MacroLibX/libmlx.so -lSDL2 -o $(BONUS_NAME)

$(OBJS_BONUS) : bonus_objs/%.o: srcs_bonus/%.c
	@$(eval SRC_COUNT_BONUS = $(shell expr $(SRC_COUNT_BONUS) + 1))
	@$(PRINTF) "\r%100s\r[ %d/%d (%d%%) ] Compiling $(GREEN)So_Long $(BLUE)$<$(DEFAULT)with bonus..." "" $(SRC_COUNT_BONUS) $(SRC_COUNT_TOT_BONUS) $(SRC_PCT_BONUS)
	@cc $(CFLAGS) -I libft/libft.h -c $< -o $@

$(OBJS) : objs/%.o: srcs/%.c
	@$(eval SRC_COUNT = $(shell expr $(SRC_COUNT) + 1))
	@$(PRINTF) "\r%100s\r[ %d/%d (%d%%) ] Compiling $(GREEN)So_Long $(BLUE)$<$(DEFAULT)..." "" $(SRC_COUNT) $(SRC_COUNT_TOT) $(SRC_PCT)
	@cc $(CFLAGS) -I libft/libft.h -c $< -o $@

clean :
	@rm -f $(OBJS)
	@rm -f $(OBJS_BONUS)
	@$(MAKE) clean -C libft/ --silent
	@$(MAKE) clean -C MacroLibX/ --silent


run: all
	./so_long map/map.ber

bonus: $(BONUS_NAME) $(OBJS_BONUS)

fclean : clean
	@rm -f $(NAME)
	@rm -f $(BONUS_NAME)
	@$(MAKE) fclean -C libft/ --silent
	@$(MAKE) fclean -C MacroLibX/ --silent
	@$(PRINTF) "$(YELLOW)*==============================*\n   /!\\ 🧹SO_LONG IS CLEAN🧹 /!\\ \n*==============================*\n"

re : fclean all

rbonus : fclean bonus

.PHONY : all clean fclean
	
