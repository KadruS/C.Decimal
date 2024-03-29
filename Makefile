CFLAGS=-std=c11 -Wall -Werror -Wextra 
TESTS=tests/*tests.c
FLAG_TEST=-lcheck
SRCS=$(wildcard s21_*.c)
OBJS=$(SRCS:.c=.o)

ifeq ($(shell uname), Linux)
	FLAG_TEST +=-lsubunit -lm
endif

all: clean s21_decimal.a gcov_report
	mkdir greport
	gcc --coverage $(SRCS) $(TESTS) $(FLAG_TEST) -o greport/greport
	./greport/greport
    #mv *.gc* ./greport


s21_decimal.a:$(OBJS)
	ar -rc s21_decimal.a $^
	ranlib s21_decimal.a
	rm -rf *.o

test: clean s21_decimal.a
	gcc --coverage $(CFLAGS) $(TESTS) s21_decimal.a $(FLAG_TEST) -o test -g
	./test

gcov_report:
	mkdir greport
	gcc --coverage $(SRCS) $(TESTS) $(FLAG_TEST) -o greport/greport
	./greport/greport
	lcov -t "test" -o s21_decimal.info -c -d .
	genhtml -o ./report s21_decimal.info
	open ./report/index.html

clean:
	-rm -rf *.o *.gcno *.gcda *.info  test s21_decimal.a gcov_report report greport a.out *.txt *.dSYM

style:
	clang-format -n *.c *.h ./tests/*.c ./tests/*.h
	clang-format -i *.c *.h ./tests/*.c ./tests/*.h

leaks:
	leaks -atExit -- ./greport/greport

cppcheck:

