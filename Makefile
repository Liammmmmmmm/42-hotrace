INCLUDE		=	$(addprefix -I,$(shell find src -name "*.h" -exec dirname {} + | sort -u))

SRC			=	$(shell find src -name "*.c")

BUILD_DIR	=	.build
OBJS		=	$(addprefix $(BUILD_DIR)/,$(SRC:.c=.o))
DEPS		=	$(OBJS:.o=.d)

CC			=	cc

FLAGS		=	-Wall -Wextra -Werror

NAME		=	a.out

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(INCLUDE) -o $@ $(OBJS)

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(FLAGS) $(INCLUDE) -MD -MP -c $< -o $@

clean:
	@rm -rf $(BUILD_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

-include $(DEPS)

.PHONY : all clean fclean re
