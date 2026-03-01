INCLUDE			=	$(addprefix -I,$(shell find src -name "*.h" -exec dirname {} + | sort -u))

SRC				=	$(shell find src -name "*.c")

GCC_PROFILE_DIR	=	.gcc_profile
TEST_FILE		=	test.htr

PREBUILD_DIR	=	.prebuild
PREBUILD_OBJS	=	$(addprefix $(PREBUILD_DIR)/,$(SRC:.c=.o))
PREBUILD_DEPS	=	$(OBJS:.o=.d)

BUILD_DIR		=	.build
OBJS			=	$(addprefix $(BUILD_DIR)/,$(SRC:.c=.o))
DEPS			=	$(OBJS:.o=.d)

CC				=	gcc

PREFLAGS		=	-Wall -Wextra -Werror -O3 -fprofile-generate=$(GCC_PROFILE_DIR)
FLAGS			=	-Wall -Wextra -Werror -O3 -Wno-missing-profile -fprofile-use=$(GCC_PROFILE_DIR)

PRECOMPILE		=	.hotrace.precompile
NAME			=	hotrace

all: $(NAME)

$(PRECOMPILE): $(TEST_FILE) $(PREBUILD_OBJS)
	$(CC) $(PREFLAGS) $(INCLUDE) -o $@ $(PREBUILD_OBJS)
	./$(PRECOMPILE) > $(PREBUILD_DIR)/dump < $(TEST_FILE)

$(PREBUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(PREFLAGS) $(INCLUDE) -MD -MP -c $< -o $@

$(TEST_FILE): test.py
	python3 ./test.py

$(NAME): $(PRECOMPILE) $(OBJS)
	$(CC) $(FLAGS) $(INCLUDE) -o $@ $(OBJS)

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(FLAGS) $(INCLUDE) -MD -MP -c $< -o $@

clean:
	@rm -rf $(BUILD_DIR)
	@rm -rf $(PREBUILD_DIR)
	@rm -rf $(GCC_PROFILE_DIR)
	@rm -f $(PRECOMPILE)
	@rm -f $(TEST_FILE)

fclean: clean
	@rm -f $(NAME)

re: fclean all

-include $(DEPS) $(PREBUILD_DEPS)

.PHONY : all clean fclean re