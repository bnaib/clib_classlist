       # ******************************************************************** #
      #                                              _____ _   __            #
     #    By: Sergey Nikolaev                       / ___// | / /           #
    #    Сontacts: sn.prog@yandex.ru                \__ \/  |/ /           #
   #    Created: 2020.05.07 (YYYY.MM.DD)           ___/ / /|  /           #
  #    Updated: 2020.07.10 (YYYY.MM.DD)           /____/_/ |_/           #
 #                                                                      #
# ******************************************************************** #

NAME		= libclasslist.a
FLAGS		= -Wall -Wextra -Werror

HFILES		=\
	class_list.h

CFILES		=\
	class_list.c\
	class_list_add.c\
	class_list_create.c\
	class_list_get.c\
	class_list_cut.c\
	class_list_del.c\
	class_list_copy.c\
	class_list_sort.c

TFILES		=\
	01_construct.c\
	02_create.c\
	03_add.c\
	04_create2.c\
	05_list_copy.c

INC_DIR		= ./inc/
INC			= $(addprefix $(INC_DIR), $(HFILES))

SRC_DIR		= ./src/
SRC			= $(addprefix $(SRC_DIR), $(CFILES))

OBJ_DIR		= ./obj/
OFILES		= $(patsubst %.c, %.o, $(CFILES))
OBJ			= $(addprefix $(OBJ_DIR), $(OFILES))

TEST_DIR	= ./tests/

.PHONY: all clean fclean re runtests

all: checkDir $(NAME)

checkDir:
	if [ ! -d $(OBJ_DIR) ]; then mkdir $(OBJ_DIR); fi

$(NAME): $(OBJ) $(INC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	gcc $(FLAGS) -I $(INC_DIR) -o $@ -c $<

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

runtests: all $(TFILES)

$(TFILES):
	@gcc -I $(INC_DIR) $(TEST_DIR)$@ $(NAME)
	@./a.out
	@rm -f ./a.out
