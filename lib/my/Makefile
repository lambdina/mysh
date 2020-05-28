##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile for lib compilation
##

########################
#####VARIABLES##########
########################


NAME 	= 	libguillem.a

SRC 	=	./check_string_toolbox.c \
			./compare_string.c \
			./conversions_toolbox.c \
			./copy_toolbox.c \
			./get_len_toolbox.c \
			./copy_toolbox.c \
			./get_len_toolbox.c \
			./get_next_line.c \
			./malloc_toolbox.c \
			./misc.c \
			./modify_string.c \
			./number_toolbox.c \
			./number_toolbox.c \
			./do_op.c \
			./tabgen.c \
			./write_toolbox.c

OBJECTS 	 	= $(patsubst %.c, $(OBJECT_DIR)%.o, $(SRC))


HEADER 	=	./lib.h

LIBPATH = 	./../../include/


########################
#####COMPILATION########
########################

all: directories $(NAME)

$(NAME): $(OBJECTS)
	@ar rc $(NAME) $(OBJECTS)
	@cp $(HEADER) $(LIBPATH)
	@cp $(NAME) ./../../.
	@echo -e "\e[34m[*** LIB CREATED ***]\e[39m"

$(OBJECT_DIR):
	@mkdir -p $@

directories: | $(OBJECT_DIR)

$(OBJECT_DIR)/%.o : %.c
	@gcc -o $@ -c -g3
	@echo -e "\e[33mCompiling $@\e[39m"

clean:
	@rm -rf $(OBJECTS)
	@rm -f $(NAME)

fclean: clean
	@rm -f $(LIBPATH)$(HEADER)
	@rm -f ../../$(NAME)
	@echo -e "\e[34m[*** LIB CLEANED ***]\e[39m"

re: fclean all

.PHONY: all clean fclean re
