CFLAGS		= -Wall -Wextra -Werror -O3
CC			= cc
INCLUDES	= -I./

NAME		= hotrace

SRCDIR		= ./
INCDIR		= ./
SRC			= hashmap.c  hashmap_utils.c  main.c  mem.c  read.c  utils.c  vector.c
OBJDIR		= .obj/
OBJ			= $(SRC:%.c=$(OBJDIR)%.o)
DEP         = $(SRC:%.c=$(OBJDIR)%.d)

$(OBJDIR)%.o : $(SRCDIR)%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -MMD -MP $(INCLUDES) -o $@ -c $<

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -MMD -MP $(INCLUDES) -o $(NAME) $(OBJ)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(DEP)