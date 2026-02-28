NAME := hotrace

INCLUDE := includes/

BUILD_DIR := .build

RM := rm -f

CC := cc

FLAGS := -Wall -Werror -Wextra

FINCLUDE := -I $(INCLUDE)

DEPFLAGS := -MMD -MP

SRC_FILES := main.c\

OBJ := $(patsubst %.c, $(BUILD_DIR)/%.o, $(SRC_FILES))
DEPS := $(patsubst %.o, %.d, $(OBJ))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(FINCLUDE) $(OBJ) -o $@

$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	$(CC) $(FLAGS) $(FINCLUDE) $(DEPFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $@

clean:
	$(RM) $(OBJ) $(DEPS)
	rm -rf $(BUILD_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(DEPS)
