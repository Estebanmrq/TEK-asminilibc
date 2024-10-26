##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

RM		?=	rm
CC		?=	gcc
ASM		?=  nasm

SRC		=	src/strlen.asm		\
			src/strcmp.asm		\
			src/strchr.asm		\
			src/strrchr.asm		\
			src/memset.asm		\
			src/memcpy.asm		\
			src/memmove.asm		\
			src/strncmp.asm		\
			src/strcasecmp.asm	\
			src/strstr.asm		\
			src/strcspn.asm		\
			src/strpbrk.asm		\
			src/index.asm		\
			src/rindex.asm		\
			src/memfrob.asm		\
			src/atoi.asm

TSRC	=	tests/tests_memcpy.c		\
			tests/tests_memmove.c		\
			tests/tests_memset.c		\
			tests/tests_strchr.c		\
			tests/tests_strcmp.c		\
			tests/tests_strlen.c		\
			tests/tests_strncmp.c		\
			tests/tests_strrchr.c		\
			tests/tests_strcasecmp.c	\
			tests/tests_strstr.c		\
			tests/tests_strcspn.c		\
			tests/tests_strpbrk.c		\
			tests/tests_index.c			\
			tests/tests_rindex.c		\
			tests/tests_memfrob.c		\
			tests/tests_atoi.c



OBJ		=	$(SRC:.asm=.o)

AFLAGS	=	-f elf64
CFLAGS	=	-shared -fPIC
TFLAGS	=	--coverage -lcriterion -w

NAME 	=	libasm.so
TNAME	=	unit_tests

all: $(NAME)

%.o: %.asm
	$(ASM) $(AFLAGS) -o $@ $<

$(NAME): $(OBJ)
	ld $(CFLAGS) -o $(NAME) $(OBJ)


unit_tests: all
	$(CC) -o $(TNAME) $(TFLAGS) $(TSRC)

tests_run: 	unit_tests
		-./$(TNAME)

coverage: 	tests_run
		gcovr --exclude tests/

branches: tests_run
		gcovr --exclude tests/ --branches

clean:
	$(RM) -rf $(OBJ) $(TOBJ) *gcno *gcda

fclean: clean
	$(RM) -rf $(NAME) $(TNAME)

re: fclean $(NAME)

.PHONY: all clean fclean re unit_tests tests_run coverage branches
