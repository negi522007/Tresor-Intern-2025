##
## EPITECH PROJECT, 2025
## receipt
## File description:
## makefile
##

SRC	=	src/clean_str.c	\
		src/get_infos.c	\
		src/main.c	\
		src/check_char.c	\
		src/print_infos.c	\
		src/gen_file.c	\
		src/my_getnbr.c	\
		src/file_managing.c
				

NAME	=	receipt

all:	$(NAME)

$(NAME):	$(SRC)
	@gcc -o $(NAME) $(SRC) -g3 -lhpdf

unit_tests: fclean $(NAME)

	@gcc -o unit_tests -coverage -lcriterion 

tests_run:      unit_tests
	./unit_tests

clean:
	@rm -rf *~
	@rm -f src/*~
	@rm -f include/*~
	@rm -f *gcno
	@rm -f *gcda

fclean: clean
	@rm -f $(NAME)
	@rm -f coding-style-reports.log

re: fclean all