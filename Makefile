##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

include sources/makefile.istl_sources

vpath %.c sources/$(ISTL_DIR)
vpath %.c sources/
vpath %.c sources/input
vpath %.c sources/builtins
vpath %.c sources/context/env_handling
vpath %.c sources/context/input_handling
vpath %.c sources/context/setup
vpath %.c sources/exec

########################
#### VARIABLES #########
########################

NAME	= 42sh

LIBPATH = ./lib/my/.

CC		= gcc

RM		= rm -rf

LINK_FLAG = -L. -lguillem

INCLUDES = -I./include/

CFLAGS 	= -g3 \
		  -Wno-unused-function \
		  -Wall -Werror -Wextra

########################
### FILES PATH #########
########################

SRC		 =	main.c

BUILTINS = builtin_cd.c \
		   builtin_cd2.c \
		   builtin_env.c \
		   builtin_exit.c \
		   builtin_prompt.c \
		   builtin_prompt2.c \
		   builtin_setenv.c \
		   builtin_setenv2.c \
		   builtin_unsetenv.c \
		   builtin_echo.c \
		   builtin_where.c \
		   builtin_which.c \
		   builtin_source.c \
		   builtin_alias.c \
		   get_function_pointer.c

CONTEXT  = parse_env.c \
		   utils.c \
		   read_user_input.c \
		   shell_main_loop.c \
		   setup_shell.c \
		   update_history.c

INPUT	=	input_module_1.c \
		input_module_2.c \
		input_module_3.c \
		input_module_4.c \
		input_module_5.c \
		input_module_6.c \
		input_module_7.c \
		input_module_8.c

EXEC    = exec.c \
		  exec_error_handling.c \
		  exec_error_messages.c	\
		  exec_redi.c \
		  right_redi.c \
		  left_redi.c

# needed for unit tests
COMBINED_NO_SRC = $(BUILTINS) \
					$(CONTEXT) \
					$(ISTL_MODULE) \
					$(INPUT) \
					$(ISTL_MODULE) \
					$(EXEC)

# binary included files
COMBINED	=	$(SRC) \
			$(COMBINED_NO_SRC)

TEST_SRC 	= ./tests/tests_gnl.c \
		   	  ./tests/tests_lib2.c \
		   	  ./tests/tests_lib.c \
		      ./tests/tests_cd.c \
			  ./tests/tests_env.c \
			  ./tests/tests_setenv.c \
			  ./tests/tests_unsetenv.c \
			  ./tests/tests_echo.c \
			  ./tests/tests_whichwhere.c

LIB  		= libguillem.a

OBJECT_DIR 	= ./objects

OBJ 	 	= $(patsubst %.c, $(OBJECT_DIR)/%.o, $(COMBINED))
OBJTST 		= $(patsubst %.c, $(OBJECT_DIR)/%.o, $(COMBINED_NO_SRC))

########################
#### COMPILATION #######
########################

all: directories $(LIB) $(NAME)

$(OBJECT_DIR):
	@mkdir -p $@

directories: | $(OBJECT_DIR)

$(OBJECT_DIR)/%.o : %.c
	@gcc -o $@ -c $< $(CFLAGS) $(INCLUDES)
	@echo -e "\e[35mCompiling $@\e[39m"


$(LIB):
	@make --no-print-directory -C $(LIBPATH)

$(NAME): $(OBJ)
	@gcc -o $(NAME) $^ $(LINK_FLAG)
	@echo -e "\e[34m[*** COMPILATION SUCCESSFUL ***]\e[39m"

clean:
	@make clean --no-print-directory -C $(LIBPATH)
	@$(RM) objects

fclean: clean
	@make fclean --no-print-directory -C $(LIBPATH)
	@$(RM) $(NAME)
	@echo -e "\e[34m[*** CLEAN ***]\e[39m"

re: fclean all

########################
#### UNIT TESTS ########
########################

func_tests:
	@sh tests/.ftests

tests_run: directories $(LIB) $(OBJTST)
	@$(CC) -c $(TEST_SRC) --coverage -g3 $(INCLUDES) $(LINK_FLAG)
	@mv *.o objects
	@$(CC) -o unit_tests ./objects/*.o --coverage $(INCLUDES) $(LINK_FLAG) -lcriterion
	@./unit_tests > /dev/null
	@echo -e "\e[34m[*** TESTS OVER ***]\e[39m"

tests_run_clean: tests_run
	@gcovr --exclude tests/
	@make fclean --no-print-directory -C $(LIBPATH)
	@$(RM) unit_tests
	@$(RM) *.gc* unit_tests
	@$(RM) $(NAME)
	@$(RM) objects
	@echo -e "\e[34m[*** CLEAN SUCCESSFUL ***]\e[39m"

########################
#### .PHONY ############
########################

.PHONY: all clean fclean re tests_run tests_run_clean
